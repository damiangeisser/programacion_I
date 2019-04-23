#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

//#include "empleados.h"

#define TAM 10
#define TAM_SEC 5

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIn;
    int idSector;
    int ocupado;
} eEmpleado;

typedef struct // tipo de dato tipificado.
{
    int id;
    char desc[20];
} eSector;


int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eSector sectores[], int tamSectores, eEmpleado emp);
void mostrarEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);
void bajaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);
void ordenarEmpleadosAZ(eEmpleado vec[], int tam);
void obtenerSector(eSector sectores[], int tamSectores, int idSectorEmp, char descMostrar[]);
void mostrarSectores(eSector sectores[], int tamSectores);
void censoSectores(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp);
void listarSectorSeleccionado(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp);

int main()
{
    char seguir = 's';
    char confirma;
    //eEmpleado lista[TAM];
    eEmpleado lista[]= {{1105, "Juan", 'm', 30000, 2,10,2002,2, 1},
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
    //inicializarEmpleados(lista, TAM);

    eSector listaSectores[]= {{1, "Sistemas"},{2, "RR HH"},{3,"Compras"},{4,"Ventas"},{5, "Legales"}};

    do
    {
        switch(menu())
        {

        case 1:

            altaEmpleado(listaSectores, TAM_SEC, lista, TAM);
            system("pause");
            break;

        case 2:

            bajaEmpleado(listaSectores, TAM_SEC, lista, TAM);
            system("pause");
            break;

        case 3:
            modificarEmpleado(lista,TAM);
            system("pause");
            break;

        case 4:

            ordenarEmpleadosAZ(lista,TAM);
            system("pause");
            break;

        case 5:
            mostrarEmpleados(listaSectores, TAM_SEC, lista, TAM);
            system("pause");
            break;

        case 6:
            mostrarSectores(listaSectores, TAM_SEC);
            system("pause");
            break;

        case 7:
            mostrarSectoresConEmpleados(listaSectores, TAM_SEC, lista, TAM);
            system("pause");
            break;
        case 8:
            censoSectores(listaSectores, TAM_SEC, lista, TAM);
            system("pause");
            break;
        case 9:
            listarSectorSeleccionado(listaSectores, TAM_SEC, lista, TAM);
            system("pause");
            break;
        case 10:
            printf("\nConfirma la salida del programa s/n?: ");
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
            scanf("%d", &vec[indice].fechaIn.dia);

            printf("Ingrese el mes de nacimiento: ");
            scanf("%d", &vec[indice].fechaIn.mes);

            printf("Ingrese el ano de nacimiento: ");
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


























//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>//permite usar la opción getche.
//
//#define TAM 3
//
//// struct eEmpleado
////    {
////        char nombre[20];
////        char apellido[20];
////        int legajo;
////        char sexo;
////    };
//
//typedef struct
//{
//    int legajo;
//    char nombre[20];
//    char sexo;
//    float sueldo;
//    int estado;//Bandera para saber si la posición esta libre 0 si lo está, 1 si no.
//} eEmpleado;
//
////Prototipos de las funciones.
//void inicializarEmpleados(eEmpleado vec[], int tam);
//void mostrarEmpleado(eEmpleado emp);
//void mostrarEmpleados(eEmpleado vec[], int tam);
//int buscarLibre(eEmpleado vec[], int tam);
//
//int main()
//{
//
//    int opcion;
//    char salida = 'n';
//
//    eEmpleado vecEmpleados[TAM]= {{1111,"Juan",'m',30000,0},{2222,"Maria",'f',32000,1},{3333,"Pedro",'m',28000,1}}; //Harcoding de vector de estructuras.
//
//    //eEmpleado vecEmpleados[TAM];
//
//    //inicializarEmpleados(vecEmpleados, TAM);
//
//
//
//    do
//    {
//        system("cls");//Limpia la pantalla.
//
//        printf("\nPor favor elija la accion a realizar y presione enter:\n\n1 - Dar de alta empleado.\n\n2 - Dar de baja empleado.\n\n3 - Modificar registro de empleado.\n\n4 - Ordenar registors de empleados.\n\n5 - Listar registros de empleados.\n\n6 - Salir.\n\n");
//
//        scanf("%d", &opcion);
//
//        switch(opcion)
//        {
//
//        case 1:
//            //printf("\nAlta empleado ");
//            if(buscarLibre(vecEmpleados, TAM)==-1){
//               printf("No hay espacio disponible\n");
//            }else{
//            printf("Hay espacio disponible en %d\n", buscarLibre(vecEmpleados, TAM));
//            }
//
//            system("pause");//Pide que el usuario le de enter para continuar el proceso en el idioma del OS.
//            //pause ();
//            break;
//        case 2:
//            printf("\nBaja empleado ");
//            system("pause");
//            break;
//        case 3:
//            printf("\nModificar empleado ");
//            system("pause");
//            break;
//        case 4:
//            printf("\nOrdenar empleados ");
//            system("pause");
//            break;
//        case 5:
//            //printf("\nListar empleados ");
//            mostrarEmpleados(vecEmpleados, TAM);
//            system("pause");
//            break;
//        case 6:
//            printf("\nDesea salir? s/n: ");
//            fflush(stdin);
//            //scanf("%c", &salida);
//            salida = getche();//Permite capturar un caracter sin necesidad de presionar enter.
//
//            if(tolower(salida)=='s')
//            {
//                printf("\n----- Programa finalizado -----\n\n");
//            }
//            break;
//        default:
//            printf("\n(!) %d no es una opcion valida (!)\n\n", opcion);
//        }
//
//
//    }
//    //while(opcion!=6);
//    while(salida=='n');
//
//    return 0;
//}
//
//void inicializarEmpleados(eEmpleado vec[], int tam)
//{
//    for(int i=0; i<tam; i++)
//    {
//        vec[i].estado=0;
//    }
//}
//
//void mostrarEmpleado(eEmpleado emp)
//{
//
//    printf("%d\t%s\t%c\t%.2f\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo);
////        printf("\nLegajo: %d ", emp.legajo);
////        printf("\n Nombre: %s ", emp.nombre);
////        printf("\nSexo: %c ", emp.sexo);
////        printf("\nSueldo: $%f ", emp.sueldo);
//
//}
//
//void mostrarEmpleados(eEmpleado vec[], int tam)
//{
//
//    int contador=0;
//
//    printf("\nLegajo\tNombre\tSexo\tSueldo\n");
//    for(int i=0; i<tam; i++)
//    {
//
//        if(vec[i].estado ==1)
//        {
//            mostrarEmpleado(vec[i]);
//            contador++;
//        }
//    }
//
//    if(contador==0)
//    {
//        printf("\nNo hay registros que mostrar.\n");
//    }
//}
//
//int buscarLibre(eEmpleado vec[], int tam)
//{
//    int lugar=-1;
//
//    for(int i=0; i<tam; i++)
//    {
//        if(vec[i].estado==0)
//        {
//            lugar=i;
//            break;
//        }
//    }
//    return lugar;
//}
