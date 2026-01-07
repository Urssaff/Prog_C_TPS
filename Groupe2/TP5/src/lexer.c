#include "lexer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int tokenizer(char* expression, Token** tokens, int* tokenNB){
    const char* separator=" ";
    char* token=strtok(expression,separator);
    while(token != NULL){
        int val_int;
        float val_float;
        if(strcmp(token,"+")==0||strcmp(token,"/")==0||strcmp(token,"*")==0||(strncmp(token,"-",1)==0&&strlen(token)==1)||strcmp(token,"(")==0||strcmp(token,")")==0||strcmp(token,"=")==0||strcmp(token,".")==0){
            strcpy((*tokens)[*tokenNB].operateur,token);
            (*tokens)[*tokenNB].type=0;
            *tokenNB=*tokenNB+1;
            Token* new_tokens=realloc(*tokens,(*tokenNB+1)*sizeof(Token));
            if(new_tokens!=NULL){
                *tokens = new_tokens;
            }
        }
        else if(sscanf(token,"%f",&val_float)==1){
            sscanf(token,"%d",&val_int);
            if(!(( val_float - val_int )>0.0)){
                (*tokens)[*tokenNB].entier=val_int;
                (*tokens)[*tokenNB].type=1;
            }
            else{
                (*tokens)[*tokenNB].flottant=val_float;
                (*tokens)[*tokenNB].type=2;
            }
            *tokenNB=*tokenNB+1;
            Token* new_tokens=realloc(*tokens,(*tokenNB+1)*sizeof(Token));
            if(new_tokens!=NULL){
                *tokens = new_tokens;
            }
        }
        else{
            strcpy((*tokens)[*tokenNB].chaine,token);
            (*tokens)[*tokenNB].type=3;
            *tokenNB=*tokenNB+1;
            Token* new_tokens=realloc(*tokens,(*tokenNB+1)*sizeof(Token));
            if(new_tokens!=NULL){
                *tokens = new_tokens;
            }
        }
        token=strtok(NULL,separator);
    }

    return 0;
}