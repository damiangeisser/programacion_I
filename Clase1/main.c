#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//    printf("Hello world!\n");
//    system(("pause"));
//    return 0;
//}


//int main()
//{
////    Creación de una máscara para poder mostrar un entero u otro tipo de dato concatenado:
////        %d máscara decimales
////        %i máscara enteros
////        %f máscara float
////        %c máscara char
////    printf("El tamanio en memoria de un int es: %d bytes\nEl tamanio en memoria de un float es: %d bytes\nEl tamanio en memoria de un char es: %d bytes\n", sizeof(int), sizeof(float), sizeof(char));
////    system(("pause"));
////    return 0;
//
//    int numero = 10;
//    int numero2 = 34;
//    char letra = 'a';// doble comilla string ej: "a", comilla simples caracter ej: 'a', la variable a ej: a.
//    char letra2 = '2';//guardado en memoria con su valor de ASCII, no como el número 2.
//    float altura = 23.5;
//    int x;
//
//    printf("%d %d \n", numero, numero2);
//
//    printf("%d \n", numero + numero2);
//
//    printf("La variable numero vale %d \n", numero);
//
//    printf("La variable numero vale %d y numero2 vale %d \n", numero, numero2);
//
//    printf("La variable letra vale %c \n", letra);
//
//    printf("La variable letra en ASCII vale %d \n", letra);//La máscara muestra el valor numérico en el que está almacenado la letra.
//
//    printf("La variable letra en ASCII vale %d \n", letra2);
//
//    printf("La variable altura vale %f \n", altura);//C muestra 6 decimales.
//
//    printf("La variable altura vale %.2f \n", altura);//Limito a dos decimales.
//
//    printf("La variable altura vale %.0f \n", altura);//Sin decimales, redondea al valor más cercano.
//
//    printf("La variable altura vale %d \n", altura);//Muestra cero, no puede representarse.
//
//    numero2 = altura;
//
//    printf("La variable numero2 vale %d \n", numero2);//Convierte de float a entero sin decimales, redondea al valor más cercano.
//
//    printf("La variable altura vale %.2f y la variable letra vale %c \n", altura, letra);
//
//    printf("%d \n", x);//Muestra la basura de la memoria porque la variabe no está asignada.
//
//    return 0;
//}

int main()
{
    int numero;//No le asigno valor porque el primer uso que se le va a dar es en una asignación

    //printf(" %d ", &numero);//Muestra la dirección de memoria.

    printf("Ingrese un numero: \n");//Mensaje para orientar al usuario así no aparezca sólo el cursor.

    scanf("%d", &numero);//Sintaxis para pedir datos (leer el buffer), la máscara debe coincidir con el tipo de datos.

    printf("Usted ingreso: %d \n", numero);

    return 0;
}
