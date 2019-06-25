#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idA;
    char apellidoA[31];
    char nombreA[31];
    int ocupado;
} eAutor;

typedef struct
{
    int idL;
    char titulo[51];
    int idAutor;
    int ocupado;
} eLibro;

typedef struct
{
    int idS;
    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    char email[31];
    eFecha fechaAlta;
    int ocupado;
} eSocio;

typedef struct
{
    int idP;
    int idLibro;
    int idSocio;
    eFecha fechaPrestamo;
    int ocupado;
} ePrestamo;

// 1 -----------------------------------------------------------
/**
* \brief Muestra en pantalla un menú de opciones y solicita el ingreso de un int.
* \param No recibe parámetros.
* \return Retorna el entero ingresado por el usuario.
*
*/
int menu();
// 2 -----------------------------------------------------------
/**
* \brief Muestra en pantalla una estructura eSocio determinada.
* \param socio Es la estructura eSocio a mostrar.
* \return No retorna valor alguno.
*/
void mostrarSocio(eSocio socio);
// 3 -----------------------------------------------------------
/**
* \brief Obtiene el nombre y el apellido de una estructura eAutor en particular y los concatena en un vector.
* \param autores[] Es el vector de estructuras eAutor en donde busca.
* \param tamAutores Es el tamaño del vector de estructuras eAutor en donde busca.
* \param idAutores Es el ID de la estructura eAutor buscada.
* \param autorNA[] Es el vector en donde guarda el nombre y apellido concatenados.
* \return No retorna valor alguno.
*/
void obtenerAutor(eAutor autores[], int tamAutores, int idAutor, char autorNA[]);
// 4 -----------------------------------------------------------
/**
* \brief Muestra en pantalla una estrutura eLibro y su autor.
* \param autores[] Es el vector de estructuras autor en donde busca al autor del libro a mostrar.
* \param tamAutores Es el tamaño del vector de estructuras autor en donde busca al autor del libro a mostrar.
* \param libro Es la estructura eLibro que se desa mostrar.
* \return No retorna valor alguno.
*/
void mostrarLibro(eAutor autores[], int tamAutores, eLibro libro);
// 5 -----------------------------------------------------------
/**
* \brief Muestra en pantalla una estrutura autor.
* \param autor Es la estructura autor a mostrar.
* \return No retorna valor alguno.
*/
void mostrarAutor(eAutor autor);
// 6 -----------------------------------------------------------
/**
* \brief Ordena y muestra en pantalla un vector de estructuras eSocio.
* \param vec[] Es el vector de estructuras socio a mostrar.
* \param tam Es el tamaño del vector de estructuras socio a mostrar.
* \return No retorna valor alguno.
*/
void mostrarSociosOrdenados(eSocio vec[], int tam);
// 7 -----------------------------------------------------------
/**
* \brief Ordena y muestra en pantalla un vector de estructuras eLibro.
* \param autores[] Es el vector de estructuras autor en donde busca al autor del libro a mostrar.
* \param tamAutores Es el tamaño del vector de estructuras autor en donde busca al autor del libro a mostrar.
* \param vec[] Es el vector de estructuras eLibro a mostrar.
* \param tam Es el tamaño del vector de estructuras eLibro a mostrar.
* \return No retorna valor alguno.
*/
void mostrarLibrosOrdenados(eAutor autores[], int tamAutores, eLibro vec[], int tam);
// 8 -----------------------------------------------------------
/**
* \brief Ordena y muestra en pantalla un vector de estructuras eAutor.
* \param vec[] Es el vector de estructuras eAutor a mostrar.
* \param tam Es el tamaño del vector de estructuras eAutor a mostrar.
* \return No retorna valor alguno.
*/
void mostrarAutoresOrdenados(eAutor vec[], int tam);
// 9 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras eSocio buscando una posición libre.
* \param vec[] Es el vector de estructuras eSocio a recorrer.
* \param tam Es el tamaño del vector de estructuras eSocio a recorrer.
* \return Retorna el índice de la primera posición libre buscada.
*/
int buscarLibre(eSocio vec[], int tam);
// 10 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras ePrestamo buscando una posición libre.
* \param vec[] Es el vector de estructuras ePrestamo a recorrer.
* \param tam Es el tamaño del vector de estructuras ePrestamo a recorrer.
* \return Retorna el índice de la primera posición libre buscada.
*/
int buscarPLibre(ePrestamo vec[], int tam);
// 11 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras eSocio inicializandola.
* \param vec[] Es el vector de estructuras eSocio a recorrer.
* \param tam Es el tamaño del vector de estructuras eSocio a recorrer.
* \return No retorna valor alguno.
*/
void inicializarSocios(eSocio vec[], int tam);
// 12 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras ePrestamo inicializandola.
* \param vec[] Es el vector de estructuras ePrestamo a recorrer.
* \param tam Es el tamaño del vector de estructuras ePrestamo a recorrer.
* \return No retorna valor alguno.
*/
void inicializarPrestamos(ePrestamo vec[], int tam);
// 13 -----------------------------------------------------------
/**
* \brief Permite dar de alta una estructura eSocio dentro de un vector, obteniendo y validando el contenido de sus variables.
* \param vec[] Es el vector de estructuras eSocio en donde dar de alta el nuevo socio.
* \param tam Es el tamaño del vector de estructuras eSocio en donde dar de alta el nuevo socio.
* \param idMain es el id autoincremental que se le pasa desde el main.
* \return Retorna 0 si no pudo realizar el alta y 1 si lo hizo.
*/
int altaSocio(eSocio vec[], int tam, int idMain);
// 14 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras eSocio buscando una estructura en particular.
* \param vec[] Es el vector de estructuras eSocio a recorrer.
* \param tam Es el tamaño del vector de estructuras eSocio a recorrer.
* \param id Es el id de la estructura eSocio a encontrar.
* \return Retorna el índice de la estructura eSocio buscada.
*/
int buscarSocio(eSocio vec[], int tam, int id);
// 15 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras eSocio buscando una estructura para darla de baja lógicamente.
* \param vec[] Es el vector de estructuras eSocio a recorrer.
* \param tam Es el tamaño del vector de estructuras eSocio a recorrer.
* \return No retorna valor alguno.
*/
void bajaSocio(eSocio vec[], int tam);
// 16 -----------------------------------------------------------
/**
* \brief Permite dar de alta una estructura ePrestamo dentro de un vector.
* \param autores[] Es el vector de estructuras eAutor utilizado para mostrar los libros cargados.
* \param tamAutores Es el tamaño del vector de estructuras eAutor.
* \param vecP[] Es el vector de estructuras ePrestamo en donde dar de alta el nuevo prestamo.
* \param tamP Es el tamaño del vector de estructuras ePrestamo en donde dar de alta el nuevo prestamo.
* \param vecS[] Es el vector de estructuras eSocio utilizado para mostrar los socios cargados.
* \param tamS Es el tamaño del vector de estructuras eSocio.
* \param vecL[] Es el vector de estructuras eLibro utilizado para mostrar los libros cargados.
* \param tamL Es el tamaño del vector de estructuras eLibro.
* \param idPMain es el id autoincremental de los préstamos que se le pasa desde el main.
* \param idSMain es el id autoincremental de los socios que se le pasa desde el main.
* \return Retorna 0 si no pudo realizar el alta y 1 si lo hizo.
*/
int altaPrestamos(eAutor autores[], int tamAutores, ePrestamo vecP[], int tamP, eSocio vecS[], int tamS, eLibro vecL[], int tamL, int idPMain, int idSMain);
// 17 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras eSocio buscando una estructura para modificarla.
* \param vec[] Es el vector de estructuras eSocio a recorrer.
* \param tam Es el tamaño del vector de estructuras eSocio a recorrer.
* \return No retorna valor alguno.
*/
void modificarSocio(eSocio vec[], int tam);
// 18 -----------------------------------------------------------
/**
* \brief Muestra en pantalla un menú de opciones y solicita el ingreso de un int.
* \param No recibe parámetros.
* \return Retorna el entero ingresado por el usuario.
*
*/
int menuInformes();
// 19 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras ePrestamo contando las posiciones ocupadas.
* \param prestamos[] Es el vector de estructuras ePrestamo a recorrer.
* \param tamP Es el tamaño del vector de estructuras ePrestamo a recorrer.
* \return Retorna la cantidad de posiciones ocupadas.
*/
int cantidadPrestamos(ePrestamo prestamos[], int tamP);
// 20 -----------------------------------------------------------
/**
* \brief Ordena un vector de estructuras ePrestamo por su fecha de forma ascendente.
* \param prestamos[] Es el vector de estructuras ePrestamo a ordenar.
* \param tamP Es el tamaño del vector de estructuras ePrestamo a ordenar.
* \return Retorna 1 si se ejecuta con éxito.
*/
int ordenarPrestamos(ePrestamo prestamos[], int tamP);
// 21 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras ePrestamo mostrando en pantalla sus datos.
* \param prestamos[] Es el vector de estructuras ePrestamo a recorrer.
* \param tamP Es el tamaño del vector de estructuras ePrestamo a recorrer.
* \return Retorna 1 si se ejecuta con éxito.
*/
int mostrarPrestamos(ePrestamo prestamos[], int tamP);
// 22 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras ePrestamo contando las posiciones ocupadas y la cantidad de fechas diferentes.
* \param prestamos[] Es el vector de estructuras ePrestamo a recorrer.
* \param tamP Es el tamaño del vector de estructuras ePrestamo a recorrer.
* \return Retorna el promedio diario de pretamos.
*/
float promedioPrestamos(ePrestamo prestamos[], int tamP);
// 23 -----------------------------------------------------------
/**
* \brief Recorre un vector de estructuras ePrestamo contando las fechas por debajo del promedio de prestamos.
* \param prestamos[] Es el vector de estructuras ePrestamo a recorrer.
* \param tamP Es el tamaño del vector de estructuras ePrestamo a recorrer.
* \return Retorna la cantidad de fechas por debajo del promedio de prestamos.
*/
int verificarPromedioPrestamos(ePrestamo prestamos[], int tamP);
// 24 -----------------------------------------------------------
/**
* \brief Permite el ingreso del id de un libro y muestra en pantalla todos los socios que solicitaron ese libro.
* \param autores[] Es el vector de estructuras eAutor.
* \param socios[] Es el vector de estructuras eSocio.
* \param libros[] Es el vector de estructuras eLibro.
* \param prestamos[] Es el vector de estructuras ePrestamo.
* \param tamAutores Es el tamaño del vector de estructuras eAutor.
* \param tamSocios Es el tamaño del vector de estructuras eSocio.
* \param tamLibros Es el tamaño del vector de estructuras eLibro.
* \param tamPrestamos Es el tamaño del vector de estructuras ePrestamo
* \return No retorna valor alguno.
*/
void listarSociosPorLibro(eAutor autores[], eSocio socios[], eLibro libros[], ePrestamo prestamos[], int tamAutores, int tamSocios, int tamLibros, int tamPrestamos);
// 25 -----------------------------------------------------------
/**
* \brief Permite el ingreso del id de un socio y muestra en pantalla todos los libros solicitados por ese socio.
* \param autores[] Es el vector de estructuras eAutor.
* \param socios[] Es el vector de estructuras eSocio.
* \param libros[] Es el vector de estructuras eLibro.
* \param prestamos[] Es el vector de estructuras ePrestamo.
* \param tamAutores Es el tamaño del vector de estructuras eAutor.
* \param tamSocios Es el tamaño del vector de estructuras eSocio.
* \param tamLibros Es el tamaño del vector de estructuras eLibro.
* \param tamPrestamos Es el tamaño del vector de estructuras ePrestamo
* \return No retorna valor alguno.
*/
void listarLibrosPorSocio(eAutor autores[], eSocio socios[], eLibro libros[], ePrestamo prestamos[], int tamAutores, int tamSocios, int tamLibros, int tamPrestamos);
// 26 -----------------------------------------------------------
/**
* \brief Permite el ingreso del una fecha y muestra en pantalla todos los libros solicitados esa fecha.
* \param autores[] Es el vector de estructuras eAutor.
* \param libros[] Es el vector de estructuras eLibro.
* \param prestamos[] Es el vector de estructuras ePrestamo.
* \param tamAutores Es el tamaño del vector de estructuras eAutor.
* \param tamLibros Es el tamaño del vector de estructuras eLibro.
* \param tamPrestamos Es el tamaño del vector de estructuras ePrestamo
* \return No retorna valor alguno.
*/
void listarLibrosPorFecha(eAutor autores[], eLibro libros[], ePrestamo prestamos[], int tamAutores, int tamLibros, int tamPrestamos);
// 27 -----------------------------------------------------------
/**
* \brief Permite el ingreso del una fecha y muestra en pantalla todos los socios que solicitaron al menos un préstamos esa fecha.
* \param socios[] Es el vector de estructuras eSocio..
* \param prestamos[] Es el vector de estructuras ePrestamo.
* \param tamSocios Es el tamaño del vector de estructuras eSocio..
* \param tamPrestamos Es el tamaño del vector de estructuras ePrestamo
* \return No retorna valor alguno.
*/
void listarSociosPorFecha(eSocio socios[], ePrestamo prestamos[], int tamSocios, int tamPrestamos);
// 28 -----------------------------------------------------------
/**
* \brief Ordena un vector de estructuras eLibro por título de forma descendente por cocktail sort.
* \param libros[] Es el vector de estructuras eLibro a ordenar.
* \param tamLibros Es el tamaño del vector de estructuras eLibro
* \return No retorna valor alguno.
*/
void ordenarLibrosTituloDescendente(eLibro libros[],int tamLibros);
// 29 -----------------------------------------------------------
/**
* \brief Ordena un vector de estructuras eSocio por apellido de forma ascendete por el método de inserción.
* \param socios[] Es el vector de estructuras eSocio a ordenar.
* \param socios Es el tamaño del vector de estructuras eSocio
* \return No retorna valor alguno.
*/
void ordenarSociosApellido(eSocio socios[], int tamSocios);
// 30 -----------------------------------------------------------
/**
* \brief Muestra en pantalla un vector de estructuras eSocio.
* \param socios[] Es el vector de estructuras socio a mostrar.
* \param tamSocios Es el tamaño del vector de estructuras socio a mostrar.
* \return No retorna valor alguno.
*/
void mostrarSocios(eSocio socios[], int tamSocios);
// 31 -----------------------------------------------------------
/**
* \brief Muestra en pantalla un vector de estructuras eLibro.
* \param libros[] Es el vector de estructuras eLibro a mostrar.
* \param autores[] Es el vector de estructuras autor en donde busca al autor del libro a mostrar.
* \param tamLibros Es el tamaño del vector de estructuras eLibro a mostrar.
* \param tamAutores Es el tamaño del vector de estructuras autor en donde busca al autor del libro a mostrar.
* \return No retorna valor alguno.
*/
void mostrarLibros(eLibro libros[], eAutor autores[], int tamLibros, int tamAutores);
// 32 -----------------------------------------------------------
/**
* \brief Cuenta la cantidad de veces que un libro fue prestado y muestra el que tiene menos préstamos.
* \param libros[] Es el vector de estructuras eLibro.
* \param autores[] Es el vector de estructuras eAutor.
* \param prestamos[] Es el vector de estructuras ePrestamo.
* \param tamLibros Es el tamaño del vector de estructuras eLibro.
* \param tamAutores Es el tamaño del vector de estructuras eAutor.
* \param tamPrestamos Es el tamaño del vector de estructuras ePrestamo.
* \return No retorna valor alguno.
*/
void contarPrestamosLibros(eLibro libros[], eAutor autores[], ePrestamo prestamos[], int tamLibros, int tamAutores,int tamPrestamos);
// 33 -----------------------------------------------------------
/**
* \brief Cuenta la cantidad de veces que un socio solicito prestamos y muestra aquellos con más solicitudes.
* \param socios[] Es el vector de estructuras eSocio.
* \param prestamos[] Es el vector de estructuras ePrestamo.
* \param tamSocios Es el tamaño del vector de estructuras eSocio.
* \param tamPrestamos Es el tamaño del vector de estructuras ePrestamo.
* \return No retorna valor alguno.
*/
void contarPrestamosSocios(eSocio socios[], ePrestamo prestamos[],int tamSocios, int tamPrestamos);


#endif // SOCIO_H_INCLUDED
