#include <stdio.h>

int main()
{
    char choice = '0', choice1 = '0';
    int turn = 1;
    printf("");
    while (1)
    {
        printf("Vez do jogador %d\n", turn);
        printf("Selecione uma opção\n");
        printf("0 - pedra\n");
        printf("1 - papel\n");
        printf("2 - tesoura\n");
        printf("s - sair\n");
        scanf(" %c", &choice);

        if (choice == 's' || choice == 'S')
        {
            break;
        }

        if (choice >= '0' && choice <= '2')
        {
            if (turn == 1)
            {
                choice1 = choice;
                turn++;
            }
            else
            {
                if (choice1 == choice)
                {
                    printf("-> A rodada empatou\n\n");
                }
                else
                {
                    if ((choice == '0' && choice1 == '2') || (choice == '1' && choice1 == '0') || (choice == '2' && choice1 == '1'))
                    {
                        printf("-> Jogador 2 ganhou \n\n");
                    }else{
                        printf("-> Jogador 1 ganhou\n\n");
                    }
                }
                turn = 1;
            }
        }
        else
        {
            printf("Opção inválida\n");
        }
    }

    return 0;
}