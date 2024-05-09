#include <stdio.h>
typedef struct pl
{
    int donnee;
    struct pl *prcd;
} Pile;
int somme_pile(Pile *P) {
    int s = 0;
    Pile *suppr = P;
    while (P != NULL) {
        s += P->donnee;
        P = P->prcd;
    }
    P = suppr;
    return s;
}
