#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de caracteres de otros idiomas.
#include <locale.h>//Permite el uso de símbolos de monedas y otros.

//Parcial ingreso, ejercicio 1.

void main(void)
{
    int ancho;
    int alto;

    setlocale(LC_ALL, "");

    printf("Por favor ingrese el ancho del rectángulo en cm. y presione enter: \n");

    scanf("%d", &ancho);

    printf("Por favor ingrese el alto del rectángulo en cm. y presione enter: \n");

    scanf("%d", &alto);

    printf("El área del rectángulo es %d cm2", ancho*alto);

}
