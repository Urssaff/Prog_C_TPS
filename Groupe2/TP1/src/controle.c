#include <stdio.h>

int main(){
    int i=1;
    while(i<1001){
        printf("%d : { ",i);
        if(i%4==0 && i%6!=0){
            printf("Divisible par 4 mais pas par 6, ");
        }
        if(i%8==0){
            printf("Nombre pair et divisible par 8, ");
        }
        if((i%5==0 || i%7==0) && i%10!=0){
            printf("Divisible par 5 ou 7 mais pas par 10, ");
        }
        printf("}\n");
        i++;
    }
}