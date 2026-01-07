// lambda.c
#include "lambda.h"
#include "parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int est_lambda_tokens(Token** tokens, int tokenNB) {
    if (tokenNB < 6) return 0;
    
    if ((*tokens)[0].type != 0 || strcmp((*tokens)[0].operateur, "(") != 0){
        return 0;
    }
    if ((*tokens)[1].type != 3 || strcmp((*tokens)[1].chaine, "lambda") != 0){
        return 0;
    }
    if ((*tokens)[2].type != 3){
        return 0; 
    }
    for (int i = 3; i < tokenNB; i++) {
        if ((*tokens)[i].type == 0 && strcmp((*tokens)[i].operateur, ".") == 0) {
            return 1;
        }
    }
    
    return 0;
}

int traiter_lambda_tokens(Token** tokens, int tokenNB, Variable** variables, int* variableNB) {
    char var_name[15];
    strcpy(var_name, (*tokens)[2].chaine);
    
    int pos_point = -1;
    for (int i = 3; i < tokenNB; i++) {
        if ((*tokens)[i].type == 0 && strcmp((*tokens)[i].operateur, ".") == 0) {
            pos_point = i;
            break;
        }
    }
    
    if (pos_point == -1) {
        printf("Erreur : point manquant dans la lambda\n");
        return -1;
    }
    
    int posFinLambda = -1;
    int niveauParenthese = 1; 
    
    for (int i = pos_point + 1; i < tokenNB; i++) {
        if ((*tokens)[i].type == 0) {
            if (strcmp((*tokens)[i].operateur, "(") == 0) {
                niveauParenthese++;
            } else if (strcmp((*tokens)[i].operateur, ")") == 0) {
                niveauParenthese--;
                if (niveauParenthese == 0) {
                    posFinLambda = i;
                    break;
                }
            }
        }
    }
    
    if (posFinLambda == -1) {
        printf("Erreur : parenthèse fermante manquante\n");
        return -1;
    }
    
    if (posFinLambda + 1 >= tokenNB) {
        printf("Erreur : argument manquant\n");
        return -1;
    }
    
    Token arg_token = (*tokens)[posFinLambda + 1];
    
    Token valeur_arg;
    
    if (arg_token.type == 1 || arg_token.type == 2) {
        valeur_arg = arg_token;
    } else if (arg_token.type == 3) {
        int trouve = -1;
        for (int i = 0; i < *variableNB; i++) {
            if (strcmp((*variables)[i].nom, arg_token.chaine) == 0) {
                trouve = i;
                break;
            }
        }
        
        if (trouve == -1) {
            printf("Erreur : la variable %s n'est pas définie\n", arg_token.chaine);
            return -1;
        }
        
        Variable var = (*variables)[trouve];
        if (var.type == 0) {
            printf("Erreur : impossible d'utiliser une chaîne comme argument lambda\n");
            return -1;
        }
        
        valeur_arg.type = var.type;
        if (var.type == 1) {
            valeur_arg.entier = var.entier;
        } else {
            valeur_arg.flottant = var.flottant;
        }
    } else {
        printf("Erreur : argument invalide\n");
        return -1;
    }
    
    int expr_len = posFinLambda - pos_point - 1;
    if (expr_len <= 0) {
        printf("Erreur : expression vide\n");
        return -1;
    }
    
    Token* expr_tokens = malloc(expr_len * sizeof(Token));
    int expr_tokenNB = 0;
    
    for (int i = pos_point + 1; i < posFinLambda; i++) {
        expr_tokens[expr_tokenNB] = (*tokens)[i];
        
        if (expr_tokens[expr_tokenNB].type == 3 && 
            strcmp(expr_tokens[expr_tokenNB].chaine, var_name) == 0) {
            expr_tokens[expr_tokenNB] = valeur_arg;
        }
        
        expr_tokenNB++;
    }
    
    Token* expression = malloc(sizeof(Token));
    int expressionNB = 0;
    
    if (parser(&expr_tokens, &expr_tokenNB, &expression, &expressionNB, NULL, NULL) != 0) {
        free(expr_tokens);
        free(expression);
        return -1;
    }
    
    Resultat resultat;
    if (eval_calc(&expression, &expressionNB, &resultat) == 0) {
        if (resultat.isfloat == 0) {
            printf("%f\n", resultat.flottant);
        } else {
            printf("%d\n", resultat.entier);
        }
    }
    
    free(expr_tokens);
    free(expression);
    
    return 0;
}