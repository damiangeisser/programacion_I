#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#include "input.h"
#include "socios.h"

#define TAM_AUT 5
#define TAM_LIB 7
#define TAM_SOC 10
#define TAM_PRES 5





int main()
{

    eAutor listaAutores[TAM_AUT]= {{101,"Lovecraft","Howard",1},{102,"Moorecock","Michael",1},{103,"Herbert","Frank",1},{104,"Leguin","Ursula",1},{105,"Borges","Luis",1}};

    eLibro listaLibros[TAM_LIB]= {{1001,"La llamada de Cthulhu",101,1},{1002,"Duna",103,1},{1003,"El mago de Terramar",104,1},{1004,"El Aleph",105,1},{1005,"El Mesias de Duna",103,1},{1006,"El libro de arena",105,1},{1007,"Eric de Melnibone",102,1}};

    eSocio listaSocios[TAM_SOC];

    ePrestamo listaPrestamos[TAM_PRES];

    char seguir = 's';
    char confirma;
    int banderaAlta;
    int idAutoIn=1;
    int idAutoInPrestamo=1;

    inicializarSocios(listaSocios, TAM_SOC);
    inicializarPrestamos(listaPrestamos, TAM_PRES);

    do
    {
        switch(menu())
        {

        case 1:


            banderaAlta = altaSocio(listaSocios, TAM_SOC, idAutoIn);

            if(banderaAlta){

                idAutoIn ++;
            }

            banderaAlta=0;

            system("pause");
            break;

        case 2:

            printf("modificar socio");
            system("pause");
            break;

        case 3:

            bajaSocio(listaSocios, TAM_SOC);
            system("pause");
            break;

        case 4:

            mostrarSociosOrdenados(listaSocios, TAM_SOC);
            system("pause");
            break;

        case 5:
            mostrarLibrosOrdenados(listaLibros, TAM_LIB);
            system("pause");
            break;

        case 6:

            mostrarAutoresOrdenados(listaAutores, TAM_AUT);
            system("pause");
            break;

        case 7:

              banderaAlta = altaPrestamos(listaPrestamos, TAM_PRES, listaSocios, TAM_SOC, listaLibros, TAM_LIB, idAutoInPrestamo, idAutoIn);

            if(banderaAlta){

                idAutoIn ++;
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
