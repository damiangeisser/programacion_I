#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de caracteres latinos.
#include <locale.h>//Permite el uso de caracteres latinos.
#include "geisser.h"

float sumar(float sumando1, float sumando2);
float restar(float minuendo, float sustraendo);
float multiplicar(float factor1, float factor2);
float dividir(float dividendo, float divisor);
int factorial(int operandoFac);

int main()
{
    int opcion;
    float operandoUno = 0;
    float operandoDos = 0;
    float rtaSuma;
    float rtaResta;
    float rtaMulti;
    float rtaDiv;
    int rtaFactor1;
    int rtaFactor2;
    int errorDiv = 0;
    int errorFactor1 = 0;
    int errorFactor2 = 0;
    int mostrarOk = 0;

    setlocale(LC_ALL, "");//Activa el uso de caracteres latinos.

    do
    {
        printf("\nPor favor elija la acción a realizar y presione enter:\n\n1 - Ingresar el primer operando.\n\n2 - Ingresar el segundo operando.\n\n3 - Realizar todas las operaciones.\n\n4 - Mostrar los resultados.\n\n5 - Salir.\n\n");

        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            printf("\nPor favor ingrese el 1er operando y presione enter: ");
            scanf("%f", &operandoUno);
            break;
        case 2:
            printf("\nPor favor ingrese el 2do operando y presione enter: ");
            scanf("%f", &operandoDos);
            break;
        case 3:
            rtaSuma=sumar(operandoUno, operandoDos);

            rtaResta=restar(operandoUno, operandoDos);

            //Inicio división con validación
            if(operandoDos == 0)
            {
                errorDiv = 1;
            }
            else
            {
                rtaDiv=dividir(operandoUno, operandoDos);
            }
            //Fin división con validación

            rtaMulti=multiplicar(operandoUno, operandoDos);

            //Incio factorial del primer operando con validación.
            if(operandoUno < 1)
            {
                errorFactor1 = 1;
            }
            else
            {
                rtaFactor1 = factorial(operandoUno);
            }
            //Fin primer factorial

            //Inicio factorial del segundo operando con validación.
            if(operandoDos < 1)
            {
                errorFactor2 = 1;
            }
            else
            {
                rtaFactor2 = factorial(operandoDos);
            }
            //Fin segundo factorial

            printf("\n>>> Operaciones realizadas <<<\n\n");

            mostrarOk = 1;
            break;
        case 4:
            if(mostrarOk)
            {
                printf("\nEl resultado de %f + %f es: %f\n", operandoUno, operandoDos, rtaSuma);

                printf("\nEl resultado de %f - %f es: %f\n", operandoUno, operandoDos, rtaResta);

                //Inicio mensajes de la división.
                if(errorDiv)
                {
                    printf("\nNo es posible dividir por cero.\n");
                }
                else
                {
                    printf("\nEl resultado de %f / %f es: %f\n", operandoUno, operandoDos, rtaDiv);
                }
                //Fin mensajes de la división.

                printf("\nEl resultado de %f x %f es: %f\n", operandoUno, operandoDos, rtaMulti);

                //Inicio mensajes del 1er factorial.
                if(errorFactor1)
                {
                    printf("\nNo fue posible calcular el factorial del primer operando, debe ser mayor o igual a 1 ");
                }
                else
                {
                    printf("\nEl factorial de %0.f es: %d ", operandoUno, rtaFactor1);
                }
                //Fin mensajes del 1er factorial.

                //Inicio mensajes del 2do factorial.
                if(errorFactor2)
                {
                    printf("y no fue posible calcular el factorial del segundo operando, debe ser mayor o igual a 1\n");
                }
                else
                {
                    printf("y el factorial de %0.f es: %d\n", operandoDos, rtaFactor2);
                }
                //Fin mensajes del 2do factorial.

                //Reinicio de las variables.
                operandoUno = 0;
                operandoDos = 0;
                //Reinicio la bandera de las operaciones.
                mostrarOk = 0;
            }
            else
            {
                printf("\n(!) Debe elegir previamente la opción 3\npara obtener los resultados a mostrar (!)\n\n");
            }
            break;
        case 5:
            printf("\n----- Programa finalizado -----\n\n");
            break;
        default:
            printf("\n(!) %d no es una opción válida (!)\n\n", opcion);
        }


    }
    while(opcion!=5);

    return 0;
}

