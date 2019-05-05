#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "input.h"

//#define F1 "Falla 3G"
//#define F2 "Falla LTE"
//#define F3 "Falla equipo"
//
//#define E1 "En curso"
//#define E2 "Solucionado"
//#define E3 "No solucionado"

#define TAM_USER 10
#define TAM_CALL 10

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    int ocupado;
} eAbonado;

typedef struct
{
    int id;
    char descripcion[20];
} eMotivo;

typedef struct
{
    int id;
    char descripcion[20];
} eEstado;

typedef struct
{
    int idAbonado;
    char motivo[20];
    char estado[20];
    int minutos;
} eLlamada;

int menu();


int main()
{

    eMotivo listaMotivos[]= {{1, "Falla 3G"},{2, "Falla LTE"},{3,"Falla Equipo"}};

    eEstado listaEstados[]= {{1, "En curso"},{2, "Solucionado"},{3,"No solucionado"}};

    eAbonado listaAbonados[TAM_USER]={{1,"Juan","Perez",1},{2, "Maria", "Fernandez", 1},{3,"Carlos","Gomez",1},{4,"Jimena","Gimenez",0}};

    char seguir = 's';
    char confirma;
    int altaOk = 0;
    //int idAuto = 1;
    int idAuto = 5;

    do
    {
        switch(menu())
        {

        case 1:

            altaOk = altaAbonado(listaAbonados, TAM_USER, idAuto);

            if(altaOk){
                idAuto++;
            }

            system("pause");
            break;

        case 2:

            printf("modificar abonado");
            system("pause");
            break;
        case 3:
           bajaAbonado(listaAbonados,TAM_USER);
            system("pause");
            break;


        case 4:
            printf("nueva llamada");
            system("pause");
            break;

        case 5:
            printf("fin de llamada");
            system("pause");
            break;

        case 6:
            printf("Mostrar abonado con mas reclamos\n");

            system("pause");
            break;

        case 7:
            printf("6Mostrar reclamo mas frecuente\n");
            system("pause");
            break;

        case 8:
            printf("Mostrar reclamo que mas tarda en resolverse\n");
            system("pause");
            break;
        case 9:
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

// 1 -----------------------------------------------------------
int menu()
{
    int opcion;

    system("cls");
    printf("  --- Tickets ---\n\n");
    printf("1- Alta de un abonado\n");
    printf("2- Modificar datos del abonado\n");
    printf("3- Baja de un abonado\n");
    printf("4- Nueva llamada\n");
    printf("5- Fin de la llamada\n");
    printf("6- Mostrar abonado con mas reclamos\n");
    printf("7- Mostrar reclamo mas frecuente\n");
    printf("8- Mostrar reclamo que mas tarda en resolverse\n");
    printf("9- Salir\n");
    getInt(&opcion,"Ingrese una opcion: ","(!) Opcion invalida (!)", 1, 8);

    return opcion;
}
// 2 -----------------------------------------------------------
void inicializarAbonados(eAbonado vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}
// 3 -----------------------------------------------------------
void mostrarAbonado(eAbonado user)
{

    printf("%d\t%s\t%s\n", user.id, user.nombre, user.apellido);

}

// 4 -----------------------------------------------------------
int buscarLibre(eAbonado vec[], int tam)
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
// 5 -----------------------------------------------------------
int buscarAbonado(eAbonado vec[], int tam, int id)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

// 6 -----------------------------------------------------------
int altaAbonado(eAbonado vec[], int tam, int id)
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
        system("cls");
        printf("--- Alta De Abonados---\n\n");

            vec[indice].id = id;

            getString(vec[indice].nombre,"Ingrese el nombre: ","(!) Largo del nombre invalido (!)", 2, 20);

            getString(vec[indice].apellido,"Ingrese el apellido: ","(!) Largo del nombre invalido (!)", 2, 20);

            vec[indice].ocupado = 1;

            printf("\n-- Abonado dado de alta exitosamente --\n\n");

            altaOk = 1;
        }

        return altaOk;
}

// 6 ----------------------------------------------------------
void bajaAbonado(eAbonado vec[], int tam)
{
    int id;
    int indice;
    char baja;

    getInt(&id,"\nIngrese el id del abonado a dar de baja: ","(!) No es un id valido (!)\n", 1, 5000);

    indice = buscarAbonado(vec, tam, id);

    if( indice == -1)
    {
        printf("\n(!) No existe un abonado con ese id (!)\n");
    }
    else
    {
        mostrarAbonado(vec[indice]);
        printf("\nDesea dar de baja al abonado? s/n: ");
        baja = getche();
        if(tolower(baja)=='s')
        {
            vec[indice].ocupado=0;
            printf("\n-- Abonado dado de baja exitosamente --\n");
        }
    }
}
