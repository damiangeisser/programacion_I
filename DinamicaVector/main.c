#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pNum;
    int* pAux;


    pNum = (int*) malloc(sizeof(int)*5);//Espacio para un vector de 5 enteros.

    if(pNum == NULL)//Verifico que haya encontrado memoria.
    {
        printf("\nNo se consiguio memoria\n");
        system("pause");
        exit(1);//Me saca de la ejecución del programa. Devuelve 1 al OS ¡No utilizar en funciones!
    }

    for(int i = 0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", pNum+i);
    }

    printf("\nUsted ingreso:\n");

    for(int i = 0; i<5; i++)
    {
        printf("%d ", *(pNum+i));
    }

    pAux = realloc(pNum,sizeof(int)*10);

    if(pAux!=NULL)
    {
        pNum = pAux;

        printf("\n\n-- Aumento el tamanio --\n\n");

        for(int i = 5; i<10; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", pNum+i);
        }
    }

    printf("\nUsted ingreso:\n");

    for(int i = 0; i<10; i++)
    {
        printf("%d ", *(pNum+i));
    }

    printf("\n\n-- Reduzco el tamanio --\n\n");

    pNum = realloc(pNum,sizeof(int)*4);//Achico el array.

    for(int i = 0; i<10; i++) //Muestro las 10 posiciones. Puede aparecer basura.
    {
        printf("%d ", *(pNum+i));
    }

    int* vec;

    vec = (int*) calloc(10,sizeof(int)*10);//Crea un array inicializado en cero.

    for(int i = 0; i<10; i++)
    {
        printf("%d ", *(vec+i));
    }

    free(pNum);//Libera la memoria pedida con malloc.

    return 0;
}
