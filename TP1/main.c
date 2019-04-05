#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de caracteres de otros idiomas.
#include <locale.h>//Permite el uso de símbolos de monedas y otros.

float sumar(float x, float y);
float restar(float x, float y);

int main()
{
    int opcion;
    float operandoUno;
    float operandoDos;
    float rtaSuma;
    float rtaResta;
    int mostrarOk = 0;

    setlocale(LC_ALL, "");//Activa el uso de caracteres latinos

    do //valido en el default. Con un flag permito o no que muestre los resultados (caso 4) y reiniciar las variables.
    {

        printf("Elija la acción a realizar y presione enter:\n\n1 - Ingresar el primer operando.\n\n2 - Ingresar el segundo operando.\n\n3 - Realizar todas las operaciones\n\n4 - Mostrar los resultados.\n\n5 - Salir.\n\n");

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
            //calcular resultados
            mostrarOk = 1;
            break;
        case 4:
            if(mostrarOk)
            {
                printf("\nEstos son los resultados\n\n");
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





//    rtaSuma = (sumar(operandoUno, operandoDos));
//
//    printf("El resultado de %.2f + %.2f es: %.2f", operandoUno, operandoDos, rtaSuma);
//
//    rtaResta = (restar(operandoUno, operandoDos));
//
//    printf("El resultado de %.2f - %.2f es: %.2f", operandoUno, operandoDos, rtaResta);


    return 0;
}

//float sumar(float x, float y)
//{
//
//    return x+y;
//}
//
//float restar(float x, float y)
//{
//
//    return x-y;
//}
