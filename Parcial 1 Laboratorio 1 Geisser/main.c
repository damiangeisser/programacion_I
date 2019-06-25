#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "input.h"
#include "socio.h"

#define TAM_AUT 100
#define TAM_LIB 100
#define TAM_SOC 100
#define TAM_PRES 100

int main()
{
    eAutor listaAutores[TAM_AUT]= {{101,"Lovecraft","Howard",1},{102,"Moorecock","Michael",1},{103,"Herbert","Frank",1},{104,"Leguin","Ursula",1},{105,"Borges","Luis",1}};

    eLibro listaLibros[TAM_LIB]= {{1001,"La llamada de Cthulhu",101,1},{1002,"Duna",103,1},{1003,"El mago de Terramar",104,1},{1004,"El aleph",105,1},{1005,"El mesias de Duna",103,1},{1006,"El libro de arena",105,1},{1007,"Elric de Melnibone",102,1}};

// Inicio hardcoding ----------
//
//    eSocio listaSocios[TAM_SOC]= {{1,"Juan","Perez",'M',"1523647825","jperez@gmail.com",{25,3,2015},1},
//        {2,"Maria","Juarez",'F',"1523659874","mjuarez@hotmail.com",{30,10,2015},1},
//        {3,"Alberto","Perez",'M',"1585423691","aperez@hotmail.com",{15,2,2018},1},
//        {4,"Carla","Gomez",'F',"1585359491","cgomez@gmail.com",{6,4,2019},1},
//        {5,"Dario","Schaf",'M',"1598319461","dschaf@gmail.com",{13,10,2018},1},
//    };
//
//    ePrestamo listaPrestamos[TAM_PRES]= {{1,1001,2,{15,3,2019},1},{2,1003,2,{20,3,2019},1},{3,1004,3,{15,3,2019},1},
//        {4,1006,4,{22,3,2018},1},{5,1004,5,{22,3,2019},1},{6,1001,3,{15,4,2019},1},{7,1002,2,{20,3,2019},1},{8,1006,3,{15,8,2019},1},
//        {9,1004,2,{18,3,2019},1},{10,1004,1,{15,8,2019},1}
//    };
// Fin hardcoding ----------

    eSocio listaSocios[TAM_SOC];// Comentar esta línea si se utiliza el harcoding.<-----
    ePrestamo listaPrestamos[TAM_PRES];// Comentar esta línea si se utiliza el harcoding.<-----

    char exitChar='n';
    int banderaAlta;
    int banderaOrdenL = 0;
    int banderaOrdenS = 0;
    int idAutoIn=1;// Comentar esta línea si se utiliza el harcoding.<-----
    int idAutoInPrestamo=1;// Comentar esta línea si se utiliza el harcoding.<-----
//    int idAutoIn=6;;// Descomentar esta línea si se utiliza el harcoding.<-----
//    int idAutoInPrestamo=11;// Descomentar esta línea si se utiliza el harcoding.<-----

    inicializarSocios(listaSocios, TAM_SOC);// Comentar esta línea si se utiliza el harcoding.<-----
    inicializarPrestamos(listaPrestamos, TAM_PRES);// Comentar esta línea si se utiliza el harcoding.<-----

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
            banderaOrdenS = 0;
            system("pause");
            break;
        case 2:
            modificarSocio(listaSocios, TAM_SOC);
            banderaOrdenS = 0;
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
            do
            {
                switch(menuInformes())
                {
                case 1:
                    if(idAutoIn>1)
                    {
                        printf("\nEl total de prestamos es: %d\n",cantidadPrestamos(listaPrestamos, TAM_PRES));
                        printf("\nEl promedio diario de prestamos es: %.2f\n\n",promedioPrestamos(listaPrestamos, TAM_PRES));
                    }
                    else
                    {
                        printf("\n(!) No hay prestamos cargados en el sistema (!)\n");
                    }
                    system("pause");
                    break;
                case 2:
                    if(idAutoIn>1)
                    {
                        printf("\nEl numero de dias que no alcanzan el promedio de prestamos es: %d\n\n",verificarPromedioPrestamos(listaPrestamos, TAM_PRES));
                    }
                    else
                    {
                        printf("\n(!) No hay prestamos cargados en el sistema (!)\n");
                    }
                    system("pause");
                    break;
                case 3:
                    listarSociosPorLibro(listaAutores, listaSocios, listaLibros, listaPrestamos, TAM_AUT, TAM_SOC, TAM_LIB, TAM_PRES);
                    system("pause");
                    break;
                case 4:
                    listarLibrosPorSocio(listaAutores, listaSocios, listaLibros, listaPrestamos, TAM_AUT, TAM_SOC, TAM_LIB, TAM_PRES);
                    system("pause");
                    break;
                case 5:
                    contarPrestamosLibros(listaLibros, listaAutores, listaPrestamos, TAM_LIB, TAM_AUT, TAM_PRES);
                    system("pause");
                    break;
                case 6:
                    //printf("6- Listado de socios con la mayor cantidad de prestamos.\n");
                    contarPrestamosSocios(listaSocios, listaPrestamos,TAM_SOC, TAM_PRES);
                    system("pause");
                    break;
                case 7:
                    listarLibrosPorFecha(listaAutores, listaLibros, listaPrestamos, TAM_AUT, TAM_LIB, TAM_PRES);
                    system("pause");
                    break;
                case 8:
                    listarSociosPorFecha(listaSocios, listaPrestamos, TAM_SOC, TAM_PRES);
                    system("pause");
                    break;
                case 9:
                    if(!banderaOrdenL)
                    {
                        ordenarLibrosTituloDescendente(listaLibros, TAM_LIB);
                        banderaOrdenL = 1;
                    }
                    mostrarLibros(listaLibros, listaAutores, TAM_LIB, TAM_AUT);
                    system("pause");
                    break;
                case 10:
                    if(!banderaOrdenS)
                    {
                        ordenarSociosApellido(listaSocios, TAM_SOC);
                        banderaOrdenS = 1;
                    }
                    mostrarSocios(listaSocios, TAM_SOC);
                    system("pause");
                    break;
                case 11:
                    exitChar = 's';
                    break;
                default:
                    printf("\n Opcion invalida\n\n");
                    system("pause");
                }
            }
            while(exitChar != 's');
            exitChar = 'n';
            break;
        case 9:
            printf("\nConfirma la salida del programa? s/n: ");
            fflush(stdin);
            exitChar = getche();

            if(tolower(exitChar) == 's')
            {
                printf("\n\n- Programa finalizado -\n");
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
        }
    }
    while(exitChar != 's');

    return 0;

}


