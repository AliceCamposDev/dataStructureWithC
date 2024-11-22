#include <stdio.h>
#include <stdbool.h>

int main()
{
    int matrix[4][4];
    int num;
    bool found;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("digite o numero da posição %dx%d\n", i, j);
            scanf(" %d", &matrix[i][j]);
        }
    }

    printf("qual número deseja checar se está na matriz?");
    scanf("%d", &num);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (matrix[i][j] == num)
            {
                found = true;
                printf("número foi encontrado na posição %dx%d\n", i, j);
            }
        }
    }
    if (!found)
    {
        printf("o número não foi encontrado na matriz\n");
    }
    return 1;
}