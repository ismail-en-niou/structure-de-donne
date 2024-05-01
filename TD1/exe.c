#include <stdio.h>
#include <stdint.h>
#include <string.h>
 int i =  0 ; 
typedef struct {
    int jour, mois, an;
} date;
typedef struct {
   char nom[20], cne[20];
   date dateNs;
   char filier[5];
   int semestre;
   float notes[6];
} etudiant;
etudiant saisie(int i) {
   
    printf("Donnez les informations sur l'etudiant %d\n", i+1);
    etudiant e;
    printf("Nom : ");
    scanf("%s", e.nom);
    printf("CNE : ");
    scanf("%s", e.cne);
    printf("Filiere : ");
    scanf("%s", e.filier);
    printf("Semestre : ");
    scanf("%d", &e.semestre);
    printf("Date de naissance :\n");
    printf("Jour : ");
    scanf("%d", &e.dateNs.jour);
    printf("Mois : ");
    scanf("%d", &e.dateNs.mois);
    printf("Annee : ");
    scanf("%d", &e.dateNs.an);
    printf("Notes :\n");
    for (int j = 0; j < 6; j++) {
        printf("Note %d : ", j + 1);
        scanf("%f", &e.notes[j]);
    }
    i++;
    return e;
}
void parfilier(etudiant Tab_Etd[10], etudiant tab_smi[10], etudiant tab_sma[10]) {
    int j = 0, k = 0;
    for (int i = 0; i < 10; i++) {
        if (strcmp(Tab_Etd[i].filier,"smi") == 0) {
           tab_smi[j++] = Tab_Etd[i];
        }
        if (strcmp(Tab_Etd[i].filier, "sma") == 0) {
            tab_sma[k++] = Tab_Etd[i];
        }
    }
}
void parsemestre(etudiant Tab_Etd[10], etudiant *tab_s4) {
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if (Tab_Etd[i].semestre == 4) {
            *(tab_s4 + j ) = Tab_Etd[i];
            j++;
        }
    }
}
void affichage_module(etudiant Tab_s4[10]){
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(Tab_s4[i].filier , "smi") == 0 || strcmp(Tab_s4[i].filier , "sma")== 0 )
        {
            printf("nom : %s " , Tab_s4[i].nom);
            printf("la note de deuxieme module : %d" , Tab_s4[i].notes[1])
        }
        
    }
    
}
int  validemodule(etudiant Tab_s4[10]){
    int nbrV;
    for (int  i = 0; i < 10; i++)
    {
        if (Tab_s4[i].notes[1] >= 10)
        {
            nbrV++;    
        }
        
    }
    return nbrV ; 
}
int main() {
    etudiant Tab_Etd[10];
    etudiant tab_sma[10], tab_smi[10];
    etudiant tab_s4[10];
    for (int i = 0; i < 10; i++) {
        Tab_Etd[i] = saisie(i + 1);
    }
    parfilier(Tab_Etd, tab_smi, tab_sma);
    parsemestre(Tab_Etd, tab_s4);
    int nbrV = validemodule(tab_s4)
    printf("le nombre des etudiant qui ont valider se module est %d  " ,nbrV );
    return 0;
}
