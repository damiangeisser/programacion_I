#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
} eEmpleado;

void mostrarEmpleados(eEmpleado** lista, int len);
int listaParaImprimir(eEmpleado** lista, int tam, char* path);
int guardarEmpleadosCSV(eEmpleado** lista, int tam, char* path);
int guardarEmpleadosBinario(eEmpleado** lista, int tam, char* path);
int leerEmpleadoCSV(eEmpleado** lista, int tam, char* path);


eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo);
eEmpleado* new_Empleado();

int main()
{
    FILE* f;

    int leerEmpleadoCSV(eEmpleado** lista, int tam, f);


//--------------------------------------------------------------

//    FILE* f;
//
//    char buffer[4][20];
//    eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*));
//    eEmpleado** pAuxEmpleado;
//    int cont = 0;
//    int cant;
//
//    f = fopen("./ListaEmpleado3","rb");
//
//    if(f == NULL)
//    {
//        printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
//        system("pause");
//        exit(EXIT_FAILURE);
//    }
//
//    while(!feof(f))
//    {
//        eEmpleado* nuevoEmpleado = new_Empleado();
//
//        if(nuevoEmpleado==NULL){
//            printf("No se puede crear un nuevo empleado");
//            getch();
//            exit(1);
//        }
//
//        cant = fread(nuevoEmpleado,sizeof(eEmpleado),1,f);
//        if( cant < 1)
//        {
//            printf("No se puede leer un empleado");
//            getch();
//            break;
//        }
//
//        *(lista + cont) = nuevoEmpleado;
//        cont++;
//
//        pAuxEmpleado = (eEmpleado**) realloc(lista, sizeof(eEmpleado*) *(cont+1));
//        if(pAuxEmpleado == NULL)
//        {
//            exit(1);
//        }
//        lista = pAuxEmpleado;
//    }

//--------------------------------------------------------------

    mostrarEmpleados(lista, cont);

    if(listaParaImprimir(lista, cont, "ListaEmpleado1.txt"))
    {
        printf("Se ha impreso la lista");
    }
    else
    {
        printf("No se ha impreso la lista");
    }

    if(guardarEmpleadosCSV(lista, cont, "ListaEmpleado2"))
    {
        printf("Se ha guardado la lista");
    }
    else
    {
        printf("No se ha guardado la lista");
    }

    if(guardarEmpleadosBinario(lista, cont, "ListaEmpleado3"))
    {
        printf("Se ha guardado la lista en binario");
    }
    else
    {
        printf("No se ha guardado la lista en binario");
    }

    fclose(f);

    return 0;
}

//===========================================================================================

int leerEmpleadoCSV(eEmpleado** lista, int tam, char* path)
{

    FILE* f;

    int error=1;
    char buffer[4][20];
    eEmpleado** pAuxEmpleado;
    int cont = 0;
    int cant;

    f = fopen(path,"r");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        system("pause");
    }

    fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(f))
    {
        cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        if( cant < 4)
        {
            break;
        }

        eEmpleado* nuevoEmpleado = new_EmpleadoParam(atoi(buffer[0]), buffer[1],buffer[2],atof(buffer[3]));

        *(lista + cont) = nuevoEmpleado;
        cont++;

        pAuxEmpleado = (eEmpleado**) realloc(lista, sizeof(eEmpleado*) *(cont+1));
        if(pAuxEmpleado == NULL)
        {
            printf("La funcion no puedo crear pAuxEmpleado\n");
            system("pause");
            error = 2;
        }
        lista = pAuxEmpleado;

        error =0;
    }

    return error;
}

void mostrarEmpleados(eEmpleado** lista, int len)
{
    for(int i=0; i < len; i++)
    {
        printf(" %5d   %10s   %20s  %8.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
    }
    printf("\n\n");
}

eEmpleado* new_Empleado()
{
    eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

    if(emp != NULL)
    {
        emp->legajo = 0;
        strcpy(emp->nombre, "");
        strcpy(emp->apellido, "");
        emp->sueldo = 0;
    }
    return emp;
}

eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo)
{
    eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

    if(emp != NULL)
    {
        emp->legajo = leg;
        strcpy(emp->nombre, nombre);
        strcpy(emp->apellido, apellido);
        emp->sueldo = sueldo;
    }
    return emp;
}

int listaParaImprimir(eEmpleado** lista, int tam, char* path)
{
    int todoOk = 1;

    FILE* f=fopen(path,"w");

    if(f==NULL)
    {
        todoOk=0;
    }

    fprintf(f, "Listado de empleado\n\n");
    fprintf(f, "Legajo Nombre Apellido Sueldo\n\n");

    for(int i=0; i < tam; i++)
    {
        fprintf(f, "%5d   %10s   %20s  %8.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
    }
    printf("\n\n");

    fclose(f);

    return todoOk;
}

int guardarEmpleadosCSV(eEmpleado** lista, int tam, char* path)
{
    int todoOk = 1;
    char ext[] = ".csv";
    //char nombreArchivo[strlen(path)+4];
    char nombreArchivo[100];
    strcpy(nombreArchivo, path);
    strcat(nombreArchivo, ext);

    FILE* f=fopen(path,"w");

    if(f==NULL)
    {
        todoOk=0;
    }

    fprintf(f, "id,first-name,last_name,sueldo\n");


    for(int i=0; i < tam; i++)
    {
        fprintf(f,"%d,%s,%s,%.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
    }
    printf("\n\n");

    fclose(f);

    return todoOk;
}

int guardarEmpleadosBinario(eEmpleado** lista, int tam, char* path)
{
    int todoOk = 1;
    char ext[] = ".bin";
    //char nombreArchivo[strlen(path)+4];
    char nombreArchivo[100];
    strcpy(nombreArchivo, path);
    strcat(nombreArchivo, ext);

    FILE* f=fopen(path,"wb");

    if(f==NULL)
    {
        todoOk=0;
    }

    for(int i=0; i < tam; i++)
    {
        fwrite( *(lista + i),sizeof(eEmpleado),1,f);
    }
    printf("\n\n");

    fclose(f);

    return todoOk;
}
