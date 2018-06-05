#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct list_node{
    int info;
    struct list_node *next;
};

void push_element_end( struct list_node *head, int new_element_value );
int pop_element_end( struct list_node *head );
void print_list( struct list_node *head );
int return_no_elements( struct list_node *head );

#endif // LIST_H_INCLUDED
