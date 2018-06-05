/**
*   @file list.c
*   @brief File which contains which implement a simple linked list.
*   @author Banica Victor Eugen
*/


#include <stdio.h>
#include "list.h"
#include "rosensthiel.h"

/**
*@fn void push_element_end( struct list_node *head, int new_element_value )
*@brief This method will push an element to the end of the list
*@param struct list_node *head The first node in the list
*@param int new_element_value The value of the element to be added in the list
*/
void push_element_end( struct list_node *head, int new_element_value ){
    ///Initializing the new node
    struct list_node *new_element = malloc( sizeof( struct list_node ) );
    struct list_node *iterator = head;
    struct list_node *last_element;

    ///While we have not reached the last node, iterate further
    while ( iterator->next != NULL ) {
        iterator = iterator->next;
    }
    last_element = iterator;
    ///We save the last element data, and insert the new element after
    last_element->next = new_element;
    new_element->info = new_element_value;
    new_element->next = NULL;
}

/**
*@fn int pop_element_end( struct list_node *head )
*@brief This method will pop the last element in the list, deleting it and returning it's value
*@param struct list_node *head The first node in the list
*/
int pop_element_end( struct list_node *head ){
    struct list_node *poped_element;
    struct list_node *iterator = head;
    int aux;

    ///While we have not reached the node previous of the last node, iterate further
    while ( iterator->next->next != NULL) {
        iterator = iterator->next;
    }
    ///We are now on the element before the last one
    ///We save the last element's data and then delete it
    poped_element = iterator->next;
    aux = poped_element->info;
    iterator->next = poped_element->next;

    free(poped_element);
    ///Return the deleted node's data
    return aux;
}

/**
*@fn void print_list( struct list_node *head )
*@brief This method will display the list on your screen
*@param struct list_node *head The first node in the list
*/
void print_list( struct list_node *head ){
    struct list_node *iterator = head;
    ///Keep iterating untill we have reached the end of the list, displaying every node in order
    while (iterator->next != NULL) {
        if (iterator->next->next != NULL)
            printf(" %d ->", iterator->next->info);
        else
            printf(" %d;", iterator->next->info);
        iterator = iterator->next;
    }
    printf("\n");
}

/**
*@fn int return_no_elements( struct list_node *head )
*@brief This method will return the number of elements in the list
*@param struct list_node *head The first node in the list
*/
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
