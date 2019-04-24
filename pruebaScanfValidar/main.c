#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int x;
    float x;
    int y;
    float z;

    printf("Ingrese un entero: ");

    y = scanf("%f%f", &x, &z);

    printf("%d\n", y);

    printf("%f %f\n", x,z);

    return 0;
}
