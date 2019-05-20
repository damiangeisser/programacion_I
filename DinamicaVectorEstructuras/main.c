#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
} eEmpleado;

int main()
{
    eEmpleado* pEmp;



//    pEmp = (eEmpleado*) malloc(sizeof(eEmpleado)*3);
//
//    if(pEmp == NULL)//Verifico que haya encontrado memoria.
//    {
//        printf("\nNo se consiguio memoria\n");
//        system("pause");
//        exit(1);//Me saca de la ejecución del programa. Devuelve 1 al OS ¡No utilizar en funciones!
//    }
//
//    for(int i =0; i<3; i++){
//
//
//    printf("Ingrese el legajo: ");
//    scanf("%d", &(pListaEmp+i)->legajo);
//
//    printf("Ingrese el nombre: ");
//    fflush(stdin);
//    //gets(emp1->nombre);//Alternativa.
//    scanf("%s", pEmp->nombre);
//
//    printf("Ingrese el sexo: ");
//    fflush(stdin);
//    scanf("%c", &pEmp->sexo);
//
//    printf("Ingrese el sueldo: ");
//    scanf("%f", &pEmp->sueldo);
//
//    }
//
//    printf("\nLegajo: %d Nombre: %s Sexo: %c Sueldo: %.2f\n", pEmp->legajo, pEmp->nombre, pEmp->sexo, pEmp->sueldo);

    return 0;
}

eEmpleado* newEmpleado(){

eEmpleado* pNuevoEmp;

pNuevoEmp = (eEmpleado*) malloc(sizeof(eEmpleado));

 if(pNuevoEmp != NULL){
    pNuevoEmp->legajo=0;
    strcpy(pNuevoEmp->nombre,"");
    pNuevoEmp->sexo='';
    pNuevoEmp->sueldo=0;

 }
return pNuevoEmp;
}

eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo){

eEmpleado* pNuevoEmp;

pNuevoEmp = (eEmpleado*) malloc(sizeof(eEmpleado));

 if(pNuevoEmp != NULL){
    pNuevoEmp->legajo=legajo;
    strcpy(pNuevoEmp->nombre,nombre);
    pNuevoEmp->sexo=sexo;
    pNuevoEmp->sueldo=sueldo;

 }
return pNuevoEmp;
}

void mostrarEmpleado(eEmpleado)
{
    printf("\nLegajo: %d Nombre: %s Sexo: %c Sueldo: %.2f\n", pEmp->legajo, pEmp->nombre, pEmp->sexo, pEmp->sueldo);
}

