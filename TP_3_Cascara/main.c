#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <strings.h>
#include "funciones.h"



int main()
{
    char seguir = 's';
    int opcion = 0;
    int i;

    int cantidadDePeliculas = 0;
    int cargarPelicula = 0;

    int flagPeliculaIngresada = 0;

    EMovie* pelicula;

    FILE* archivoPeliculas;

    char auxTitulo[51];
    int auxInt;


    archivoPeliculas = fopen("index.html", "rb");

    if(archivoPeliculas == NULL)
    {
        archivoPeliculas = fopen("index.html", "wb");
    }

    if(archivoPeliculas != NULL)
    {
        pelicula = iniciarPelicula();
        if(pelicula != NULL)
        {
            while(!feof(archivoPeliculas))
            {
                fread(pelicula, sizeof(EMovie),1, archivoPeliculas);
            }
        }
    }


    while(seguir == 's')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");


        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                pelicula = iniciarPelicula();

                cargarPelicula = altaPelicula(pelicula);

                if(cantidadDePeliculas == 0)
                {
                    cargarPelicula = agregarPelicula(pelicula, archivoPeliculas);
                }

                else
                {
                    cargarPelicula = agregarPelicula((pelicula + cantidadDePeliculas), archivoPeliculas);
                }

                if(cargarPelicula == 1)
                {
                    printf("Pelicula cargada exitosamente!\n");
                    cantidadDePeliculas++;
                    pelicula = (EMovie*)realloc(pelicula, sizeof(EMovie)*cantidadDePeliculas);
                    flagPeliculaIngresada = 1;
                }
                else
                {
                    printf("Error, no se pudo cargar la pelicula ");
                }

                system("pause");
                system("cls");

                break;

            case 2:
                if(flagPeliculaIngresada == 0)
                {
                    printf("No hay peliculas ingresadas ");
                    break;
                }
                for(i=0;i<cantidadDePeliculas;i++)
                {
                    mostrarPelicula(pelicula);
                }

                printf("Elija el nombre de la pelicula que desea borrar");
                fflush(stdin);
                gets(auxTitulo);
                if(strcmp(auxTitulo, (pelicula+i)->titulo)== 0)
                {
                    auxInt = borrarPelicula(*(pelicula+i), archivoPeliculas);
                    if(auxInt == 1)
                    {
                        cantidadDePeliculas--;
                        printf("Pelicula borrada exitosamente");
                    }
                    break;
                }

                system("pause");
                system("cls");


                break;

            case 3:
                if(flagPeliculaIngresada == 0)
                {
                    printf("No hay peliculas ingresadas ");
                    break;
                }

                 for(i=0;i<cantidadDePeliculas;i++)
                {
                    mostrarPelicula(pelicula);
                }

                printf("Elija el nombre de la pelicula que desea modificar");
                fflush(stdin);
                gets(auxTitulo);
                for(i=0;i<cantidadDePeliculas;i++)
                {
                    if(strcmp(auxTitulo, (pelicula+i)->titulo)== 0)
                    {
                        auxInt = modificarPelicula(pelicula+i);
                        break;
                    }
                }

                system("pause");
                system("cls");

               break;

            case 4:
                if(flagPeliculaIngresada == 0)
                {
                    printf("No hay peliculas ingresadas ");
                    break;
                }
                printf("Ingrese nombre de la pagina");
                fflush(stdin);
                gets(auxTitulo);

                generarPagina(pelicula, auxTitulo);

                system("pause");
                system("cls");

               break;

            case 5:
                seguir = 'n';
                break;

            default:
                printf("Error, elija una opcion valida");
                break;

        }
        system("pause");
        system("cls");
    }

    return 0;
}
