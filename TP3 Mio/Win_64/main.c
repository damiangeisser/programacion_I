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
        switch(controller_menu())
        {
        case 1:
            controller_loadFromText("prueba.csv",listaEmpleados);
            break;
        case 2:
            controller_loadFromBinary("prueba.bin",listaEmpleados);
            // controller_loadFromBinary("data.bin",listaEmpleados);
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            controller_saveAsText("prueba.csv" , listaEmpleados);
            //controller_saveAsText("data.csv" , listaEmpleados);
            break;
        case 9:
            printf("\nGuardar en BIN\n");
            controller_saveAsBinary("prueba.bin", listaEmpleados);
            //controller_saveAsBinary("data.bin", listaEmpleados);
            system("pause");
            break;
        case 10:
            exitChar=controller_exit(listaEmpleados);
            break;
        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
        }
    }
    while(exitChar != 's');

    return 0;
}
