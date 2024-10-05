// fazendo isso aqui de novo porque perdi o arquivo

#include <stdio.h>

int factorial(int num){
    printf("%d", num);
    int result = 1;
    if (num < 1)
        return 0;
    for(;num >= 1; num --){
        result *= num;
    }
    return result;
}

int main()
{
    char choice;

    printf("Selecione uma opção abaixo:\n");
    printf("A- Calcular o fatorial de um número\n");
    fflush(stdout);
    scanf("%c", &choice);

    switch (choice)
    {
    case 'A':
    case 'a':
        int num;
        printf("Insira o número que deseja calcular o fatorial: ");
        scanf("%d", &num);
        printf("O fatorial de %d é %d", num, factorial(num));
        break;

    default:
        break;
    }

    return 0;
}
