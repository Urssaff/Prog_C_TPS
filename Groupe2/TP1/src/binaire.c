#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    short var_int;
    char* result=malloc(16);
    printf("Entrez un entier : ");
    scanf("%hd",&var_int);

    while(var_int!=0){
        int reste=var_int%2;
        char* reste_str[1];
        sprintf(*reste_str,"%d",reste);
        strcat(*reste_str, result);
        strcpy(result,*reste_str);
        var_int=var_int/2;
    }
    printf("%s",result);
}