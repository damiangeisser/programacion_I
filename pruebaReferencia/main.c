#include <stdio.h>
#include <stdlib.h>

int sumar(float sum1, float sum2, int* dir);


int main()
{
    float operandoUno = 20.35;
    float operandoDos = 30.84;
    float rtaSuma;

rtaSuma = operandoUno + operandoDos;

printf("\nEstos son los resultados: %f", rtaSuma);

sumar(operandoUno, operandoDos, &rtaSuma);

printf("\nEstos son los resultados: %f", rtaSuma);

    return 0;
}


int sumar(float sum1, float sum2, int* dir)
{
    float rtaFuncion;

    rtaFuncion = sum1 + sum2;

    printf("\nFuncion: %d\n\n", rtaFuncion);

    //*dir = rtaFuncion;

    return 0;
}
