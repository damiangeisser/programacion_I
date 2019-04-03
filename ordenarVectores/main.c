#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[5]= {7,5,6,2,8};
    int aux;

    for(int q=0; q<5; q++)
    {
        printf("%d", vec[q]);

    }

    printf("\n\n");

    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<4; j++)
        {
            if(vec[i]>vec[j])//Mayor ordena de forma ascendente. Menor de forma descendente.
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;

                for(int q=0; q<5; q++)
                {
                    printf("%d", vec[q]);
                }
                printf("\n\n");
            }

        }
    }

//    for(int q=0; q<5; q++)
//    {
//        printf("%d", vec[q]);
//    }


    return 0;
}
