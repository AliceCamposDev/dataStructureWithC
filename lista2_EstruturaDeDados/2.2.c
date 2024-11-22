#include <stdio.h>

int main()
{
    int matrix1[3][3] = {
        {9, 5, 3},
        {7, 2, 10},
        {6, 4, 1}};

    int matrix2[3][3] = {
        {8, 3, 6},
        {5, 1, 9},
        {4, 7, 2}};
    int sum[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 1;
}