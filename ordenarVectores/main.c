#include <stdio.h>
#include <stdlib.h>
#define CANT 5 //Define una constante con el largo del vector. Parte del ejemplo, no lo usé en el código.

int main()
{
    int vec[5]= {7,5,6,2,8};
    int aux;

    printf("Vector sin ordenar: ");

    for(int q=0; q<5; q++)//CANT en lugar del 5.
    {
        printf("%d", vec[q]);
    }

    printf("\n\n");

    for(int i=0; i<4; i++)//CANT-1 en lugar del 4.
    {
        for(int j=i+1; j<5; j++)//CANT en lugar del 5.
        {
            if(vec[i]>vec[j])//Mayor ordena de forma ascendente. Menor de forma descendente.
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;

//                for(int q=0; q<5; q++)
//                {
//                    printf("%d", vec[q]);
//                }
//                printf("\n\n");
            }

        }
    }

    printf("Vector ordenado: ");

    for(int q=0; q<5; q++)//CANT en lugar del 5.
    {
        printf("%d", vec[q]);
    }

    printf("\n");

    return 0;
}
