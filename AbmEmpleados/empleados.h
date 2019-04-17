typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct{//Tipo de dato tipificado.
int id;
char desc[31];
}eSector;

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;
    eFecha fechaNac;
    int idSector;
} eEmpleado;

/** \brief Muestra un switch que debe ser modificado desde la función. Pide un int que guarda en la variable opcion.
 *
 * \param No recibe parámetros.
 * \return
 *
 */

int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam);
void bajaEmpleado(eEmpleado vec[], int tam);
