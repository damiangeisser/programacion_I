#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "inputDin.h"
#include "empleadosDin.h"

#define PATH	".\\bin.dat"
#define ESC 27

int main()
{
char exitChar='n';

     do
    {
        switch(menu())
        {

        case 1:

            //printf("\nAlta empleado\n");
            altaEmpleado(PATH);
            system("pause");
            break;

        case 2:

            printf("\nBaja empleado\n");
            system("pause");
            break;

        case 3:
            //printf("\nModificar empleado\n");
            //buscarEmpleado(PATH);
            system("pause");
            break;

        case 4:
            mostrarEmpleados(PATH);
            system("pause");
            break;

        case 5:
            printf("\nConfirma la salida del programa? s/n: ");
            fflush(stdin);
            exitChar = getche();

            if(tolower(exitChar) == 's')
            {
                printf("\n\n- Programa finalizado -\n");
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
        }
    }
    while(exitChar != 's');

    return 0;
}
