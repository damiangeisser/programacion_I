#include <stdio.h>
#include <stdlib.h>

void mostrarVector1(int vec[], int tam);//Nomenclatura vectorial recorre como vector.
void mostrarVector2(int vec[], int tam);//Nomenclatura vectorial recorre como puntero.
void mostrarVector3(int* vec, int tam);//Nomenclatura puntero recorre como vector.
void mostrarVector4(int* vec, int tam);//Nomenclatura puntero recorre como puntero.

int main()
{

    int numeros[]= {3,5,2,4,3};

    //int* p;
//
//    printf("%x\n", numeros);
//
//    printf("%x\n", &numeros[0]);//En memoria estática es ídem al anterior.
//
//    printf("%d\n", *numeros);//Muestra el primer elemento del vector.
//
//    printf("%d\n", *(numeros+1));//Muestra el segundo elemento del vector, +1 suma 1 sizeof.
//
//    for(int i = 0; i<5; i++)
//    {
//        printf("%d\n", *(numeros+i));
//    }

    mostrarVector1(numeros, 5);
    mostrarVector2(numeros, 5);
    mostrarVector3(numeros, 5);
    mostrarVector4(numeros, 5);

    return 0;
}

void mostrarVector1(int vec[], int tam)
{
    printf("\n--- Funcion mostrarVector1 ---\n");
    for(int i = 0; i<tam; i++)
    {
        printf("%d ", vec[i]);
    }

}

void mostrarVector2(int vec[], int tam)
{
    printf("\n--- Funcion mostrarVector2 ---\n");
    for(int i = 0; i<tam; i++)
    {
        printf("%d ", *(vec+i));
    }

}

void mostrarVector3(int* vec, int tam)
{
    printf("\n--- Funcion mostrarVector3 ---\n");

    for(int i = 0; i<tam; i++)
    {
        printf("%d ", vec[i]);
    }

}

void mostrarVector4(int* vec, int tam)
{

    printf("\n--- Funcion mostrarVector4 ---\n");
    for(int i = 0; i<tam; i++)
    {
        printf("%d ", *(vec+i));
    }

}
