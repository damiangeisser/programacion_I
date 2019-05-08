#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "input.h"
//#include "socios.h"

#define TAM_AUT 5
#define TAM_LIB 7
#define TAM_SOC 10
#define TAM_PRES 5

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

int main()
{

    eAutor listaAutores[TAM_AUT]= {{101,"Lovecraft","Howard",1},{102,"Moorecock","Michael",1},{103,"Herbert","Frank",1},{104,"Leguin","Ursula",1},{105,"Borges","Luis",1}};

    eLibro listaLibros[TAM_LIB]= {{1001,"La llamada de Cthulhu",101,1},{1002,"Duna",103,1},{1003,"El mago de Terramar",104,1},{1004,"El Aleph",105,1},{1005,"El Mesias de Duna",103,1},{1006,"El libro de arena",105,1},{1007,"Eric de Melnibone",102,1}};

    eSocio listaSocios[TAM_SOC]= {{1,"Juan","Perez",'M',"1523647825","jperez@gmail.com",{25,3,2015},1},
        {2,"Maria","Juarez",'F',"1523659874","mjuarez@hotmail.com",{30,10,2015},1},
        {3,"Alberto","Perez",'M',"1585423691","aperez@hotmail.com",{15,2,2018},1}
    };

    //eSocio listaSocios[TAM_SOC];

    ePrestamo listaPrestamos[TAM_PRES];

    char seguir = 's';
    char confirma;
    int banderaAlta;
    //int idAutoIn=1;
    int idAutoIn=3;
    int idAutoInPrestamo=1;

    //inicializarSocios(listaSocios, TAM_SOC);
    inicializarPrestamos(listaPrestamos, TAM_PRES);

    do
    {
        switch(menu())
        {

        case 1:
            banderaAlta = altaSocio(listaSocios, TAM_SOC, idAutoIn);

            if(banderaAlta)
            {
                idAutoIn++;
            }

            banderaAlta=0;
            system("pause");
            break;
        case 2:
            modificarSocio(listaSocios, TAM_SOC);
            system("pause");
            break;
        case 3:
            bajaSocio(listaSocios, TAM_SOC);
            system("pause");
            break;
        case 4:
            mostrarSociosOrdenados(listaSocios, TAM_SOC);
            printf("\n");
            system("pause");
            break;
        case 5:
            mostrarLibrosOrdenados(listaAutores, TAM_AUT, listaLibros, TAM_LIB);
            printf("\n");
            system("pause");
            break;
        case 6:
            mostrarAutoresOrdenados(listaAutores, TAM_AUT);
            printf("\n");
            system("pause");
            break;
        case 7:
            banderaAlta = altaPrestamos(listaAutores, TAM_AUT, listaPrestamos, TAM_PRES, listaSocios, TAM_SOC, listaLibros, TAM_LIB, idAutoInPrestamo, idAutoIn);

            if(banderaAlta)
            {
                idAutoIn++;
            }

            banderaAlta=0;
            system("pause");
            break;
        case 8:
            printf("\nConfirma la salida del programa? s/n: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                printf("\n\n- Programa finalizado -\n");
                seguir = 'n';
            }
            break;
        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
        }
    }
    while(seguir == 's');

    return 0;

}

//============================================================


// 1 -----------------------------------------------------------
int menu()
{
    int opcion;

    system("cls");
    printf("--- ABM Socios ---\n\n");
    printf("1- Alta de Socio\n");
    printf("2- Modificar Socio\n");
    printf("3- Baja de Socio\n");
    printf("4- Listar Socios\n");
    printf("5- Listar Libros\n");
    printf("6- Listar Autores\n");
    printf("7- Alta Prestamos\n");
    printf("8- Salir\n");

    getInt(&opcion,"Ingrese una opcion: ","(!) Opcion invalida (!)", 1, 8);

    return opcion;
}

// 2 -----------------------------------------------------------
void mostrarSocio(eSocio socio)
{

    printf("%d\t%s\t%s\t%c\t%s %s %02d/%02d/%d\n", socio.idS, socio.apellido, socio.nombre, socio.sexo, socio.telefono, socio.email, socio.fechaAlta.dia, socio.fechaAlta.mes, socio.fechaAlta.anio);
    //printf("%.3d %-8s\t%-8s %c %s\t%s\t%02d/%02d/%d\n", socio.idS, socio.apellido, socio.nombre, socio.sexo, socio.telefono, socio.email, socio.fechaAlta.dia, socio.fechaAlta.mes, socio.fechaAlta.anio);

}

void obtenerAutor(eAutor autores[], int tamAutores, int idAutor, char autorNA[])
{
    for(int i=0; i<tamAutores; i++)
    {
        if(idAutor == autores[i].idA)
        {
            strcpy(autorNA, autores[i].apellidoA);
            strcat(autorNA, ", ");
            strcat(autorNA, autores[i].nombreA);
            break;
        }
    }
}
// 3 -----------------------------------------------------------
void mostrarLibro(eAutor autores[], int tamAutores, eLibro libro)
{
    char autorNA[80];

    obtenerAutor(autores, TAM_AUT, libro.idAutor, autorNA);

    printf("%d\t%s\t%s\n", libro.idL, libro.titulo, autorNA);

}
// 4 -----------------------------------------------------------
void mostrarAutor(eAutor autor)
{

    printf("%d\t%s\t%s\n", autor.idA, autor.apellidoA, autor.nombreA);

}
// 5 -----------------------------------------------------------
void mostrarSociosOrdenados(eSocio vec[], int tam)
{
    int contador = 0;
    eSocio auxSocio;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].apellido, vec[j].apellido)>0)
            {
                auxSocio = vec[i];
                vec[i] = vec[j];
                vec[j] = auxSocio;
            }
            else if((strcmp(vec[i].apellido, vec[j].apellido)==0) && strcmp(vec[i].nombre, vec[j].nombre)>0)
            {
                auxSocio = vec[i];
                vec[i] = vec[j];
                vec[j] = auxSocio;
            }
        }
    }

    system("cls");
    printf("\nCarnet   Apellido\tNombre\tSexo\tTelefono\teMail\tFecha de alta\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarSocio(vec[i]);
            contador++;
        }
    }

    if(contador == 0)
    {
        printf("\n(!) No hay socios que mostrar (!)\n");
    }
}



// 6 -----------------------------------------------------------
void mostrarLibrosOrdenados(eAutor autores[], int tamAutores, eLibro vec[], int tam)
{
    int contador = 0;
    eLibro auxLibro;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].titulo, vec[j].titulo)>0)
            {
                auxLibro = vec[i];
                vec[i] = vec[j];
                vec[j] = auxLibro;
            }
        }
    }

    system("cls");
    printf("\nCodigo\tTitulo\tAutor\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarLibro(autores, TAM_AUT, vec[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\n(!) No hay libros que mostrar (!)\n");
    }
}
// 7 -----------------------------------------------------------
void mostrarAutoresOrdenados(eAutor vec[], int tam)
{
    int contador = 0;
    eAutor auxAutor;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].apellidoA, vec[j].apellidoA)>0)
            {
                auxAutor = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAutor;
            }
            else if((strcmp(vec[i].apellidoA, vec[j].apellidoA)==0) && strcmp(vec[i].nombreA, vec[j].nombreA)>0)
            {
                auxAutor = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAutor;
            }
        }
    }

    system("cls");
    printf("\nID\tApellido\tNombre\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarAutor(vec[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\n(!) No hay autores que mostrar (!)\n");
    }
}
// 8 -----------------------------------------------------------
int buscarLibre(eSocio vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
// 9 -----------------------------------------------------------
int buscarPLibre(ePrestamo vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
// 10 -----------------------------------------------------------
void inicializarSocios(eSocio vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}
// 11 -----------------------------------------------------------
void inicializarPrestamos(ePrestamo vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}
// 12 -----------------------------------------------------------
int altaSocio(eSocio vec[], int tam, int idMain)
{
    int indice;
    int altaOk = 0;

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\n(!) No hay lugar en el sistema (!)\n\n");
    }
    else
    {
        vec[indice].idS = idMain++;

        system("cls");

        printf("--- Alta Socios ---\n\n");

        getName(vec[indice].nombre,"Ingrese el nombre: ","(!) Error: ingrese entre 2 y 31 letras y/o espacios (!)", 2, 31);

        getName(vec[indice].apellido,"Ingrese el apellido: ","(!) Error: ingrese entre 2 y 31 letras y/o espacios (!)", 2, 31);

        getCharGenre(&vec[indice].sexo,"Ingrese el sexo: ","(!) Error: ingrese f o m (!)");

        getPhone(vec[indice].telefono,"Ingrese el telefono: ","(!) Error: ingrese entre 8 y 16 digitos sin espacios (!)", 8, 16);

        getEmail(vec[indice].email,"Ingrese el email: ","(!) Error: ingrese un mail valido (!)", 5, 31);

        getDate(&vec[indice].fechaAlta.anio, &vec[indice].fechaAlta.mes, &vec[indice].fechaAlta.dia, "alta:", 2005, 2020);

        vec[indice].ocupado = 1;

        printf("\n-- Socio dado de alta exitosamente --\n\n");

        altaOk=1;
    }

    return altaOk;
}
// 13 -----------------------------------------------------------
int buscarSocio(eSocio vec[], int tam, int id)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].idS == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
// 14 -----------------------------------------------------------
void bajaSocio(eSocio vec[], int tam)
{
    int id;
    int indice;
    char confirm;

    getInt(&id,"\nIngrese el carnet del socio a dar de baja: ","(!) No es un carnet valido (!)\n", 1, 5000);

    indice = buscarSocio(vec, tam, id);

    if( indice == -1)
    {
        printf("\n(!) No existe un socio con ese carnet (!)\n");
    }
    else
    {
        mostrarSocio(vec[indice]);
        printf("\nDesea dar de baja al Socio? s/n: ");
        confirm = getche();
        if(tolower(confirm)=='s')
        {
            vec[indice].ocupado=0;
            printf("\n-- Socio dado de baja exitosamente --\n");
        }
    }
}
// 15 -----------------------------------------------------------
int altaPrestamos(eAutor autores[], int tamAutores, ePrestamo vecP[], int tamP, eSocio vecS[], int tamS, eLibro vecL[], int tamL, int idPMain, int idSMain)
{
    int indice;
    int altaOk = 0;

    indice = buscarPLibre(vecP, tamP);

    if( indice == -1)
    {
        printf("\n(!) No hay lugar en el sistema (!)\n\n");
    }
    else
    {
        vecP[indice].idP = idPMain++;

        mostrarSociosOrdenados(vecS, tamS);

        getInt(&vecP[indice].idSocio,"\nIngrese el carnet del socio que retira el libro: ","(!) Carnet inexistente (!)", 1, idSMain);

        mostrarLibrosOrdenados(autores, tamAutores, vecL, tamL);

        getInt(&vecP[indice].idLibro,"\nIngrese el codigo del libro prestado: ","(!) Codigo inexistente (!)", 1, 2000);

        getDate(&vecP[indice].fechaPrestamo.anio, &vecP[indice].fechaPrestamo.mes, &vecP[indice].fechaPrestamo.dia, "prestamo:", 2005, 2020);

        vecP[indice].ocupado = 1;

        printf("\n-- Prestamo dado de alta exitosamente --\n\n");

        altaOk=1;
    }

    return altaOk;
}
// 16 -----------------------------------------------------------
void modificarSocio(eSocio vec[], int tam)
{
    int id;
    int indice;
    int opcion;
    char confirm;

    system("cls");

    printf("--- Modificacion de Socios ---\n\n");

    getInt(&id,"\nIngrese el carnet del socio a modificar: ","(!) No es un carnet valido (!)\n", 1, 5000);

    indice = buscarSocio(vec, tam, id);

    if( indice == -1)
    {
        printf("\n(!) No existe un socio con ese carnet (!)\n\n");
    }
    else
    {
        printf("\n");
        mostrarSocio(vec[indice]);
        printf("\nDesea modificar este socio? s/n: ");
        confirm = getche();
        if(tolower(confirm)=='s')
        {
            printf("\n1- Modificar apellido\n");
            printf("2- Modificar nombre\n");
            printf("3- Modificar sexo\n");
            printf("4- Modificar telefono\n");
            printf("5- Modificar mail\n");
            printf("6- Salir\n");

            getInt(&opcion,"Ingrese una opcion: ","(!) Opcion invalida (!)", 1, 6);

            switch(opcion)
            {
            case 1:
                getName(vec[indice].apellido,"Ingrese el nuevo apellido: ","(!) Error: ingrese entre 2 y 31 letras y/o espacios (!)", 2, 31);

                printf("\n-- Apellido modificado exitosamente --\n\n");

                break;

            case 2:
                getName(vec[indice].nombre,"\n\nIngrese el nuevo nombre: ","(!) Error: ingrese entre 2 y 31 letras y/o espacios (!)", 2, 31);

                printf("\n-- Nombre modificado exitosamente --\n\n");

                break;

            case 3:
                getCharGenre(&vec[indice].sexo,"Ingrese el nuevo sexo: ","(!) Error: ingrese f o m (!)");

                printf("\n-- Sexo modificado exitosamente --\n\n");

                break;

            case 4:
                getPhone(vec[indice].telefono,"Ingrese el nuevo telefono: ","(!) Error: ingrese entre 8 y 16 digitos sin espacios (!)", 8, 16);

                printf("\n-- Telefono modificado exitosamente --\n\n");

                break;

            case 5:
                getEmail(vec[indice].email,"Ingrese el nuevo email: ","(!) Error: ingrese un mail valido (!)", 5, 31);

                printf("\n-- eMail modificado exitosamente --\n\n");

                break;

            case 6:
                break;

            default:
                printf("\n Opcion invalida\n\n");
            }
        }
    }
}

void listarPrestamosSocios(eSocio socios[], eLibro libros[], ePrestamo prestamos[], int cantSocios, int cantLibros)
{
    system("cls");
    printf("\n--- Listado de Prestamos ---\n\n");
    for(int i = 0; i < cantLibros; i++)
    {
        if(libros[i].ocupado)
        {
            for(int j = 0; j<(cantSocios * cantLibros); j++ )
            {
                if((prestamos[j].ocupado) && (libros[i].idL == prestamos[j].idLibro))
                {
                    for(int k = 0; k < cantSocios; k++ )
                    {
                        if((socios[k].ocupado) && (prestamos[j].idSocio == socios[k].idS))
                        {
                            printf("%d %s %s", socios[k].idS, socios[k].nombre, socios[i].apellido,libros[i].titulo,prestamos[j].fechaPrestamo);
                        }
                    }//Cierre for(int k = 0; k < cantSocios; k++ )
                }//Cierre if((prestamos[j].ocupado) && (libros[i].idL == prestamos[j].idLibro))
            }//Cierre 2do For
        }//Cierre if(libros[i].ocupado)
    }//Cierre 1er For

}

