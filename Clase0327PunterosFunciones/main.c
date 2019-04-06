#include <stdio.h>
#include <stdlib.h>

int main()
{

//    int nro;
//
//    int* n;//Declaración de un puntero.
//
//    nro = 3;
//    n = &nro;//Asigno la dirección de memoria de nro a n.
//
//    printf("%d", nro);//Muestar el contenido de nro.
//
//    printf("%p", n);// Muestra la dirección de memoria almacenada en n.
//
//    printf("%d", *n);//Muestra lo contenido por indirección en la dirección de memoria contenida en n, es decir nro.
//
//    //En el argumento de las funciones y en el protptipo incluyo un puntero Ej: funcion(int* x) el dato que le paso
//    //debe ser la dirección de memoria en la llamada funcion(&variablePasada)

    int x, y;

    printf("ingrese x");
    scanf("%d", &x);

    printf("ingrese y");
    scanf("%d", &y);

    muestra(&x, y);//Envío la dirección de memoria de x y el valor de la variable y

    printf("x: %d y: %d", x, y);


    return 0;
}

void muestra (int* x, int y)//Espera una dirección de memoria y una variable.
{
    *x = y;//Asigna el valor de y a la indirección de x es decir lo almacenado en la variable x del main.

    printf("x: %d y: %d", *x, y);

}
