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
////    Creaci�n de una m�scara para poder mostrar un entero u otro tipo de dato concatenado:
////        %d m�scara decimales
////        %i m�scara enteros
////        %f m�scara float
////        %c m�scara char
////    printf("El tamanio en memoria de un int es: %d bytes\nEl tamanio en memoria de un float es: %d bytes\nEl tamanio en memoria de un char es: %d bytes\n", sizeof(int), sizeof(float), sizeof(char));
////    system(("pause"));
////    return 0;
//
//    int numero = 10;
//    int numero2 = 34;
//    char letra = 'a';// doble comilla string ej: "a", comilla simples caracter ej: 'a', la variable a ej: a.
//    char letra2 = '2';//guardado en memoria con su valor de ASCII, no como el n�mero 2.
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
//    printf("La variable letra en ASCII vale %d \n", letra);//La m�scara muestra el valor num�rico en el que est� almacenado la letra.
//
//    printf("La variable letra en ASCII vale %d \n", letra2);
//
//    printf("La variable altura vale %f \n", altura);//C muestra 6 decimales.
//
//    printf("La variable altura vale %.2f \n", altura);//Limito a dos decimales.
//
//    printf("La variable altura vale %.0f \n", altura);//Sin decimales, redondea al valor m�s cercano.
//
//    printf("La variable altura vale %d \n", altura);//Muestra cero, no puede representarse.
//
//    numero2 = altura;
//
//    printf("La variable numero2 vale %d \n", numero2);//Convierte de float a entero sin decimales, redondea al valor m�s cercano.
//
//    printf("La variable altura vale %.2f y la variable letra vale %c \n", altura, letra);
//
//    printf("%d \n", x);//Muestra la basura de la memoria porque la variabe no est� asignada.
//
//    return 0;
//}

int main()
{
    int numero;//No le asigno valor porque el primer uso que se le va a dar es en una asignaci�n

    //printf(" %d ", &numero);//Muestra la direcci�n de memoria.

    printf("Ingrese un numero: \n");//Mensaje para orientar al usuario as� no aparezca s�lo el cursor.

    scanf("%d", &numero);//Sintaxis para pedir datos (leer el buffer), la m�scara debe coincidir con el tipo de datos.

    printf("Usted ingreso: %d \n", numero);

    return 0;
}
