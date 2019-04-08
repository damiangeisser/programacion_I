#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[5];
    char apellido[5];
    char nombreCompleto[41];// 19 + 19 + 2(coma y espacio) + 1 (terminador)
    //char espaciador[3]={',',' '}; No es necesario.

    printf("Ingrese su nombre: ");

    //gets(nombre);

    validarString(nombre, strlen(nombre));

    printf("Ingrese su apellido: ");

    //gets(apellido);

    validarString(apellido, strlen(apellido));

    //strlwr(nombre);
    //strlwr(apellido);

    //strupr(nombre[1]);//Mal, sólo recibe vectores.

    //strupr(apellido[1]);//Mal, sólo recibe vectores.

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");//No necesariamente tengo que copiar vectores.
    strcat(nombreCompleto,nombre);

    nombreCompleto[0] = toupper(nombreCompleto[0]);

    for(int i=0; i<strlen(nombreCompleto); i++)
    {
        if(nombreCompleto[i] == ' ')
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
        }
    }

//    printf("Su nombre es: ");//
//
//    for(int i=0; i < strlen(nombreCompleto);i++)
//    {
//        printf("%c", nombreCompleto[i]);
//    }

puts(nombreCompleto);//Imprime

    return 0;
}

int validarString(char* dirVector, int largo)
{
//char vecIngreso[largo];
char auxVec[largo*5];

gets(auxVec);

while(strlen(auxVec)>strlen(vecIngreso))
{
    printf("Error. Escriba nuevamente.\n");
    gets(auxVec);
}
strcpy(vecIngreso,auxVec);

//dirVector = vecIngreso;

return 0;
}

