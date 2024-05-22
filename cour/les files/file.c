#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct 
{
    int tete;
    int Queue;
    int taille ;
    int *T;
}file;
int estVide( file f){
    return (f.tete == f.Queue);
}
int estplen( file f ){
    return (f.taille == f.Queue );
}
void EnFiler( file *f , int v ){
    f->T[f->Queue++] = v;
}
int DeFiler(file *f){
    return f->T[f->tete++] ;
}
int main(){
    file f1 ; 
    int n;
    f1.Queue = f1.tete = 0 ;
    printf("Donner la taille maximale de la file p1 : ");
    scanf("%d", &f1.taille);
    f1.T = (int *)malloc(f1.taille * sizeof(int));


    while (!estplen(f1))
    {
        printf("Donner la valeur que vous voulez ajouter : ");
        scanf("%d", &n);
        EnFiler(&f1, n);
    }
    while (!estVide(f1))
    {
        printf("%d \n", DeFiler(&f1));
    }
    free(f1.T);
    return 0 ;
}