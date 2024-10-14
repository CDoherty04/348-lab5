#include <stdio.h>

#define SIZE 5

// This function should take two matrices as input and return their sum
int (*addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE]
{
    static int localSumMatrix[SIZE][SIZE];

    // Find the sum matrix
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            localSumMatrix[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return localSumMatrix;
}

// This function should take two matrices as input and return their product
int (*multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE]
{
    static int localProductMatrix[SIZE][SIZE];

    // Find the product matrix
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            localProductMatrix[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
            {
                localProductMatrix[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return localProductMatrix;
}

// This function should take a matrix as input and return its transpose
int (*transposeMatrix(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE]
{
    return 0;
}

// This function should take a matrix as input and print it in a user-friendly format
void printMatrix(int m[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}};

    // Display original matricies
    printf("\nMatrix 1:\n");
    printMatrix(m1);
    printf("\nMatrix 2:\n");
    printMatrix(m2);

    // Display Matrix Addition
    int(*sumMatrix)[SIZE] = addMatrices(m1, m2);
    printf("\nSum of Matrix 1 and Matrix 2:\n");
    printMatrix(sumMatrix);

    // Display Matrix Multiplication
    int(*multipliedMatrix)[SIZE] = multiplyMatrices(m1, m2);
    printf("\nProduct of Matrix 1 and Matrix 2:\n");
    printMatrix(multipliedMatrix);

    // transposeMatrix(m1, m2);

    return 0;
}