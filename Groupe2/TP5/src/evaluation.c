#include "evaluation.h"
#include <string.h>
#include <stdlib.h>

int eval(Token** expression, int* expressionNB, Resultat* resultat){
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