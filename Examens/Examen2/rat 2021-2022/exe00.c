#include <stdio.h>

typedef struct 
{
    char nom[50] ;
    int date[3];
}Perssonne;
void adulte_mineur( Perssonne *L  ){
    int old = 0 ;
    int jour = 26 ; int mount = 5 ; int  year  = 2024 ;
    old =  2024 - L->date[2];
    if (L->date[0] < jour || L->date[1]< mount  || L->date[2] < year )
        old--;
    if(old > 18)
         printf("%s est adulte. age : %d\n", L->nom , old);
    else
        printf("%s est mineur. age : %d \n", L->nom , old);
}
int main(){
    Perssonne P = {"ismail enniou" ,{8,11,2004}};
    adulte_mineur(&P);
    return 0 ;
}