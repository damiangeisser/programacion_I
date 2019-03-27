#include <stdio.h>
#include <stdlib.h>

int main()
{

    int nro;

    int* n;//Declaraci�n de un puntero.

    nro = 3;
    n = &nro;//Asigno la direcci�n de memoria de nro a n.

    printf("%d", nro);//Muestar el contenido de nro.

    printf("%p", n);// Muestra la direcci�n de memoria almacenada en n.

    printf("%d", *n);//Muestra lo contenido en la direcci�n de memoria contenida en n, es decir nro.

    //En el argumento de las funciones y en el protptipo incluyo un puntero Ej: funcion(int* x) el dato que le paso
    //debe ser la direcci�n de memoria en la llamada funcion(&variablePasada)


    return 0;
}
