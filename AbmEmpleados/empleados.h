

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
void mostrarEmpleado(eSector sectores[], int tamSectores, eEmpleado emp)
void mostrarEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);
void bajaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
void ordenarEmpleadosAZ(eEmpleado vec[], int tam);
