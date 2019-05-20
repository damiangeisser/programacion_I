#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* pNum;

    pNum = (int*) malloc(sizeof(int));//Si no consigue espacio devuelve NULL (no dirección de memoria). Se castea para convertirlo.

    if(pNum == NULL)//Verifico que haya encontrado memoria.
    {
        printf("\nNo se consiguio memoria\n");
        system(pause);
        exit(1);//Me saca de la ejecución del programa. Devuelve 1 al OS.
    }

    *pnum = 10;

    return 0;
}
