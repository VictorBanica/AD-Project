#include <stdio.h>

int number_of_nodes;
int cycle_lenght;
int *nodes_array;
int eulerian_cycle_array[100];
int **adjacency_matrix;


struct a_stack{

    int elements[100];
    int top;
};

struct a_stack stack;

void push( int value ){
    if (stack.top == ( number_of_nodes - 1 ))
        printf("Stack is full\n");
    else{
        stack.top = stack.top + 1;
        stack.elements[stack.top] = value;
        printf("Pushed %d\n", value);
    }
}


void pop(){
    if (stack.top == - 1){
        printf ("Stack is empty\n");
    }
    else
        {stack.top = stack.top - 1;
        int aux = stack.elements[stack.top];
        printf("Popped: %d\n ", aux);

}
}

int is_empty(){

  if ( stack.top == -1 )
     return 1;
  else
     return 0;
}


void rosensiehl( int root )
{
    int iterator;
    push( root );
    while ( !is_empty() ){
        root = stack.elements[stack.top];
        pop();
        iterator = 0;
        while ( iterator < number_of_nodes ){
            if ( adjacency_matrix[root][iterator] == 1 ){
                adjacency_matrix[root][iterator] = 0;
                adjacency_matrix[iterator][root] = 0;
                push( root );
                root = iterator;
                iterator = 0;
            }else
                iterator++;
        }

    eulerian_cycle_array[cycle_lenght] = root;
    cycle_lenght++;
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



int main()
{
    int is_edge;
    int iterator1;
    int iterator2;


    stack.top = -1;
    cycle_lenght = 0;


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
            //scanf("%i", &is_edge);
            is_edge=1;
            if ( iterator1 == iterator2 )
                adjacency_matrix[iterator1][iterator2] = 0;
            else
                adjacency_matrix[iterator1][iterator2] = is_edge;
        }
        printf("\n\n");
    }

    rosensiehl(0);
    print_cycle();

}
