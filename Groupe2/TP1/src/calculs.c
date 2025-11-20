#include <stdio.h>
#define LEN 200

int main(){
    int num1,num2,result=0;
    char c;

    printf("Entrez les deux opérandes de l'opération :\n");
    scanf("%d %d",&num1, &num2);

    printf("Entrez l'opérateur de l'opération :\n");
    scanf(" %c",&c);

    switch(c){
        case '+':
            result=num1+num2;
            break;
        case '-':
            result=num1-num2;
            break;
        case '*':
            result=num1*num2;
            break;
        case '/':
            if(num2==0){
                printf("Division par zéro");
            }
            else{
                result=num1/num2;
            }
            break;
        case '%':
            if(num2==0){
                printf("Division par zéro");
            }
            else{
                result=num1%num2;
            }
            break;
        case '&':
            result=num1&num2;
            break;
        case '|':
            result=num1|num2;
            break;
        case '~':
            result=~num1;
            break;
        default:
            printf("Opérateur invalide\n");
    }
    printf("Résultat : %d",result);
}
