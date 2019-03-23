#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de caracteres de otros idiomas.
#include <locale.h>//Permite el uso de símbolos de monedas y otros.

int main()
{
    int i;
    int numero;
    int contadorNegativos = 0;
    int contadorPositivos = 0;

    setlocale(LC_ALL, "");//Activa el uso de caracteres de otros idiomas.

    for(i=0; i<10; i++)
    {

        printf("Por favor ingrese un número y presione enter:");
        scanf("%d", &numero);

        if(numero>0)
        {
            contadorPositivos++;
        }
        else
        {
            if(numero<0)
            {
                contadorNegativos++;
            }
        }

    }

    printf("\nUsted ingresó %d números positivos y %d números negativos\n", contadorPositivos, contadorNegativos);

    return 0;
}
