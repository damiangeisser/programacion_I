#include <stdio.h>

#define ARCH	"./bin.dat"
#define ESC 27//Constante del tipo char. en ASCII representa a escape para cerrar la aplicación.

struct a
{
    char nombre[31];
    int edad;
};

int main (void)
{
    FILE  *bin;//Crea un puntero a FILE
    struct a pers;
    system("pause");
    printf("\nSe va a generar por primera vez el archivo\n");
    if ((bin=fopen(ARCH,"wb"))==NULL)//Asigna el valor del puntero a bin y verifica que no sea NULL.
    {
        printf("El archivo no puede ser abierto");
        exit(1);
    }
    do
    {
        printf("\nIngrese el nombre: ");
        gets(pers.nombre);
        printf("Ingrese la edad: ");
        scanf("%d",&pers.edad);
        fflush(stdin);
        fwrite(&pers,sizeof(pers),1,bin);//Parámetros: puntero a la estructura, tamaño de la etructura, cantidad de estructuras, puntero al archivo.
        printf("\nPresione ESC para terminar");
    }
    while((getche())!=ESC);//Lee escape para terminar.

    fclose(bin);

    return 0;
}
