#include <stdio.h>
#include <stdlib.h>
#include <string.h>//Necesario para fgets

int main()
{

    char cadena[50];

    int vec1[3]:{-1,2,10};

    int vec2[5]:{-3,2,4,15,18};


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




    return 0;
}
