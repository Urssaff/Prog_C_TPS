#pragma once
#include "lexer.h"
#include "evaluation.h"

int est_lambda_tokens(Token** tokens, int tokenNB);
int traiter_lambda_tokens(Token** tokens, int tokenNB, Variable** variables, int* variableNB);