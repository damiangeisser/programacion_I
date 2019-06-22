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


int menu();
void mostrarSocio(eSocio socio);
void mostrarSociosOrdenados(eSocio vec[], int tam);
int altaSocio(eSocio vec[], int tam, int idMain);
void inicializarSocios(eSocio vec[], int tam);
int buscarSocio(eSocio vec[], int tam, int id);
void bajaSocio(eSocio vec[], int tam);
//void mostrarLibro(eLibro libro);
void mostrarLibro(eAutor autores[], int tamAutores, eLibro libro);
//void mostrarLibrosOrdenados(eLibro vec[], int tam);
void mostrarLibrosOrdenados(eAutor autores[], int tamAutores, eLibro vec[], int tam);
void mostrarAutor(eAutor autor);
void mostrarAutoresOrdenados(eAutor vec[], int tam);
//int altaPrestamos(ePrestamo vecP[], int tamP, eSocio vecS[], int tamS, eLibro vecL[], int tamL, int idPMain, int idSMain);
int altaPrestamos(eAutor autores[], int tamAutores, ePrestamo vecP[], int tamP, eSocio vecS[], int tamS, eLibro vecL[], int tamL, int idPMain, int idSMain);
void inicializarPrestamos(ePrestamo vec[], int tam);
void modificarSocio(eSocio vec[], int tam);
void listarPrestamosSocios(eSocio socios[], eLibro libros[], ePrestamo prestamos[], int cantSocios, int cantLibros);
void obtenerAutor(eAutor autores[], int tamAutores, int idAutor, char autorNA[]);
// 18 -----------------------------------------------------------
int menuInformes();
// 19 -----------------------------------------------------------
int cantidadPrestamos(ePrestamo prestamos[], int tamP);
// 20 -----------------------------------------------------------
int ordenarPrestamos(ePrestamo prestamos[], int tamP);
// 21 -----------------------------------------------------------
int mostrarPrestamos(ePrestamo prestamos[], int tamP);
// 22 -----------------------------------------------------------
float promedioPrestamos(ePrestamo prestamos[], int tamP);
// 23 -----------------------------------------------------------
int verificarPromedioPrestamos(ePrestamo prestamos[], int tamP);
// 24 -----------------------------------------------------------
void listarSociosPorLibro(eAutor autores[], eSocio socios[], eLibro libros[], ePrestamo prestamos[], int tamAutores, int tamSocios, int tamLibros, int tamPrestamos);
// 25 -----------------------------------------------------------
void listarLibrosPorSocio(eAutor autores[], eSocio socios[], eLibro libros[], ePrestamo prestamos[], int tamAutores, int tamSocios, int tamLibros, int tamPrestamos);
// 26 -----------------------------------------------------------
void listarLibrosPorFecha(eAutor autores[], eLibro libros[], ePrestamo prestamos[], int tamAutores, int tamLibros, int tamPrestamos);
// 27 -----------------------------------------------------------
void listarSociosPorFecha(eSocio socios[], ePrestamo prestamos[], int tamSocios, int tamPrestamos);
// 28 -----------------------------------------------------------
void ordenarLibrosTituloDescendente(eLibro libros[],int tamLibros);
// 29 -----------------------------------------------------------
void ordenarSociosApellido(eSocio socios[], int tamSocios);
// 30 -----------------------------------------------------------
void mostrarSocios(eSocio socios[], int tamSocios);
// 31 -----------------------------------------------------------
void mostrarLibros(eLibro libros[], eAutor autores[], int tamLibros, int tamAutores);
// 32 -----------------------------------------------------------
void contarPrestamosLibros(eLibro libros[], eAutor autores[], ePrestamo prestamos[], int tamLibros, int tamAutores,int tamPrestamos);
// 33 -----------------------------------------------------------
void contarPrestamosSocios(eSocio socios[], ePrestamo prestamos[],int tamSocios, int tamPrestamos);


#endif // SOCIO_H_INCLUDED
