// 2, 7, 3, 4, 21, 12, 8, 63, 48, 16, 189, 192, 32, 567, 768...

#include <stdio.h>

int main()
{
    int n;
    printf("Até qual casa deseja exibir a sequencia? ");
    scanf("%d", &n);
    int aux1 = 2;
    int aux2 = 7;
    int aux3 = 3;
    for (int i = 3; i <= n + 3; i++)
    {
        if (i % 3 == 0)
        {
            printf("%d ", aux1);
            aux1 *= 2;
        }
        else
        {
            if (i % 3 == 1)
            {
                printf("%d ", aux2);
                aux2 *= 3;
            }
            else
            {
                printf("%d ", aux3);
                aux3 *= 4;
            }
        }
    }

    return 0;
}