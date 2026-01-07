#include "parser.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int resoudre_variable(Token* token, Variable** variables, int* variableNB){
    if(token->type != 3){
        return 0;
    }
    
    for(int i = 0; i < *variableNB; i++){
        if(strcmp((*variables)[i].nom, token->chaine) == 0){
            Variable var = (*variables)[i];
            
            switch(var.type){
                case 1:
                    token->type = 1;
                    token->entier = var.entier;
                    return 0;
                case 2:
                    token->type = 2;
                    token->flottant = var.flottant;
                    return 0;
                case 0:
                    printf("Erreur : impossible d'utiliser une chaîne '%s' dans une expression\n", var.nom);
                    return -1;
            }
        }
    }
    
    printf("Erreur : variable '%s' non définie\n", token->chaine);
    return -1;
}

int parser(Token** tokens, int* tokenNB, Token** expression, int* expressionNB, Variable** variables, int* variableNB){
    int i=0;
    Token* pile=malloc(*tokenNB * sizeof(Token));
    int pileNB=0;

    while(i < *tokenNB || pileNB>0){
        if(i < *tokenNB){
            Token cur_token=(*tokens)[i];

            if(cur_token.type==0){
                if(pileNB==0 || strcmp(pile[pileNB-1].operateur,"(")==0 || strcmp(cur_token.operateur, "(")==0 || ((strcmp(cur_token.operateur, "*")==0 || strcmp(cur_token.operateur, "/")==0) && (strcmp(pile[pileNB - 1].operateur, "+")==0 || strcmp(pile[pileNB - 1].operateur, "-")==0))){
                    pile[pileNB]=cur_token;
                    pileNB++;
                    i++;
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
                        if(pileNB > 0){
                            token_depile=pile[pileNB - 1];
                        }
                    }
                    pile[pileNB]=cur_token;
                    pileNB++;
                    i++;
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
                }
            }
            else{
                if(resoudre_variable(&cur_token, variables, variableNB) != 0){
                    free(pile);
                    return -1;
                }

                (*expression)[*expressionNB]=cur_token;
                *expressionNB=*expressionNB+1;
                Token* new_expression=realloc(*expression,(*expressionNB+1)*sizeof(Token));
                if(new_expression!=NULL){
                    *expression = new_expression;
                }
                i++;
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