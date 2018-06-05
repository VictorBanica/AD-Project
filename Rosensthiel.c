#include <stdio.h>
#define MAXNODES 25
#include <time.h>

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


int main(){
    srand(time(0));

    struct list_node *head = malloc(sizeof(struct list_node));
    head->next = NULL;
    struct list_node *cycle_head = malloc(sizeof(struct list_node));
    cycle_head->next = NULL;


    int iterator1,iterator2;
    int **adjacency_matrix;
    int is_edge;
    int number_of_nodes;
    int option;

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

                number_of_nodes = rand() % MAXNODES;

                adjacency_matrix = (int**)calloc( number_of_nodes, sizeof(int) );
                for ( iterator1 = 0; iterator1 < number_of_nodes; iterator1++ )
                    adjacency_matrix[iterator1] = (int**)calloc( number_of_nodes, sizeof(int) );

                for( iterator1 = 0; iterator1 < number_of_nodes; iterator1++ )
                    for( iterator2 = 0; iterator2 < number_of_nodes; iterator2++ )
                        if ( iterator1 != iterator2 )
                           adjacency_matrix[iterator1][iterator2] = adjacency_matrix[iterator2][iterator1] = rand() % 2;
                        else
                           adjacency_matrix[iterator1][iterator2] = 0;

                printf("\nThe random input data have been generated!");
                break;

            case 3:
                printf("\nThe number of nodes is: %d\n\n", number_of_nodes);
                printf("The adjacency matrix is: \n\n");
                for(iterator1 = 0; iterator1 < number_of_nodes; iterator1++){
                    for(iterator2 = 0; iterator2 < number_of_nodes; iterator2++)
                        printf("%d ", adjacency_matrix[iterator1][iterator2]);
                    printf("\n");
                }
                break;

            case 4:
                if(test_for_cycle(number_of_nodes, adjacency_matrix)){

                    int root = 0;
                    rosenstiehl(number_of_nodes, adjacency_matrix, root, head, cycle_head);
                    printf("\nThe eulerian cycle is: ");
                    print_list(cycle_head);
                }else
                    printf("\nThe graph has no eulerian cycle!");
                break;

            case 5:
                printf("Fleury...");
                break;
            case 6:
                return 0;
            default:
                printf("Wrong option!\n");
            }
    }while ( option != 6 );


    free(head);
    free(cycle_head);
    free(adjacency_matrix);

    return 0;
}
