#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de caracteres de otros idiomas.
#include <locale.h>//Permite el uso de s�mbolos de monedas y otros.

int main()
{
    int i;
    int numero;
    int contadorNegativos = 0;
    int contadorPositivos = 0;

    setlocale(LC_ALL, "");//Activa el uso de caracteres de otros idiomas.

    for(i=0; i<10; i++)
    {

        printf("Por favor ingrese un n�mero y presione enter:");
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

    printf("\nUsted ingres� %d n�meros positivos y %d n�meros negativos\n", contadorPositivos, contadorNegativos);

    return 0;
}
