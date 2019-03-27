#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de caracteres de otros idiomas.
#include <locale.h>//Permite el uso de símbolos de monedas y otros.

float sumar(float x, float y);
float restar(float x, float y);

int main()
{
    float operandoUno;
    float operandoDos;
    float rtaSuma;
    float rtaResta;

    setlocale(LC_ALL, "");//Activa el uso de caracteres latinos

    printf("Por favor ingrese el 1er operando y presione enter:\n");

    scanf("%f", &operandoUno);

    printf("Por favor ingrese el 2er operando y presione enter:\n");

    scanf("%f", &operandoDos);

    rtaSuma = (sumar(operandoUno, operandoDos));

    printf("El resultado de %.2f + %.2f es: %.2f", operandoUno, operandoDos, rtaSuma);

    rtaResta = (restar(operandoUno, operandoDos));

    printf("El resultado de %.2f - %.2f es: %.2f", operandoUno, operandoDos, rtaResta);


    return 0;
}

float sumar(float x, float y){

    return x+y;
}

float restar(float x, float y){

    return x-y;
}
