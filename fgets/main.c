#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[64];
    int cantidad;

    printf("Nombre: ");
    //fgets(buffer, 62, stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);//Nombre de la cadena, largo de la cadena en bytes -2

    cantidad = strlen(buffer);//strlen devuelve la cantidad de elementos del string incluyendo el caracter último caracter con basura. Probar para recorrer vectores.

    buffer[cantidad-1] = '\0';//Pone el caracter terminador en el caracter de más.

    printf("%s", buffer);

    return 0;
}
