#include <stdio.h>

int main(){
    int a=16, b=3;
    printf("Addition :\n");
    int result=a+b;
    printf("16 + 3 = 19 %b\n", result == 19);
    printf("Soustraction :\n");
    result=a-b;
    printf("16 - 3 = 13 %b\n", result == 13);
    printf("Multiplication :\n");
    result=a*b;
    printf("16 * 3 = 48 %b\n", result == 48);
    printf("Division :\n");
    result=a/b;
    printf("16 / 3 = 5 %b\n", result == 5);
    printf("Modulo :\n");
    result=a%b;
    printf("16 %% 3 = 19 %b\n", result == 1);
}