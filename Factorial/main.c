#include <stdio.h>
#include <stdlib.h>

int main()
{

    int valor,result;

    printf("\nIngrese numero:");
    scanf("%d",&valor);
    result=factorial(valor);
    printf("\nEl factorial de %d es %d",valor,result);

    return 0;
}

int factorial(int n)
{
    int resp;
    resp = 1;
    for(n; n>1; n--)
    {
        resp = resp * n;
    }

    return resp;
}
