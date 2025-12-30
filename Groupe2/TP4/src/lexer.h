#pragma once

typedef struct token{
    union{
        int entier;
        float flottant;
        char operateur[2];
    };
    int type;
}Token;

int tokenizer(char* expression, Token** tokens, int* tokenNB);