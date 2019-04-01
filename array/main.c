#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[5];
    int total;
    float promedio;

    total = 0;

    for(int i=0; i<5; i++)
    {
        printf("Ingrese un numero y presione enter:");
        scanf("%d", &numeros[i]);

    }

    for(int i=0; i<5; i++)
    {
        total = total + numeros[i];
    }

    promedio = total/sizeof(numeros[5]);

    printf("El total es: %d\n" , total);

    printf("El promedio es: %.2f\n" , promedio);

    return 0;
}
