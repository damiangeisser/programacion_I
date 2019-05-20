#include <stdio.h>
#include <stdlib.h>

void leerPuntero(int* p);

int main()
{

    int x =10;

    int* p = &x;//Puntero, contiene una dirección de memoria a un entero. *p cuando utilizo la variable.
    int* q = p;//El puntero q apunta al mismo lugar que p.

    int** r = &p;//Un puntero que almacena un puntero.

    printf("%d\n", **r);//Muestra x. Puntero a puntero.

//    char* j;//Puntero, contiene una dirección de memoria a un char.
//
//    p=&x;//Guarda la dirección de memoria de x en el puntero p.
//
//    printf("%d\n", x);
//
//    printf("%d\n", *p);//*p operador de indirección. printfmuestra el contenido de la dirección de memoria contenida en p.
//
//    printf("%x\n", p);//Muestra la dirección de memoria %x máscara para hexadecimal. %p muestra el puntero.
//
//    printf("%x\n", &x);//Ídem anterior.
//
//    printf("Direccion de x: %x\n", &x);
//
//    printf("Antes de llamar a la funcion\n");
//
//    printf("%d\n", x);
//
//    leerPuntero(&x);
//
//     printf("Despues de llamar a la funcion\n");

    printf("%d\n", x);

    return 0;
}

void leerPuntero(int* p)
{

//    printf("%d\n", *p);
    printf("Direccion guardada en p: %x\n", p);

    *p=38;//Afecto a x en el main desde el ámbito de la función.

}
