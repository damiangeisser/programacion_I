#include <stdio.h>
#include <stdlib.h>
#include <conio.h>//permite usar la opci�n getche.

#define TAM 3

// struct eEmpleado
//    {
//        char nombre[20];
//        char apellido[20];
//        int legajo;
//        char sexo;
//    };

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int estado;//Bandera para saber si la posici�n esta libre 0 si lo est�, 1 si no.
} eEmpleado;

void inicilaizarEmpleados (eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);

int main()
{

    int opcion;
    char salida = 'n';

    eEmpleado vecEmpleados[TAM]={{1111,"Juan",'m',30000,1},{2222,"Maria",'f',32000,1},{3333,"Pedro",'m',28000,0}};//Harcoding de vector de estructuras.

        //eEmpleado vecEmpleados[TAM];

    //inicilaizarEmpleados(vecEmpleados, TAM);



    do
    {

        system("cls");//Limpia la pantalla.

        printf("\nPor favor elija la accion a realizar y presione enter:\n\n1 - Dar de alta empleado.\n\n2 - Dar de baja empleado.\n\n3 - Modificar registro de empleado.\n\n4 - Ordenar registors de empleados.\n\n5 - Listar registros de empleados.\n\n6 - Salir.\n\n");

        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            printf("\nAlta empleado ");
            system("pause");//Pide que el usuario le de enter para continuar el proceso en el idioma del OS.
            //pause ();
            break;
        case 2:
            printf("\nBaja empleado ");
            system("pause");
            break;
        case 3:
            printf("\nModificar empleado ");
            system("pause");
            break;
        case 4:
            printf("\nOrdenar empleados ");
            system("pause");
            break;
        case 5:
            //printf("\nListar empleados ");
            mostrarEmpleados(vecEmpleados, TAM);
            system("pause");
            break;
        case 6:
            printf("\nDesea salir? s/n: ");
            fflush(stdin);
            //scanf("%c", &salida);
            salida = getche();//Permite capturar un caracter sin necesidad de presionar enter.

            if(tolower(salida)=='s')
            {
                printf("\n----- Programa finalizado -----\n\n");
            }
            break;
        default:
            printf("\n(!) %d no es una opcion valida (!)\n\n", opcion);
        }


    }
    //while(opcion!=6);
    while(salida=='n');

    return 0;
}

void inicilaizarEmpleados (eEmpleado vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        vec[i].estado=0;
    }

}

void mostrarEmpleado(eEmpleado emp)
{

        printf(" %d %s %c %.2f\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo);
//        printf("\nLegajo: %d ", emp.legajo);
//        printf("\n Nombre: %s ", emp.nombre);
//        printf("\nSexo: %c ", emp.sexo);
//        printf("\nSueldo: $%f ", emp.sueldo);

}

void mostrarEmpleados(eEmpleado vec[], int tam){

    for(int i=0; i<tam; i++){

        if(vec[i].estado ==1){
            mostrarEmpleado(vec[i]);
        }
    }
}