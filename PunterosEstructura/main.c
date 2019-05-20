#include <stdio.h>
#include <stdlib.h>

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
    eFecha fechaIngreso;
} eEmpleado;

int main()
{
    eEmpleado unEmpleado = {1234, "Juan", 'm', 30000, {13,5,2019}};

    eEmpleado otroEmpleado = {2222, "Ana", 'f', 32000, {20,8,2010}};

    eEmpleado lista[]= {unEmpleado, otroEmpleado};

    //printf("Legajo: %d\n", unEmpleado.legajo);

    //eEmpleado* punteroEmpleado;

    //punteroEmpleado = &unEmpleado;

    //printf("Legajo: %d\n", punteroEmpleado->legajo);//Operador flecha. para mostrar campos de las estructuras.

    //printf("Legajo: %d\n", *punteroEmpleado);//No usar.

//    printf("Nombre: %s\n", punteroEmpleado->nombre);
//
//    printf("Nombre: %s\n", (*punteroEmpleado).nombre);//Una variante.
//
//    printf("Sexo: %c\n", punteroEmpleado->sexo);
//
//    printf("Sueldo: %f\n", punteroEmpleado->sueldo);
//
//    printf("Fecha de ingreso: %s\n", punteroEmpleado->fechaIngreso.dia);//El operador punto se usa cuando se desea acceder al campo de una estructura anidada.

    for(int i=0; i<2; i++)
    {
        printf("%s\n", (lista+i)->nombre);
    }
    return 0;
}
