#pragma once
#include "lexer.h"


typedef struct resultat{
   union{
    int entier;
    float flottant;
   };
   int isfloat;
}Resultat;

typedef struct variable{
    char nom[15];
    int type;
    union{
        int entier;
        float flottant;
        char chaine[200];
    };
}Variable;

int eval(Token** tokens, int* tokenNB, Variable** variables, int* variableNB);

int eval_calc(Token** expression, int* expressionNB, Resultat* resultat);

int assigner_variable(Token** tokens, Variable** variables, int* variableNB);

int afficher_variable(Token** tokens, Variable** variables, int* variableNB);