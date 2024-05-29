#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nom[20];
    int apoge;
}etd ;
etd * ajouter_file(etd *file){
    etd *l = (etd *)malloc(sizeof(etd));
    strcpy(l->nom , "salma");
    l->apoge = 9999;
    etd -> s = NULL;
    fin->s = etd ;fin = fin->s;
}
