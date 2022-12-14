#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(){
    int **matrix = (int **) malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++)
    {
        matrix[i] = (int *) malloc(SIZE * sizeof(int));
    }

    while(1){
        char c = ' ';
        scanf("%c", &c);

        if(c == 'A'){
            function_1(matrix);
            /*printf("\n");
            for(int y = 0; y < SIZE; y++){
                for(int x = 0; x < SIZE; x++){
                    printf("%d," , matrix[y][x]);
                }
                printf("\n");
            }*/
        }
        else if(c == 'B'){
            int i = 0, j = 0;
            scanf("%d", &i);
            scanf("%d", &j);

            int ans = function_2(matrix, i, j);
            
            if(ans == 1) printf("True\n");
            else printf("False\n");
            //printf("\n%d->%d = %d", i,j,ans);
        }
        else if(c == 'C'){
            int i = 0, j = 0;
            scanf("%d", &i);
            scanf("%d", &j);

            int ans = function_3(matrix, i, j);
            //printf("\n%d->%d = %d", i,j,ans);
            printf("%d\n", ans);
        }
        else if(c == 'D'){
            break;
        }
    }

    for (int i = 0; i < SIZE; i++)
        free(matrix[i]);
    free(matrix);
    return 0;
}

