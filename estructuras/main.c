#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosPersonales //Palabra reservada struct crea una estructura. Se crea debajo de los directivas del preprocesador.
{
    char nombre[20];//Campo nombre.
    char apellido[20];//Campo apellido.
    char calle[20];//Campo calle.
    int numero;//Campo numero.
    //int codigoPostal;
};//Se cierra con llave y punto y coma.

//int main()
//{
//
//    struct datosPersonales agenda;//Declaración de la variable agenda del tipo struct datosPersonales.
//
////    strcpy(agenda.nombre, "Yanina");//Hardcoding del nombre a través del operador punto.
////    strcpy(agenda.apellido, "Scudero");
////    strcpy(agenda.calle, "Avenida Mitre");
////    agenda.numero = 750;
//
//    printf("Ingrese el nombre: ");
//    gets(agenda.nombre);
//    fflush(stdin);
//
//    printf("Ingrese el apellido: ");
//    gets(agenda.apellido);
//    fflush(stdin);
//
//    printf("Ingrese el nombre de la calle: ");
//    gets(agenda.calle);
//    fflush(stdin);
//
//    printf("Ingrese el numero de la calle: ");
//    scanf("%d", &agenda.numero);
//
////    printf("Ingrese el codigo postal: ");
////    scanf("%d", &agenda.codigoPostal);
//
//    printf("\nEl nombre es: %s\n", agenda.nombre);
//    printf("El apellido es: %s\n", agenda.apellido);
//    printf("La calle es: %s\n", agenda.calle);
//    printf("El numero es: %d\n", agenda.numero);
////    printf("El codigo postal es: %d\n", agenda.codigoPostal);
//
////    printf("Nombre\tApellido\n\n");
////    printf("%s\t%s\n\n", agenda.nombre, agenda.apellido);
//
//    return 0;
//}

int main()
{

    struct datosPersonales vecAgenda[3];//Declaración de un vector de struct datosPersonales.
    int i=0;//Indice para el for.

    for(i=0; i<3; i++)
    {

        printf("Ingrese el nombre: ");
        gets(vecAgenda[i].nombre);
        fflush(stdin);

        printf("Ingrese el apellido: ");
        gets(vecAgenda[i].apellido);
        fflush(stdin);

        printf("Ingrese el nombre de la calle: ");
        gets(vecAgenda[i].calle);
        fflush(stdin);

        printf("Ingrese el numero de la calle: ");
        scanf("%d", &vecAgenda[i].numero);//No olvidar que cuando apunto a una posición del vector requiero el &
        fflush(stdin);

        printf("-------------------\n");

   }

    printf("\nNombre Apellido Direccion Numero\n\n");

    for(i=0; i<3; i++)
    {
//        printf("\nEl nombre es: %s\n", vecAgenda[i].nombre);
//        printf("El apellido es: %s\n", vecAgenda[i].apellido);
//        printf("La calle es: %s\n", vecAgenda[i].calle);
//        printf("El numero es: %d\n", vecAgenda[i].numero);

    printf("%s\t%s\t%s\t%d\n\n", vecAgenda[i].nombre, vecAgenda[i].apellido, vecAgenda[i].calle, vecAgenda[i].numero);
    }
    return 0;
}
