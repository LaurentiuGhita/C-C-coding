#include <stdio.h>


void rotateMatrix90(int** matrix, int dim)
{
    matrix[0][0] = 100;
}

void printMatrix(int** matrix, int dim)
{
    int i,j;
    for(i = 0; i < dim; ++i)
    {
        for(j = 0; j < dim; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void readMatrix(int** matrix, int dim)
{
    int i,j;
    for(i = 0; i < dim; ++i)
    {
        for(j = 0; j < dim; ++j)
            scanf("%d ", &matrix[i][j]);
    }   
}

int main()
{
    int dim;
    printf("Dimension = "); scanf("%d", &dim);
    
    int i;
    int** matrix = malloc(dim * sizeof(int*));
    for(i = 0; i < dim; ++i)
        matrix[i] = malloc(dim * sizeof(int));

    readMatrix(matrix,dim);
    rotateMatrix90(matrix,dim);
    printMatrix(matrix, dim);
}
