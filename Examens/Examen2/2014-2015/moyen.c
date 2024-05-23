#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int value;
    struct list *next;
} L ;
// functionn 1
float moyenne(L *list)
{
    int sum = 0;
    int count = 0;
    while (list != NULL)
    {
        sum += list->value;
        count++;
        list = list->next;
    }
    if (count != 0)
        return (float)sum / count;
    else
        return 0;
}
// function 2 {this function return the last element in list }
int last(L *list)
{
    L *temp = (L)malloc(sizeof(L));
    while (temp->next != NULL)
    {
        temp = list->next;
    }
    return temp->value;
}
// function 3 {this function return lenght of this list}
int lenght(L *list)
{
    int count = 1;
    while (list != NULL)
    {
        count++;
        list = list->next;
    }
    return count;
}
// function 4 {this function delete the last elment in list }
L *delete_last(L *list)
{

    if (list == NULL)
    {
        printf("la liste est vide ");
        exit(EXIT_FAILURE);
    }
    else
    {
        L *der, *avder;
        if (list->next == NULL)
        {
            free(list);
            return NULL;
        }
        else
        {
            der = list;
            avder = NULL;
            while (der->next != NULL)
            {
                avder = der;
                der = der->next;
            }
            free(der);
            if (avder != NULL)
                avder->next = NULL;
            else
                list = NULL;
            return list;
        }
    }
}
// function 5 {this funcion add element inn  position passed by argument of function }

L *add_posi(L *list, int val, int x)
{
    int position = 1;
    if (lenght(list) + 1 == x)
    {
        // ajouter fin
        L *temp = (L *)malloc(sizeof(L));
        temp->value = val;
        temp->next = NULL;
        if (list == NULL)
        {
            return temp;
        }
        L *c;
        while (c->next != NULL)
            c = c->next;
        c->next = temp;
        return list;
    }
    if (lenght(list) + 1 < x)
    {
        printf("la position donner est fausse ");
    }

    if (lenght(list) + 1 > x)
    {
        if (x == 0)
        {
            // add in the first
            L *temp = (L *)malloc(sizeof(L));
            temp->value = val;
            temp->next = list;
            return temp;
        }
        else
        {
            L *c = list;
            while (position != x - 1)
            {
                c->next;
                position++;
            }
            if (c->next == NULL)
            {
                // ajouter fin
                L *temp = (L *)malloc(sizeof(L));
                temp->value = val;
                temp->next = NULL;
                if (list == NULL)
                {
                    return temp;
                }
                L *c;
                while (c->next != NULL)
                    c = c->next;
                c->next = temp;
                return list;
            }
            else
            {
                temp->next = c ->next ;
                c->next = temp ;
            }
        }
    }
    return L ;
}
// function 6 {inverse the list}
L *inver(L *list){
    L* invert(L *list) {
    L *prev = NULL;
    L *current = list;
    L *next = NULL;
    
    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current; // Move the prev pointer one step forward
        current = next; // Move the current pointer one step forward
    }
    
    return prev; // prev becomes the new head of the inverted list
}
}