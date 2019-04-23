#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#ifndef empleados_H_INCLUIDA
#define empleados_H_INCLUIDA

#include "empleados.h"

#endif

#include "input.h"

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
    printf("6- Listar Sectores\n");
    printf("7- Listar Sectores Con Empleados\n");
    printf("8- Listar Cantidad De Empleados Por Sector\n");
    printf("9- Listar Cantidad De Empleados Por Sector Especifico\n");
    printf("10- salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
//-----------------------------------------------------------
void mostrarEmpleado(eSector sectores[], int tamSectores, eEmpleado emp)
{
    char descSector[20];

    obtenerSector(sectores, tamSectores, emp.idSector, descSector);

    printf("%d\t%s\t%c\t%.2f\t%02d/%02d/%d\t\t%s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIn.dia, emp.fechaIn.mes, emp.fechaIn.anio, descSector);

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
        printf("Ingrese el nro. de legajo: ");
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

//            printf("Ingrese el nombre: ");
//            fflush(stdin);
//            gets(vec[indice].nombre);

            getString(vec[indice].nombre,"Ingrese el nombre: ","Largo del nombre invalido", 2, 20);

//            printf("Ingrese el sexo: ");
//            fflush(stdin);
//            scanf("%c", &vec[indice].sexo);
//            vec[indice].sexo=toupper(vec[indice].sexo);
            getCharGenre(&vec[indice].sexo,"Ingrese el sexo: ","Debe ingresar F o M");

            printf("Ingrese el sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            printf("Ingrese el dia de ingreso: ");
            scanf("%d", &vec[indice].fechaIn.dia);

            printf("Ingrese el mes de ingreso: ");
            scanf("%d", &vec[indice].fechaIn.mes);

            printf("Ingrese el ano de ingreso: ");
            scanf("%d", &vec[indice].fechaIn.anio);

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

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].nombre, vec[j].nombre)>0)//si las cadenas son iguales retornara 0, si la primera es mayor retornara un valor positivo y si es menor retornara un valor negativo.
            {
                auxEmp = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmp;
            }
        }
    }
    printf("\nEmpleados ordenados exitosamente.\n\n");

}
//-----------------------------------------------------------
void obtenerSector(eSector sectores[], int tamSectores, int idSectorEmp, char descMostrar[])
{
    for(int i=0; i<tamSectores; i++)
    {
        if(idSectorEmp == sectores[i].id)
        {
            strcpy(descMostrar,sectores[i].desc);
            break;
        }
    }



}
//---------------------------------------------------------
void mostrarSectores(eSector sectores[], int tamSectores)
{
    int contador = 0;

    printf("\nID\tSector\n");

    for(int i=0; i < tamSectores; i++)
    {
        printf("%d\t%s\n", sectores[i].id, sectores[i].desc);
        contador = 1;
    }

    if( contador == 0)
    {
        printf("\nNo sectores definidos\n");
    }
    printf("\n\n");
}
//-----------------------------------------------------------
void mostrarSectoresConEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp)
{
    system("cls");
    for(int i =0; i<tamSectores; i++)
    {
        printf("%s\n----------\n", sectores[i].desc);
        printf("\nLegajo\tNombre\tSexo\tSueldo\t\tFecha de ingreso\tSector\n");
        for(int j=0; j<tamEmp; j++ )
        {
            if(vec[j].idSector==sectores[i].id && vec[j].ocupado==1)
            {
                mostrarEmpleado(sectores, tamSectores, vec[j]);
            }
        }
        printf("\n\n");
    }
}
//-----------------------------------------------------------
void censoSectores(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp)
{
    int contador;
    system("cls");

    for(int i =0; i<tamSectores; i++)
    {
        contador=0;
        printf("%s\n----------\n", sectores[i].desc);
        for(int j=0; j<tamEmp; j++ )
        {
            if(vec[j].idSector==sectores[i].id && vec[j].ocupado==1)
            {
                contador++;
            }
        }
        printf("%d empleados", contador);

        printf("\n\n");
    }
}
//-----------------------------------------------------------
void listarSectorSeleccionado(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp)
{
    int seleccion;
    int busquedaOk=0;

    mostrarSectores(sectores, tamSectores);

    printf("Por favor seleccione un sector: ");

    scanf("%d", &seleccion);

    system("cls");

    for(int i =0; i<tamSectores; i++)
    {
        if(sectores[i].id == seleccion)
        {
            printf("\n%s\n----------\n", sectores[i].desc);
            printf("\nLegajo\tNombre\tSexo\tSueldo\t\tFecha de ingreso\tSector\n");
            for(int j=0; j<tamEmp; j++ )
            {
                if(vec[j].idSector==sectores[i].id && vec[j].ocupado==1)
                {
                    mostrarEmpleado(sectores, tamSectores, vec[j]);
                }
            }
            printf("\n");
            busquedaOk=1;
        }

    }
    if(busquedaOk==0)
        {
            printf("No se han hallado empleados para el sector seleccionado.\n\n");
        }

}
