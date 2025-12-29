#include "evaluation.h"
#include <string.h>

int eval(Expression* expression, Resultat* resultat){
    char* operateur=expression->operation.operateur;
    if(strcmp(operateur,"+")==0){
        if(expression->operande1.type == 2 && expression->operande2.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.flottant + expression->operande2.flottant;
        }
        else if(expression->operande1.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.flottant + expression->operande2.entier;
        }
        else if(expression->operande2.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.entier + expression->operande2.flottant;
        }
        else{
            resultat->isfloat = 1;
            resultat->entier = expression->operande1.entier + expression->operande2.entier;
        }
    }
    else if(strcmp(operateur,"-")==0){
        if(expression->operande1.type == 2 && expression->operande2.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.flottant - expression->operande2.flottant;
        }
        else if(expression->operande1.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.flottant - expression->operande2.entier;
        }
        else if(expression->operande2.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.entier - expression->operande2.flottant;
        }
        else{
            resultat->isfloat = 1;
            resultat->entier = expression->operande1.entier - expression->operande2.entier;
        }
    }
    else if(strcmp(operateur,"*")==0){
        if(expression->operande1.type == 2 && expression->operande2.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.flottant * expression->operande2.flottant;
        }
        else if(expression->operande1.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.flottant * expression->operande2.entier;
        }
        else if(expression->operande2.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.entier * expression->operande2.flottant;
        }
        else{
            resultat->isfloat = 1;
            resultat->entier = expression->operande1.entier * expression->operande2.entier;
        }
    }
    else if(strcmp(operateur,"/")==0){
        if(expression->operande1.type == 2 && expression->operande2.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.flottant / expression->operande2.flottant;
        }
        else if(expression->operande1.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.flottant / expression->operande2.entier;
        }
        else if(expression->operande2.type == 2){
            resultat->isfloat = 0;
            resultat->flottant = expression->operande1.entier / expression->operande2.flottant;
        }
        else{
            int modulo = expression->operande1.entier % expression->operande2.entier;
            if(modulo > 0){
                resultat->isfloat = 0;
                resultat->flottant = (float)(expression->operande1.entier) /  (float)(expression->operande2.entier);
            }
            else{
                resultat->isfloat = 1;
                resultat->entier = expression->operande1.entier / expression->operande2.entier;
            }
        }
    }
    return 0;
}