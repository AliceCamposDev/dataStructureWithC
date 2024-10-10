#include <stdio.h>

int main()
{

    const int studentsNum = 6;
    double grades[studentsNum][2];
    double averages[studentsNum];

    int approved = 0, recovery = 0, failed = 0;

    double sumAverages = 0.0;

    for (int i = 0; i < studentsNum; i++)
    {
        printf("Digite as notas o aluno %d:\n", i + 1);
        printf("Nota 1: ");
        scanf("%lf", &grades[i][0]);
        printf("Nota 2: ");
        scanf("%lf", &grades[i][1]);

        averages[i] = (grades[i][0] + grades[i][1]) / 2.0;
        sumAverages += averages[i];

        if (averages[i] < 3)
        {
            failed++;
        }
        else if (averages[i] >= 3 && averages[i] < 7)
        {
            recovery++;
        }
        else
        {
            approved++;
        }
    }

    double classAverage = sumAverages / studentsNum;

    printf("\n--------------------------------------\n");
    printf("Alunos aprovados: %d\n", approved);
    printf("Alunos em recuperação: %d\n", recovery);
    printf("Alunos reprovados: %d\n", failed);
    printf("Média total: %.2f\n", classAverage);

    return 0;
}
