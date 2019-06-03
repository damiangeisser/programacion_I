#include <stdlib.h>//Incluye el Define de NULL
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{

    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id =0;
        strcpy(nuevoEmpleado->nombre,"");
        nuevoEmpleado->horasTrabajadas=0;
        nuevoEmpleado->sueldo = 0;
    }
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    int error = 1;

    if(nuevoEmpleado != NULL)
    {
        if(!employee_setId(nuevoEmpleado,atoi(idStr))
    {
        if(!employee_setNombre(nuevoEmpleado,nombreStr))
            {
                if(!employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr))
            {
                if(!employee_setSueldo(nuevoEmpleado,atoi(sueldoStr))
                {
                    error = 0;
                }
            }
        }
}
        if(!error)
            {
                free(nuevoEmpleado);
                nuevoEmpleado=NULL;
            }


    }


//        nuevoEmpleado->id = atoi(idStr);
//        strcpy(nuevoEmpleado->nombre,nombreStr);
//        nuevoEmpleado->horasTrabajadas=atoi(horasTrabajadasStr);
//        nuevoEmpleado->sueldo=atoi(sueldoStr);

}

int employee_setId(Employee* this,int id)
{
    int error=1;

    if(this != NULL && id < 0))
    {
        this->id = id;
        error = 0;
    }

    return error;
}


int employee_getId(Employee* this,int* id)
{
    int error = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }

    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error=1;

    if(this != NULL && (sueldo > 0 && sueldo < 100000))
    {
        this->sueldo = sueldo;
        error = 0;
    }

    return error;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        error = 0;
    }

    return error;
}
