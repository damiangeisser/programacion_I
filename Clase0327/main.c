#include <stdio.h>
#include <stdlib.h>

int main()
{

    int nro;

    int* n;//Declaración de un puntero.

    nro = 3;
    n = &nro;//Asigno la dirección de memoria de nro a n.

    printf("%d", nro);//Muestar el contenido de nro.

    printf("%p", n);// Muestra la dirección de memoria almacenada en n.

    printf("%d", *n);//Muestra lo contenido en la dirección de memoria contenida en n, es decir nro.

    //En el argumento de las funciones y en el protptipo incluyo un puntero Ej: funcion(int* x) el dato que le paso
    //debe ser la dirección de memoria en la llamada funcion(&variablePasada)


    return 0;
}
