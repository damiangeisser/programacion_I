#include <stdio.h>
#include <stdlib.h>

int main()
{
    char hora;

    printf("Ingrese la hora y presione enter: \n");

    scanf( "%c", &hora);//%c es la máscara para char, %s es la máscara para string.

    //fflush(stdin);//Limpia el buffer sólo en Windows
    setbuf(NULL, stdin);//Limpia el buffer en Windows, Linux y MacOS

    switch(hora){
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
        printf("A dormir.");
        break;
    case '7':
    case '8':
        printf("Buenos dias");
        break;
    default:
        printf("Error - Ingrese un valor entre 0 y 8");
    }

    return 0;
}
