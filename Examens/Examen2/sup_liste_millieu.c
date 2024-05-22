typedef struct 
{
    int val ;
    struct lst *suiv ;
}lst;
lst * sup_millieu(lst *L , int pos ){
    int pos  = 1 ;
    lst *par = L , *sup = L ;
    if (pos == 1 )
    {
        L = L->suiv ;
        free(sup);
    }else{
        while (par != NULL)
        {
           
        }
        
    }
    
}
