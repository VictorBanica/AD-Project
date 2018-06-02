#include<stdio.h>
#include<conio.h>
#include "functions.h"


int main()
{
    char is_edge;
    int iterator1;
    int iterator2;

    printf("Enter the number of nodes in a graph\n");
    scanf("%d", &number_of_nodes);

    printf("Enter the value of the nodes\n");

    nodes_array = (int*)calloc( number_of_nodes, sizeof(int) );
    for ( iterator1 = 0; iterator1 < number_of_nodes ; iterator1++ )
        scanf( "%d", &nodes_array[iterator1] );


    printf("Enter the value in adjancency matrix like so\n");
    printf("\nIf there is an edge between the two nodes enter 'y' else 'n'\n");


    adjacency_matrix = (int**)calloc( number_of_nodes, sizeof(int) );
    for ( iterator1 = 0; iterator1 < number_of_nodes; iterator1++ )
        adjacency_matrix[iterator1] = (int**)calloc( number_of_nodes, sizeof(int) );

    for( iterator1 = 0; iterator1 < number_of_nodes; iterator1++){
        for( iterator2 = 0; iterator2 < number_of_nodes; iterator2++ ){
            printf( "%c ", is_edge = getch() );
            if ( iterator1 == iterator2 )
                adjacency_matrix[iterator1][iterator2] = 'n';
            else
                adjacency_matrix[iterator1][iterator2] = is_edge;
        }
        printf("\n\n");
    }


    int root;

    if ( test_for_cycle() == 1 ){
        root = nodes_array[0];
        printf("The eulerian cycle is: \n");
        eulerian_cycle_array = (int*)calloc( number_of_nodes + 1, sizeof(int) );
        cycle_lenght = 0;
        eulerian_cycle_array[0] = root;
        cycle_lenght++;
        find_cycle( root );
        print_cycle();
    }else
        printf("No cycle available!");

    return 0;
}
