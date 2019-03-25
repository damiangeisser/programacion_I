#include <stdio.h>
#include <stdlib.h>

int obtenerMaximo(int x, int y, int z);

int main()
{
    printf("%d", obtenerMaximo(-1 , 2, 100));

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
        }

    }

    return maximo;

}
