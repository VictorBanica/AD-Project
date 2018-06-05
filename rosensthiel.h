#ifndef ROSENSTHIEL_H_INCLUDED
#define ROSENSTHIEL_H_INCLUDED

void rosenstiehl( int number_of_nodes, int **adjacency_matrix, int root, struct list_node *head, struct list_node *cycle_head );
int test_for_cycle( int number_of_nodes, int **adjacency_matrix );

#endif // ROSENSTHIEL_H_INCLUDED
