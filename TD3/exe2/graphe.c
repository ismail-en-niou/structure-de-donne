#include <stdio.h>
void mat_adjacent(int M[7][7] , int n){
    int i = j = 0 ;
    printf("***********donner la matrice avec 1 et 2 seulemet ************** \n") ;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("donner la valeur de M[%d][%d] = " , i , j );
            scanf("%d" , &M[i][j]);
        }
        
    }
    
}
void affiche_graphe(int M[7][7] , int n){
    int i = j = 0 ;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf(" %d" , M[i][j] );
        }
        printf("\n") ;
    }
}
int degre(int sommet ,int M[7][7] , int n){
    int d ; 
    for (int i = 0; i < count; i++)
    {
       if (M[sommet][i] == 1)
       {
            d++;
       }
       if (M[i][sommet])
       {
            d++;
       }
       
       
        
    }
   return d  ;  
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
