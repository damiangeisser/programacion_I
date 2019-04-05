#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de caracteres de otros idiomas.
#include <locale.h>//Permite el uso de símbolos de monedas y otros.

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
    int mostrarOk = 0;
    int errorDiv = 0;
    int errorFactor1 = 0;
    int errorFactor2 = 0;
    int mostrarOk = 0;

    setlocale(LC_ALL, "");//Activa el uso de caracteres latinos

    do
    {
        printf("\nElija la acción a realizar y presione enter:\n\n1 - Ingresar el primer operando.\n\n2 - Ingresar el segundo operando.\n\n3 - Realizar todas las operaciones\n\n4 - Mostrar los resultados.\n\n5 - Salir.\n\n");

        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            printf("\nPor favor ingrese el 1er operando y presione enter:\n");
            scanf("%f", &operandoUno);
            break;
        case 2:
            printf("\nPor favor ingrese el 2er operando y presione enter:\n");
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

            if(operando1 < 1)
            {
                errorFactor1 = 1;
            }
            else
            {

                rtaFactor1 = factorial(operandoUno);
            }

            //Fin primer factorial

            //Inicio factorial del segundo operando con validación.

            if(operando2 < 1)
            {
                errorFactor2 = 1;
            }
            else
            {

                rtaFactor2 = factorial(operandoDos);
            }

            //Fin segundo factorial

            printf("\nOperaciones realizadas.\n\n");

            mostrarOk = 1;
            break;
        case 4:
            if(mostrarOk)
            {
                printf("\nEl resultado de %f + %f es: %f\n\n", operandoUno, operandoDos, rtaSuma);

                printf("\nEl resultado de %f - %f es: %f\n\n", operandoUno, operandoDos, rtaResta);

                //

                operandoUno = 0;
                operandoDos = 0;
            }
            else
            {
                printf("\nDebe elegir previamente la opción 3 para obtener los resultados a mostrar.\n\n");
            }
            break;
        case 5:
            printf("\nPrograma finalizado.\n\n");
            break;
        default:
            printf("\n%d no es una opción válida.\n\n", opcion);
        }


    }
    while(opcion!=5);

    rtaSuma=sumar(5.5, 3.3);

    rtaResta=restar(5.5, 3.3);

    rtaMulti=multiplicar(5.5, 3.3);

    rtaDiv=dividir(5.5, 3.3);

    rtaFactor=factorial(3.9);

    printf("\nEstos son los resultados: %f\n\n", rtaSuma);
    printf("\nEstos son los resultados: %f\n\n", rtaResta);
    printf("\nEstos son los resultados: %f\n\n", rtaMulti);
    printf("\nEstos son los resultados: %f\n\n", rtaDiv);

    printf("\nEstos son los resultados factor: %d\n\n", rtaFactor);



//    rtaSuma = (sumar(operandoUno, operandoDos));
//
//    printf("El resultado de %.2f + %.2f es: %.2f", operandoUno, operandoDos, rtaSuma);
//
//    rtaResta = (restar(operandoUno, operandoDos));
//
//    printf("El resultado de %.2f - %.2f es: %.2f", operandoUno, operandoDos, rtaResta);


    return 0;
}

float sumar(float sumando1, float sumando2)
{
    float rtaFuncionSum;

    rtaFuncionSum = sumando1 + sumando2;

    return rtaFuncionSum;
}

float restar(float minuendo, float sustraendo)
{
    float rtaFuncionRes;

    rtaFuncionRes = minuendo - sustraendo;

    return rtaFuncionRes;
}

float multiplicar(float factor1, float factor2)
{
    float rtaFuncionMulti;

    rtaFuncionMulti = factor1 * factor2 ;

    return rtaFuncionMulti;
}

float dividir(float dividendo, float divisor)
{
    float rtaFuncionDiv;

    rtaFuncionDiv = dividendo / divisor ;

    return rtaFuncionDiv;
}

int factorial(int operandoFac)
{
    int rtaFuncionFactor=1;

    for(operandoFac; operandoFac>1; operandoFac--)
    {
        rtaFuncionFactor = rtaFuncionFactor * operandoFac;
    }
    return rtaFuncionFactor;
}
