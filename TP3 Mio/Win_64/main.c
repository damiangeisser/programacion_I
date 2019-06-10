#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char exitChar='n';

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(employee_menu())
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            system("pause");
            break;
        case 2:
            //controller_loadFromBinary("pruebabinaria.bin",listaEmpleados);
           // controller_loadFromText("data.bin",listaEmpleados);
           system("pause");
            break;
        case 3:
            printf("\nAlta Empleados\n");
            system("pause");
            break;
        case 4:
            printf("\nModificar Empleados\n");
            system("pause");
            break;
        case 5:
           // printf("\nBaja Empleados\n");
            controller_removeEmployee(listaEmpleados);
            system("pause");
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            system("pause");
            break;
        case 7:
            printf("\nOrdenar Empleados\n");
            system("pause");
            break;
        case 8:
            printf("\nGuardar en CSV\n");
            //controller_saveAsText("prueba.csv" , listaEmpleados);
            system("pause");
            break;
        case 9:
            printf("\nGuardar en BIN\n");
            //controller_saveAsBinary("pruebabinaria.bin", listaEmpleados);
            system("pause");
            break;
        case 10:
            printf("\nConfirma la salida del programa? s/n: ");
            fflush(stdin);
            exitChar = getche();

            if(tolower(exitChar) == 's')
            {
                ll_deleteLinkedList(listaEmpleados);
                printf("\n\n- Programa finalizado -\n");
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
        }

    }
while(exitChar != 's');

printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));
// agrego un empleado a la lista
//    if(ll_add(listaEmpleados, emp1)== 0){
//        printf("Se ha agregado el empleado con exito a la lista\n");
//    }
//
//     printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));
//
//     if(ll_add(listaEmpleados, emp2)== 0){
//        printf("Se ha agregado el empleado con exito a la lista\n");
//    }
//
//     printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));
//
//     if(ll_add(listaEmpleados, emp3)== 0){
//        printf("Se ha agregado el empleado con exito a la lista\n");
//    }
//
//     printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));


//     mostrarEmpleado((Employee*) ll_get(listaEmpleados,1));
//
//
//
//     if(ll_push(listaEmpleados, 1, emp4)== 0){
//        printf("Se ha agregado el empleado con exito a la lista\n");
//
//    }
//
//     printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));
//
//
//       mostrarEmpleado( (Employee*) ll_get(listaEmpleados,1));
//
//         mostrarEmpleado( (Employee*) ll_get(listaEmpleados,2));
//
//
// printf("----------------------------------------------\n\n");
//
// for(int i = 0; i < ll_len(listaEmpleados); i++){
//
//       mostrarEmpleado( (Employee*) ll_get(listaEmpleados,i));
//
// }
//
// printf("Ordeno la lista por sueldo\n\n");
//
// //ll_sort(listaEmpleados,ordenarXHoras, 0);
//
// for(int i = 0; i < ll_len(listaEmpleados); i++){
//
//       mostrarEmpleado((Employee*) ll_get(listaEmpleados,i));
//
// }





return 0;
}
