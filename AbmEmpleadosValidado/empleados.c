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

// 1 -----------------------------------------------------------
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
    printf("10- Salir\n");
    getInt(&opcion,"Ingrese una opcion: ","(!) Opcion invalida (!)", 1, 10);

    return opcion;
}
// 2 -----------------------------------------------------------
void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}
// 3 -----------------------------------------------------------
void mostrarEmpleado(eSector sectores[], int tamSectores, eEmpleado emp)
{
    char descSector[20];

    obtenerSector(sectores, tamSectores, emp.idSector, descSector);

    printf("%d\t%s\t%c\t%.2f\t%02d/%02d/%d\t\t%s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIn.dia, emp.fechaIn.mes, emp.fechaIn.anio, descSector);

}
// 4 -----------------------------------------------------------
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
        printf("\n(!) No hay empleados que mostrar (!)\n");
    }
}
// 5 -----------------------------------------------------------
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
// 6 -----------------------------------------------------------
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
// 7 -----------------------------------------------------------
void altaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
{

    int indice;
    int legajo;
    int esta;

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {

        printf("\n(!) No hay lugar en el sistema (!)\n\n");
    }
    else
    {
        system("cls");
        printf("--- Alta De Empleados---\n\n");

        getInt(&legajo,"Ingrese el nro. de legajo: ","(!) No es un legajo valido (!)\n", 1, 5000);

        //printf("Ingrese el nro. de legajo: ");
        //scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta != -1)
        {
            printf("(!) Existe un empleado de legajo %d en el sistema (!)\n\n", legajo);
            mostrarEmpleado(sectores, tamSectores, vec[esta]);
        }
        else
        {
            vec[indice].legajo = legajo;

            getString(vec[indice].nombre,"Ingrese el nombre: ","(!) Largo del nombre invalido (!)", 2, 20);

            getCharGenre(&vec[indice].sexo,"Ingrese el sexo: ","(!) Debe ingresar F o M (!)");

            getFloat(&vec[indice].sueldo,"Ingrese el sueldo: ","(!) El monto no es valido (!)", 9000, 80000);

            getDate(&vec[indice].fechaIn.anio, &vec[indice].fechaIn.mes, &vec[indice].fechaIn.dia, "ingreso:", 1950, 2020);

            mostrarSectores(sectores, tamSectores);

            getInt(&vec[indice].idSector,"Ingrese el codigo del sector: ","(!) Sector inexistente (!)", 1, 5);

            vec[indice].ocupado = 1;

            printf("\n-- Empleado dado de alta exitosamente --\n\n");
        }

    }
}
// 8 -----------------------------------------------------------
void bajaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
{
    int legajo;
    int indice;
    char baja;

    getInt(&legajo,"\nIngrese legajo del empleado a dar de baja: ","(!) No es un legajo valido (!)\n", 1, 5000);

    indice = buscarEmpleado(vec, tam, legajo);

    if( indice == -1)
    {
        printf("\n(!) No existe un empleado con ese legajo (!)\n");
    }
    else
    {
        mostrarEmpleado(sectores, tamSectores, vec[indice]);
        printf("\nDesea dar de baja al empleado? s/n: ");
        baja = getche();
        if(tolower(baja)=='s')
        {
            vec[indice].ocupado=0;
            printf("\n-- Empleado dado de baja exitosamente --\n");
        }
    }
}
// 9 -----------------------------------------------------------
void modificarEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
{
    int legajo;
    int indice;
    char baja;

    getInt(&legajo,"\nIngrese legajo del empleado a modificar: ","(!) No es un legajo valido (!)\n", 1, 5000);

    indice = buscarEmpleado(vec, tam, legajo);

    if( indice == -1)
    {
        printf("\n(!) No existe un empleado con ese legajo (!)\n\n");
    }
    else
    {
        mostrarEmpleado(sectores, tamSectores, vec[indice]);
        printf("\nDesea modificar este empleado? s/n: ");
        baja = getche();
        if(tolower(baja)=='s')
        {
            getFloat(&vec[indice].sueldo,"Ingrese el nuevo sueldo: ","(!) El monto no es valido (!)", 9000, 80000);

            printf("\n-- Sueldo modificado exitosamente --\n\n");
        }
    }
}
// 10 -----------------------------------------------------------
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
    printf("\n-- Empleados ordenados exitosamente --\n\n");

}
// 11 -----------------------------------------------------------
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
// 12 ---------------------------------------------------------
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
        printf("\n(!) No existen sectores definidos (!)\n");
    }
    printf("\n\n");
}
// 13 -----------------------------------------------------------
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
// 14 -----------------------------------------------------------
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
// 15 -----------------------------------------------------------
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
        printf("(!) No se han hallado empleados para el sector seleccionado (!)\n");
    }
}

// 16 -----------------------------------------------------------
void ordenarEmpleadosLegajoAZ(eEmpleado vec[], int tam)
{
    eEmpleado auxEmp;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i].sexo > vec[j].sexo)// Primer criterio: agrupación.
            {
                auxEmp = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmp;
            }
             else if(vec[i].sexo == vec[j].sexo && strcmp(vec[i].nombre, vec[j].nombre)>0)//si las cadenas son iguales retornara 0, si la primera es mayor retornara un valor positivo y si es menor retornara un valor negativo.
            {
                auxEmp = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmp;
            }
        }
    }
    printf("\n-- Empleados ordenados exitosamente --\n\n");

}
