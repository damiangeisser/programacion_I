#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "inputDin.h"
#include "empleadosDin.h"

// 1 -----------------------------------------------------------
int menu()
{
    int opcion;

    system("cls");
    printf("  --- ABM Empleados ---\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Listar Empleados\n");
    printf("5- Salir\n");
    getInt(&opcion,"Ingrese una opcion: ","(!) Opcion invalida (!)", 1, 5);

    return opcion;
}

// 2 -----------------------------------------------------------
int mostrarEmpleado(const char *path, int position)
{
    FILE *bin;

    eEmpleado emp;

    int readQty;

    int error = 1;

    if ((bin=fopen(path,"rb"))==NULL)
    {
        printf("\n(!) No se pudo abrir el archivo para su lectura (!)\n\n");
    }
    else
    {

        fseek(bin,(long)position*sizeof(emp),SEEK_SET);

        readQty = fread(&emp,sizeof(emp),1,bin);

        if(readQty!=1)
        {
            if(feof(bin))
            {
                printf("\n(!) Se leyo el ultimo registro (!)\n\n");
            }
            else
            {
                printf("\n (!) Lectura incorrecta (!)\n\n");
            }
        }
    }

    if(bin!=NULL && readQty==1 && !emp.isEmpty)
    {
        printf("\n%s\t%d\t%d\n",emp.nombre,emp.edad,emp.legajo);
        error=0;
    }

    fclose(bin);

    return error;
}

// 2 -----------------------------------------------------------
long measureFile(const char *path)
{
    FILE *bin;

    long fileSize = -1;

    if ((bin=fopen(path,"rb"))==NULL)
    {
        printf("\n(!) No se pudo abrir el archivo para averiguar su tamanio (!)\n\n");
        system("pause");
    }
    else
    {

        fseek(bin,0L,SEEK_END);

        fileSize = ftell(bin);

    }

    fclose(bin);

    return fileSize;
}

void mostrarEmpleados(const char *path)
{
    int stop;
    int position = 0;
    eEmpleado emp;
    int limit;

    limit=(int)(measureFile(path)/sizeof(emp));

    printf("\nNombre\tEdad Legajo\n");

    do
    {
        stop = mostrarEmpleado(path, position);//Si mostrarEmpleado devuelve 0, sale del while.
        position++;

    }
    while(!stop && position<limit);
}

int buscarEmpleado(const char *path, int legajo)
{
    FILE *bin;
    eEmpleado emp;
    int readQty;
    int found =0;

    if ((bin=fopen(path,"rb"))==NULL)
    {
        printf("\n(!) No se pudo abrir el archivo para su lectura (!)\n\n");
    }
    else
    {

        while(!feof(bin))
        {
            readQty = fread(&emp,sizeof(emp),1,bin);

            if(readQty!=1 && !feof(bin))
            {
                printf("\n(!) Lectura incorrecta (!)\n\n");
            }

            if(legajo == emp.legajo && !emp.isEmpty)
            {
                printf("\nNombre\tEdad Legajo\n");
                printf("\n%s\t%d\t%d\n",emp.nombre,emp.edad,emp.legajo);
                found = 1;
                break;
            }

        }
    }

//    if(!found)
//    {
//        printf("\n(!) No existe un empleado con ese legajo (!)\n");
//    }

    fclose(bin);

    return found;
}

void altaEmpleado(const char *path)
{
    FILE  *bin;
    eEmpleado emp;
    int legajoAux;
    int yaExiste = 0;

    do
    {
        getInt(legajoAux,"\nIngrese el legajo del nuevo empleado y presione enter: ","(!) El legajo ingresado no es valido (!)",1,1000);

        yaExiste=buscarEmpleado(path, legajoAux);

        if(!yaExiste)
        {
            if ((bin=fopen(path,"rb+"))==NULL)
            {
                if ((bin=fopen(path,"wb+"))==NULL)
                {
                    printf("No se pudo abrir el archivo a modificar");
                }
            }else
            {
                getName(emp.nombre,"\nIngrese el nombre del nuevo empleado y presione enter: ","(!) El nombre ingresado no es valido (!)",2,31);

                getInt(&emp.edad,"\nIngrese la edad del nuevo empleado y presione enter: ","(!) La edad ingresada no es valida (!)",16,65);

                emp.legajo=legajoAux;

                emp.isEmpty=0;

                fseek(bin , 0L, SEEK_END);

                fwrite(&emp,sizeof(emp),1,bin);

            }
        }
        else
        {
            printf("\nYa existe un empleado con ese legajo.");
        }

        printf("\nPresione ESC para terminar la carga de empleados o enter para continuar.");

    }
    while((getche())!=27);

fclose(bin);

}
