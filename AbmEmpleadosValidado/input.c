#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int valor;
    int error = -1;

    printf("%s ", message);
    scanf("%d", &valor);

    while(valor < lowLimit || valor > hiLimit)
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
    int error = -1;

    printf("%s ", message);
    scanf("%f", &valor);

    while(valor < lowLimit || valor > hiLimit)
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
//----------------------------------------------------------------------------------
int getDate(int* inputY, int* inputM, int* inputD, char message[], int yLowLimit, int yHiLimit)
{
    int day;
    int month;
    int year;
    int leap=0;//Bandera para los años bisiestos.
    int error = -1;

    printf("Ingrese el anio de %s: ", message);
    scanf("%d", &year);

    while(year < yLowLimit || year > yHiLimit)
    {
        printf("\nel anio ingresado no es valido\n");
        printf("Ingrese el anio de %s: ", message);
        scanf("%d", &year);
    }

    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        leap=1;//El año es bisiesto.
    }

    *inputY = year;

    printf("Ingrese el nro de mes de %s: ", message);
    scanf("%d", &month);

    while(month < 1 || month > 12)
    {
        printf("\nel nro de mes ingresado no es valido\n");
        printf("Ingrese el nro de mes de %s: ", message);
        scanf("%d", &month);
    }

    *inputM = month;

    printf("Ingrese el dia de %s: ", message);
    scanf("%d", &day);

    if(leap==0 && month == 2)
    {
        while(day < 1 || day > 28)
        {
            printf("\nel dia ingresado no es valido para el mes\n");
            printf("Ingrese el dia de %s: ", message);
            scanf("%d", &day);
        }
    }
    else if(leap==1 && month == 2)
    {
        while(day < 1 || day > 29)
        {
            printf("\nel dia ingresado no es valido para el mes\n");
            printf("Ingrese el dia de %s: ", message);
            scanf("%d", &day);
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        while(day < 1 || day > 30)
        {
            printf("\nel dia ingresado no es valido para el mes\n");
            printf("Ingrese el dia de %s ", message);
            scanf("%d", &day);
        }
    }
    else
    {
        while(day < 1 || day > 31)
        {
            printf("\nel dia ingresado no es valido\n");
            printf("Ingrese el dia de %s ", message);
            scanf("%d", &day);
        }
    }

    *inputD = day;

    error = 0;

    return error;
}
