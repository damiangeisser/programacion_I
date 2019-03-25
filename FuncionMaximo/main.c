#include <stdio.h>
#include <stdlib.h>

int obtenerMaximo(int x, int y, int z);

int main()
{
    printf("%d", obtenerMaximo(-6 , 100, 10));//Hard coding para probar la función.

    return 0;
}

int obtenerMaximo(int x, int y, int z)
{
    int maximo;

    if(x > y && x > z)
    {
        maximo = x;
    }
    else
    {
        if (y > z)
        {
            maximo = y;
        }
        else
        {
            maximo = z;
        }//if (y > z)
    }//if(x > y && x > z)

    return maximo;

}
