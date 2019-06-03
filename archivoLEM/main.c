#include <stdio.h>

#define ARCH	".\\bin.dat"
#define ESC 27

struct a
{
    char nombre[31];
    int edad;
    int legajo;
    int isEmpty;
};

int main (void)
{
    FILE  *bin;
    struct a pers;
    int cant;
    int legajoAux;

    if ((bin=fopen(ARCH,"rb+"))==NULL)
    {
        if ((bin=fopen(ARCH,"wb+"))==NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
    }

    do
    {
        printf("\nIngrese el nombre: ");
        gets(pers.nombre);

        printf("Ingrese la edad: ");
        scanf("%d",&pers.edad);

        printf("Ingrese el legajo: ");
        scanf("%d",&pers.legajo);

        pers.isEmpty=0;

        fflush(stdin);
        fseek(bin , 0L, SEEK_END);
        fwrite(&pers,sizeof(pers),1,bin);

        printf("\nPresione ESC para terminar");
    }
    while((getche())!=27);

    /* Busqueda */
    system("cls");
    printf("Legajo: ");
    scanf("%d", &legajoAux);


    rewind (bin);//se lleva el indicador de posición al principio para comenzar a leer

    while(!feof(bin))//feof (end of file) devuelve 0 si no se llegó al final del archivo.
    {
        cant = fread(&pers,sizeof(pers),1,bin);//fread devuelve la cantidad de datos leídos.

        if(cant!=1)
        {
            if(feof(bin))//Si fread no devuelve la cantidad correcta, verifico que no sea el final del archivo.
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }

        if(legajoAux == pers.legajo)//Como fread se ejecutó de forma exitosa, verifico si es el legajo que busco.
        {
            printf("\nIngrese nuevo nombre: ");
            fflush(stdin);
            gets(pers.nombre);

            fseek(bin, (long) (-1) * sizeof(pers), SEEK_CUR);//Ubico el indicador de posición al principio de la estructura que voy a modificar.
            fflush(stdin);
            fwrite(&pers,sizeof(pers),1,bin);//Escribo los datos en el archivo.
            break;
        }
    }


    rewind (bin);//se lleva el indicador de posición al principio para comenzar a leer

    while(!feof(bin))
    {
        cant = fread(&pers,sizeof(pers),1,bin);

        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }

        printf("\n%s\t%d",pers.nombre,pers.edad);
    }

    fclose(bin);
    getch();

    return 0;
}
