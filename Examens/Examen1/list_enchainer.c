#include <stdio.h>

typedef struct list
{
    int val ;
    struct list *suiv ; 
}Liste;
Liste * remplacer( Liste * L , int p , int v ){
    int pos  = 1 ; 
    Liste * par  = L ;
    while( par != NULL){
        par = par->suiv;
        pos++;
    }
    if (p == pos && par != NULL)
    {
        par->val = v ; 
    }
    return L; 
}
