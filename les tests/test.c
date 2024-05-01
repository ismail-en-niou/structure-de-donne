#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------
struct lst
{
    int valeur;
    struct lst *suiv;
}; // Définition de la structure
typedef struct lst Liste;
//------------------------------------------------------
Liste *CreerListe()
{
    Liste *L = NULL;
    printf("\nListe vide creee................");
    printf("\nNULL\n");
    return L;
}
//------------------------------------------------------
// Calcul du nombre d'éléments d'une liste
int nbElements(Liste *L)
{
    int nb = 0;
    while (L != NULL)
    {
        nb++;
        L = L->suiv;
    }
    return nb;
}
//------------------------------------------------------
// Ajout au début d'une liste
Liste *AjoutDebut(Liste *L, int x)
{
    Liste *tmp = (Liste *)malloc(sizeof(Liste));
    tmp->valeur = x;
    tmp->suiv = L;
    return tmp;
}
//------------------------------------------------------
// Ajout à la fin d'une liste
Liste *AjoutFin(Liste *L, int x)
{
    Liste *tmp = (Liste *)malloc(sizeof(Liste));
    tmp->valeur = x;
    tmp->suiv = NULL;

    if (L == NULL)
        return tmp;

    Liste *c = L;
    while (c->suiv != NULL)
    {
        c = c->suiv;
    }
    c->suiv = tmp;
    return L;
}
//------------------------------------------------------

// Ajout au milieu d'une liste (à une position donnée : pos)
Liste *AjoutMilieu(Liste *L, int x, int pos)
{
    if (pos < 1 || pos > nbElements(L) + 1)
    {
        printf("\n Position incorrecte \n");
        return L;
    }

    if (pos == 1)
        return AjoutDebut(L, x);

    if (pos == nbElements(L) + 1)
        return AjoutFin(L, x);

    Liste *tmp = (Liste *)malloc(sizeof(Liste));
    tmp->valeur = x;

    Liste *c = L;
    for (int i = 1; i < pos - 1; i++)
    {
        c = c->suiv;
    }
    tmp->suiv = c->suiv;
    c->suiv = tmp;
    return L;
}
//------------------------------------------------------
// Affichage des éléments d'une liste
void Affichage(Liste *L)
{
    while (L != NULL)
    {
        printf("%d--->", L->valeur);
        L = L->suiv;
    }
    printf("NULL\n");
}
//------------------------------------------------------
Liste *SupprimerDebut(Liste *L)
{
    if (L == NULL)
        return NULL;

    Liste *tmp = L;
    L = L->suiv;
    free(tmp);
    return L;
}
//------------------------------------------------------
Liste *SupprimerFin(Liste *L)
{
    if (L == NULL)
        return NULL;

    if (L->suiv == NULL)
    {
        free(L);
        return NULL;
    }

    Liste *avDer = L;
    Liste *Der = avDer->suiv;
    while (Der->suiv != NULL)
    {
        Der = Der->suiv;
        avDer = avDer->suiv;
    }
    avDer->suiv = NULL;
    free(Der);
    return L;
}
//------------------------------------------------------
Liste *SupprimerMilieu(Liste *L, int position)
{
    if (L == NULL)
        return NULL;

    if (position < 1 || position > nbElements(L))
        return L;

    if (position == 1)
        return SupprimerDebut(L);

    if (position == nbElements(L))
        return SupprimerFin(L);

    Liste *S = L;
    Liste *Ss = S->suiv;
    for (int pos = 1; pos < position - 1; pos++)
    {
        S = S->suiv;
        Ss = Ss->suiv;
    }
    S->suiv = Ss->suiv;
    free(Ss);
    return L;
}
//------------------------------------------------------
void MENU()
{
    printf("\n================= MENU =================");
    printf("\nCreer une liste --------------------- 1");
    printf("\nAfficher une liste ------------------ 2");
    printf("\nLe nombre des elements d'une liste -- 3");
    printf("\nAjouter au debut d'une liste -------- 4");
    printf("\nAjouter au milieu d'une liste ------- 5");
    printf("\nAjouter a la fin d'une liste -------- 6");
    printf("\nSupprimer au debut d'une liste ------ 7");
    printf("\nSupprimer au milieu d'une liste ----- 8");
    printf("\nSupprimer a la fin d'une liste ------ 9");
    printf("\nDetruire la liste ------------------ 10");
    printf("\nQuitter ---------------------------- 11");
    printf("\n========================================");
}
//------------------------------------------------------
int main()
{
    Liste *X = NULL;
    int choice, val, p;

    do
    {
        MENU();
        printf("\nEntrer votre choix : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            X = CreerListe();
            break;
        case 2:
            Affichage(X);
            break;
        case 3:
            printf("\n%d elements", nbElements(X));
            break;
        case 4:
            printf("\nValeur a ajouter ? : ");
            scanf("%d", &val);
            X = AjoutDebut(X, val);
            Affichage(X);
            break;
        case 5:
            printf("\nValeur a ajouter ? : ");
            scanf("%d", &val);
            printf("\nPosition ou ajouter ? : ");
            scanf("%d", &p);
            X = AjoutMilieu(X, val, p);
            Affichage(X);
            break;
        case 6:
            printf("\nValeur a ajouter ? : ");
            scanf("%d", &val);
            X = AjoutFin(X, val);
            Affichage(X);
            break;
        case 7:
            X = SupprimerDebut(X);
            Affichage(X);
            break;
        case 8:
            printf("\nPosition a supprimer ? : ");
            scanf("%d", &p);
            X = SupprimerMilieu(X, p);
            Affichage(X);
            break;
        case 9:
            X = SupprimerFin(X);
            Affichage(X);
            break;
        case 10:
            while (X != NULL)
                X = SupprimerDebut(X);
            printf("\nListe detruite.............");
            break;
        case 11:
            printf("\nVous avez quitte .....................");
            break;
        default:
            printf("\nChoix invalide !\n");
            break;
        }
    } while (choice != 11);

    return 0;
}
