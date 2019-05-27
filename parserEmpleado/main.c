#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *txtNum;
    int legajo;
    char nombre[20];
    char apellido[20];
float sueldo;

    txtNum=fopen("./numeros.txt","r");

    if(txtNum==NULL)
    {

        printf("Error al leer el archivo");

        exit(1);
    }

    while(!feof(txtNum)){
       cant= fscanf(txtNum,"%d, %d, %d, %d\n",&num1,&num2,&num3,&num4);//Le doy el formato del archivo que leo.
       if(cant < 4){
        break;
       }
       printf("%d %d %d %d ",num1,num2,num3,num4);
    }



    fclose(txtNum);
    return 0;
}
