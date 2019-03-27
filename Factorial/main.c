#include <stdio.h>
#include <stdlib.h>

int main()
{

    int valor,result;

    printf("\nIngrese numero: ");
    scanf("%d",&valor);
    result=factorial(valor);

    if(result==-1)
    {

        printf("\nError - El numero del que se desea el factorial debe ser mayor a 0\n");
    }
    else
    {
        printf("\nEl factorial de %d es %d\n",valor,result);
    }
    return 0;
}

int factorial(int n)
{
    int resp;

    if(n>0)
    {
        resp=1;
        for(n; n>1; n--)
        {
            resp = resp * n;
        }
    }
    else
    {
        resp=-1;
    }
    return resp;
}
