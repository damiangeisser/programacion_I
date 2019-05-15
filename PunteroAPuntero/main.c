#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(int* punteroInt, int** punteroPunteroInt);

int main()
{

    int a = 10;
    int *punteroInt;
    int **punteroPuntero;
    punteroInt = &a;
    punteroPuntero = &punteroInt;

    mostrarCadena(punteroInt, punteroPuntero);


    return 0;
}

void mostrarCadena(int* punteroInt, int** punteroPunteroInt)
{
        printf("\t%p",punteroInt);

        printf("\t%d",*punteroInt);

        printf("\t%p",punteroPunteroInt);

        printf("\t%d",**punteroPunteroInt);
}
