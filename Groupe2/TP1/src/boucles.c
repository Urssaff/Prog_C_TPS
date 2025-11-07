#include <stdio.h>

int main(){
    short taille=0;
    printf("Entrez une taille < 10.\nTaille : ");
    scanf("%hd",&taille);
    if(taille<10){
        for(int i=0; i<taille; i++){
            for(int j=0; j<=i;j++){
                if(j==0 || j==i || i==(taille-1)){
                    printf("* ");
                }
                else{
                    printf("# ");
                }
            }
            printf("\n");
        }

        int i=0,j=0;
        while(i<taille){
            j=0;
            while(j<=i){
                if(j==0 || j==i || i==(taille-1)){
                    printf("* ");
                }
                else{
                    printf("# ");
                }
                j++;
            }
            printf("\n");
            i++;
        }
    }   
}