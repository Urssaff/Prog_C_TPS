#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant_struct{
    char nom[20];
    char prenom[20];
    char adresse[50];
    char notes[50];
} Etudiant;

int main(){
    Etudiant* liste=(Etudiant *) malloc(5*sizeof(Etudiant));
    char* nom=malloc(20);
    char* prenom=malloc(20);
    char* adresse=malloc(50);
    char* notes=malloc(50);
    for(int i=0; i<5; i++){
        printf("Veuillez saisir les informations d'un étudiant (au format nom;prénom;adresse;notes)");
        scanf("%19[^;];%19[^;];%49[^;];%49s",nom,prenom,adresse,notes);
        fgetc(stdin);
        /*printf("%s\n",nom);
        printf("%s\n",prenom);
        printf("%s\n",adresse);
        printf("%s\n",notes);*/
        strcpy(liste[i].nom,nom);
        strcpy(liste[i].prenom,prenom);
        strcpy(liste[i].adresse,adresse);
        strcpy(liste[i].notes,notes);
        printf("%s\n",liste[i].nom);
        printf("%s\n",liste[i].prenom);
        printf("%s\n",liste[i].adresse);
        printf("%s\n",liste[i].notes);
    }
    printf("Saisie terminée\n");
    for(int i=0; i<5; i++){
        printf("Etudiant numéro %d : { \n\tNom : %s,\n\tPrénom : %s,\n\tAdresse : %s,\n\tNotes : %s \n}\n",i+1,liste[i].nom,liste[i].prenom,liste[i].adresse,liste[i].notes);
    }
}