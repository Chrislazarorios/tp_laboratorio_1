#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}EMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* pelicula, FILE*);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie pelicula, FILE*);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* pelicula, char nombre[]);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
EMovie* iniciarPelicula();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int altaPelicula(EMovie*);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarPelicula(EMovie*);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int modificarPelicula(EMovie*);



#endif // FUNCIONES_H_INCLUDED
