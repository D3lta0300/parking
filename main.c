#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct Voiture {
    char immatriculation[20];
    char marque[30];
    int etage;
    int place;
    time_t entree;  // Ajout de la variable pour enregistrer le temps dans le parking
};

typedef struct Voiture Voiture;


//Permet d'afficher une voiture de façon condensé.
void condenseVoiture(Voiture voiture){
    int length;
    length = strlen(voiture.marque);
    length += strlen(voiture.immatriculation);
    printf("%s : %s", voiture.marque, voiture.immatriculation);
    for (int i = 0; i<17-length; i++){
        printf(" ");
    }
}


//Affiche les détails d'une voiture.
void afficheVoiture(Voiture voiture) {
    printf("La %s immatriculée %s est garée place %d, étage %d", voiture.marque, voiture.immatriculation, voiture.place, voiture.etage);
}


//Initialise le parking avec un certain nombre de voiture.
void initialiseParking(int nbEtage, int nbPlacesEtages, int nbVoiture, Voiture *pParking){
    Voiture initialisatrice;
    int k = 0;
    for (int i = 0;i<nbEtage;i++){
        for (int j = 0; j<nbPlacesEtages; j++){
            initialisatrice.etage=i;
            initialisatrice.place=j;


            time_t maintenant;
            time(&maintenant);
            initialisatrice.entree = maintenant;

            if (k<nbVoiture){
                strcpy(initialisatrice.immatriculation,"00-000-00");
                strcpy(initialisatrice.marque, "Tesla");
            } else {
                strcpy(initialisatrice.immatriculation," ");
                strcpy(initialisatrice.marque, " ");
            }
            *(pParking+i*nbPlacesEtages+j) = initialisatrice;
            k++;
        }
    }
}


//Affiche le parking d'une façon lisible pour l'utilisateur.
void afficheParking(int nbEtage, int nbPlacesEtages, Voiture *pParking){
    printf("\n\nÉtage =");

    for (int j = nbPlacesEtages; j>=1; j--){
        printf("=======================");
    }

    for (int i = nbEtage-1;i>=0;i--){
        printf("\n  %d   | ",i);
        for (int j = 0; j<nbPlacesEtages; j++){
            condenseVoiture(*(pParking+i*nbPlacesEtages+j));
            printf(" | ");
        }
        printf("\n      =");
        for (int j = nbPlacesEtages; j>=1; j--){
            printf("=======================");
        }
    }
    
    printf("\n       ");
    for (int j = 0; j<nbPlacesEtages; j++){
        printf("           %d           ",j);
    }
    printf("\n");
}



//Supprime une voiture du parking.
void sortDuParking(int nbEtage, int nbPlacesEtages, Voiture *pParking){
    printf("\n\nÀ quel étage êtes vous garé ? ");
    int etage;
    scanf("%d", &etage);

    printf("\nÀ quelle place êtes-vous garé ? ");
    int place;
    scanf("%d", &place);

    if(strncmp((*(pParking+etage*nbPlacesEtages+place)).immatriculation, " ",1)==0){
        printf("\nIl n'y a pas de voiture ici. Êtes vous un fantôme ?");
    } else {
        time_t maintenant;
        time(&maintenant);

        double duree = (double) difftime(maintenant, (*(pParking+etage*nbPlacesEtages+place)).entree);
        double paye = duree * (1./60.);
        printf("La voiture est restée dans le parking pendant %.2f secondes et doit payer %2f €.\n", duree, paye);

        Voiture initialisatrice;
        strcpy(initialisatrice.immatriculation, " ");
        strcpy(initialisatrice.marque, " ");
        initialisatrice.etage = etage;
        initialisatrice.place = place;
        initialisatrice.entree = 0;
        
        *(pParking+etage*nbPlacesEtages+place) = initialisatrice;
        printf("Place libérée.");
    }
}



//Place la voiture à la meilleure place.
void gareVoitureAuMeilleurEndroit(int nbEtage, int nbPlacesEtages, Voiture *pParking, Voiture voiture){
    char reponse[4];
    for (int i = 0;i<nbEtage;i++){
        printf("\nBienvenue à l'étage n°%d",i);
        for (int j = 0; j<nbPlacesEtages; j++){
            if(!strncmp((*(pParking+i*nbPlacesEtages+j)).immatriculation, " ",1)){
                printf("\nSouhaitez vous vous garer à la place numéro %d ? (Oui/Non) ",j);
                scanf("%s",reponse);
                if(!strncmp(reponse, "Oui",1)){
                    *(pParking+i*nbPlacesEtages+j) = voiture;
                    printf("\nVous êtes garé.");
                    j=nbPlacesEtages;
                    i = nbEtage;
                } else if (!strncmp(reponse, "Non",1)){
                    printf("\nD'accord, nous allons vous proposer une nouvelle place.");
                } else {
                    printf("\nApprenez à écrire. Pour la peine, vous irez à une place suivante.");
                }
            }
        }
        printf("\nIl n'y a plus de places à cette étage...");
    }
    printf("\nDésolé, il n'y a plus de places dans le parking...");
}



//Ajoute une voiture créée par l'utilisateur dans le parking.
void ajouteVoiture(int nbEtage, int nbPlacesEtages, Voiture *pParking){

    bool isPlaceOk = false;
    int etage;
    int place;

    printf("\nQuel est la marque de votre voiture ?");
    char marque[50];
    scanf("%s", marque);

    printf("\nQuelle est votre plaque d'immatriculation ? ");
    char immatriculation[50];
    scanf("%s", immatriculation);

    time_t maintenant;
    time(&maintenant);

    Voiture nouvelle;
    strcpy(nouvelle.immatriculation, immatriculation);
    strcpy(nouvelle.marque, marque);
    nouvelle.etage = etage;
    nouvelle.place = place;
    nouvelle.entree = maintenant;  // Enregistrement du temps d'entrée

    gareVoitureAuMeilleurEndroit(nbEtage,nbPlacesEtages,pParking,nouvelle);

    afficheParking(nbEtage,nbPlacesEtages, pParking);
}


//Main. C'est ici que sont organisées toutes les fonctions.
int main() {
    printf("Bienvenue dans mon super programme de PARKING !!!\n");
    int nbVoiture = 9;
    int nbEtage = 3;
    int nbPlacesEtages = 5;
    Voiture parking[nbEtage][nbPlacesEtages];

    initialiseParking(nbEtage, nbPlacesEtages, nbVoiture, parking);

    while (1 == 1) {
        printf("\nMon super parking à %d places !!! Malheureusement pour vous, %d sont déjà occupées.\n", nbEtage * nbPlacesEtages, nbVoiture);

        if (nbVoiture >= nbEtage * nbPlacesEtages) {
            printf("\nLa BARRIÈRE est fermée.");
        } else {
            printf("\nLa BARRIÈRE est ouverte.");
        }
        
        afficheParking(nbEtage,nbPlacesEtages,parking);
        
        printf("\n\nQue souhaitez-vous faire ? 'Entrer' ou 'Sortir' ? \n");

        char reponse[40];
        scanf("%s", reponse);

        const char* entrer = "Entrer";
        const char* sortir = "Sortir";


        if (strncmp(entrer, reponse, 3) == 0) {
            if (nbVoiture >= nbEtage * nbPlacesEtages) {
                printf("\nDésolé, mais mon super parking est plein. La BARRIÈRE est fermée.\n");
            } else {
                ajouteVoiture(nbEtage, nbPlacesEtages, parking);
                printf("\nOh non, une voiture s'ajoute dans le parking...\n");
                nbVoiture++;
            }
        } else if (strncmp(sortir, reponse, 3) == 0) {
            sortDuParking(nbEtage, nbPlacesEtages, parking);
            printf("\n[Parking] Ouiii, je m'alège!!!\n\n");
            nbVoiture--;
        } else {
            printf("\nC'est au CP qu'on apprend à écrire, recommence.\n");
        }
    }
    return 0;
}