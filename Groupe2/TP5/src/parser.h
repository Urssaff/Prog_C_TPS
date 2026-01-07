#pragma once
#include "lexer.h"
#include "evaluation.h"

int resoudre_variable(Token* token, Variable** variables, int* variableNB);

int parser(Token** tokens, int* tokenNB, Token** expression, int* expressionNB, Variable** variables, int* variableNB);