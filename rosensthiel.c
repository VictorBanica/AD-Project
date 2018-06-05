/**
*   @file rosensthiel.c
*   @brief File which contains the rosensthiel algorithm
*   @author Banica Victor Eugen
*/

#include <stdio.h>
#include "list.h"
#include "rosensthiel.h"


/**
*@fn void rosenstiehl( int number_of_nodes, int **adjacency_matrix, int root, struct list_node *head, struct list_node *cycle_head )
*@brief This method will generate the eulerian cycle
*@param int number_of_nodes The number of nodes in the graph
*@param int **adjacency_matrix The adjacency matrix
*@param int root The root node of the graph
*@param struct list_node *head The first node in the list used for generating the cycle
*@param struct list_node *cycle_head The first node in the list used to store the eulerian cycle
*/
void rosenstiehl( int number_of_nodes, int **adjacency_matrix, int root, struct list_node *head, struct list_node *cycle_head ){

    int next_node;
    ///Adding the root element to the list
    push_element_end(head, root);
    ///While the list is not empty keep getting nodes
    while ( return_no_elements(head) ) {
        ///Assign the new root to be the last element in the list
        root = pop_element_end(head);
        next_node = 0;
        ///Check for edges using the matrix
        while ( next_node < number_of_nodes ) {
            if ( adjacency_matrix[root][next_node] == 1) {
                adjacency_matrix[root][next_node] = 0;
                adjacency_matrix[next_node][root] = 0;
                ///Adding the current node to the end of the list
                push_element_end(head, root);
                ///The current node becomes the next one
                root = next_node;
                next_node = 0;
            }
            else next_node++;
        }
        ///Add the element to eulerian cycle
        push_element_end(cycle_head, root);
    }
}


/**
*@fn int test_for_cycle( int number_of_nodes, int **adjacency_matrix )
*@brief This method will return wether the graph has an eulerian cycle of not
*@param int number_of_nodes The number of nodes in the graph
*@param int **adjacency_matrix The adjacency matrix of the graph
*/

int test_for_cycle( int number_of_nodes, int **adjacency_matrix )
{
    int number_of_edges = 0;
    int has_cycle = 1;
    int iterator1, iterator2;
    ///If we find 1 in the matrix, then that node has an edge
    for(iterator1 = 0; iterator1 < number_of_nodes; iterator1++){
        for(iterator2 = 0; iterator2 < number_of_nodes; iterator2++)
            if(adjacency_matrix[iterator1][iterator2]==1)
                number_of_edges++;
        ///If the number of edges is 0, then the graph is not connected
        ///If the number of edges of each node is not even, then we don't have eulerian cycle
        if(number_of_edges == 0 || number_of_edges % 2 != 0){
            has_cycle = 0;
            break;
        }

    number_of_edges = 0;
    }
    ///Return 1 if the graph has a cycle
    return has_cycle;
}
