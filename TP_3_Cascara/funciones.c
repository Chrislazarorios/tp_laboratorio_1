#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "funciones.h"

EMovie* iniciarPelicula()
{
    EMovie* pelicula = NULL;
    pelicula = malloc(sizeof(EMovie));

    return pelicula;
}


int altaPelicula(EMovie* pelicula)
{
    EMovie* auxPelicula;
    char opcion;
    int flag = 0;

    auxPelicula = iniciarPelicula();

    printf("Ingrese titulo de la pelicula : ");
    fflush(stdin);
    gets(auxPelicula->titulo);

    printf("Ingrese genero de la pelicula : ");
    fflush(stdin);
    gets(auxPelicula->genero);

    printf("Ingrese duracion de la pelicula : ");
    scanf("%d", &auxPelicula->duracion);

    printf("Ingrese descripcion de la pelicula : ");
    fflush(stdin);
    gets(auxPelicula->descripcion);

    printf("Ingrese puntaje de la pelicula : ");
    scanf("%d", &auxPelicula->puntaje);

    printf("Ingrese Link de imagen de la pelicula : ");
    fflush(stdin);
    gets(auxPelicula->linkImagen);


    printf("Desea guardar estos datos en una pelicula? s/n : \n");
    mostrarPelicula(auxPelicula);
    fflush(stdin);
    opcion = tolower(getch());

    if(opcion == 's')
    {
        *pelicula = *auxPelicula;
        free(auxPelicula);
        flag = 1;
    }
    else
    {
        printf("Pelicula no guardada!!\n");
        flag = 0;
    }


    return flag;

}


void mostrarPelicula(EMovie* pelicula)
{
    printf("Titulo : %s \n Genero : %s \n Duracion : %d \n Descripcion : %s \n Puntaje : %d \n Link Imagen : %s \n", pelicula->titulo, pelicula->genero, pelicula->duracion, pelicula->descripcion, pelicula->puntaje, pelicula->linkImagen);
}


int agregarPelicula(EMovie* pelicula, FILE* archivo)
{
    int flag = 0;

    archivo = fopen("index.html","wb");

    if(archivo != NULL)
    {
        flag = fwrite(pelicula, sizeof(EMovie), 1, archivo);

        if(flag == 1)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }

    fclose(archivo);

    return flag;
}




int borrarPelicula(EMovie pelicula,  FILE* archivo)
{
    EMovie* auxPelicula;
    int i, flag = 0;

    archivo = fopen("index.html","wb");

    if(archivo != NULL)
    {
        flag = fread(&auxPelicula, sizeof(EMovie), 1, archivo);

        if(flag != 1)
        {
            for(i = 0; i < sizeof(auxPelicula); i++)
            {
                *(auxPelicula + i) =  *(auxPelicula + i + 1);
            }
        }
        flag = fwrite(&auxPelicula, sizeof(EMovie), 1, archivo);

        if(flag < 1)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    }


    return 0;
}


int modificarPelicula(EMovie* pelicula)
{
    int flag = 0;
    int opcion;
    char respuesta;

    char nuevoTitulo[51];
    char nuevoGenero[51];
    int nuevaDuracion;
    char nuevaDescripcion[51];
    int nuevoPuntaje;
    char nuevoLinkImagen[51];


    EMovie* nuevaPelicula;

    nuevaPelicula = iniciarPelicula();

    nuevaPelicula = pelicula;

    printf("Que caracteristica desea modificar? \n");

    printf("1- Titulo.\n2- Genero.\n3- Duracion.\n4- Descripcion.\n5- Puntaje.\n6- Link de imagen.\n");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            printf("Ingrese nuevo titulo : ");
            fflush(stdin);
            gets(nuevoTitulo);
            strcpy(nuevaPelicula->titulo, nuevoTitulo);
            printf("Seguro que desea realizar este cambio? s/n\n");
            mostrarPelicula(nuevaPelicula);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                pelicula = nuevaPelicula;
                printf("Cambio exitoso!");
                flag = 1;
            }
            else
            {
                printf("Cambio cancelado!");
                flag = 0;
            }


            break;

        case 2:
            printf("Ingrese nuevo genero : ");
            fflush(stdin);
            gets(nuevoGenero);
            strcpy(nuevaPelicula->genero, nuevoGenero);
            printf("Seguro que desea realizar este cambio? s/n\n");
            mostrarPelicula(nuevaPelicula);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                pelicula = nuevaPelicula;
                printf("Cambio exitoso!");
                flag = 1;
            }
            else
            {
                printf("Cambio cancelado!");
                flag = 0;
            }

            break;

        case 3:
            printf("Ingrese nueva duracion : ");
            scanf("%d", &nuevaDuracion);
            nuevaPelicula->duracion = nuevaDuracion;
            printf("Seguro que desea realizar este cambio? s/n\n");
            mostrarPelicula(nuevaPelicula);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                pelicula = nuevaPelicula;
                printf("Cambio exitoso!");
                flag = 1;
            }
            else
            {
                printf("Cambio cancelado!");
                flag = 0;
            }

            break;

        case 4:
            printf("Ingrese nueva descripcion : ");
            fflush(stdin);
            gets(nuevaDescripcion);
            strcpy(nuevaPelicula->descripcion, nuevaDescripcion);
            printf("Seguro que desea realizar este cambio? s/n\n");
            mostrarPelicula(nuevaPelicula);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                pelicula = nuevaPelicula;
                printf("Cambio exitoso!");
                flag = 1;
            }
            else
            {
                printf("Cambio cancelado!");
                flag = 0;
            }

            break;

        case 5:
            printf("Ingrese nuevo puntaje : ");
            scanf("%d", &nuevoPuntaje);
            nuevaPelicula->puntaje = nuevoPuntaje;
            printf("Seguro que desea realizar este cambio? s/n\n");
            mostrarPelicula(nuevaPelicula);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                pelicula = nuevaPelicula;
                printf("Cambio exitoso!");
                flag = 1;
            }
            else
            {
                printf("Cambio cancelado!");
                flag = 0;
            }

            break;

        case 6:
            printf("Ingrese nuevo link de imagen : ");
            fflush(stdin);
            gets(nuevoLinkImagen);
            strcpy(nuevaPelicula->linkImagen, nuevoLinkImagen);
            printf("Seguro que desea realizar este cambio? s/n\n");
            mostrarPelicula(nuevaPelicula);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                pelicula = nuevaPelicula;
                printf("Cambio exitoso!");
                flag = 1;
            }
            else
            {
                printf("Cambio cancelado!");
                flag = 0;
            }


            break;
        default:
            printf("Error, elija una opcion valida");
            flag = 0;
            break;
    }


    return flag;
}





void generarPagina(EMovie* pelicula, char nombre[])
{
    FILE* pagina;



    char codigoPrincipio[] = {" <!DOCTYPE html>\
                                <!-- Template by Quackit.com -->\
                                <html lang='en'>\
                                <head>\
                                    <meta charset='utf-8'>\
                                    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
                                    <meta name='viewport' content='width=device-width, initial-scale=1'>\
                                    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\
                                    <title>Lista peliculas</title>\
                                    <!-- Bootstrap Core CSS -->\
                                    <link href='css/bootstrap.min.css' rel='stylesheet'>\
                                    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\
                                    <link href='css/custom.css' rel='stylesheet'>\
                                    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\
                                    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\
                                    <!--[if lt IE 9]>\
                                        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\
                                        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\
                                    <![endif]-->\
                                </head>\
                                <body>\
                                    <div class='container'>\
                                        <div class='row'>"};

    char codigoFinal[] = {"</div>\
                            <!-- /.row -->\
                            </div>\
                            <!-- /.container -->\
                            <!-- jQuery -->\
                            <script src='js/jquery-1.11.3.min.js'></script>\
                            <!-- Bootstrap Core JavaScript -->\
                            <script src='js/bootstrap.min.js'></script>\
                            <!-- IE10 viewport bug workaround -->\
                            <script src='js/ie10-viewport-bug-workaround.js'></script>\
                            <!-- Placeholder Images -->\
                            <script src='js/holder.min.js'></script>\
                        </body>\
                        </html>"};



    nombre = strcat(nombre, ".html");
    pagina = fopen(nombre, "w");

    if(pagina != NULL)
    {
        fwrite(codigoPrincipio, sizeof(EMovie),1, pagina);
        fprintf(pagina, "<article class='col-md-4 article-intro'>\
                <a href='#'>\
                    <img class='img-responsive img-rounded' src='%s' alt=''>\
                </a>\
                <h3>\
                    <a href='#'>%s</a>\
                </h3>\
				<ul>\
					<li>Género: %s</li>\
					<li>Puntaje: %d</li>\
					<li>Duración: %d</li>\
				</ul>\
                <p>%s</p>\
            </article>", pelicula->linkImagen, pelicula->titulo, pelicula->genero, pelicula->puntaje, pelicula->duracion, pelicula->descripcion);

        fwrite(codigoFinal, sizeof(EMovie), 1, pagina);
    }

    fclose(pagina);



}
