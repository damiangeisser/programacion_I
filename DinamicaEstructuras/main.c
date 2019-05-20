#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;
} eEmpleado;

int main()
{
    eEmpleado emp1;

    eEmpleado* pEmp;

    pEmp = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(pEmp == NULL)//Verifico que haya encontrado memoria.
    {
        printf("\nNo se consiguio memoria\n");
        system("pause");
        exit(1);//Me saca de la ejecución del programa. Devuelve 1 al OS ¡No utilizar en funciones!
    }

    printf("Ingrese el legajo: ");
    scanf("%d", &pEmp->legajo);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    //gets(emp1->nombre);//Alternativa.
    scanf("%s", pEmp->nombre);

    printf("Ingrese el sexo: ");
    fflush(stdin);
    scanf("%c", &pEmp->sexo);

    printf("Ingrese el sueldo: ");
    scanf("%f", &pEmp->sueldo);

    printf("\nLegajo: %d Nombre: %s Sexo: %c Sueldo: %.2f\n", pEmp->legajo, pEmp->nombre, pEmp->sexo, pEmp->sueldo);

    return 0;
}
