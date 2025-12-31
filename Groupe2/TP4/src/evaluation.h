#pragma once
#include "lexer.h"

typedef struct resultat{
   union{
    int entier;
    float flottant;
   };
   int isfloat;
}Resultat;

int eval(Token** expression, int* expressionNB, Resultat* resultat);