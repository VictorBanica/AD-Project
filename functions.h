#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int number_of_nodes;
int cycle_lenght;
int *nodes_array;
int *eulerian_cycle_array;
char **adjacency_matrix;

int get_node_index( int node );
int get_node_degree( int node );
int test_for_cycle();
int node_has_one_edge( int node );
int is_last_node( int node );
int get_next_node( int node );
int visit_all_nodes();
void delete_edge( root , next_node );
void find_cycle( int root );
void print_cycle();

#endif // FUNCTIONS_H_INCLUDED
