#include <stdio.h>

int main(){
    char var_char='a';
    signed char var_signed_char=-1;
    unsigned char var_unsigned_char='g';
    short var_short=-500;
    unsigned short var_unsigned_short=32767;
    int var_int=-4000;
    unsigned int var_unsigned_int=4294967295;
    long int var_long_int=-50000;
    unsigned long int var_unsigned_long_int=18446744073709551615;
    long long int var_long_long_int=-999999999999;
    float var_float=-9565.63529;
    double var_double=-525894528.56;
    long double var_long_double=-5126542566595995.65;

    printf("%c\n",var_char);
    printf("%c\n",var_signed_char);
    printf("%c\n",var_unsigned_char);
    printf("%d\n",var_short);
    printf("%u\n",var_unsigned_short);
    printf("%d\n",var_int);
    printf("%u\n",var_unsigned_int);
    printf("%ld\n",var_long_int);
    printf("%lu\n",var_unsigned_long_int);
    printf("%lld\n",var_long_long_int);
    printf("%f\n",var_float);
    printf("%lf\n",var_double);
    printf("%Lf\n",var_long_double);
}