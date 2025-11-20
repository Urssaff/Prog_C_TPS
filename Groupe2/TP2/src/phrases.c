#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 200

int enter_n_file(char* f)
{
    char e[LEN];
    FILE* nfile;

    do{
        printf("Veuillez entrer le nom de votre fichier et son extension :");
        fgets(f,LEN,stdin);

        if (f[0]=='\n')
        {
            printf("Voulez-vous fermer l'application? Pour quitter entrez 1.\n");
            fgets(e,LEN,stdin);

            if (e[0]=='1')
            {
                printf("Fermeture de l'application. Veuillez patienter.\n");
                exit(0);
                return EXIT_SUCCESS;
            }
        }

        int l=(int)strlen(f);

        if (f[l-1]=='\n')
        {
            f[l-1]='\0';
        }

        nfile = fopen(f, "r");

        if (nfile==NULL)
        {
            perror("");
        }
    }
    while (nfile==NULL);
    fclose(nfile);

    return 0;
}

int src_str_inline(char* line, char* to_find, int* nb_occ){
    printf("%s\n",line);
    char* pos=strstr(line,to_find);
    //printf("%s\n",pos);
    if(pos!=NULL){
        //printf("banane");
        *nb_occ=*nb_occ+1;
        printf("%d\n",*nb_occ);
        src_str_inline(pos+(strlen(to_find)),to_find,nb_occ);
    }

    return 0;
}

int main(){
    char* filename=malloc(LEN);
    if(!enter_n_file(filename)){
        FILE* file;
        file=fopen(filename,"r");
        char* line=malloc(LEN);
        char* to_find=malloc(LEN/2);
        printf("Veuillez entrer une chaîne à rechercher : ");
        scanf("%[^\n]",to_find);
        int nb_occ=0;
        do{
            fgets(line,LEN,file);
            if(!ferror(file)){
                src_str_inline(line,to_find,&nb_occ);
            }
            //printf("%d\n",nb_occ);
            //fgetc(file);
        }//essayer de récupérer la sortie de fgets  et de l'utiliser pour la boucle ça règlerait peut être le problème de dernière ligne vide 
        while(!feof(file));
        fclose(file);
        printf("%d",nb_occ);
        free(line);
        free(to_find);
    }
    free(filename);
}