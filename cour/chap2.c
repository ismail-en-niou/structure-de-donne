#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Fonction pour insérer un nouvel élément au milieu de la liste
void insertAfter(struct node *prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Le nœud précédent est NULL. Impossible d'insérer.\n");
        return;
    }

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Fonction pour supprimer un nœud au milieu de la liste
void deleteNode(struct node *prev_node) {
    if (prev_node == NULL || prev_node->next == NULL) {
        printf("Le nœud précédent est NULL ou le nœud suivant est NULL. Impossible de supprimer.\n");
        return;
    }

    struct node *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Fonction pour afficher la liste
void printList(struct node *n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printf("Liste initiale : ");
    printList(head);

    // Insérer un nouvel élément au milieu de la liste
    insertAfter(third, 4);
    printf("Liste après insertion : ");
    printList(head);

    // Supprimer un nœud au milieu de la liste
    deleteNode(second);
    printf("Liste après suppression : ");
    printList(head);

    return 0;
}
