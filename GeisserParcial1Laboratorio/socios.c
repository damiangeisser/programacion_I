#include "socios.h"


int menu()
{
    int opcion;

    system("cls");
    printf("  --- ABM Socios ---\n\n");
    printf("1- Alta de Socio\n");
    printf("2- Modificar Socio\n");
    printf("3- Baja de Socio\n");
    printf("4- Listar Socios\n");
    printf("5- Listar Libros\n");
    printf("6- Listar Autores\n");
    printf("7- Alta Prestamos\n");
    printf("8- Salir\n");

    getInt(&opcion,"Ingrese una opcion: ","(!) Opcion invalida (!)", 1, 8);

    return opcion;
}

// 3 -----------------------------------------------------------
void mostrarSocio(eSocio socio)
{

    printf("%d %s\t%s\t%c\t%d\t%s %02d/%02d/%d\n", socio.idS, socio.apellido, socio.nombre, socio.sexo, socio.telefono, socio.email, socio.fechaAlta.dia, socio.fechaAlta.mes, socio.fechaAlta.anio);

}

void mostrarLibro(eLibro libro)
{

    printf("%d\t%s\t%d\n", libro.idL, libro.titulo, libro.idAutor);

}

void mostrarAutor(eAutor autor)
{

    printf("%d\t%s\t%s\n", autor.idA, autor.apellidoA, autor.nombreA);

}

void mostrarSociosOrdenados(eSocio vec[], int tam)
{
    int contador = 0;
    eSocio auxSocio;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].apellido, vec[j].apellido)>0)
            {
                auxSocio = vec[i];
                vec[i] = vec[j];
                vec[j] = auxSocio;
            }
        }
    }

    printf("\nCodigo Nombre\tApellido\tSexo\tTel\temail\tFecha de Alta\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarSocio(vec[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\n(!) No hay socios que mostrar (!)\n");
    }
}

void mostrarLibrosOrdenados(eLibro vec[], int tam)
{
    int contador = 0;
    eLibro auxLibro;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].titulo, vec[j].titulo)>0)
            {
                auxLibro = vec[i];
                vec[i] = vec[j];
                vec[j] = auxLibro;
            }
        }
    }

    printf("\nCodigo\tTitulo\tID Autor\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarLibro(vec[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\n(!) No hay libros que mostrar (!)\n");
    }
}

void mostrarAutoresOrdenados(eAutor vec[], int tam)
{
    int contador = 0;
    eAutor auxAutor;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].apellidoA, vec[j].apellidoA)>0)
            {
                auxAutor = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAutor;
            }
        }
    }

    printf("\nID\tApellido\tNombre\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarAutor(vec[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\n(!) No hay autores que mostrar (!)\n");
    }
}


int buscarLibre(eSocio vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarPLibre(ePrestamo vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void inicializarSocios(eSocio vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

void inicializarPrestamos(ePrestamo vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int altaSocio(eSocio vec[], int tam, int idMain)
{

    int indice;
    int altaOk = 0;

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\n(!) No hay lugar en el sistema (!)\n\n");
    }
    else
    {
        vec[indice].idS = idMain++;

        getString(vec[indice].nombre,"Ingrese el nombre: ","(!) Largo del nombre invalido (!)", 2, 31);

        getString(vec[indice].apellido,"Ingrese el apellido: ","(!) Largo del apellido invalido (!)", 2, 31);

        getCharGenre(&vec[indice].sexo,"Ingrese el sexo: ","(!) Debe ingresar F o M (!)");

        getCell(vec[indice].telefono,"Ingrese el telefono","(!) Telefono invalido (!)", 8, 16);

        getString(vec[indice].email,"Ingrese el email: ","(!) Largo del apellido invalido (!)", 5, 31);

        getDate(&vec[indice].fechaAlta.anio, &vec[indice].fechaAlta.mes, &vec[indice].fechaAlta.dia, "alta:", 2005, 2020);

        vec[indice].ocupado = 1;

        printf("\n-- Socio dado de alta exitosamente --\n\n");

        altaOk=1;
    }

    return altaOk;
}

int buscarSocio(eSocio vec[], int tam, int id)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].idS == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void bajaSocio(eSocio vec[], int tam)
{
    int id;
    int indice;
    char baja;

    getInt(&id,"\nIngrese el id del socio a dar de baja: ","(!) No es un id valido (!)\n", 1, 5000);

    indice = buscarSocio(vec, tam, id);

    if( indice == -1)
    {
        printf("\n(!) No existe un socio con ese id (!)\n");
    }
    else
    {
        mostrarSocio(vec[indice]);
        printf("\nDesea dar de baja al empleado? s/n: ");
        baja = getche();
        if(tolower(baja)=='s')
        {
            vec[indice].ocupado=0;
            printf("\n-- Empleado dado de baja exitosamente --\n");
        }
    }
}

int altaPrestamos(ePrestamo vecP[], int tamP, eSocio vecS[], int tamS, eLibro vecL[], int tamL, int idPMain, int idSMain)
{
    int indice;
    int altaOk = 0;

    indice = buscarPLibre(vecP, tamP);

    if( indice == -1)
    {
        printf("\n(!) No hay lugar en el sistema (!)\n\n");
    }
    else
    {
        vecP[indice].idP = idPMain++;

        mostrarSociosOrdenados(vecS, tamS);

        getInt(&vecP[indice].idSocio,"Ingrese el ID del socio: ","(!) ID inexistente (!)", 1, idSMain);

        mostrarLibrosOrdenados(vecL, tamL);

        getInt(&vecP[indice].idLibro,"Ingrese el ID del libro: ","(!) ID inexistente (!)", 1, 2000);

        getDate(&vecP[indice].fechaPrestamo.anio, &vecP[indice].fechaPrestamo.mes, &vecP[indice].fechaPrestamo.dia, "prestamo:", 2005, 2020);

        vecP[indice].ocupado = 1;

        printf("\n-- Prestamo dado de alta exitosamente --\n\n");

        altaOk=1;
    }

    return altaOk;
}
