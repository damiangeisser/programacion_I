#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();//Hecho
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);//Hecho
void employee_delete();

int employee_setId(Employee* this,int id);//Hecho
int employee_getId(Employee* this,int* id);//Hecho

int employee_setNombre(Employee* this,char* nombre);//Hecho
int employee_getNombre(Employee* this,char* nombre);//Hecho

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);//Hecho
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);//Hecho

int employee_setSueldo(Employee* this,int sueldo);//Hecho
int employee_getSueldo(Employee* this,int* sueldo);//Hecho

void mostrarEmpleado(Employee* emp);//Hecho
int ordenarXSueldo( void* emp1, void* emp2);
int ordenarXHoras( void* emp1, void* emp2);

#endif // employee_H_INCLUDED
