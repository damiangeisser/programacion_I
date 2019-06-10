#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDin.h"
#include "LinkedList.h"
#include "Employee.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* fCSV;

    char buffer[4][20];
    int qty;
    int error=1;
    Employee* empAux;

    fCSV = fopen(path,"r");

    if(fCSV == NULL)
    {
        printf(" (!) No se pudo abrir el archivo de texto (!)\n");
        system("pause");
    }

    fscanf(fCSV, "%[^,],%[^,],%[^,],%5s", buffer[0], buffer[1], buffer[2], buffer[3]);//Lectura fantasma encabezados.

    while(!feof(fCSV))
    {
        qty = fscanf(fCSV, "%[^,],%[^,],%[^,],%5s",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(qty < 4)
        {
            if(feof(fCSV))
            {
                break;
            }
            else
            {
                printf("(!) No se leyo correctamente el ultimo registro (!)");
                system("pause");
                break;
            }
        }

        empAux = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

        if (empAux!=NULL)
        {
            ll_add(pArrayListEmployee, empAux);

            error=0;
        }
    }

    fclose(fCSV);

    if(!error){

        printf("\n>> Archivo de texto cargado exitosamente <<\n");
    }

    return 1;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)//Revisar
{
    FILE* fBIN;

    int qty;
    Employee* empAux;

    fBIN = fopen(path,"rb");

    if(fBIN == NULL)
    {
        printf("(!) No se pudo abrir el archivo binario (!)\n");
        system("pause");
    }
    empAux = employee_new();

    if(empAux == NULL)
    {
        printf("(!) Error en memoria dinamica (!)\n");
        system("pause");
    }

    while(!feof(fBIN))
    {
        qty=fread(empAux,sizeof(Employee),1,fBIN);

        if(qty!=1)
        {
            if(feof(fBIN))
            {
                break;
            }
            else
            {
                printf("\n(!) No se leyo correctamente el ultimo registro (!)\n");
                system("pause");
                break;
            }
        }
        ll_add(pArrayListEmployee, empAux);
    }

    fclose(fBIN);

    return 1;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int listLimit;
    int searchID;
    char confirmChar;
    int foundFlag = 0;
    Employee* pEmpAux;

    listLimit=ll_len(pArrayListEmployee);

    getInt(&searchID,"Por favor ingrese el ID del empleado que desea dar de baja: ","El ID ingresado no es valido", 0, 5000);

    for(int i =0; i<listLimit; i++)
    {
        pEmpAux=ll_get(pArrayListEmployee, i);

        if(pEmpAux->id==searchID)
        {
            mostrarEmpleado(pEmpAux);

            foundFlag=1;

            printf("\n\nPresione s para dar de baja a este empleado: ");
            fflush(stdin);
            confirmChar = getche();
            printf("\n\n");

            if(tolower(confirmChar) == 's')
            {
                ll_remove(pArrayListEmployee, i);
                printf("\nEmpleado dado de baja exitosamente\n");
                system("pause");
            }
            break;
        }

    }

    if(!foundFlag)
    {
        printf("\nNo fue posible encontrar a un empleado con ese ID\n");
    }

    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int counter=0;

    printf("ID\tNombre\tHoras\tSueldo\n\n");

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
//        if(counter==50)
//        {
//            system("pause");
//            counter=0;
//        }
        mostrarEmpleado((Employee*) ll_get(pArrayListEmployee,i));
        counter++;
    }

    return 1;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pText;

    int listSize;
    Employee* pEmpAux;

    pText=fopen(path,"w");

    listSize = ll_len(pArrayListEmployee);

    if(pText==NULL)
    {
        printf("\n(!) Error al escribir el archivo de texto (!)");
    }
    else
    {
        fprintf(pText, "id,nombre,horasTrabajadas,sueldo");

        for(int i=0; i < listSize; i++)
        {
            pEmpAux = ll_get(pArrayListEmployee, i);

            fprintf(pText,"%d,%s,%d,%d", pEmpAux->id, pEmpAux->nombre, pEmpAux->horasTrabajadas, pEmpAux->sueldo);
        }
    }

    fclose(pText);

    return 1;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pBin;

    int listSize;
    Employee* pEmpAux;

    pBin=fopen(path,"wb");

    listSize = ll_len(pArrayListEmployee);

    if(pBin==NULL)
    {
        printf("\n(!) Error al escribir el archivo binario (!)");
    }
    else
    {
        for(int i=0; i < listSize; i++)
        {
            pEmpAux = ll_get(pArrayListEmployee, i);
            fwrite((void*)pEmpAux,sizeof(Employee),1,pBin);
        }
    }

    fclose(pBin);

    return 1;
}

