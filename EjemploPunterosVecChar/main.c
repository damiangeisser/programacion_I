#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(char* punteroCadena);
void mostrarCadena2(char* punteroCadena);
void mostrarCadena3(char* punteroCadena);

int main()
{
    char letra='a';
    char palabra[]="Hola";

    char *p, *q;

    p=&letra;

    q=palabra;

    printf("\nDato\tPosicion de memoria\n");

    mostrarCadena(palabra);

    printf("\n\n------------------------------\n");

    printf("\nDato\tPosicion de memoria\n");

    mostrarCadena3(palabra);

    return 0;
}

void mostrarCadena(char* punteroCadena)
{
    while(*punteroCadena != '\0')
    {
        printf("\n%c",*punteroCadena);
        printf("\t%p",punteroCadena);
        punteroCadena++;
    }
}

void mostrarCadena2(char* punteroCadena)
{
    for(int i=0; i<strlen(punteroCadena); i++)
    {

        printf("\n%c",*(punteroCadena+i));
        printf("\t%p",punteroCadena);
    }
}

void mostrarCadena3(char* punteroCadena)
{
    int i = 0;

    while(*(punteroCadena+i) != '\0')
    {
        printf("\n%c",*(punteroCadena+i));
        printf("\t%p",punteroCadena);
        i++;
    }
}

