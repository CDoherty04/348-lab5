#include <stdio.h>

#define SIZE 5

// This function should take two matrices as input and return their sum
int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    return 0;
}

// This function should take two matrices as input and return their product
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    return 0;
}

// This function should take a matrix as input and return its transpose
int transposeMatrix(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    return 0;
}

// This function should take a matrix as input and print it in a user-friendly format
void printMatrix(int m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
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

    // addMatrices(m1, m2);
    // multiplyMatrices(m1, m2);
    // transposeMatrix(m1, m2);
    printf("\nPrinting Matrix 1:\n");
    printMatrix(m1);
    printf("\nPrinting Matrix 2:\n");
    printMatrix(m2);
}