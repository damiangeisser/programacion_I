#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 1 -------------------------------------------------------------------------------
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int valor;
    int returnScanf;
    int error = -1;

    printf("%s ", message);
    returnScanf = scanf("%d", &valor);

    while(returnScanf == 0 || valor < lowLimit || valor > hiLimit)
    {

        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        returnScanf = scanf("%d", &valor);
    }

    *input = valor;
    error = 0;

    return error;
}
// 2 -------------------------------------------------------------------------------
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float valor;
    int returnScanf;
    int error = -1;

    printf("%s ", message);
    returnScanf = scanf("%f", &valor);

    while(returnScanf == 0 || valor < lowLimit || valor > hiLimit)
    {

        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        returnScanf = scanf("%f", &valor);
    }

    *input = valor;
    error = 0;

    return error;
}
// 3 ----------------------------------------------------------------------------------
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
// 4 ----------------------------------------------------------------------------------
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char valor[50];
    int error = -1;

    printf("%s ", message);
    fflush(stdin);
    gets(valor);

    while(strlen(valor) < lowLimit || strlen(valor) > hiLimit)
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        gets(valor);
    }

    strcpy(input,valor);

    error = 0;

    return error;
}
// 5 ----------------------------------------------------------------------------------
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
// 6 ----------------------------------------------------------------------------------
int getDate(int* inputY, int* inputM, int* inputD, char message[], int yLowLimit, int yHiLimit)
{
    int day;
    int month;
    int year;
    int leap=0;//Bandera para los años bisiestos.
    int error = -1;
    char printYear[50]="Ingrese el anio de ";
    char printMonth[50]="Ingrese el mes de ";
    char printDay[50]="Ingrese el dia de ";

    strcat(printYear, message);
    strcat(printMonth, message);
    strcat(printDay, message);

    getInt(&year,printYear,"(!) El anio ingresado no es valido (!)\n", yLowLimit, yHiLimit);

    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        leap=1;//El año es bisiesto.
    }

    *inputY = year;

    getInt(&month,printMonth,"(!) El mes ingresado no es valido (!)\n", 1, 12);

    *inputM = month;

    if(leap==0 && month == 2)
    {

        getInt(&day,printDay,"(!) No es un dia valido para el anio y mes ingresados (!)\n", 1, 28);

    }
    else if(leap==1 && month == 2)
    {

        getInt(&day,printDay,"(!) No es un dia valido para el anio y mes ingresados (!)\n", 1, 29);

    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {


        getInt(&day,printDay,"(!) No es un dia valido para el mes ingresado (!)\n", 1, 30);

    }
    else
    {
        getInt(&day,printDay,"(!) No es un dia valido (!)\n", 1, 31);
    }

    *inputD = day;

    error = 0;

    return error;
}
