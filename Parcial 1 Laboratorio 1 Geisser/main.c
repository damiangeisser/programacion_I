#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "input.h"
#include "socio.h"

#define TAM_AUT 5
#define TAM_LIB 7
#define TAM_SOC 10
#define TAM_PRES 5

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

    char exitChar='n';
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


