#include <stdio.h>
#include <stdlib.h>

void getChar(char* message, char* caracter);
void mostraCadena(char* cadena);

int main()
{

    //char nombre[20] = "Sebastian";

    //char sexo;

    char mensaje[]="Hola mundo!";

//getChar("Ingrese sexo: ", &sexo);

//printf("El sexo es %c\n", sexo);

    mostrarCadena(mensaje);

    return 0;
}

void getChar(char* message, char* caracter)
{
    printf("%s", message);
    fflush(stdin);
    scanf("%c", caracter);
}

void mostrarCadena(char* cadena)
{

    printf("\n--- Funcion mostrarCadena ---\n");

    while(*cadena !='\0')
    {
        printf("%c", *cadena);
        cadena++;
    }
}
