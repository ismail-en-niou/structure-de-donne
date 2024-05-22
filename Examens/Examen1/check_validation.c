#include <stdio.h>
typedef struct etd 
{
    char nom[20];
    int apoge ;
    float notes[6];
}etudiant;



void check_validation(etudiant *L , int j  ){
    int n =  6 ; 
    for (int i = 0; i < n; i++)
    {
        if (L[j].notes[i] >10)
            d++; 
        else
            break;
    }
    if (d == 6)
    {
        printf("oui");
    }
    else
        printf("non");
        
}