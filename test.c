#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void afficheMatrice(int lignes, int colonnes, int matrice[][colonnes]){
    for (int i = 0; i<lignes; i++){
        for(int j = 0; j<colonnes; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int lignes = 3;
    int colonnes = 4;
    int tableau[lignes][colonnes];
    for (int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            tableau[i][j]= i+j;
        }
    }

    afficheMatrice(lignes,colonnes,tableau);

    return 0;
}