#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int sommet;
    int taille;
    int *T;
} pile;

int estVide(pile p)
{
    return (p.sommet == 0);
}
int estPleine(pile p)
{
    return (p.sommet == p.taille);
}
void empiler(pile *p, int v)
{
    p->T[p->sommet++] = v;
}
int depiler(pile *p)
{
    return p->T[--p->sommet];
}
int main()
{
    pile p1, p2;
    int n;
    printf("Donner la taille maximale de la pile p1 : ");
    scanf("%d", &p1.taille);
    p1.T = (int *)malloc(p1.taille * sizeof(int));

    p1.sommet = 0;
    while (!estPleine(p1))
    {
        printf("Donner la valeur que vous voulez ajouter : ");
        scanf("%d", &n);
        empiler(&p1, n);
    }
    while (!estVide(p1))
    {
        printf("%d \n", depiler(&p1));
    }
    free(p1.T);
    return 0;
}
