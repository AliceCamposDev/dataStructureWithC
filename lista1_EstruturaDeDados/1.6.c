#include <stdio.h>
#include <stdbool.h>

int main()
{
    double num;
    double sum = 0.0;
    double min = 0.0;
    double max = 0.0;
    int count = 0;
    bool first = 1;
    double evenSum = 0.0;
    int evenCount = 0;
    int oddCount = 0;

    printf("Digite os números (digite 30000 para finalizar):\n");

    while (1)
    {

        scanf("%lf", &num);

        if (num == 30000)
        {
            break;
        }

        if (first)
        {
            max = num;
            min = num;
            first = 0;
        }

        sum += num;
        count++;

        if (num > max)
        {
            max = num;
        }
        if (num < min)
        {
            min = num;
        }

        if ((int)num % 2 == 0)
        {
            evenSum += num;
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }

    double average = sum / count;                                        
    double evenAverage = (evenCount > 0) ? evenSum / evenCount : 0;      
    double oddPercentage = (count > 0) ? (oddCount * 100.0 / count) : 0;

    printf("\n----------------------------------------------------\n");
    printf("Soma: %.2f\n", sum);
    printf("Números digitados: %d\n", count);
    printf("Média: %.2f\n", average);
    printf("Maior número: %.2f\n", max);
    printf("Menor número: %.2f\n", min);
    printf("Média dos pares: %.2f\n", evenAverage);
    printf("Porcentagem dos ímpares: %.2f%%\n", oddPercentage);

    return 0;
}