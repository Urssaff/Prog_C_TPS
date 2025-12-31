#include "parser.h"
#include <stdlib.h>
#include <string.h>

int parser(Token** tokens, int* tokenNB, Token** expression, int* expressionNB){
    int i=0;
    Token* pile=malloc(*tokenNB * sizeof(Token));
    int pileNB=0;
    Token cur_token=(*tokens)[i];
    while(i < *tokenNB || pileNB>0){
        if(i < *tokenNB){
            if(cur_token.type==0){
                if(pileNB==0 || strcmp(pile[pileNB-1].operateur,"(")==0 || strcmp(cur_token.operateur, "(")==0 || ((strcmp(cur_token.operateur, "*")==0 || strcmp(cur_token.operateur, "/")==0) && (strcmp(pile[pileNB - 1].operateur, "+")==0 || strcmp(pile[pileNB - 1].operateur, "-")==0))){
                    pile[pileNB]=cur_token;
                    pileNB++;
                    i++;
                    cur_token=(*tokens)[i];
                }
                else if(strcmp(cur_token.operateur, ")")==0){
                    Token token_depile;
                    do{
                        token_depile=pile[pileNB - 1];
                        if(strcmp(token_depile.operateur,"(")!=0){
                            (*expression)[*expressionNB]=token_depile;
                            *expressionNB=*expressionNB+1;
                            Token* new_expression=realloc(*expression,(*expressionNB+1)*sizeof(Token));
                            if(new_expression!=NULL){
                                *expression = new_expression;
                            }
                        }
                        pileNB--;
                    }
                    while(strcmp(token_depile.operateur, "(")!=0);
                    i++;
                    cur_token=(*tokens)[i];
                }
                else if((strcmp(cur_token.operateur, "*")==0 || strcmp(cur_token.operateur, "/")==0) && (strcmp(pile[pileNB - 1].operateur, "*")==0 || strcmp(pile[pileNB - 1].operateur, "/")==0)){
                    Token token_depile=pile[pileNB - 1];
                    while(pileNB>0 && (strcmp(token_depile.operateur, "+")!=0 && strcmp(token_depile.operateur, "-")!=0)){
                        (*expression)[*expressionNB]=token_depile;
                        *expressionNB=*expressionNB+1;
                        Token* new_expression=realloc(*expression,(*expressionNB+1)*sizeof(Token));
                        if(new_expression!=NULL){
                            *expression = new_expression;
                        }
                        pileNB--;
                        token_depile=pile[pileNB - 1];
                    }
                    pile[pileNB]=cur_token;
                    pileNB++;
                    i++;
                    cur_token=(*tokens)[i];
                }
                else{
                    while(pileNB>0){
                        Token token_depile=pile[pileNB - 1];
                        (*expression)[*expressionNB]=token_depile;
                        *expressionNB=*expressionNB+1;
                        Token* new_expression=realloc(*expression,(*expressionNB+1)*sizeof(Token));
                        if(new_expression!=NULL){
                            *expression = new_expression;
                        }
                        pileNB--;
                    }
                    pile[pileNB]=cur_token;
                    pileNB++;
                    i++;
                    cur_token=(*tokens)[i];
                }
            }
            else{
                (*expression)[*expressionNB]=cur_token;
                *expressionNB=*expressionNB+1;
                Token* new_expression=realloc(*expression,(*expressionNB+1)*sizeof(Token));
                if(new_expression!=NULL){
                    *expression = new_expression;
                }
                i++;
                cur_token=(*tokens)[i];
            }
        }
        else{
            while(pileNB>0){
                Token token_depile=pile[pileNB - 1];
                (*expression)[*expressionNB]=token_depile;
                *expressionNB=*expressionNB+1;
                Token* new_expression=realloc(*expression,(*expressionNB+1)*sizeof(Token));
                if(new_expression!=NULL){
                    *expression = new_expression;
                }
                pileNB--;
            }
        }
    }
    free(pile);
    return 0;
}