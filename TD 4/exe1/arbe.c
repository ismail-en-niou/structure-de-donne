#include <stdio.h>

#include <stdlib.h>
// question 1 
typedef struct 
{
    int valeur ;
    struct noued* right ;
    struct noued* left ;
}noued;
// question  2 
noued * creer_arbe(int v , noued *G , noued *D){
    noued *x ;
    x = (noued *)malloc(sizeof(noued));
    x->valeur = v ;
    x->right = G;
    x->left = D ;
    return X ;
}
// question 3
noued *nombre_noued(noued *X){
    if (X == NULL)
    {
        return 0 ;
    }else{
        return 1 + nombre_noued(X->left) + nombre_noued(X->right);
    }
}
// question 4
int max(int a , int b){
    if (a> b)
    {
        return a ;
    }else 
    {
        return b ;
    }
}
noued * Hauteur(noued *X){
    if ( X = NULL)
    {
        return 0 ;
    }else{
        return 1 + max(Hauteur(X->right) + Hauteur(X->left))
    }
    
}