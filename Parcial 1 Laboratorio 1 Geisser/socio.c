#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "input.h"
#include "socio.h"

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
    printf("8- Informes\n");
    printf("9- Salir\n");

    getInt(&opcion,"\nIngrese una opcion: ","(!) Opcion invalida (!)", 1, 9);

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

    obtenerAutor(autores, tamAutores, libro.idAutor, autorNA);

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
            mostrarLibro(autores, tamAutores, vec[i]);
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

        getCharGender(&vec[indice].sexo,"Ingrese el sexo: ","(!) Error: ingrese f o m (!)");

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
                getCharGender(&vec[indice].sexo,"Ingrese el nuevo sexo: ","(!) Error: ingrese f o m (!)");

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
// 17 -----------------------------------------------------------
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

// 18 -----------------------------------------------------------
int menuInformes()
{
    int opcion;

    system("cls");
    printf("--- Informes Socios ---\n\n");
    printf("1- Total general y promedio diario de los prestamos.\n");
    printf("2- Cantidad de dias con prestamos por debajo del promedio.\n");
    printf("3- Socios que solicitaron un libro determinado.\n");
    printf("4- Libros solicitados por un socio determinado.\n");
    printf("5- Listado de libros menos solicitados.\n");
    printf("6- Listado de socios con la mayor cantidad de prestamos.\n");
    printf("7- Listado de libros solicitados en una fecha determinada.\n");
    printf("8- Listado de socios que solicitaron libros en una fecha determinada.\n");
    printf("9- Listado de libros ordenados por titulo.\n");
    printf("10- Listado de socios ordenados por apellido.\n");
    printf("11- Regresar al menu principal.\n");

    getInt(&opcion,"\nIngrese una opcion: ","(!) Opcion invalida (!)", 1, 11);

    return opcion;
}
// 19 -----------------------------------------------------------
int cantidadPrestamos(ePrestamo prestamos[], int tamP)
{
    int cantidadP=0;

    for (int i=0; i<tamP; i++)
    {
        if(prestamos[i].ocupado)
        {
            cantidadP++;
        }
    }
    //printf("\nEl total de prestamos es: %d\n",cantidadP);
    return cantidadP;
}
// 20 -----------------------------------------------------------
int ordenarPrestamos(ePrestamo prestamos[], int tamP)
{
    ePrestamo pAux;

    for (int i=0; i<tamP-1; i++)
    {
        for(int j=i+1; j<tamP; j++)
        {
            if((prestamos[i].fechaPrestamo.anio>prestamos[j].fechaPrestamo.anio)||(prestamos[i].fechaPrestamo.anio==prestamos[j].fechaPrestamo.anio && prestamos[i].fechaPrestamo.mes>prestamos[j].fechaPrestamo.mes)||(prestamos[i].fechaPrestamo.anio==prestamos[j].fechaPrestamo.anio && prestamos[i].fechaPrestamo.mes==prestamos[j].fechaPrestamo.mes && prestamos[i].fechaPrestamo.dia>prestamos[j].fechaPrestamo.dia))
            {
                pAux = prestamos[j];
                prestamos[j]=prestamos[i];
                prestamos[i]=pAux;
            }
        }
    }
    return 1;
}
// 21 -----------------------------------------------------------
int mostrarPrestamos(ePrestamo prestamos[], int tamP)
{
    system("cls");
    printf("\nPrestamos registrados:\n");
    printf("ID ID Socio ID Libro Fecha\n");
    for (int i=0; i<tamP; i++)
    {
        if(prestamos[i].ocupado)
        {
            printf("%d\t%d\t%d\t%d/%d/%d\n",prestamos[i].idP,prestamos[i].idSocio,prestamos[i].idLibro,prestamos[i].fechaPrestamo.dia,prestamos[i].fechaPrestamo.mes,prestamos[i].fechaPrestamo.anio);

        }
    }
    return 1;
}

// 22 -----------------------------------------------------------
float promedioPrestamos(ePrestamo prestamos[], int tamP)
{
    int cantidadP;
    int fechasDif=1;
    float promedio;

    cantidadP=cantidadPrestamos(prestamos,tamP);

    ordenarPrestamos(prestamos,tamP);

    for (int i=0; i<tamP-1; i++)
    {
        for(int j = i+1; j<tamP; j++)
        {
            if((prestamos[i].ocupado && prestamos[j].ocupado)&&(prestamos[i].fechaPrestamo.dia!=prestamos[j].fechaPrestamo.dia || prestamos[i].fechaPrestamo.mes!=prestamos[j].fechaPrestamo.mes || prestamos[i].fechaPrestamo.anio!=prestamos[j].fechaPrestamo.anio))
            {
                i=j;
                fechasDif++;
            }
        }
    }
    //printf("\nEl total de fechas diferentes es: %d\n",fechasDif);
    promedio=(float)cantidadP/fechasDif;

    //printf("\nEl promedio de prestamos por dia es: %.2f\n\n",promedio);
    return promedio;
}
// 23 -----------------------------------------------------------
int verificarPromedioPrestamos(ePrestamo prestamos[], int tamP)
{
    int contNoPromedio=0;
    float contPrestamos=1;
    float promedio;

    promedio = promedioPrestamos(prestamos, tamP);

    for (int i=0; i<tamP-1; i++)
    {
        for(int j = i+1; j<tamP; j++)
        {
            if(prestamos[i].ocupado && prestamos[j].ocupado)
            {
                if(prestamos[i].fechaPrestamo.dia==prestamos[j].fechaPrestamo.dia && prestamos[i].fechaPrestamo.mes==prestamos[j].fechaPrestamo.mes && prestamos[i].fechaPrestamo.anio==prestamos[j].fechaPrestamo.anio)
                {
                    contPrestamos++;
                }
                else
                {
                    i=j;
                    if (contPrestamos<promedio)
                    {
                        contNoPromedio++;
                    }
                    contPrestamos = 1;
                }
            }
        }
    }

    if((prestamos[tamP-1].ocupado && prestamos[tamP-2].ocupado) && (prestamos[tamP-1].fechaPrestamo.dia!=prestamos[tamP-2].fechaPrestamo.dia || prestamos[tamP-1].fechaPrestamo.mes!=prestamos[tamP-2].fechaPrestamo.mes || prestamos[tamP-1].fechaPrestamo.anio!=prestamos[tamP-2].fechaPrestamo.anio)&&(promedio>1))
    {
        contNoPromedio++;
    }

    //printf("\nEl numero de dias que no alcanzan el promedio de prestamos es: %d\n",contNoPromedio);

    return contNoPromedio;
}
// 24 -----------------------------------------------------------
void listarSociosPorLibro(eAutor autores[], eSocio socios[], eLibro libros[], ePrestamo prestamos[], int tamAutores, int tamSocios, int tamLibros, int tamPrestamos)
{
    int idLibroAux;
    int flagOk = 0;

    mostrarLibrosOrdenados(autores,tamAutores, libros,tamLibros);

    getInt(&idLibroAux,"\nIngrese el ID del libro a buscar: ","(!) Id no valido (!)",1,5000);

    system("cls");
    printf("\n--- Socios que solicitaron el libro ID: %d ---\n\n",idLibroAux);
    for(int i = 0; i <tamPrestamos; i++)
    {
        if(prestamos[i].ocupado && prestamos[i].idLibro==idLibroAux)
        {
            for(int j = 0; j<tamSocios; j++)
            {
                if((socios[j].ocupado) && (prestamos[i].idSocio == socios[j].idS))
                {
                    mostrarSocio(socios[j]);
                    flagOk =1;
                }//Cierre if ((socios[j].ocupado) && (prestamos[i].idSocio == socios[j].idS))
            }//Cierre 2do For
        }//Cierre if (prestamos[i].ocupado && prestamos[i].idLibro==idLibroAux)
    }//Cierre 1er For

    if(!flagOk)
    {
        printf("\n(!) No se han hallado prestamos de ese libro (!)\n");
    }
}

// 25 -----------------------------------------------------------
void listarLibrosPorSocio(eAutor autores[], eSocio socios[], eLibro libros[], ePrestamo prestamos[], int tamAutores, int tamSocios, int tamLibros, int tamPrestamos)
{
    int idSocioAux;
    int flagOk = 0;

    mostrarSociosOrdenados(socios, tamSocios);

    getInt(&idSocioAux,"\nIngrese el ID del socio a buscar: ","(!) Id no valido (!)",1,5000);

    system("cls");
    printf("\n--- Libros solicitados por el socio ID: %d ---\n\n",idSocioAux);
    for(int i = 0; i <tamPrestamos; i++)
    {
        if(prestamos[i].ocupado && prestamos[i].idSocio==idSocioAux)
        {
            for(int j = 0; j<tamLibros; j++)
            {
                if((libros[j].ocupado) && (prestamos[i].idLibro == libros[j].idL))
                {
                    mostrarLibro(autores, tamAutores, libros[j]);
                    flagOk =1;
                }//Cierre if ((libros[j].ocupado) && (prestamos[i].idLibro == libros[j].idL))
            }//Cierre 2do For
        }//Cierre if (prestamos[i].ocupado && prestamos[i].idSocio==idSocioAux)
    }//Cierre 1er For

    if(!flagOk)
    {
        printf("\n(!) No se han hallado prestamos para ese socio (!)\n");
    }
}
// 26 -----------------------------------------------------------
void listarLibrosPorFecha(eAutor autores[], eLibro libros[], ePrestamo prestamos[], int tamAutores, int tamLibros, int tamPrestamos)
{
    eFecha fechaAux;
    int flagOk = 0;

    getDate(&fechaAux.anio,&fechaAux.mes,&fechaAux.dia,"prestamo",2000,2020);

    system("cls");
    printf("\n--- Libros solicitados el %d/%d/%d ---\n\n",fechaAux.dia,fechaAux.mes,fechaAux.anio);
    for(int i = 0; i <tamPrestamos; i++)
    {
        if((prestamos[i].ocupado) && (prestamos[i].fechaPrestamo.dia==fechaAux.dia && prestamos[i].fechaPrestamo.mes==fechaAux.mes && prestamos[i].fechaPrestamo.anio==fechaAux.anio))
        {
            for(int j = 0; j<tamLibros; j++)
            {
                if((libros[j].ocupado) && (prestamos[i].idLibro == libros[j].idL))
                {
                    mostrarLibro(autores, tamAutores, libros[j]);
                    flagOk =1;
                }//Cierre if ((libros[j].ocupado) && (prestamos[i].idLibro == libros[j].idL))
            }//Cierre 2do For
        }//Cierre if ((prestamos[i].ocupado) && (prestamos[i].fechaPrestamo.dia==fechaAux.dia && prestamos[i].fechaPrestamo.mes==fechaAux.mes && prestamos[i].fechaPrestamo.anio==fechaAux.anio)
    }//Cierre 1er For

    if(!flagOk)
    {
        printf("\n(!) No se han hallado prestamos para esa fecha (!)\n");
    }
}
// 27 -----------------------------------------------------------
void listarSociosPorFecha(eSocio socios[], ePrestamo prestamos[], int tamSocios, int tamPrestamos)
{
    eFecha fechaAux;
    int flagOk = 0;

    getDate(&fechaAux.anio,&fechaAux.mes,&fechaAux.dia,"prestamo",2000,2020);

    system("cls");
    printf("\n--- Libros solicitados el %d/%d/%d ---\n\n",fechaAux.dia,fechaAux.mes,fechaAux.anio);
    for(int i = 0; i <tamPrestamos; i++)
    {
        if((prestamos[i].ocupado) && (prestamos[i].fechaPrestamo.dia==fechaAux.dia && prestamos[i].fechaPrestamo.mes==fechaAux.mes && prestamos[i].fechaPrestamo.anio==fechaAux.anio))
        {
            for(int j = 0; j<tamSocios; j++)
            {
                if((socios[j].ocupado) && (prestamos[i].idSocio == socios[j].idS))
                {
                    mostrarSocio(socios[j]);
                    flagOk =1;
                }//Cierre if ((libros[j].ocupado) && (prestamos[i].idLibro == libros[j].idL))
            }//Cierre 2do For
        }//Cierre if ((prestamos[i].ocupado) && (prestamos[i].fechaPrestamo.dia==fechaAux.dia && prestamos[i].fechaPrestamo.mes==fechaAux.mes && prestamos[i].fechaPrestamo.anio==fechaAux.anio)
    }//Cierre 1er For

    if(!flagOk)
    {
        printf("\n(!) No se han hallado socios que hayan solicitado prestamos para esa fecha (!)\n");
    }
}
// 28 -----------------------------------------------------------
void ordenarLibrosTituloDescendente(eLibro libros[],int tamLibros)
{
    int fin = tamLibros-1;
    int comienzo = 0;
    int flagSwap;
    eLibro libroAux;

    do//Cocktail sort
    {
        flagSwap=0;
        for (int i = comienzo;  i < fin; i++)
        {
            if ((libros[i].ocupado!=0 && libros[i+1].ocupado!=0) && (strcmp(libros[i].titulo, libros[i+1].titulo)<0))
            {
                libroAux=libros[i];
                libros[i]=libros[i+1];
                libros[i+1]=libroAux;
                flagSwap=1;
            }
        }
        fin--;

        for (int i = fin; i >= 0; i--)
        {
            if ((libros[i].ocupado!=0 && libros[i-1].ocupado!=0) && (strcmp(libros[i].titulo, libros[i-1].titulo)>0))
            {
                libroAux=libros[i];
                libros[i]=libros[i-1];
                libros[i-1]=libroAux;
                flagSwap=1;
            }
        }
        comienzo++;
    }
    while (flagSwap);
}
// 29 -----------------------------------------------------------
void ordenarSociosApellido(eSocio socios[], int tamSocios)
{
    int i;
    int j;
    eSocio socioAux;

    for (i = 1; i < tamSocios; i++)
    {
        socioAux = socios[i];
        j = i - 1;
        while ((j >= 0) && strcmp(socioAux.apellido, socios[j].apellido)<0)
        {
            socios[j + 1] = socios[j];
            j--;
            socios[j + 1] = socioAux;
        }
    }
}

// 30 -----------------------------------------------------------
void mostrarSocios(eSocio socios[], int tamSocios)
{
    int contador = 0;

    system("cls");
    printf("\nCarnet   Apellido\tNombre\tSexo\tTelefono\teMail\tFecha de alta\n");

    for(int i=0; i < tamSocios; i++)
    {
        if(socios[i].ocupado == 1)
        {
            mostrarSocio(socios[i]);
            contador++;
        }
    }

    if(contador == 0)
    {
        printf("\n(!) No hay socios que mostrar (!)\n");
    }
}
// 31 -----------------------------------------------------------
void mostrarLibros(eLibro libros[], eAutor autores[], int tamLibros, int tamAutores)
{
    int contador = 0;

    system("cls");
    printf("\nCodigo\tTitulo\tAutor\n");

    for(int i=0; i < tamLibros; i++)
    {
        if(libros[i].ocupado == 1)
        {
            mostrarLibro(autores, tamAutores, libros[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\n(!) No hay libros que mostrar (!)\n");
    }
}
// 32 -----------------------------------------------------------
void contarPrestamosLibros(eLibro libros[], eAutor autores[], ePrestamo prestamos[], int tamLibros, int tamAutores,int tamPrestamos)
{
    int vecesPrestado=0;
    int minimo;
    int flagMinimo = 0;

    for(int i=0; i < tamLibros; i++)
    {
        vecesPrestado=0;

        if(libros[i].ocupado != 0)
        {
            for (int j = 0; j < tamPrestamos; j++)
            {
                if(prestamos[j].ocupado!=0 && (libros[i].idL==prestamos[j].idLibro))
                {
                    vecesPrestado++;
                }
            }
            if(!vecesPrestado)
            {
                minimo = 0;
            }
        }

        if(!flagMinimo && vecesPrestado!=0)
        {
            minimo = vecesPrestado;
            flagMinimo = 1;
        }
        if(vecesPrestado<minimo && vecesPrestado!=0)
        {
            minimo = vecesPrestado;
        }
    }

    printf("\nLos libros menos solicitados (con %d prestamos) son: \n",minimo);

    for(int i=0; i < tamLibros; i++)
    {
        vecesPrestado=0;

        if(libros[i].ocupado != 0)
        {
            for (int j = 0; j < tamPrestamos; j++)
            {
                if(prestamos[j].ocupado!=0 && (libros[i].idL==prestamos[j].idLibro))
                {
                    vecesPrestado++;
                }
            }
        }
        if(libros[i].ocupado != 0 && vecesPrestado==minimo)
        {
            mostrarLibro(autores, tamAutores, libros[i]);
        }
    }
}
// 33 -----------------------------------------------------------
void contarPrestamosSocios(eSocio socios[], ePrestamo prestamos[],int tamSocios, int tamPrestamos)
{
    int solicitudes=0;
    int maximo=0;
    int flagMax = 0;

    for(int i=0; i < tamSocios; i++)
    {
        solicitudes=0;

        if(socios[i].ocupado != 0)
        {
            for (int j = 0; j < tamPrestamos; j++)
            {
                if(prestamos[j].ocupado!=0 && (socios[i].idS==prestamos[j].idSocio))
                {
                    solicitudes++;
                }
            }
        }

        if(!flagMax && solicitudes!=0)
        {
            maximo = solicitudes;
            flagMax = 1;
        }
        if(solicitudes>maximo && solicitudes!=0)
        {
           maximo = solicitudes;
        }
    }

    printf("\nLos socios con mas solicitudes (con %d prestamos) son: \n",maximo);

    for(int i=0; i < tamSocios; i++)
    {
        solicitudes=0;

        if(socios[i].ocupado != 0)
        {
            for (int j = 0; j < tamPrestamos; j++)
            {
                if(prestamos[j].ocupado!=0 && (socios[i].idS==prestamos[j].idSocio))
                {
                    solicitudes++;
                }
            }
        }
        if(socios[i].ocupado != 0 && solicitudes==maximo)
        {
             mostrarSocio(socios[i]);
        }
    }
}
