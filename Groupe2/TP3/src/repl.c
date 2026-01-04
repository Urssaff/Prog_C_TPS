#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "lexer.h"
#include "parseur.h"
#include "evaluation.h"

#define VERSION 1.0
#define CMD_NUMBER 5

typedef struct commande{
    char nom[15];
    char expression[100];
    char desc[500];
    char exemples[200];
}Commande;

typedef struct locale{
    char nom[10];
    Commande* local_man;
}Locale;

Commande cmd_fr_man[]={
    {"date","date","Affiche la date.","date"},
    {"echo","echo [TEXTE]...","Affiche une ligne de texte.","echo banane flambée"},
    {"aide","aide","Renvoie la liste des commandes et leur utilisation.","help"},
    {"quitter","quitter","Ferme l'interpréteur de commande.","quit"},
    {"version","version","Renvoie la version de l'interpréteur de commande.","version"}
};

Commande cmd_en_man[]={
    {"date","date","Prints the date.","date"},
    {"echo","echo [TEXT]...","Prints a line of text","echo banane flambée"},
    {"help","help","Returns the command list and their usage.","help"},
    {"quit","quit","Shuts down the interpreter.","quit"},
    {"version","version","Prints the interpreters version","version"}
};

Locale locale_list[]={
    {"en-en",cmd_en_man},
    {"fr-fr",cmd_fr_man}
};

int afficher_aide(Locale* locale){
    char* fr_text[]={"MANUEL DES COMMANDES","NOM","USAGE","DESCRIPTION","EXEMPLES"};
    char* en_text[]={"COMMAND MANUAL","NAME","USE","DESCRIPTION","EXEMPLES"};
    char** text;
    if(strcmp(locale->nom,"en-en")==0){
        text=en_text;
    }
    else if(strcmp(locale->nom,"fr-fr")==0){
        text=fr_text;
    }
    else{
        text=en_text;
    }
    printf("%s\n\n",text[0]);
    for(long unsigned int i=0; i<CMD_NUMBER;i++){
        if(i>0){
            printf("\n--------------------------------\n\n");
        }
        printf("%s : %s\n\n",text[1],locale->local_man[i].nom);
        printf("%s : %s\n\n",text[2],locale->local_man[i].expression);
        printf("%s : %s\n\n",text[3],locale->local_man[i].desc);
        printf("%s : %s\n",text[4],locale->local_man[i].exemples);
    }

    return 0;
}

int afficher_version(){
    printf("v%f", VERSION);

    return 0;
}

int traiter_echo(char* commande){
    printf("Echo: ");

    for (int i = 5; commande[i] != '\0'; i++)
    {
        printf("%c", commande[i]);
    }
    printf("\n");

    return 0;
}

int traiter_quit(Locale* locale,int* continuer){
    char* fr_text="Arrêt";
    char* en_text="Stopping";
    char* text;
    if(strcmp(locale->nom,"en-en")==0){
        text=en_text;
    }
    else if(strcmp(locale->nom,"fr-fr")==0){
        text=fr_text;
    }
    else{
        text=en_text;
    }

    printf("%s...\n",text);
    *continuer=0;

    return 0;
}

int traiter_calcul(char* commande){
    Token* tokens=malloc(1*sizeof(Token));
    Expression* expression=malloc(1*sizeof(Expression));
    Resultat* resultat=malloc(1*sizeof(Resultat));
    int tokenNB=0;
    int resultparser=1;
    int resulttokenizer=tokenizer(commande, &tokens, &tokenNB);
    if(resulttokenizer==0){
        resultparser=parser(&tokens,&tokenNB,expression);
        if(resultparser==0){
            eval(expression,resultat);
            if(resultat->isfloat==0){
                printf("%f\n",resultat->flottant);
            }
            else{
                printf("%d\n",resultat->entier);
            }
        }
    }
    free(resultat);
    free(tokens);
    free(expression);
    if(resulttokenizer==0 || resultparser==1){
        return 1;
    }
    return 0;
}

int main()
{
    int continuer = 1;

    while (continuer)
    {
        printf("> ");

        char commande[1024];

        fgets(commande, sizeof(commande), stdin);

        commande[strcspn(commande, "\n")] = 0;

        int cmd_to_exec=-1;
        Locale* locale=NULL;
        for(long unsigned int j=0; j<(sizeof(locale_list)/sizeof(locale_list[0]));j++){
            Commande* cmd_man=locale_list[j].local_man;
            for(long unsigned int i=0; i<CMD_NUMBER;i++){
                int cmd_proxi=strncmp(cmd_man[i].nom,commande,strlen(cmd_man[i].nom));
                if(cmd_proxi==0){
                    cmd_to_exec=i;
                    locale=&locale_list[j];
                    break;
                }
            }
        }

        switch(cmd_to_exec){
            case 0:
                time_t date;
                time(&date);

                printf("Date: %s", ctime(&date));
                break;
            case 1:
                if(strlen(commande)==0){
                    printf("Argument manquant, veuillez entrer un argument après votre commande.");
                }
                else{
                    traiter_echo(commande);
                }
                break;
            case 2:
                afficher_aide(locale);
                break;
            case 3:
                traiter_quit(locale,&continuer);
                break;
            case 4:
                afficher_version();
                break;
            default:
                traiter_calcul(commande);
                printf("Commande non reconnue. Essayez 'help' pour connaître les fonctions disponibles.\n");
        }
        printf("\n"); // Saut de ligne après la sortie
    }

    return 0;
}
