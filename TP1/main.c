#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de caracteres de otros idiomas.
#include <locale.h>//Permite el uso de símbolos de monedas y otros.

float sumar(float x, float y);
float restar(float x, float y);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int main()
{
    int opcion;
    float operandoUno;
    float operandoDos;
    float rtaSuma;
    float rtaResta;

    setlocale(LC_ALL, "");//Activa el uso de caracteres latinos

    printf("Elija la acción a realizar y presione enter:\n1 - Ingresar el primer operando.\n2 - Ingresar el segundo operando.\n3 - Realizar todas las operaciones\n4 - Mostrar los resultados.\n5 - Salir.\n");

    scanf("%d", &opcion);

    while(opcion<1 && opcion>5)
    {
        printf("Por favor elija una de las opciones del menú");

        printf("Elija la acción a realizar y presione enter:\n1 - Ingresar el primer operando.\n2 - Ingresar el segundo operando.\n3 - Realizar todas las operaciones\n4 - Mostrar los resultados.\n5 - Salir.\n");

        scanf("%d", &opcion);
    }

    while(opcion!=5){//valido en el default. Con un flag permito o no que muestre los resultados (caso 4) y reiniciar las variables.

        switch(opcion){


        }


    }


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

float sumar(float x, float y)
{

    return x+y;
}

float restar(float x, float y)
{

    return x-y;
}
