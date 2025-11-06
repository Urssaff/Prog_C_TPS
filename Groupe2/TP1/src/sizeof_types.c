#include <stdio.h>

int main(){
    printf("Taille des types : \n");
    printf("- Char : %ld\n", sizeof(char));
    printf("- Signed char : %ld\n", sizeof(signed char));
    printf("- Unigned char : %ld\n", sizeof(unsigned char));
    printf("- Short : %ld\n", sizeof(short));
    printf("- Unsigned short : %ld\n", sizeof(unsigned short));
    printf("- Int : %ld\n", sizeof(int));
    printf("- Unsigned int : %ld\n", sizeof(unsigned int));
    printf("- Long int : %ld\n", sizeof(long int));
    printf("- Unsigned long int : %ld\n", sizeof(unsigned long int));
    printf("- Long long int : %ld\n", sizeof(long long int));
    printf("- Float : %ld\n", sizeof(float));
    printf("- Double : %ld\n", sizeof(double));
    printf("- Long double : %ld\n", sizeof(long double));
}