// fazendo isso aqui de novo porque perdi o arquivo

#include <stdio.h>
#include <stdbool.h>

int factorial(int num)
{
    printf("%d", num);
    int result = 1;
    if (num < 1)
        return 0;
    for (; num >= 1; num--)
    {
        result *= num;
    }
    return result;
}

int even_sum(int num){
     if (num < 1){
        printf("Escolha um número maior que 0\n");
        return 0;
    }
    int result = 0;

    if (num%2 == 1)
        num--;
    for (; num >= 2; num -= 2)
    {
        result += num;
    }
    return result;
}

bool is_prime_num(int num){
    if (num < 2)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for(int i = (num - 1) / 2; i > 2; i -= 2){
        if (num % i == 0) 
            return false;
    };
    return true;
}

void fibonnacci(int num){

    if (num < 1){
        printf("Escolha um número maior que 0\n");
        return;
    }

    int previous = 1;
    int current = 1;
    int next = 1;
    printf("1");
    for (int i = 1; i < num; i++)
    {
        printf(", %d", current);
        next = current + previous;
        previous = current;
        current = next;
    }
    printf("\n");
}

int main()
{
    char choice;

    printf("Selecione uma opção abaixo:\n");
    printf("A- Calcular o fatorial de um número\n");
    printf("B- Calcular sequencia de fibonnacci até N\n");
    printf("C- Somar pares existentes entre 1 e N\n");
    printf("D- Verificar se N é primo\n");
    fflush(stdout);
    scanf("%c", &choice);
    int num;

    switch (choice)
    {
    case 'A':
    case 'a':
        printf("Insira o número que deseja calcular o fatorial: ");
        scanf("%d", &num);
        printf("O fatorial de %d é %d\n", num, factorial(num));
        break;

    case 'B':
    case 'b':
        
        printf("Até que número deseja calcular a sequencia de fibonnacci? ");
        scanf("%d", &num);
        fibonnacci(num);
        break;

    case 'C':
    case 'c':
        
        printf("Até que número deseja calcular a soma dos pares? ");
        scanf("%d", &num);
        printf("A soma é igual a %d\n", even_sum(num));
        break;

    case 'D':
    case 'd':
        
        printf("Qual número quer verificar se é primo? ");
        scanf("%d", &num);
        printf("%d", num);
        !is_prime_num(num) ? printf(" não é um número primo\n") : printf(" é um número primo\n");
        break;

    default:
        break;
    }

    return 0;
}
