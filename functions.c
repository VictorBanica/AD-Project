#include <stdio.h>
#include <conio.h>
#include "functions.h"

int get_node_index( int node ){

    int iterator = 0;

    while ( node != nodes_array[iterator] )
        iterator++;

    return iterator;
}

int get_node_degree( int node ){

    int iterator;
    int degree = 0;
    int index = get_node_index( node );

    for ( iterator = 0; iterator < number_of_nodes; iterator++ )
        if ( adjacency_matrix[index][iterator] ==  'y' )
            degree++;

    return degree;
}

int test_for_cycle(){

     int iterator;
     int has_cycle = 1;

     for ( iterator = 0; iterator < number_of_nodes; iterator++){
        if ( ( get_node_degree( nodes_array[iterator] ) % 2 ) != 0 ){
            has_cycle = 0;
            break;
        }
     }
     return has_cycle;
}

int node_has_one_edge( int node ){

    if ( get_node_degree( node ) == 1 )
        return 1;
    else
        return 0;
}

int is_last_node( int node ){

    int iterator;
    int sum_of_degrees = 0;

    for ( iterator = 0; iterator < number_of_nodes; iterator++ )
        sum_of_degrees = sum_of_degrees + get_node_degree( nodes_array[iterator] );

    if ( sum_of_degrees == 2 )
        return 1;
    else
        return 0;
}

int get_next_node( int node ){

    int iterator;
    int index = get_node_index( node );

    for ( iterator = 0; iterator < number_of_nodes; iterator++ ){
        if ( adjacency_matrix[index][iterator] == 'y' )
            if ( !node_has_one_edge( nodes_array[iterator] ) )
                return nodes_array[iterator];
        else if ( is_last_node( nodes_array[iterator] ))
                return nodes_array[iterator];
    }
    return -1;
}

int visit_all_nodes(){

    int iterator = 0;

    for ( iterator = 0; iterator < number_of_nodes; iterator++)
        if ( get_node_degree( nodes_array[iterator] ) > 0 )
            return 0;

    return 1;
}

void delete_edge( root , next_node )
{
     int index1 = get_node_index( root );
     int index2 = get_node_index( next_node );

     adjacency_matrix[index1][index2] = 'n';
     adjacency_matrix[index2][index1] = 'n';
}


void find_cycle( int root ){

     int next_node;

     while ( !visit_all_nodes() ){

        next_node = get_next_node( root );
        eulerian_cycle_array[cycle_lenght++] = next_node;
        delete_edge( root, next_node );
        root = next_node;
     }
}

void print_cycle(){

    int iterator;

    for ( iterator = 0; iterator < cycle_lenght; iterator++ ){
        if ( iterator != cycle_lenght - 1 )
            printf( "%d -> ", eulerian_cycle_array[iterator] );
        else
            printf( "%d;", eulerian_cycle_array[iterator] );
     }
}
