#include <stdio.h>
#include "list.h"
#include "rosensthiel.h"

void rosenstiehl( int number_of_nodes, int **adjacency_matrix, int root, struct list_node *head, struct list_node *cycle_head ){

    int next_node;
    push_element_end(head, root);
    while ( return_no_elements(head) ) {
        root = pop_element_end(head);
        next_node = 0;
        while ( next_node < number_of_nodes ) {
            if ( adjacency_matrix[root][next_node] == 1) {
                adjacency_matrix[root][next_node] = 0;
                adjacency_matrix[next_node][root] = 0;
                push_element_end(head, root);
                root = next_node;
                next_node = 0;
            }
            else next_node++;
        }
        push_element_end(cycle_head, root);
    }
}

int test_for_cycle( int number_of_nodes, int **adjacency_matrix )
{
    int number_of_edges = 0;
    int has_cycle = 1;
    int iterator1, iterator2;

    for(iterator1 = 0; iterator1 < number_of_nodes; iterator1++){
        for(iterator2 = 0; iterator2 < number_of_nodes; iterator2++)
            if(adjacency_matrix[iterator1][iterator2]==1)
                number_of_edges++;

        if(number_of_edges == 0 || number_of_edges % 2 != 0){
            has_cycle = 0;
            break;
        }

    number_of_edges = 0;
    }
    return has_cycle;
}
