#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Voiture{
    char immatriculation[20];
    char marque[30];
};

typedef struct Voiture Voiture;

void afficheVoiture(Voiture voiture){
    printf("%s : %s", voiture.marque, voiture.immatriculation);
}

void initialiseParking(Voiture *pParking, int nbEtage, int nbPlacesEtages, int nbVoiture){
    int k = 0;
    for (int i = 0;i<nbEtage;i++){
        for (int j = 0; j<nbPlacesEtages; j++){
            if (k<nbVoiture){
                struct Voiture initialisatrice;
                strcpy(initialisatrice.immatriculation,"00-000-00");
                strcpy(initialisatrice.marque, "Tesla");
                pParking[i,j] = initialisatrice;
            }
            k++;
        }
    }
}

void afficheParking(Voiture parking[], int nbEtage, int nbPlacesEtages){
    for (int i = 0;i<nbEtage;i++){
        for (int j = 0; j<nbPlacesEtages; j++){
            afficheVoiture(parking[i,j]);
            printf(" | ");
        }
        printf("\n");
    }
}


int main(){
    printf("Bienvenue dans mon super programme de PARKING !!!\n");
    int nbVoiture = 16;
    int nbEtage = 3;
    int nbPlacesEtages = 43;
    Voiture parking[nbEtage][nbPlacesEtages];
    while (1==1) {
        printf("Mon super parking à %d places !!! Malheureusement pour vous, %d sont déjà occupées.", nbEtage*nbPlacesEtages, nbVoiture);
        printf("Que souhaitez vous faire ? 'Entrer' ou 'Sortir' ? \n");

        char reponse[40];
        scanf("%s", reponse);

        const char* entrer = "Entrer";
        const char* sortir = "Sortir";
        const char* initialiser = "Initialiser";
        const char* afficher = "Afficher";

        if (strncmp(entrer,reponse,6)==0){
            printf("Oh nan, une voiture s'ajoute dans le parking...\n\n");
            nbVoiture++;
        } else if (strncmp(sortir,reponse,6)==0){
            printf("Ouiii, je m'alège!!!\n\n");
            nbVoiture--;
        } else if (strncmp(initialiser,reponse,6)==0){
            printf("Initialisation du parking ...");
            initialiseParking(parking, nbEtage,nbPlacesEtages, nbVoiture);
            printf(" terminée ! \n\n");
        } else if (strncmp(afficher,reponse,6)==0){
            afficheParking(parking, nbEtage, nbPlacesEtages);
        } else {
            printf("C'est au CP qu'on apprend à écrire, recommence.\n\n");
        }

    }
    return 0;

}