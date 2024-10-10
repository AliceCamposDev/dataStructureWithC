#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int code;
    int vehiclesNum;
    int accidentsNum;
} city;

int main()
{
    int citiesNum = 5;
    city *cities = (city *)malloc(citiesNum * sizeof(city)); // Alocação dinâmica
    if (cities == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int accidentsTotal = 0;
    int vehiclesTotal = 0;
    int safeCities = 0;
    int safeCitiesAccidents = 0;

    for (int i = 0; i < citiesNum; i++)
    {
        printf("Digite o código da cidade %d: ", i + 1);
        scanf("%d", &cities[i].code);
        printf("Digite o número de veículos de passeio da cidade %d: ", i + 1);
        scanf("%d", &cities[i].vehiclesNum);
        printf("Digite o número de acidentes de trânsito com vítimas da cidade %d: ", i + 1);
        scanf("%d", &cities[i].accidentsNum);

        vehiclesTotal += cities[i].vehiclesNum;
        accidentsTotal += cities[i].accidentsNum;

        if (cities[i].vehiclesNum < 2000)
        {
            safeCitiesAccidents += cities[i].accidentsNum;
            safeCities++;
        }
    }

    int maxAccidents = cities[0].accidentsNum;
    int minAccidents = cities[0].accidentsNum;
    int cityWithMaxAccidents = 0;
    int cityWithMinAccidents = 0;

    for (int i = 1; i < citiesNum; i++)
    {
        if (cities[i].accidentsNum > maxAccidents)
        {
            maxAccidents = cities[i].accidentsNum;
            cityWithMaxAccidents = i;
        }
        if (cities[i].accidentsNum < minAccidents)
        {
            minAccidents = cities[i].accidentsNum;
            cityWithMinAccidents = i;
        }
    }

    double averageVehicles = (double)vehiclesTotal / citiesNum;
    double averageAccidentsSafeCities = (safeCities > 0) ? (double)safeCitiesAccidents / safeCities : 0;
    printf("\n--------------------------------------------------------------\n");
    printf("Maior índice de acidentes: %d na cidade %d\n", maxAccidents, cities[cityWithMaxAccidents].code);
    printf("Menor índice de acidentes: %d na cidade %d\n", minAccidents, cities[cityWithMinAccidents].code);
    printf("Média de veículos nas cinco cidades: %.2f\n", averageVehicles);
    printf("Média de acidentes nas cidades com menos de 2000 veículos: %.2f\n", averageAccidentsSafeCities);

    free(cities);

    return 0;
}
