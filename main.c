#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(){
    printf("Bienvenue dans mon super programme de PARKING !!!\n");
    int nbVoiture = 16;
    int nbEtage = 3;
    int nbPlacesEtages = 43;
    int parking[nbEtage][nbPlacesEtages];
    while (1==1) {
        printf("Mon super parking à %d places !!! Malheureusement pour vous, %d sont déjà occupées.", nbEtage*nbPlacesEtages, nbVoiture);
        printf("Que souhaitez vous faire ? 'Entrer' ou 'Sortir' ? \n");

        char reponse[40];
        scanf("%s", reponse);

        const char* entrer = "Entrer";
        const char* sortir = "Sortir";

        if (strncmp(entrer,reponse,6)==0){
            printf("Oh nan, une voiture s'ajoute dans le parking...\n\n");
            nbVoiture++;
        } else if (strncmp(sortir,reponse,6)==0){
            printf("Ouiii, je m'alège!!!\n\n");
            nbVoiture--;
        } else {
            printf("C'est au CP qu'on apprend à écrire, recommence.\n\n");
        }

    }
    //is it ok ?
    return 0;

}