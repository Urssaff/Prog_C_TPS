#pragma once
#include "lexer.h"

typedef struct expression{
   Token operation;
   Token operande1;
   Token operande2;
}Expression;

int parser(Token** tokens, int* tokenNB, Expression* expression);