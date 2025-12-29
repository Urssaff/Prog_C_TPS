#pragma once
#include "parseur.h"

typedef struct resultat{
   union{
    int entier;
    float flottant;
   };
   int isfloat;
}Resultat;

int eval(Expression* expression, Resultat* resultat);