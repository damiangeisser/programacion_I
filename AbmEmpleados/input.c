#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int valor;
    int returnScanf;
    int error = -1;

    printf("%s ", message);
    returnScanf = scanf("%d", &valor);

    while(returnScanf = 0 || valor < lowLimit || valor > hiLimit)
    {

        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        scanf("%d", &valor);
    }

    *input = valor;
    error = 0;

    return error;
}
//-------------------------------------------------------------------------------
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float valor;
    int returnScanf;
    int error = -1;

    printf("%s ", message);
    scanf("%f", &valor);

    while(returnScanf = 0 || valor < lowLimit || valor > hiLimit)
    {

        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        scanf("%f", &valor);
    }

    *input = valor;
    error = 0;

    return error;
}
//----------------------------------------------------------------------------------
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    char valor;
    int error = -1;

    printf("%s ", message);
    fflush(stdin);
    scanf("%c", &valor);

    while(valor < lowLimit || valor > hiLimit)
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        scanf("%c", &valor);
    }

    *input = valor;
    error = 0;

    return error;

    //*input = 'S';
    //return 0;
}
//----------------------------------------------------------------------------------
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char valor[50];
    int error = -1;

    printf("%s ", message);
    fflush(stdin);
    scanf("%s", valor);

    while(strlen(valor) < lowLimit || strlen(valor) > hiLimit)
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        scanf("%s", &valor);
    }

    strcpy(input,valor);

    error = 0;

    return error;
}
//----------------------------------------------------------------------------------
int getCharGenre(char* input,char message[],char eMessage[])
{
    char valor;
    int error = -1;

    printf("%s ", message);
    fflush(stdin);
    scanf("%c", &valor);
    valor=toupper(valor);

    while(valor !='F' && valor !='M')
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        scanf("%c", &valor);
        valor=toupper(valor);
    }

    *input = valor;
    error = 0;

    return error;
}
