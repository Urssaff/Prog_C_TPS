#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int charsize=sizeof(char);
    char* chaine1=malloc(charsize*50);
    char* chaine2=malloc(charsize*50);
    printf("Saisissez une première chaîne de caractères : ");
    scanf("%s",chaine1);
    printf("Saisissez une seconde chaîne de caractères : ");
    scanf("%s",chaine2);
    printf("Chaîne 1 : %s\nChaîne 2 : %s\n",chaine1,chaine2);
    printf("Longueurs : \n- Chaîne 1 : %ld\n- Chaîne 2 : %ld\n",strlen(chaine1),strlen(chaine2));
    char* concat=malloc(charsize*100);
    strcat(concat,chaine1);
    strcat(concat,chaine2);
    strcpy(chaine2,chaine1);
    printf("Copie de chaine 1 dans chaine 2 : \n");
    printf("Chaîne 1 : %s\nChaîne 2 : %s\n",chaine1,chaine2);
    printf("Chaînes concaténées : %s\n",concat);
    return 0;
}