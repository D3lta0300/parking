#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Voiture{
    char immatriculation[20];
    char marque[30];
    int etage;
    int place;
};

typedef struct Voiture Voiture;

void condenseVoiture(Voiture voiture){
    printf("%s : %s", voiture.marque, voiture.immatriculation);
}

void afficheVoiture(Voiture voiture){
    printf("La %s immatriculée %s est garée place %d, étage %d", voiture.marque, voiture.immatriculation, voiture.place, voiture.etage);
}

void initialiseParking(int nbEtage, int nbPlacesEtages, int nbVoiture, Voiture pParking[][nbPlacesEtages]){
    int k = 0;
    for (int i = 0;i<nbEtage;i++){
        for (int j = 0; j<nbPlacesEtages; j++){
            if (k<nbVoiture){
                Voiture initialisatrice;
                strcpy(initialisatrice.immatriculation,"00-000-00");
                strcpy(initialisatrice.marque, "Tesla");
                initialisatrice.etage=i;
                initialisatrice.place=j;
                pParking[i][j] = initialisatrice;
                printf("added\n");
            } else {
                Voiture initialisatrice;
                strcpy(initialisatrice.immatriculation," ");
                strcpy(initialisatrice.marque, " ");
                initialisatrice.etage=i;
                initialisatrice.place=j;
                pParking[i][j] = initialisatrice;
                printf("added\n");
            }
            k++;
        }
    }
}

void afficheParking(int nbEtage, int nbPlacesEtages, Voiture parking[][nbPlacesEtages]){
    printf("\nAffichage en cours\n");
    for (int i = 0;i<nbEtage;i++){
        for (int j = 0; j<nbPlacesEtages; j++){
            condenseVoiture(parking[i][j]);
            printf(" | ");
        }
        printf("\n");
    }
}

void ajouteVoiture(int nbEtage, int nbPlacesEtages, Voiture parking[][nbPlacesEtages]){

    printf("\n\nÀ quelle étage souhaitez vous vous garer ?");
    int etage;
    scanf("%d",&etage);

    printf("\nÀ quelle place souhaitez vous vous garer ?");
    int place;
    scanf("%d",&place);

    printf("Vous allez vous garer à la place %d, etage %d",place,etage);

    printf("\nQuel est la marque de votre voiture ?");
    char marque[50];
    scanf("%s",marque);

    printf("\nQuelle est votre plaque d'immatriculation ?");
    char immatriculation[50];
    scanf("%s",immatriculation);

    Voiture nouvelle;
    strcpy(nouvelle.immatriculation,immatriculation);
    strcpy(nouvelle.marque, marque);
    nouvelle.etage=etage;
    nouvelle.place=place;

    afficheVoiture(nouvelle);

    parking[etage][place] = nouvelle;

    afficheParking(nbEtage,nbPlacesEtages,parking);
}


int main(){
    printf("Bienvenue dans mon super programme de PARKING !!!\n");
    int nbVoiture = 4;
    int nbEtage = 2;
    int nbPlacesEtages = 3;
    Voiture parking[nbEtage][nbPlacesEtages];
    while (1==1) {
        printf("\nMon super parking à %d places !!! Malheureusement pour vous, %d sont déjà occupées.", nbEtage*nbPlacesEtages, nbVoiture);
        printf("\nQue souhaitez vous faire ? 'Entrer', 'Sortir', 'Initialiser' ou 'Afficher' ? \n");

        char reponse[40];
        scanf("%s", reponse);

        const char* entrer = "Entrer";
        const char* sortir = "Sortir";
        const char* initialiser = "Initialiser";
        const char* afficher = "Afficher";


        if (strncmp(entrer,reponse,3)==0){
            ajouteVoiture(nbEtage,nbPlacesEtages,parking);
            printf("\nOh nan, une voiture s'ajoute dans le parking...\n\n");
            nbVoiture++;
        } else if (strncmp(sortir,reponse,3)==0){
            printf("Ouiii, je m'alège!!!\n\n");
            nbVoiture--;
        } else if (strncmp(initialiser,reponse,3)==0){
            printf("Initialisation du parking ...");
            initialiseParking(nbEtage,nbPlacesEtages, nbVoiture, parking);
            printf(" terminée ! \n\n");
            afficheVoiture(parking[0][1]);
        } else if (strncmp(afficher,reponse,3)==0){
            afficheParking(nbEtage, nbPlacesEtages, parking);
        } else {
            printf("C'est au CP qu'on apprend à écrire, recommence.\n\n");
        }

    }
    return 0;
}// String compare pour verifier si la place qu'on demande est deja prise ou non