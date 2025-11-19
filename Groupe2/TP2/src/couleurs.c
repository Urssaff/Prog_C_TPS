#include <stdlib.h>
#include <stdio.h>
typedef struct couleur{
    int r;
    int g;
    int b;
    int a;
} Couleur;

// Tableau de 100 couleurs au format [R, G, B, A]
Couleur couleurs[100] = {
    {255, 0, 0, 255},       // Rouge vif
    {0, 255, 0, 255},       // Vert vif
    {0, 0, 255, 255},       // Bleu vif
    {255, 255, 0, 255},     // Jaune
    {255, 0, 255, 255},     // Magenta
    {0, 255, 255, 255},     // Cyan
    {255, 128, 0, 255},     // Orange
    {128, 0, 255, 255},     // Violet
    {255, 192, 203, 255},   // Rose
    {165, 42, 42, 255},     // Brun
    {128, 128, 128, 255},   // Gris
    {0, 0, 0, 255},         // Noir
    {255, 255, 255, 255},   // Blanc
    {75, 0, 130, 255},      // Indigo
    {238, 130, 238, 255},   // Violet clair
    {0, 128, 128, 255},     // Sarcelle
    {128, 128, 0, 255},     // Olive
    {128, 0, 0, 255},       // Marron foncé
    {0, 128, 0, 255},       // Vert foncé
    {0, 0, 128, 255},       // Bleu marine
    {255, 215, 0, 255},     // Or
    {192, 192, 192, 255},   // Argent
    {255, 99, 71, 255},     // Tomate
    {255, 127, 80, 255},    // Corail
    {255, 160, 122, 255},   // Saumon clair
    {220, 20, 60, 255},     // Cramoisi
    {219, 112, 147, 255},   // Rose pâle
    {255, 105, 180, 255},   // Rose vif
    {199, 21, 133, 255},    // Magenta moyen
    {186, 85, 211, 255},    // Orchidée moyen
    {147, 112, 219, 255},   // Violet moyen
    {138, 43, 226, 255},    // Violet bleu
    {148, 0, 211, 255},     // Violet foncé
    {153, 50, 204, 255},    // Orchidée foncé
    {139, 0, 139, 255},     // Magenta foncé
    {72, 61, 139, 255},     // Bleu ardoise foncé
    {106, 90, 205, 255},    // Bleu ardoise
    {123, 104, 238, 255},   // Bleu ardoise moyen
    {65, 105, 225, 255},    // Bleu royal
    {0, 191, 255, 255},     // Bleu ciel profond
    {135, 206, 235, 255},   // Bleu ciel
    {135, 206, 250, 255},   // Bleu ciel clair
    {70, 130, 180, 255},    // Bleu acier
    {176, 196, 222, 255},   // Bleu acier clair
    {173, 216, 230, 255},   // Bleu clair
    {176, 224, 230, 255},   // Turquoise poudre
    {175, 238, 238, 255},   // Turquoise pâle
    {0, 206, 209, 255},     // Turquoise foncé
    {64, 224, 208, 255},    // Turquoise
    {72, 209, 204, 255},    // Turquoise moyen
    {32, 178, 170, 255},    // Vert mer clair
    {95, 158, 160, 255},    // Cadet bleu
    {0, 139, 139, 255},     // Cyan foncé
    {127, 255, 212, 255},   // Vert aqua
    {102, 205, 170, 255},   // Vert aqua moyen
    {60, 179, 113, 255},    // Vert mer moyen
    {46, 139, 87, 255},     // Vert mer
    {34, 139, 34, 255},     // Vert forêt
    {0, 100, 0, 255},       // Vert foncé
    {144, 238, 144, 255},   // Vert clair
    {152, 251, 152, 255},   // Vert pâle
    {143, 188, 143, 255},   // Vert mer foncé
    {50, 205, 50, 255},     // Vert citron
    {124, 252, 0, 255},     // Vert pelouse
    {127, 255, 0, 255},     // Chartreuse
    {173, 255, 47, 255},    // Vert jaune
    {154, 205, 50, 255},    // Jaune vert
    {85, 107, 47, 255},     // Olive terne foncé
    {107, 142, 35, 255},    // Olive terne
    {189, 183, 107, 255},   // Kaki foncé
    {240, 230, 140, 255},   // Kaki
    {238, 232, 170, 255},   // Kaki pâle
    {250, 250, 210, 255},   // Jaune clair
    {255, 255, 224, 255},   // Jaune clair
    {255, 250, 205, 255},   // Citron chiffon
    {255, 239, 213, 255},   // Papaye fouet
    {255, 228, 181, 255},   // Mocassin
    {255, 218, 185, 255},   // Pêche puff
    {244, 164, 96, 255},    // Brun sablonneux
    {210, 180, 140, 255},   // Brun tan
    {222, 184, 135, 255},   // Bois burlywood
    {218, 165, 32, 255},    // Verge d'or
    {184, 134, 11, 255},    // Verge d'or foncé
    {188, 143, 143, 255},   // Brun rosé
    {205, 92, 92, 255},     // Rouge indien
    {139, 69, 19, 255},     // Brun selle
    {160, 82, 45, 255},     // Sienna
    {205, 133, 63, 255},    // Pérou
    {210, 105, 30, 255},    // Chocolat
    {139, 90, 43, 255},     // Brun tan foncé
    {233, 150, 122, 255},   // Saumon foncé
    {250, 128, 114, 255},   // Saumon
    {255, 140, 0, 255},     // Orange foncé
    {255, 165, 0, 255},     // Orange
    {255, 69, 0, 255},      // Orange rouge
    {178, 34, 34, 255},     // Rouge brique
    {220, 220, 220, 255},   // Gris clair
    {169, 169, 169, 255},   // Gris foncé
    {105, 105, 105, 255},   // Gris dim
    {112, 128, 144, 255},   // Gris ardoise
};

int main(){
    int int_size=sizeof(int);
    int ptr_size=sizeof(int*);
    int** col_found = NULL;
    int nb_found = 0;
    
    for(int i = 0; i < 100; i++){
        Couleur cur_col = couleurs[i];
        
        if(col_found == NULL){
            col_found = malloc(ptr_size);
            col_found[0] = malloc(2 * int_size);
            col_found[0][0] = i;
            col_found[0][1] = 1;
            nb_found = 1;
        }
        else{
            int dub_found = 0;
            
            for(int j = 0; j < nb_found; j++){
                Couleur col_to_cmp = couleurs[col_found[j][0]];
                if(cur_col.r == col_to_cmp.r && cur_col.g == col_to_cmp.g && cur_col.b == col_to_cmp.b && cur_col.a == col_to_cmp.a){
                    col_found[j][1]++;
                    dub_found = 1;
                    break;
                }
            }
            
            if(!dub_found){
                col_found = realloc(col_found, (nb_found + 1) * ptr_size);
                col_found[nb_found] = malloc(2 * int_size);
                col_found[nb_found][0] = i;
                col_found[nb_found][1] = 1;
                nb_found++;
            }   
        }
    }
    
    for(int i = 0; i < nb_found; i++){
        Couleur cur_col=couleurs[col_found[i][0]];
        printf("Couleur {R:%d, G:%d, B:%d, A:%d} apparaît %d fois\n", cur_col.r, cur_col.g, cur_col.b, cur_col.a, col_found[i][1]);
    }
    
    for(int i = 0; i < nb_found; i++){
        free(col_found[i]);
    }
    free(col_found);
    
    return 0;
}