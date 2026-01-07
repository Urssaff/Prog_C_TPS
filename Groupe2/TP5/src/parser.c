#include "parser.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int resoudre_variable(Token* token, Variable** variables, int* variableNB){
    // Si ce n'est pas une chaîne, rien à faire
    if(token->type != 3){
        return 0;
    }
    
    // Chercher la variable
    for(int i = 0; i < *variableNB; i++){
        if(strcmp((*variables)[i].nom, token->chaine) == 0){
            Variable var = (*variables)[i];
            
            switch(var.type){
                case 1:  // Entier
                    token->type = 1;
                    token->entier = var.entier;
                    return 0;
                case 2:  // Flottant
                    token->type = 2;
                    token->flottant = var.flottant;
                    return 0;
                case 0:  // Chaîne
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





/*
        int contient_chaine=0;
        int premier_chaine=0;
        int assignation=0;

        for(int i=0;i<tokenNB;i++){
            Token cur_token=tokens[i];
            if(cur_token.type==3){
                contient_chaine=1;
                if(i==0){
                    premier_chaine=1;
                }
            }
            else if(cur_token.type==0 && strcmp(cur_token.operateur,"=")==0){
                assignation=1;
            }
        }

        if(contient_chaine==1 && premier_chaine==1 && tokenNB==1){
            afficher_variable(&tokens,variables,variableNB);
        }
        else if(contient_chaine==1 && premier_chaine==1 && tokenNB==3 && assignation==1){
            assigner_variable(&tokens,variables,variableNB);
        }
        else if(contient_chaine==0 && assignation==0 && tokenNB>=3){
            resultparser=parser(&tokens,&tokenNB,&expression,&expressionNB);
            if(resultparser==0){
                Resultat* resultat=malloc(1*sizeof(Resultat));
                eval(&expression,&expressionNB,resultat);
                if(resultat->isfloat==0){
                    printf("%f\n",resultat->flottant);
                }
                else{
                    printf("%d\n",resultat->entier);
                }
                free(resultat);
            }
        }
        else{
            printf("Erreur de syntaxe\n");
        }
*/