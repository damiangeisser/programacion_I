#include <stdio.h>
#include <stdlib.h>
#include <string.h>//Necesario para fgets

int main()
{

    char cadena[50];

    char vec1[3];

    char vec2[5];


    fflush(stdin);

    //setbuf(NULL,stdin);//Equivalente a fflush(stdin) válida en linux, unix y windows.

    printf("Ingreso con scanf: ");

    scanf("%s", cadena);//Como el nombre del vector es la dirección de memoria del 1er elemento, no lleva &. cadena es lo mismo que &cadena[0]

    printf("\n%s\n\n", cadena);

    printf("Ingreso con gets: ");

    fflush(stdin);

    gets(cadena);//Tiene muchos problemas de seguridad. NO USAR. Sólo existe en Windows.

    printf("\n%s\n\n", cadena);

    fflush(stdin);

    fgets(cadena);//Hay que incluir <string.h> Desventaja: coloca dos finalizadores de cadena. Deja un caracter de más.

    printf("\n%s\n\n", cadena);

    strcmp(vec1, vec2);//Case sensitive. Devuelve 0 si vec1 == vec2, >0 si vec1 > vec2, <0 si vec1 < vec2 Compara los valores ASCII

    stricmp(vec1, vec2);//No es case sensitive.

    strcpy(vec1, vec2);//Copia el contenido del segundo parámetro se copia en el primero. El segundo puede ser variable, constante o cadena literal.

    return 0;
}
