#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

//#ifndef empleados_H_INCLUIDA//Para evitar que el compilador tire error por incluir varias veces la misma biblioteca del usuario.
//#define empleados_H_INCLUIDA
//
//#include "empleados.h"
//
//#endif // empleados_H_INCLUIDA

#ifndef empleados_H_INCLUIDA//Para evitar que el compilador tire error por incluir varias veces la misma biblioteca del usuario.
#define empleados_H_INCLUIDA

#include "input.h"

#endif // empleados_H_INCLUIDA

#define TAM_EMP 11
#define TAM_SEC 5
#define TAM_MENU 10
#define TAM_ALMUERZOS 2000

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct // tipo de dato tipificado.
{
    int id;
    char desc[20];
} eSector;

typedef struct // tipo de dato tipificado.
{
    int id;
    char desc[51];
    float importe;
} eMenu;

typedef struct
{
    int legajo;
    char apellido[51];
    char nombre[51];
    char sexo;
    float sueldo;
    eFecha fechaIn;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct // tipo de dato tipificado.
{
    int id;
    int idMenu;
    int legajoEmp;
    eFecha fechaAlmuerzo;
} eAlmuerzo;


int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
int altaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam, int legajoMain);
void bajaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);



int main()
{
    char seguir = 's';
    char confirma;
    int banderaAlta;
    int legajoIncremental=11;

    eEmpleado listaEmp[TAM_EMP]= {{1, "Gomez","Juan", 'm', 30000, 2,10,2002,2, 0},
        {2, "Perez", "Ana",'f', 32000,25,6,2015,1, 0},
        {3, "Roble","Pedro", 'm', 32000,10,10,2013,4, 0},
        {4, "Garcia","Jose", 'm', 34000,25,6,2003,2, 0},
        {5, "Smith","Maria", 'f', 35000,15,8,2010,4, 0},
        {6, "Roble","Jorge", 'm', 28000,11,12,2008,3, 0},
        {7, "Garcia","Carla", 'f', 33000,21,6,2015,3, 0},
        {8, "Gus","Martin", 'm', 33000,3,7,2011,3, 0},
        {9, "Diaz","Hernan", 'm', 38000,7,3,2004,5, 0},
        {10, "Mann","Aldana", 'f', 35000,12,9,2008,5, 0},
        {11, "Mann","Aldana", 'f', 35000,12,9,2008,5, 1}};

    eSector listaSectores[]= {{1, "Sistemas"},{2, "RR HH"},{3,"Compras"},{4,"Ventas"},{5, "Legales"}};

    eMenu listaMenues[]= {{1, "Fideos con tuco", 75.00},{2, "Sopa", 50.25},{3, "Tarta de verdura", 45.75},{4, "Hamburguesa", 62.15},{5, "Empanadas", 75.00},{6, "Pizza", 82.00},{7, "Ensalada mixta", 55.00},{8, "Pollo al horno", 50.25},{9, "Pastel de papas", 35.75},{9, "Ravioles de verdura", 45.75},{10, "Asado al horno", 65.15}};

    //inicializarEmpleados(listaEmp, TAM);

    do
    {
        switch(menu())
        {

        case 1:

            //banderaAlta=(altaEmpleado(listaSectores, TAM_SEC, listaEmp, TAM_EMP, legajoIncremental));
            altaEmpleado(listaSectores, TAM_SEC, listaEmp, TAM_EMP, legajoIncremental);
            system("pause");

            if(banderaAlta){
                legajoIncremental++;
            }

            break;

        case 2:

            bajaEmpleado(listaSectores, TAM_SEC, listaEmp, TAM_EMP);
            system("pause");
            break;

        case 3:
            //modificarEmpleado(lista,TAM);
            system("pause");
            break;

        case 4:

            //ordenarEmpleadosAZ(lista,TAM);
            system("pause");
            break;

        case 5:
            //mostrarEmpleados(listaSectores, TAM_SEC, lista, TAM);
            system("pause");
            break;

        case 6:
            mostrarEmpleados(listaSectores, TAM_SEC, listaEmp, TAM_EMP);

            system("pause");
            break;

        case 7:
            //mostrarSectoresConEmpleados(listaSectores, TAM_SEC, lista, TAM);
            system("pause");
            break;
        case 8:
            //censoSectores(listaSectores, TAM_SEC, lista, TAM);
            system("pause");
            break;
        case 9:
            printf("\nConfirma la salida del programa s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                printf("\n\n-- Programa finalizado --\n");
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




//----------------------------------------------------------------

int menu()
{
    int opcion;

    system("cls");
    printf("  --- ABM Empleados ---\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Buscar Empleado\n");
    printf("5- Ordenar Empleados Alfabeticamente\n");
    printf("6- Listar Empleados\n");
    printf("7- Alta Almuerzos\n");
    printf("8- Listar Almuerzos Por Empleados\n");
    printf("9- salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

//----------------------------------------------------------------

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}
//----------------------------------------------------------------

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

//----------------------------------------------------------------
void mostrarEmpleado(eSector sectores[], int tamSectores, eEmpleado emp)
{
    char descSector[20];

    obtenerSector(sectores, tamSectores, emp.idSector, descSector);

    printf("%03d\t%s\t%s\t%c\t%.2f\t%02d/%02d/%d\t%s\n", emp.legajo, emp.apellido, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIn.dia, emp.fechaIn.mes, emp.fechaIn.anio, descSector);

}
//-----------------------------------------------------------
void mostrarEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
{
    int contador = 0;

    printf("\nLegajo\tApelli.\tNombre\tSexo\tSueldo\t\tIngreso\t\tSector\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
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
//-----------------------------------------------------------
int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
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
        if(vec[i].isEmpty == 0 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//----------------------------------------------------------------
int altaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam, int legajoMain)
{

    int indice;
    int altaOk = 0;

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\n(!) No hay lugar en el sistema (!)\n\n");
    }
    else
    {
        vec[indice].legajo = legajoMain++;

        getString(vec[indice].nombre,"Ingrese el nombre: ","(!) Largo del nombre invalido (!)", 2, 51);

        getString(vec[indice].apellido,"Ingrese el apellido: ","(!) Largo del apellido invalido (!)", 2, 51);

        getCharGenre(&vec[indice].sexo,"Ingrese el sexo: ","(!) Debe ingresar F o M (!)");

        printf("Ingrese el sueldo: ");
        scanf("%f", &vec[indice].sueldo );

        printf("Ingrese el dia de ingreso: ");
        scanf("%d", &vec[indice].fechaIn.dia);

        printf("Ingrese el mes de ingreso: ");
        scanf("%d", &vec[indice].fechaIn.mes);

        printf("Ingrese el anio de ingreso: ");
        scanf("%d", &vec[indice].fechaIn.anio);

        printf("Ingrese el codigo del sector: ");
        scanf("%d", &vec[indice].idSector);

        vec[indice].isEmpty = 0;

        printf("\n-- Empleado dado de alta exitosamente --\n\n");

        altaOk=1;
    }

    return altaOk;
}
//----------------------------------------------------------------

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

        printf("\n(!) No existe un empleado con ese legajo (!)\n\n");
    }
    else
    {
        mostrarEmpleado(sectores, tamSectores, vec[indice]);
        printf("\nDesea dar de baja al empleado? s/n: ");
        baja = getche();
        if(tolower(baja)=='s')
        {
            vec[indice].isEmpty = 1;
            printf("\n-- Empleado dado de baja exitosamente --\n\n");
        }
    }

}
