#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char name[100];
    int finalGrade;
    bool approved;
} Student;

int validateNumber()
{
    int num;
    do
    {
        printf("Escolha um nmero entre 1 e 10: ");
        scanf("%d", &num);
    } while (num < 1 || num > 10);
    return num;
}

void registerName(char *name)
{
    printf("Digite o nome do aluno: ");
    getchar();
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';
}

void registerGrade(Student *student)
{
    do
    {
        printf("Digite a nota do aluno entre 0 e 100: ");
        scanf("%d", &student->finalGrade);
    } while (student->finalGrade < 0 || student->finalGrade > 100);
}

void registerStatus(int grade, bool *approved)
{
    if (grade >= 60)
    {
        *approved = true;
    }
    else
    {
        *approved = false;
    }
}

void registerStudents(Student *students, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nDados do estudante %d:\n", i + 1);
        registerName(students[i].name);
        registerGrade(&students[i]);
        registerStatus(students[i].finalGrade, &students[i].approved);
    }
}

void displayAllStudents(Student *students, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Nome: %s, Nota: %d, Status: %s\n", students[i].name, students[i].finalGrade, students[i].approved ? "Aprovado" : "Reprovado");
    }
}

void displayByStatus(Student *students, int size, char status)
{
    bool found = false;
    printf("\nEstudantes %s:\n", (status == 'A' ? "aprovados" : "reprovados"));
    for (int i = 0; i < size; i++)
    {
        if (status == 'A' && students[i].approved)
        {

            printf("Nome: %s, Nota: %d, Aprvado", students[i].name, students[i].finalGrade);
            found = true;
        }
        else
        {
            if (status == 'R' && !students[i].approved)
            {
                printf("Nome: %s, Nota: %d, Reprovado", students[i].name, students[i].finalGrade);
                found = true;
            }
        }
    }
    if (!found)
    {
        printf("Nenhum estudante encontrado");
    }
}

float calculateAverage(Student *students, int size)
{
    int sumGrades = 0;
    for (int i = 0; i < size; i++)
    {
        sumGrades += students[i].finalGrade;
    }
    return (size > 0) ? (float)sumGrades / size : 0.0;
}

void menuOption()
{
    Student *students = NULL;
    char option = ' ';

    while (1)
    {
        printf("\nMenu:\n");
        printf("A. preencher dados\n");
        printf("B. Exibir todos os alunos\n");
        printf("C. Exibir alunos aprovados/reprovados\n");
        printf("D. Sair\n");
        printf("Escolha uma das opções acima: ");
        scanf(" %c", &option);

        switch (option)
        {
        case 'A':
        case 'a':
            int numberOfStudents = 0;
            printf("Digite o número de estudantes: ");
            numberOfStudents = validateNumber();
            students = (Student *)malloc(numberOfStudents * sizeof(Student));
            registerStudents(students, numberOfStudents);
            break;

        case 'B':
        case 'b':
            if (students == NULL)
            {
                printf("Nenhum estudante registrado.\n");
            }
            else
            {
                displayAllStudents(students, numberOfStudents);
                printf("Média: %.2f\n", calculateAverage(students, numberOfStudents));
            }
            break;

        case 'C':
        case 'c':
            if (students == NULL)
            {
                printf("Nenhum estudante registrado.\n");
            }
            else
            {
                char status;
                printf("quer mostrar os estudantes aprovados ou reprovados? (A/R) ");
                scanf(" %c", &status);
                displayByStatus(students, numberOfStudents, status);
            }
            break;

        case 'D':
        case 'd':
            if (students != NULL)
            {
                free(students);
            }
            return;

        default:
            printf("Opção não encontrada\n");
        }
    }
}

int main()
{
    menuOption();

    return 0;
}
