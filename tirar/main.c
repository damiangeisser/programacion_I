#include <stdio.h>
#include <stdlib.h>

int main()
{

    char numeros[10];
    int error=-1;

    printf("ingreso numeros\n");
    gets(numeros);
    printf("\nnumeros: \n");
    puts(numeros);

    error = chequeo(numeros);

    printf("\n error: %d", error);


    return 0;
}

int chequeo(char* vec)
{

    int error=0;
    for(int i =0; i<strlen(vec);i++)
    {
        if(vec[i]<'0'||vec[i]>'9')
        {
            printf("\n posicion %d no es un numero. %c", i,vec[i]);

            error=1;
        }
    }

    printf("\n error: %d", error);


    return error;
}
