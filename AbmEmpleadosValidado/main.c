#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#ifndef empleados_H_INCLUIDA//Para evitar que el compilador tire error por incluir varias veces la misma biblioteca del usuario.
#define empleados_H_INCLUIDA

#include "empleados.h"

#endif // empleados_H_INCLUIDA

#define TAM_EMP 11
#define TAM_SEC 5

int main()
{
    char seguir = 's';
    char confirma;
    //eEmpleado listaEmpleados[TAM_EMP];
    eEmpleado listaEmpleados[TAM_EMP]= {{1105, "Juan", 'm', 30000, 2,10,2002,2, 1},
        {1236, "Ana", 'f', 32000,25,6,2015,1, 1},
        {1110, "Pedro", 'm', 32000,10,10,2013,4, 1},
        {1185, "Jose", 'm', 34000,25,6,2003,2, 1},
        {1396, "Maria", 'f', 35000,15,8,2010,4, 1},
        {1180, "Jorge", 'm', 28000,11,12,2008,3, 1},
        {1103, "Carla", 'f', 33000,21,6,2015,3, 1},
        {1001, "Martin", 'm', 33000,3,7,2011,3, 1},
        {1253, "Hernan", 'm', 38000,7,3,2004,5, 1},
        {1118, "Aldana", 'f', 35000,12,9,2008,5, 1}
    };
    //inicializarEmpleados(listaEmpleados, TAM_EMP);

    eSector listaSectores[]= {{1, "Sistemas"},{2, "RR HH"},{3,"Compras"},{4,"Ventas"},{5, "Legales"}};

    do
    {
        switch(menu())
        {

        case 1:

            altaEmpleado(listaSectores, TAM_SEC, listaEmpleados, TAM_EMP);
            system("pause");
            break;

        case 2:

            bajaEmpleado(listaSectores, TAM_SEC, listaEmpleados, TAM_EMP);
            system("pause");
            break;

        case 3:
            modificarEmpleado(listaSectores, TAM_SEC, listaEmpleados, TAM_EMP);
            system("pause");
            break;

        case 4:

            //ordenarEmpleadosAZ(listaEmpleados,TAM_EMP);
            ordenarEmpleadosLegajoAZ(listaEmpleados, TAM_EMP);
            system("pause");
            break;

        case 5:
            mostrarEmpleados(listaSectores, TAM_SEC, listaEmpleados, TAM_EMP);
            system("pause");
            break;

        case 6:
            mostrarSectores(listaSectores, TAM_SEC);
            system("pause");
            break;

        case 7:
            mostrarSectoresConEmpleados(listaSectores, TAM_SEC, listaEmpleados, TAM_EMP);
            system("pause");
            break;
        case 8:
            censoSectores(listaSectores, TAM_SEC, listaEmpleados, TAM_EMP);
            system("pause");
            break;
        case 9:
            listarSectorSeleccionado(listaSectores, TAM_SEC, listaEmpleados, TAM_EMP);
            system("pause");
            break;
        case 10:
            printf("\nConfirma la salida del programa? s/n: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                printf("\n\n- Programa finalizado -\n");
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
        }
    }
    while(seguir == 's');

    return 0;
}

