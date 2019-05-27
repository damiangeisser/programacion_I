#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *txtNum;

    txtNum=fopen("./numeros.txt","w");

    if(txtNum==NULL)
    {

        printf("Error al leer el archivo");

        exit(1);
    }

    int vecNum[]= {1,2,3,4,5,6,7,8,9,10,11,12};

    for(int i=0; i<12; i++)
    {

        if((i+1)%4 != 0)
        {
            fprintf(txtNum,"%d, ", vecNum[i]);

        }
        else
        {

            fprintf(txtNum,"%d\n", vecNum[i]);
        }
    }

    fclose(txtNum);
    return 0;
}
