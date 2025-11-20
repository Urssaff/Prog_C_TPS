int cmp_str(char* stra, char* strb){
    int i=0;
    int diff=0;
    while(stra[i]!='\0' && strb[i]!='\0' && diff==0){
        if(stra[i]!=strb[i]){
            diff=1;
            break;
        }
        else{
            i++;
        }
    }
    if((stra[i]=='\0' && strb[i]!='\0') || (stra[i]!='\0' && strb[i]=='\0')){
        diff=1;
    }
    return diff;
}

int syscall(int number, ...);

int main(){
    char* tab[]={
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial.",
    };
    char* phrase="Il fait beau dehors";
    char* retour;
    int trouve=0;

    for(int i=0; i<10; i++){
        if(cmp_str(tab[i],phrase)==0){
            trouve=1;
            break;
        }
    }

    if(trouve==1){
        retour="Phrase trouvée\n";
        syscall(1,1,retour,17);
    }
    else{
        retour="hrase non trouvée\n";
        syscall(1,1,retour,20);
    }
}