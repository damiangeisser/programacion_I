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
//   // struct datosPersonales agenda;//Declaración de la variable agenda del tipo struct datosPersonales.
//
//    struct datosPersonales agenda, contactos;//Declaración de la variable agenda del tipo struct datosPersonales.
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
//    contactos = agenda;//Puedo asignar directamente una estructura a otra.
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
//    printf("\nEl nombre es: %s\n", contactos.nombre);
//    printf("El apellido es: %s\n", contactos.apellido);
//    printf("La calle es: %s\n", contactos.calle);
//    printf("El numero es: %d\n", contactos.numero);
//
//    return 0;
//}

// ----- Vectores de estructuras -----

int main()
{

    //struct datosPersonales vecAgenda[3];//Declaración de un vector de struct datosPersonales.
    struct datosPersonales vecAgenda[3], vecContactos[3], vecAmigos[3];
    int i;//Indice para el for.

    for(i=0; i<3; i++)
    {
        printf("Ingrese el nombre: ");
        gets(vecAgenda[i].nombre);
        //fflush(stdin);

        printf("Ingrese el apellido: ");
        gets(vecAgenda[i].apellido);
        //fflush(stdin);

        printf("Ingrese el nombre de la calle: ");
        gets(vecAgenda[i].calle);
        // fflush(stdin);

        printf("Ingrese el numero de la calle: ");
        scanf("%d", &vecAgenda[i].numero);//No olvidar que cuando apunto a una posición del vector requiero el &
        fflush(stdin);

        printf("-------------------\n");
    }

    //  printf("\nNombre Apellido Direccion Numero\n\n");

    for(i=0; i<3; i++)
    {
        printf("\nEl nombre es: %s\n", vecAgenda[i].nombre);
        printf("El apellido es: %s\n", vecAgenda[i].apellido);
        printf("La calle es: %s\n", vecAgenda[i].calle);
        printf("El numero es: %d\n", vecAgenda[i].numero);

//        printf("%s\t%s\t%s\t%d\n\n", vecAgenda[i].nombre, vecAgenda[i].apellido, vecAgenda[i].calle, vecAgenda[i].numero);
    }

    //strcpy(vecContactos, vecAgenda); //No funciona


    for(i=0; i<3; i++)//Asignación campo a campo.
    {
        strcpy(vecContactos[i].nombre,vecAgenda[i].nombre);
        strcpy(vecContactos[i].apellido,vecAgenda[i].apellido);
        strcpy(vecContactos[i].calle,vecAgenda[i].calle);
        vecContactos[i].numero = vecAgenda[i].numero;
    }



    for(i=0; i<3; i++)//Asignación desde la posición. Copia todo sin excepción.
    {
        vecAmigos[i]=vecContactos[i];
    }

    for(i=0; i<3; i++)
    {
        printf("\nEl nombre es: %s\n", vecContactos[i].nombre);
        printf("El apellido es: %s\n", vecContactos[i].apellido);
        printf("La calle es: %s\n", vecContactos[i].calle);
        printf("El numero es: %d\n", vecContactos[i].numero);
    }

    for(i=0; i<3; i++)
    {
        printf("\nEl nombre es: %s\n", vecAmigos[i].nombre);
        printf("El apellido es: %s\n", vecAmigos[i].apellido);
        printf("La calle es: %s\n", vecAmigos[i].calle);
        printf("El numero es: %d\n", vecAmigos[i].numero);
    }

    return 0;
}
