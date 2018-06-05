#include <stdio.h>

struct list_node{
    int info;
    struct list_node *next;
};

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


void rosenstiehl( int number_of_nodes, int **adjacency_matrix, int root, struct list_node *head, struct list_node *cycle_head ) {

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


int main(){

    struct list_node *head = malloc(sizeof(struct list_node));
    head->next = NULL;
    struct list_node *cycle_head = malloc(sizeof(struct list_node));
    cycle_head->next = NULL;


    int iterator1,iterator2;
    int **adjacency_matrix;
    int is_edge;
    int number_of_nodes;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &number_of_nodes);
    printf("\nThe nodes IDs range from 0 to %d\n", number_of_nodes - 1);

    adjacency_matrix = (int**)calloc( number_of_nodes, sizeof(int) );
    for ( iterator1 = 0; iterator1 < number_of_nodes; iterator1++ )
        adjacency_matrix[iterator1] = (int**)calloc( number_of_nodes, sizeof(int) );

    for( iterator1 = 0; iterator1 < number_of_nodes; iterator1++){
        for( iterator2 = 0; iterator2 < number_of_nodes; iterator2++ ){
            scanf("%d", &is_edge);
            if ( iterator1 == iterator2 )
                adjacency_matrix[iterator1][iterator2] = 0;
            else
                adjacency_matrix[iterator1][iterator2] = is_edge;
        }
        printf("\n\n");
    }

    int root = 0;
    rosenstiehl(number_of_nodes, adjacency_matrix, root, head, cycle_head);
    printf("\nThe eulerian cycle is: ");
    print_list(cycle_head);

    free(head);
    free(cycle_head);
    free(adjacency_matrix);

    return 0;
}
