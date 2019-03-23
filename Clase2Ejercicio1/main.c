#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de caracteres de otros idiomas.
#include <locale.h>//Permite el uso de símbolos de monedas y otros.

int main()
{
    int valor, max, min, flag, i, acumulador = 0;
    float promedio;

    setlocale(LC_ALL, "");//Activa el uso de caracteres de otros idiomas.

    for(i=0; i<5; i++)
    {
        printf("Ingrese un valor:");

        scanf("%d", &valor);

        if(flag == 0 || valor > max)
        {
            max = valor;
        }
        if(flag == 0 || valor < min)
        {
            min = valor;
            flag = 1;
        }

        acumulador = acumulador + valor;
    }

    promedio = (float)acumulador/5;

    printf("\nEl promedio de los cinco números ingresados es: %.2f\nEl máximo fue: %d\nEl mínimo fue: %d\n", promedio, max, min);

    return 0;
}
