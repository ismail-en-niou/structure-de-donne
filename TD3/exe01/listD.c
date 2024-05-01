#include <stdio.h>
#include <stdlib.h>

typedef struct box
{
    int data;
    struct box *next;
    struct box *prev;
} box;

box *ajouteAuDebut(box *L, int x)
{
    box *b = (box *)malloc(sizeof(box));
    b->data = x;
    b->next = b->prev = NULL;
    b->next = L;
    if (L != NULL)
        L->prev = b;
    L = b;
    return L;
}

box *ajouteAuFin(box *L, int x)
{
    box *b = (box *)malloc(sizeof(box));
    b->data = x;
    b->next = NULL;

    if (L == NULL)
    {
        b->prev = NULL;
        L = b;
    }
    else
    {
        box *temp = L;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = b;
        b->prev = temp;
    }
    return L;
}

box *ajouteAuMilieu(box *L, int x)
{
    box *b = (box *)malloc(sizeof(box));
    b->data = x;
    b->next = b->prev = NULL;

    if (L == NULL || x < L->data)
    {
        L = ajouteAuDebut(L, x);
    }
    else
    {
        box *temp = L;
        while (temp->next != NULL && temp->next->data < x)
        {
            temp = temp->next;
        }
        b->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = b;
        }
        temp->next = b;
        b->prev = temp;
    }
    return L;
}
// show the liste -_- *********
void affichage(box *L)
{
    box *temp = L;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    box *L = NULL;
    // normalle innserte

    L = ajouteAuDebut(L, 5);
    L = ajouteAuDebut(L, 3);
    L = ajouteAuDebut(L, 2);
    L = ajouteAuFin(L, 7);

    // he insert the element with check here position **********
    L = ajouteAuMilieu(L, 6); 
    L = ajouteAuMilieu(L, 8);
    L = ajouteAuMilieu(L, 4);
    affichage(L);
    return 0;
}
