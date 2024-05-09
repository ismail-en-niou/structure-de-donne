#include <stdio.h>

void mat_adjacent(int M[7][7], int n);
void affiche_graphe(int M[7][7], int n);
int degre(int sommet, int M[7][7], int n);

int main(int argc, char const *argv[]) {
    int M[7][7];
    int n = 6;

    mat_adjacent(M, n);
    affiche_graphe(M, n);
    int vertex = 1;
    int degree_of_vertex = degre(vertex, M, n);
    printf("Degree of vertex %d: %d\n", vertex, degree_of_vertex);

    return 0;
}

void mat_adjacent(int M[7][7], int n) {
    int i, j;
    printf("*********** Donner la matrice avec 1 et 2 seulement **************\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Donner la valeur de M[%d][%d] = ", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

void affiche_graphe(int M[7][7], int n) {
    int i, j;
    printf("*********** Matrice **************\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(" %d", M[i][j]);
        }
        printf("\n");
    }
}

int degre(int sommet, int M[7][7], int n) {
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (M[sommet][i] == 1) {
            d++;
        }
        if (M[i][sommet] == 1) {
            d++;
        }
    }
    return d;
}
