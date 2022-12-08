#include <stdio.h>
#include <stdlib.h>

#define INF 0
#define SIZE 10
void function_1(int **matrix);
int function_2(int **matrix, int i, int j);
int function_3(int **matrix, int i, int j);

/// @param final_matrix pass empty matrix, returns 2D matrix
void function_1(int **final_matrix){
    int *matrix = (int *) malloc(SIZE * SIZE * sizeof(int));

    int size = 1; //array size

    int next_addition = 3; //how many slots to add to the 1D array next size inc
    int current_2d_size = 1; //current size after converting to 2D array 

    int num_elements = 0;
    int value;

    //Keep reading values until the user enters a non-integer value
    while (scanf("%d", &value) == 1)
    {
        //inc current number of elemts in array
        num_elements++;

        // If the matrix is full, reallocate memory to make it larger
        if (num_elements > current_2d_size * current_2d_size)
        {
            size = size + next_addition; //inc 1d array size
            current_2d_size++;
            next_addition += 2;

            matrix = realloc(matrix, size * sizeof(int));
        }

        // Store the value in the matrix
        matrix[num_elements - 1] = value;
    }
    
    //fill 2d matrix, convert from 1D to 2D
    for(int y = 0; y < current_2d_size; y++){
        for(int x = 0; x < current_2d_size; x++){
            final_matrix[y][x] = matrix[y * current_2d_size + x];
        }
    }

    free(matrix);
}

/// @param size matrix width/height (NxN)
/// @param matrix 2D [SIZE][SIZE] matrix 
/// @return 1 if there is a path, 0 otherwise
int function_2(int **matrix, int i, int j)
{
    if(i == j) return 0;

    // distances array to store the shortest distance
    // from each node to every other node in the graph
    int **distances = (int**) malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++)
    {
        distances[i] = (int*) malloc(SIZE * sizeof(int));
    }

    // initialize the distances array
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            distances[i][j] = matrix[i][j];

    // run the Floyd-Warshall algorithm
    for (int k = 0; k < SIZE; k++)
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (((distances[i][j] == INF && distances[i][k] + distances[k][j] != INF) ||
                    (distances[i][k] + distances[k][j] < distances[i][j])) && 
                        distances[i][k] != INF && distances[k][j] != INF)
                    distances[i][j] = distances[i][k] + distances[k][j];


    int ret = distances[i][j] != INF;

    // free the memory
    for (int i = 0; i < SIZE; i++)
        free(distances[i]);
    free(distances);

    // return true if there is a path between i and j
    // and false otherwise
    return ret;
}

int function_3(int **matrix, int i, int j)
{
    if(i == j) return -1;

    // distances array to store the shortest distance
    // from each node to every other node in the graph
    int **distances = (int**) malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++)
    {
        distances[i] = (int*) malloc(SIZE * sizeof(int));
    }

    // initialize the distances array
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            distances[i][j] = matrix[i][j];

    // run the Floyd-Warshall algorithm
    for (int k = 0; k < SIZE; k++)
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (((distances[i][j] == INF && distances[i][k] + distances[k][j] != INF) ||
                    (distances[i][k] + distances[k][j] < distances[i][j])) && 
                        distances[i][k] != INF && distances[k][j] != INF)
                    distances[i][j] = distances[i][k] + distances[k][j];

    int ret = distances[i][j];

    // free the memory
    for (int i = 0; i < SIZE; i++)
        free(distances[i]);
    free(distances);
    
    // return the distance
    // and false otherwise
    if(ret == 0) return -1;
    return ret;
}
