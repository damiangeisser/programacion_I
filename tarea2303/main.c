#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de diferentes tipos de caracter.
#include <locale.h>//Permite el uso de diferentes formatos de fecha, monedas, etc.

void main(void)
{
    int ancho;
    int largo;

    setlocale(LC_ALL, "");//Permite imprimir caracteres que no son estandar.

    printf("Por favor ingrese el ancho del rectángulo a calcular y presione enter: \n");

    scanf("%d", ancho);
}
