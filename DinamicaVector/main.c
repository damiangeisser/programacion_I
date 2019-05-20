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
        exit(1);//Me saca de la ejecuci�n del programa. Devuelve 1 al OS �No utilizar en funciones!
    }

    for(int i = 0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", pNum+i);
    }

    printf("\nUsted ingreso:\n");

    for(int i = 0; i<5; i++)
    {
        printf("%d\n", *(pNum+i));
    }

    pAux = realloc(pNum,sizeof(int)*10);

    if(pAux!=NULL){

        pNum = pAux;
    }

     printf("\n-- Cambio tamanio --\n\n");

    for(int i = 5; i<10; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", pNum+i);
    }

    printf("\nUsted ingreso:\n");

    for(int i = 0; i<10; i++)
    {
        printf("%d\n", *(pNum+i));
    }

    //printf("%d", sizeof(*pNum));

    free(pNum);//Libera la memoria pedida con malloc.

    return 0;
}
