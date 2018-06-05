/**
*   @file main.c
*   @brief The main function of the program
*   @author Banica Victor Eugen
*/



#include <stdio.h>
#include <time.h>
#include "list.h"
#include "rosensthiel.h"

///Here you define the max number of nodes that can be randomly generated
#define MAXNODES 25


/**
* @fn int main
* @brief Main function that takes user input to establish what the program does
*/
int main(){

    srand(time(0));
    ///Allocate memory for the lists heads
    struct list_node *head = malloc(sizeof(struct list_node));
    head->next = NULL;
    struct list_node *cycle_head = malloc(sizeof(struct list_node));
    cycle_head->next = NULL;


    int iterator1,iterator2;
    int **adjacency_matrix;
    int is_edge;
    int number_of_nodes;
    int option;
    ///Menu used to select diffrent options, like generation of random input data
    do{

        printf("\n\n\nChoose an option: \n\n");
        printf(" 1. Read input data manually, from keyboard \n\n");
        printf(" 2. Generate random input data \n\n");
        printf(" 3. Display the input data \n\n");
        printf(" 4. Find eulerian cycle using Rosensthiel algorithm \n\n");
        printf(" 5. Find eulerian cycle using Fleury algorithm \n\n");
        printf(" 6. Exit program \n\n");
        printf("\nYour option: ");
        scanf("%i", &option);
        printf("\n\n");

        switch(option){
            case 1:
                printf("Enter the number of nodes in the graph: ");
                scanf("%d", &number_of_nodes);
                printf("\nThe nodes IDs range from 0 to %d\n", number_of_nodes - 1);
                ///Allocate memory for the matrix
                adjacency_matrix = (int**)calloc( number_of_nodes, sizeof(int) );
                for ( iterator1 = 0; iterator1 < number_of_nodes; iterator1++ )
                    adjacency_matrix[iterator1] = (int**)calloc( number_of_nodes, sizeof(int) );

                printf("Input the adjacency matrix...\n\n");

                for( iterator1 = 0; iterator1 < number_of_nodes; iterator1++){
                    for( iterator2 = 0; iterator2 < number_of_nodes; iterator2++ ){
                        scanf("%d", &is_edge);
                        adjacency_matrix[iterator1][iterator2] = is_edge;
                    }
                printf("\n");
                }
                break;
            case 2:
                ///Randomly generating the nodes
                number_of_nodes = rand() % MAXNODES;

                adjacency_matrix = (int**)calloc( number_of_nodes, sizeof(int) );
                for ( iterator1 = 0; iterator1 < number_of_nodes; iterator1++ )
                    adjacency_matrix[iterator1] = (int**)calloc( number_of_nodes, sizeof(int) );
                ///Randomly generating the matrix, assuring to have 0 on the principal diagonal
                for( iterator1 = 0; iterator1 < number_of_nodes; iterator1++ )
                    for( iterator2 = 0; iterator2 < number_of_nodes; iterator2++ )
                        if ( iterator1 != iterator2 )
                           adjacency_matrix[iterator1][iterator2] = adjacency_matrix[iterator2][iterator1] = rand() % 2;
                        else
                           adjacency_matrix[iterator1][iterator2] = 0;

                printf("\nThe random input data have been generated!");
                break;

            case 3:
                ///Displaying the input data
                printf("\nThe number of nodes is: %d\n\n", number_of_nodes);
                printf("The adjacency matrix is: \n\n");
                for(iterator1 = 0; iterator1 < number_of_nodes; iterator1++){
                    for(iterator2 = 0; iterator2 < number_of_nodes; iterator2++)
                        printf("%d ", adjacency_matrix[iterator1][iterator2]);
                    printf("\n");
                }
                break;

            case 4:
                ///If the graph has a cycle, apply rosenstiehl algorithm
                if(test_for_cycle(number_of_nodes, adjacency_matrix)){
                    ///Assume the root of the graph to be the node of index 0
                    int root = 0;
                    rosenstiehl(number_of_nodes, adjacency_matrix, root, head, cycle_head);
                    printf("\nThe eulerian cycle is: ");
                    print_list(cycle_head);
                }else
                    printf("\nThe graph has no eulerian cycle!");
                break;

            case 5:
                printf("Fleury not implemented...");
                break;
            case 6:
                return 0;
            default:
                printf("Wrong option!\n");
            }
    }while ( option != 6 );

    ///Free the memory
    free(head);
    free(cycle_head);
    free(adjacency_matrix);

    return 0;

}
