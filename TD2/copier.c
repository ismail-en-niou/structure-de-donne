#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int day, month, year;
} date;

typedef struct
{
    char nom[20], cne[20], filier[5];
    date dateNs;
    int semester;
    float notes[6];
} etudiant;

typedef struct
{
    etudiant E;
    struct list_etd *next;
} list_etd;

// fonction pour calculer le nombre des elemet qu on a dans ce liste

int nb_Element(list_etd *L)
{
    int i = 0;
    while (L != NULL)
    {
        i++;
        L = L->next;
    }
    return i;
}

// insertion d'element au debut ;
list_etd *ajoute_debut(list_etd *L, etudiant x)
{
    list_etd *temp = (list_etd *)malloc(sizeof(list_etd));
    if (temp == NULL)
    {
        printf("ereur");
        exit(-1);
    }
    else
    {
        temp->E = x;
        temp->next = L;
        L = temp ;
        return L;
    }
}

// insertion a la fin ;

list_etd *ajoute_fin(list_etd *L, etudiant x)
{
    list_etd *temp = (list_etd *)malloc(sizeof(list_etd));

    temp->E = x;
    temp->next = NULL;
    if (L == NULL)
    {
        return temp;
    }
    list_etd *c;
    c = L;
    while (c->next != NULL)
        c = c->next;

    c->next = temp;
    return L;
}

// insertion au milieu ;

list_etd *ajouter_milieu(list_etd *L, int position, etudiant x)
{
    list_etd *temp = (list_etd *)malloc(sizeof(list_etd));
    list_etd *c;
    int i = 1;
    temp->E = x;
    if (nb_Element(L) + 1 == position)
    {
        L = ajoute_fin(L, x);
    }
    if (nb_Element(L) + 1 < position)
    {
        printf("ereur de position");
    }
    if (nb_Element(L) + 1 > position)
    {
        if (position = 1)
        {
            L = ajoute_debut(L, x);
        }
        else
        {
            c = L;
            while (i != position)
            {
                c = c->next;
                i++;
            }
            temp->next = c->next;
            c->next = temp;
        }
        return L;
    }
}
// les fonction de supression
// fonction de debut
list_etd *sup_debut(list_etd *L)
{
    list_etd *temp;
    if (L = NULL)
    {
        return NULL
    }
    temp = L;
    L = L->next;
    free(temp);
    return L;
}

// fonction de fin
list_etd *sup_fin(list_etd *L)
{
    if (L != NULL)
    {
        if (L->next == NULL)
        {
            free(L);
            L = NULL;
        }
        else
        {
            list_etd *c;
            c = L;
            while (c->next->next != NULL)
            {
                c = c->next;
            }
            free(c->next);
            c->next = NULL;
        }
    }
}

// supression au milieux par variabble;
list_etd sup_mill(list_etd *L, etudiant x)
{
    if (L != NULL)
    {
        list_etd *p, *temp;
        if (L->next = x)
        {

            p = L;
            L = L->next;
            free(p);
        }
        else
        {
            temp = L;
            while (temp->next->E != NULL)
            {
                temp = temp->next;
            }
            p = temp->next;
            temp->next = temp->next->next;
            free(p);
        }
    }
    return L;
}
// affichage  de la listes ;
//  char nom[20], cne[20], filier[5];
    // date dateNs;
    // int semester;
    // float notes[6];
list_etd *affichage_de_la_liste(list_etd *L){
    printf("Affichage De La Liste \n");
    while (L != NULL)
    {
        printf("nom : %s  , cne : %s , filier : %s \n" , L->E.nom , L->E.cne , L->E.filier);
        printf("datte de naissance : %d - %d - %d est semestre %d \n", L->E.dateNs.day , L->E.dateNs.month , L->E.dateNs.year , L->E.semester);
        printf("les notes \n");
        for (int i = 0; i < 6; i++)
        {
            printf(" %d \n ", L->E.notes[i]);
        }
         printf("\n=============================================\n");
         L=L->next ; 
    }
    
} 
list_etd *student_position(list_etd *L , etudiant x){
    int i = 1 ; 
    list_etd temp = (list_etd *)(malloc(sizeof(list_etd)));
    temp = L;
    while (temp->next != NULL && temp->E == x)
    {
        temp = temp->next ;
        i++;
    }
    if (temp != 0){
        return i ;
    }else{
        return -1 ;
    }
}
int main(int argc, char const *argv[])
{
    list_etd *L;
    L = NULL;
    return 0;
}
