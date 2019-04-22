#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "empleados.h"

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}
//-----------------------------------------------------------
int menu()
{
    int opcion;

    system("cls");
    printf("  --- ABM Empleados ---\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
//-----------------------------------------------------------
void mostrarEmpleado(eSector sectores[], int tamSectores, eEmpleado emp)
{
    char descSector[20];

    obtenerSector(sectores, tamSectores, emp.idSector, descSector);

    printf("%d\t%s\t%c\t%.2f\t%02d/%02d/%d\t%s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaNac.dia, emp.fechaNac.mes, emp.fechaNac.anio, descSector);

}
//-----------------------------------------------------------
void mostrarEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
{
    int contador = 0;

    printf("\nLegajo\tNombre\tSexo\tSueldo\t\tFecha de ingreso\tSector\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(sectores, tamSectores, vec[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}
//-----------------------------------------------------------
int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
//-----------------------------------------------------------
int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
//-----------------------------------------------------------
void altaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
{

    int indice;
    int legajo;
    int esta;

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n\n");
    }
    else
    {
        printf("Ingrese el nº de legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n\n", legajo);
            mostrarEmpleado(sectores, tamSectores, vec[esta]);
        }
        else
        {
            vec[indice].legajo = legajo;

            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese el sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);
            vec[indice].sexo=toupper(vec[indice].sexo);

            printf("Ingrese el sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            printf("Ingrese el dia de nacimiento: ");
            scanf("%d", &vec[indice].fechaNac.dia);

            printf("Ingrese el mes de nacimiento: ");
            scanf("%d", &vec[indice].fechaNac.mes);

            printf("Ingrese el ano de nacimiento: ");
            scanf("%d", &vec[indice].fechaNac.anio);

            printf("Ingrese el codigo del sector: ");
            scanf("%d", &vec[indice].idSector);

            vec[indice].ocupado = 1;

            printf("\nEmpleado dado de alta exitosamente.\n\n");
        }

    }
}
//-----------------------------------------------------------
void bajaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
{
    int legajo;
    int indice;
    char baja;

    printf("\nIngrese legajo del empleado a dar de baja: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(vec, tam, legajo);

    if( indice == -1)
    {

        printf("\nNo existe un empleado con ese legajo.\n\n");
    }
    else
    {
        mostrarEmpleado(sectores, tamSectores, vec[indice]);
        printf("\nDesea dar de baja al empleado s/n: ");
        baja = getche();
        if(tolower(baja)=='s')
        {
            vec[indice].ocupado=0;
            printf("\nEmpleado dado de baja exitosamente.\n\n");
        }
    }

}
//-----------------------------------------------------------
void modificarEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
{
    int legajo;
    int indice;
    char baja;

    printf("\nIngrese legajo del empleado a modificar: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(vec, tam, legajo);

    if( indice == -1)
    {
        printf("\nNo existe un empleado con ese legajo.\n\n");
    }
    else
    {
        mostrarEmpleado(sectores, tamSectores, vec[indice]);
        printf("\nDesea modificar este empleado s/n: ");
        baja = getche();
        if(tolower(baja)=='s')
        {
            printf("\nIngrese el nuevo sueldo: ");
            scanf("%f",&vec[indice].sueldo);
            printf("\nSueldo modificado exitosamente.\n\n");
        }
    }
}
//-----------------------------------------------------------
void ordenarEmpleadosAZ(eEmpleado vec[], int tam)
{
    eEmpleado auxEmp;

    for(int i=0; i<TAM-1; i++)
    {
        for(int j=i+1; j<TAM; j++)
        {
            if(strcmp(vec[i].nombre, vec[j].nombre)>0)//si las cadenas son iguales retornara 0, si la primera es mayor retornara un valor positivo y si es menor retornara un valor negativo.
            {
                auxEmp = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmp;
            }
        }
    }

}
