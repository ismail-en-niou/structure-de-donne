#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day, month, year;
} date;

typedef struct {
    char nom[20], cne[20], filier[5];
    date dateNs;
    int semester;
    float notes[6];
} etudiant;

typedef struct {
    etudiant E;
    struct list_etd *next;
} list_etd;

// Function for insertion at the beginning
list_etd *ajouter_au_debut(list_etd *L, etudiant x) {
    list_etd *temp = (list_etd *)malloc(sizeof(list_etd));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    temp->E = x;
    temp->next = L;
    return temp;
}

// Function for insertion at the end
list_etd *ajout_fin(list_etd *L, etudiant x) {


    list_etd *temp = (list_etd *)malloc(sizeof(list_etd));
    
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    temp->E = x;
   

    if (L == NULL) {
        return temp;
    }

    list_etd *pass = L;
    while (pass->next != NULL) {
        pass = pass->next;
    }
    pass->next = temp;
    temp->next = NULL;
    return L;
}

// Function to count elements in the list
int nbElements(list_etd *L) {
    int nb = 0;
    while (L != NULL) {
        nb++;
        L = L->next;
    }
    return nb;
}

// Function for insertion between elements
list_etd *ajout_milieu(list_etd *L, etudiant x, int pos) {
    list_etd *temp = (list_etd *)malloc(sizeof(list_etd));
    list_etd *c;
    int i = 1; // Initialize i
    if (nbElements(L) + 1 < pos) {
        printf("Error: Cannot add element at this position.\n");
    } else if (nbElements(L) + 1 == pos) {
        L = ajout_fin(L, x);
    } else {
        if (pos == 1) {
            L = ajouter_au_debut(L, x);
        } else {
            c = L;
            while (i != pos - 1) {
                c = c->next;
                i++;
            }
            if (c->next == NULL) {
                L = ajout_fin(L, x);
            } else {
                temp->next = c->next;
                c->next = temp;
            }
        }
    }
    return L;
}

// Function to input values for an etudiant
etudiant input_etudiant() {
    etudiant new_etudiant;
    printf("Nom: ");
    scanf("%s", new_etudiant.nom);
    printf("CNE: ");
    scanf("%s", new_etudiant.cne);
    printf("Filiere: ");
    scanf("%s", new_etudiant.filier);
    printf("Date de naissance (jour mois année): ");
    scanf("%d %d %d", &new_etudiant.dateNs.day, &new_etudiant.dateNs.month, &new_etudiant.dateNs.year);
    printf("Donner les notes: ");
    for (int i = 0; i < 6; i++) {
        scanf("%f", &new_etudiant.notes[i]);
    }
    printf("Semestre: ");
    scanf("%d", &new_etudiant.semester);
    return new_etudiant;
}

// Function to delete the first element
list_etd *sup_debut(list_etd *L) {
    if (L == NULL) {
        printf("La liste est déjà vide.\n");
        exit(EXIT_FAILURE);
    } else {
        list_etd *temp = L;
        L = L->next;
        free(temp);
    }
    return L;
}

// Function to delete the last element
list_etd *sup_fin(list_etd *L) {
    if (L == NULL) {
        printf("La liste est vide.\n");
        exit(EXIT_FAILURE);
    } else {
        list_etd *der, *avder;
        if (L->next == NULL) {
            free(L);
            return NULL;
        }
        der = L;
        avder = NULL;
        while (der->next != NULL) {
            avder = der;
            der = der->next;
        }
        free(der);
        if (avder != NULL) {
            avder->next = NULL;
        } else {
            L = NULL;
        }
        return L;
    }
}

// Function to delete an element in the middle
list_etd *sup_mellieu(list_etd *L, int pos) {
    if (L == NULL) {
        printf("La liste est vide.\n");
        exit(EXIT_FAILURE);
    }
    if (pos == 1) {
        return sup_debut(L);
    }
    list_etd *prev = L;
    for (int i = 1; i < pos - 1; i++) {
        if (prev == NULL || prev->next == NULL) {
            printf("Erreur: La position spécifiée est invalide.\n");
            return L;
        }
        prev = prev->next;
    }
    if (prev == NULL || prev->next == NULL || prev->next->next == NULL) {
        printf("Erreur: La position spécifiée est invalide.\n");
        return L;
    }
    list_etd *temp = prev->next;
    prev->next = temp->next;
    free(temp);
    return L;
}

// Function to display the list
void afficher_liste(list_etd *L) {
    printf("Liste des étudiants :\n=============================================\n");
    while (L != NULL) {
        printf("Nom: %s, CNE: %s, Filière: %s\n", L->E.nom, L->E.cne, L->E.filier);
        printf("Notes: ");
        for (int i = 0; i < 6; i++) {
            printf("%.2f ", L->E.notes[i]);
        }
        printf("\n");
        printf("Semestre: %d\n", L->E.semester);
         printf("\n=============================================\n");
        L = L->next;
    }
}

int main(int argc, char const *argv[]) {
    list_etd *L = NULL;
    printf("Liste vide est créée.\n");
    // Input a new student
    etudiant new_student = input_etudiant();
    L = ajouter_au_debut(L, new_student);
    etudiant new_student2 = input_etudiant();
    L = ajout_fin(L, new_student2);

    // Display the list
    L = sup_fin(L);
    afficher_liste(L);
    return 0;
}
