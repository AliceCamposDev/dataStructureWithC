#include <stdio.h>

double arithmetic_mean(double numbers[], int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += numbers[i];
    }
    return (sum / n);
}

double weighted_mean(double numbers[], double weights[], int n)
{
    double weighted_sum = 0.0;
    double total_weight = 0.0;

    for (int i = 0; i < n; i++)
    {
        weighted_sum += numbers[i] * weights[i];
        total_weight += weights[i];
    }

    return (total_weight > 0) ? (weighted_sum / total_weight) : 0.0;
}

double harmonic_mean(double numbers[], int n)
{
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += 1.0 / numbers[i];
    }

    return (sum > 0) ? (n / sum) : 0.0; //
}

int main()
{
    int numberQuantity = 3;
    double numbers[numberQuantity];
    double weights[numberQuantity];

    char choice;

    for (int i = 0; i < numberQuantity; i++)
    {
        printf("Digite a %dª nota: ", i + 1);
        scanf("%lf", &numbers[i]);
    }

    printf("Escolha o tipo de média a ser calculada:\n");
    printf("A - Média Aritmética\n");
    printf("B - Média Ponderada\n");
    printf("C - Média Harmônica\n");
    scanf(" %c", &choice);

    switch (choice)
    {
    case 'A':
    case 'a':
        printf("Média Aritmética: %.2f\n", arithmetic_mean(numbers, numberQuantity));
        break;
    case 'B':
    case 'b':

        for (int i = 0; i < numberQuantity; i++)
        {
            printf("Digite o peso da %dª nota: ", i + 1);
            scanf("%lf", &weights[i]);
        }

        printf("Média Ponderada: %.2f\n", weighted_mean(numbers, weights, numberQuantity));
        break;
    case 'C':
    case 'c':
        printf("Média Harmônica: %.2f\n", harmonic_mean(numbers, numberQuantity));
        break;
    default:
        printf("Opção inválida.\n");
    }

    return 0;
}
