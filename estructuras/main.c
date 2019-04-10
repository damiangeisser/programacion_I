#include <stdio.h>
#include <stdlib.h>

struct datosPersonales //Palabra reservada struct crea una estructura. Se crea debajo de los directivas del preprocesador.
{
    char nombre[20];//Campo nombre.
    char apellido[20];//Campo apellido.
    char calle[20];//Campo calle.
    int numero;//Campo numero.
};//Se cierra con llave y punto y coma.

int main()
{

    struct datosPersonales agenda;//Declaración de la variable agenda del tipo struct datosPersonales.

    strcpy(agenda.nombre, "Yanina");//Hardcoding del nombre a través del operador punto.
    strcpy(agenda.apellido, "Scudero");
    strcpy(agenda.calle, "Avenida Mitre");
    agenda.numero = 750;

//    printf("El nombre es: %s\n", agenda.nombre);
//    printf("El apellido es: %s", agenda.apellido);

    printf("Nombre\tApellido\n\n");
    printf("%s\t%s\n\n", agenda.nombre, agenda.apellido);

    return 0;
}
