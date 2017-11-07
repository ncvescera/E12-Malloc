#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

struct s_node {
    char c;
    struct s_node *next;
};
typedef struct s_node node;
typedef node * nodePtr;

void add(nodePtr *lista, char val);
void rm(nodePtr *lista, char val);
void fill(nodePtr *lista);
void printList(nodePtr lista);
int cerca(nodePtr lista, char elem);

int main(int argc, char** argv) {
    nodePtr list = malloc(sizeof (node));

    fill(&list);
    printList(list);

    rm(&list, 'w');
    printList(list);

    printf("%d\n", cerca(list, 'y'));

    return (EXIT_SUCCESS);
}

void add(nodePtr *lista, char val) {
    nodePtr newLista = malloc(sizeof (node));

    if (lista != NULL) {
        newLista->c = val;
        newLista->next = *lista;
        *lista = newLista;
    }

}

void rm(nodePtr *lista, char val) {
    if ((*lista)->c == val) {
        nodePtr temp = *lista;
        *lista = (*lista)->next;
        free(temp);
    } else {
        nodePtr temp = *lista;

        while (temp->next != NULL && temp->next->c != val)
            temp = temp->next;

        if (temp->next != NULL) {
            nodePtr del = temp->next;
            temp->next = temp->next->next;
            free(del);
        }
    }
}

void fill(nodePtr *lista) {
    if (lista == NULL)
        lista = malloc(sizeof (node));


    for (int i = 'a'; i <= 'z'; i++)
        add(&(*lista), ((char) i));
}

void printList(nodePtr lista) {
    nodePtr temp = lista;

    while (temp->next != NULL) {
        printf("%c -> ", temp->c);
        temp = temp->next;
    }

    printf("NULL\n");
}

int cerca(nodePtr lista, char elem) {
    bool trovato = FALSE;

    nodePtr temp = lista;
    int posizione;

    for (posizione = 0; temp->next != NULL && !trovato; posizione++) {
        if (temp->c == elem)
            trovato = TRUE;
        else {
            temp = temp->next;
        }
    }

    if (trovato == FALSE)
        posizione = -1;
    else
        posizione -= 1; //la posizione viene incrementata di 1 dopo la fine del for e non va bene

    return posizione;

}