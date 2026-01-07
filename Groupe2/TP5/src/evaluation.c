#include "evaluation.h"
#include "parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int eval(Token** tokens, int* tokenNB, Variable** variables, int* variableNB){
    int contient_chaine=0;
    int premier_chaine=0;
    int assignation=0;

    for(int i=0;i<*tokenNB;i++){
        Token cur_token=(*tokens)[i];
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

    if(contient_chaine==1 && premier_chaine==1 && *tokenNB==1){
        return afficher_variable(tokens,variables,variableNB);
    }
    else if(contient_chaine==1 && premier_chaine==1 && *tokenNB==3 && assignation==1){
        return assigner_variable(tokens,variables,variableNB);
    }
    else if(assignation==0 && *tokenNB>=3){
        Token* expression=malloc(1*sizeof(Token));
        int expressionNB=0;
        int resultparser=parser(tokens,tokenNB,&expression,&expressionNB,variables,variableNB);
        if(resultparser==0){
            Resultat* resultat=malloc(1*sizeof(Resultat));
            eval_calc(&expression,&expressionNB,resultat);
            if(resultat->isfloat==0){
                printf("%f\n",resultat->flottant);
            }
            else{
                printf("%d\n",resultat->entier);
            }
            free(resultat);
        }
        free(expression);
        if(resultparser==-1){
            return -1;
        }
    }
    else{
        printf("Erreur de syntaxe\n");
        return -1;
    }
    return 0;
}

int eval_calc(Token** expression, int* expressionNB, Resultat* resultat){
    Token* pile=malloc(*expressionNB * sizeof(Token));
    int pileNB=0;
    int i=0;
    Token cur_token=(*expression)[i];
    while(i < *expressionNB){
        if(cur_token.type==0){
            Token operande2=pile[pileNB-1];
            pileNB--;
            Token operande1=pile[pileNB-1];
            pileNB--;
            char* operateur=cur_token.operateur;
            Token result_inter;
            if(strcmp(operateur,"+")==0){
                if(operande1.type == 2 && operande2.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.flottant + operande2.flottant;
                }
                else if(operande1.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.flottant + operande2.entier;
                }
                else if(operande2.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.entier + operande2.flottant;
                }
                else{
                    result_inter.type=1;
                    result_inter.entier=operande1.entier + operande2.entier;
                }
            }
            else if(strcmp(operateur,"-")==0){
                if(operande1.type == 2 && operande2.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.flottant - operande2.flottant;
                }
                else if(operande1.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.flottant - operande2.entier;
                }
                else if(operande2.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.entier - operande2.flottant;
                }
                else{
                    result_inter.type=1;
                    result_inter.entier=operande1.entier - operande2.entier;
                }
            }
            else if(strcmp(operateur,"*")==0){
                if(operande1.type == 2 && operande2.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.flottant * operande2.flottant;
                }
                else if(operande1.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.flottant * operande2.entier;
                }
                else if(operande2.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.entier * operande2.flottant;
                }
                else{
                    result_inter.type=1;
                    result_inter.entier=operande1.entier * operande2.entier;
                }
            }
            else if(strcmp(operateur,"/")==0){
                if(operande1.type == 2 && operande2.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.flottant / operande2.flottant;
                }
                else if(operande1.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.flottant / operande2.entier;
                }
                else if(operande2.type == 2){
                    result_inter.type=2;
                    result_inter.flottant=operande1.entier / operande2.flottant;
                }
                else{
                    int modulo = operande1.entier % operande2.entier;
                    if(modulo > 0){
                        result_inter.type=2;
                        result_inter.flottant=(float)operande1.entier / (float)operande2.entier;
                    }
                    else{
                        result_inter.type=1;
                        result_inter.entier=operande1.entier / operande2.entier;
                    }
                }
            }
            pile[pileNB]=result_inter;
            pileNB++;
        }
        else{
            pile[pileNB]=cur_token;
            pileNB++;
        }
        i++;
        cur_token=(*expression)[i];
    }
    Token token_result=pile[0];
    if(token_result.type==1){
        (*resultat).isfloat=1;
        (*resultat).entier=token_result.entier;
    }
    else{
        (*resultat).isfloat=0;
        (*resultat).flottant=token_result.flottant;
    }
    free(pile);
    return 0;
}

int assigner_variable(Token** tokens, Variable** variables, int* variableNB){
    Token var_search=(*tokens)[0];
    if((*tokens)[1].type==0 && strcmp((*tokens)[1].operateur,"=")==0){
        int trouve=0;
        Variable* exist_var;
        for(int i=0; i<*variableNB;i++){
            Variable* cur_var=&(*variables)[i];
            if(strcmp((*cur_var).nom,var_search.chaine)==0){
                trouve=1;
                exist_var=cur_var;
                break;
            }
        }
        if(trouve==1){
            int modif=0;
            switch((*exist_var).type){
                case 0:
                    if((*tokens)[2].type==0){
                        modif=1;
                        strcpy((*exist_var).chaine,(*tokens)[2].operateur);
                    }
                    else if((*tokens)[2].type==3){
                        modif=1;
                        strcpy((*exist_var).chaine,(*tokens)[2].chaine);
                    }
                    break;
                case 1:
                    if((*tokens)[2].type==1){
                        modif=1;
                        (*exist_var).entier=(*tokens)[2].entier;
                    }
                    break;
                case 2:
                    if((*tokens)[2].type==2){
                        modif=1;
                        (*exist_var).flottant=(*tokens)[2].flottant;
                    }
                    break;
            }
            if(modif==0){
                printf("Erreur : Variable déjà définie. Tentative d'assignation d'une valeur d'un mauvais type.\n");
            }
        }
        else{
            switch((*tokens)[2].type){
                case 0:
                    (*variables)[*variableNB].type=0;
                    strcpy((*variables)[*variableNB].chaine,(*tokens)[2].operateur);
                    break;
                case 1:
                    (*variables)[*variableNB].type=1;
                    (*variables)[*variableNB].entier=(*tokens)[2].entier;
                    break;
                case 2:
                    (*variables)[*variableNB].type=2;
                    (*variables)[*variableNB].flottant=(*tokens)[2].flottant;
                    break;
                case 3:
                    (*variables)[*variableNB].type=0;
                    strcpy((*variables)[*variableNB].chaine,(*tokens)[2].chaine);
                    break;
            }
            strcpy((*variables)[*variableNB].nom,var_search.chaine);
            *variableNB=*variableNB+1;
            Variable* new_var=realloc(*variables,(*variableNB+1)*sizeof(Variable));
            if(new_var!=NULL){
                *variables=new_var;
            }
        }
    }
    else{
        return -1;
    }
    return 0;
}

int afficher_variable(Token** tokens, Variable** variables, int* variableNB){
    Token var_search=(*tokens)[0];
    int trouve=0;
    Variable exist_var;
    for(int i=0; i<*variableNB;i++){
        Variable cur_var=(*variables)[i];
        if(strcmp(cur_var.nom,var_search.chaine)==0){
            trouve=1;
            exist_var=cur_var;
            break;
        }
    }
    if(trouve==1){
        switch(exist_var.type){
            case 0:
                printf("%s\n",exist_var.chaine);
                break;
            case 1:
                printf("%d\n",exist_var.entier);
                break;
            case 2:
                printf("%f\n",exist_var.flottant);
                break;
        }
    }
    return 0;
}