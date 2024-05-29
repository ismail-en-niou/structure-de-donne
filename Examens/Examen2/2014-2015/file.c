#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    int numero ;
    int note ;
}Data;
typedef struct 
{
    int tete;
    int Queue;
    int taille ;
    int capacite ;
    Data *T ;
}File;

File *creer_file() {
    int capacite = 4;
    File *F = (File *)malloc(sizeof(File));
    if (F == NULL) {
        printf("Erreur d'allocation de mémoire pour la file\n");
        exit(EXIT_FAILURE);
    }
    F->capacite = capacite;
    F->tete = 0;
    F->queue = -1;
    F->taille = 0;
    F->T = (Data *)malloc(capacite * sizeof(Data));
    if (F->T == NULL) {
        printf("Erreur d'allocation de mémoire pour le tableau\n");
        free(F);
        exit(EXIT_FAILURE);
    }
    
    // Initialiser les 4 éléments
    for (int i = 0; i < 4; i++) {
        F->T[i].numero = 0;  // ou toute autre valeur par défaut
        F->T[i].note = 0;    // ou toute autre valeur par défaut
    }
    return F;
}
File *enfiler(File *F , int note ,int nemro){
    F->T[F->Queue].note = note;
    F->T[F->Queue++].numero = nemro;
    
}