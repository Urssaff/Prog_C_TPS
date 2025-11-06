#include <stdio.h>
#include <math.h>

int main(){
    double rayon = 0, aire = 0, perimetre = 0;
    printf("Veuillez saisir un rayon: ");
    scanf("%lf", &rayon);
    if(rayon){
        aire=rayon * rayon * M_PI;
        perimetre= 2 * M_PI * rayon;
        printf("Aire : %lf \nPérimètre : %lf\n",aire,perimetre);
    }
}