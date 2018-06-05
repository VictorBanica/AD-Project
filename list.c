#include <stdio.h>
#include "list.h"
#include "rosensthiel.h"

void push_element_end( struct list_node *head, int new_element_value ){
    struct list_node *new_element = malloc( sizeof( struct list_node ) );
    struct list_node *iterator = head;
    struct list_node *last_element;

    while ( iterator->next != NULL ) {
        iterator = iterator->next;
    }
    last_element = iterator;

    last_element->next = new_element;
    new_element->info = new_element_value;
    new_element->next = NULL;
}

int pop_element_end( struct list_node *head ){
    struct list_node *poped_element;
    struct list_node *iterator = head;
    int aux;

    while ( iterator->next->next != NULL) {
        iterator = iterator->next;
    }

    poped_element = iterator->next;
    aux = poped_element->info;
    iterator->next = poped_element->next;

    free(poped_element);

    return aux;
}

void print_list( struct list_node *head ){
    struct list_node *iterator = head;

    while (iterator->next != NULL) {
        if (iterator->next->next != NULL)
            printf(" %d ->", iterator->next->info);
        else
            printf(" %d;", iterator->next->info);
        iterator = iterator->next;
    }
    printf("\n");
}

int return_no_elements( struct list_node *head ){
    int no_elements ;
    struct list_node *iterator;
    iterator = head;
    no_elements = 0;

    while ( iterator->next != NULL ) {
        iterator = iterator->next;
        ++no_elements;
    }
    return no_elements;
}
