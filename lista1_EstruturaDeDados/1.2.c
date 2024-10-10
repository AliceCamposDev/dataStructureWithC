// formula: E = 1 + 1/1! + 1/2! + 1/3! + ... + 1/N!

#include <stdio.h>

int factorial(int num)
{
    int result = 1;
    if (num < 1)
        return 0;
    for (; num >= 1; num--)
    {
        result *= num;
    }
    return result;
}

int main()
{
    int num;
    double e = 1.0;
    printf("Insira um número para aplicar a fórmula:\nE = 1 + 1/1! + 1/2! + 1/3! + ... + 1/N!\n");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        e += 1.0 / factorial(i);
    }
    printf("o resultado é %f", e);

    return 0;
}
