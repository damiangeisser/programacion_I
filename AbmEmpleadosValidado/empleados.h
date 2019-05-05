typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct // tipo de dato tipificado.
{
    int id;
    char desc[20];
} eSector;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIn;
    int idSector;
    int ocupado;
} eEmpleado;

/** \brief Muestra un menú que debe ser personalizado en la función. Pide un int que guarda en la variable opcion.
 *
 * \param No recibe parámetros.
 * \return la variable int opcion que ingresa el usuario.
 *
 */
int menu();

/** \brief Realiza la baja lógica de todos las estructuras eEmpleado del vector asignando 0 a la variable ocupado.
 *
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados.
 * \return No devuelve parámetros.
 *
 */
void inicializarEmpleados(eEmpleado vec[], int tam);

/** \brief Muestra en pantalla todos los campos de una estructura eEmpleado. Invoca a la función de usuario obtenerSector.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tamaño del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados.
 * \return No devuelve parámetros.
 *
 */
void mostrarEmpleado(eSector sectores[], int tamSectores, eEmpleado emp);

/** \brief Muestra en pantalla los campos de todas las estructuras eEmpleado de un vector. Valida si el vector está vacío. Invoca a la función de usuario mostrarEmpleado.
 *
 * \param Recibe un vector de estructuras eSector, su tamaño, un vector de estructuras eEmpleado y su tamaño.
 * \return No devuelve parámetros.
 *
 */
void mostrarEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);

/** \brief Busca una posición vacía en un vector de estructuras eEmpleado (campo ocupado == 0).
 *
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados.
 * \return Devuelve el índice de la primera posición vacía hallada. De no hallar ninguna, devuelve -1.
 *
 */
int buscarLibre(eEmpleado vec[], int tam);

/** \brief Busca una estructura eEmpleado utilizando su campo legajo.
 *
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados.
 * \param legajo es el legajo del empleado a buscar en el vector.
 * \return Devuelve el índice de la primera posición cuya estructura posee el legajo buscado. De no hallar ninguna, devuelve -1.
 *
 */
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);

/** \brief Da de alta a una estructura eEmpleado en una posición libre. Valida la existencia de una posición vacía. Invoca a las funciones de usuario: buscarLibre, buscarEmpleado, mostrarEmpleado, getString, getCharGenre, getFloat, getDate, mostrarSectores.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tamaño del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados..
 * \return No devuelve parámetros.
 *
 */
void altaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);

/** \brief Realiza la baja lógica de una estructura eEmpleado determinada por su campo legajo. Valida la existencia del legajo ingresado. Invoca a las funciones de usuario: buscarEmpleado, mostrarEmpleado.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tamaño del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados.
 * \return No devuelve parámetros.
 *
 */
void bajaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);

/** \brief Modifica el campo sueldo de una estructura eEmpleado determinada por su campo legajo. Valida la existencia del legajo ingresado. Invoca a las funciones de usuario: buscarEmpleado, mostrarEmpleado.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tamaño del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados.
 * \return No devuelve parámetros.
 *
 */
void modificarEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);

/** \brief Ordena a las estructuras del vector alfabéticamente por su nombre.
 *
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados.
 * \return No devuelve parámetros.
 *
 */
void ordenarEmpleadosAZ(eEmpleado vec[], int tam);

/** \brief Compara el sector de una estructura eEmpleado con el id del vector de estructuras eSector y copia su campo descripcion a un vector pasado en los parámetros.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tamaño del vector de sectores.
 * \param idSectorEmp es el entero del campo sector de una estructura eEmpleado.
 * \param descMostrar es el vector al cual se debe copiar la descripción.
 * \return No devuelve parámetros.
 *
 */
void obtenerSector(eSector sectores[], int tamSectores, int idSectorEmp, char descMostrar[]);

/** \brief Lista las estructuras eSector existentes con un encabezado para sus campos.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tamaño del vector de sectores.
 * \return No devuelve parámetros.
 *
 */
void mostrarSectores(eSector sectores[], int tamSectores);

/** \brief Lista las estructuras eEmpleado existentes agrupadas por sector con un encabezado para sus campos. Invoca a la función mostrarEmpleado.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tamaño del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados.
 * \return No devuelve parámetros.
 *
 */
void mostrarSectoresConEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp);

/** \brief Lista la cantidad de estructuras eEmpleado existentes de cada sector.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tamaño del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados.
 * \return No devuelve parámetros.
 *
 */
void censoSectores(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp);

/** \brief Lista las estructuras eEmpleado existentes para un sector determinado por el usuario con un encabezado para sus campos. Valida que el sector exista y tenga empleados. Invoca a la función mostrarEmpleado.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tamaño del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tamaño del vector de empleados.
 * \return No devuelve parámetros.
 *
 */
void listarSectorSeleccionado(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp);

void ordenarEmpleadosLegajoAZ(eEmpleado vec[], int tam);
