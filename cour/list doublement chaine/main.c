#include <stdio.h>
#include <stdlib.h>

typedef struct box {
    int data;
    struct box *next;
    struct box *prev;
} box;

box *ajouteAuDebut(box *L, int x) {
    box *b = (box *)malloc(sizeof(box));
    b->data = x;
    b->next = b->prev = NULL;
    b->next = L;
    if (L != NULL)
        L->prev = b;
    L = b;
    return L;
}

box *ajouteAuFin(box *L, int x) {
    box *b = (box *)malloc(sizeof(box));
    b->data = x;
    b->next = NULL;

    if (L == NULL) {
        b->prev = NULL;
        L = b;
    } else {
        box *temp = L;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = b;
        b->prev = temp;
    }
    return L;
}

box *ajouteAuMilieu(box *L, int x) {
    box *b = (box *)malloc(sizeof(box));
    b->data = x;
    b->next = b->prev = NULL;

    if (L == NULL || x < L->data) {
        L = ajouteAuDebut(L, x);
    } else {
        box *temp = L;
        while (temp->next != NULL && temp->next->data < x) {
            temp = temp->next;
        }
        b->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = b;
        }
        temp->next = b;
        b->prev = temp;
    }
    return L;
}

void affichage(box *L) {
    box *temp = L;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

box *supprimeDebut(box *L) {
    if (L == NULL) return NULL;
    box *temp = L;
    L = L->next;
    if (L != NULL) {
        L->prev = NULL;
    }
    free(temp);
    return L;
}

box *supprimeMilieu(box *L, int x) {
    if (L == NULL) return NULL;
    box *temp = L;
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }
    if (temp == NULL) return L; // Element not found
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        L = temp->next; // Element to be deleted is the first element
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return L;
}

box *supprimeFin(box *L) {
    if (L == NULL) return NULL;
    box *temp = L;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        L = NULL; // List becomes empty
    }
    free(temp);
    return L;
}

int main() {
    box *L = NULL;

    // Insertion normale
    L = ajouteAuDebut(L, 5);
    L = ajouteAuDebut(L, 3);
    L = ajouteAuDebut(L, 2);
    L = ajouteAuFin(L, 7);

    // Insertion au milieu
    L = ajouteAuMilieu(L, 6);
    L = ajouteAuMilieu(L, 8);
    L = ajouteAuMilieu(L, 4);

    printf("Liste après insertion:\n");
    affichage(L);

    // Suppression au début
    L = supprimeDebut(L);
    printf("\nListe après suppression du début:\n");
    affichage(L);

    // Suppression au milieu
    L = supprimeMilieu(L, 6);
    printf("\nListe après suppression du milieu (6):\n");
    affichage(L);

    // Suppression à la fin
    L = supprimeFin(L);
    printf("\nListe après suppression de la fin:\n");
    affichage(L);

    return 0;
}

