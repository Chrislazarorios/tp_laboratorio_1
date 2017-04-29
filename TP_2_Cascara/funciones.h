#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[51];
    int edad;
    int dni;
    int estado;

}ePersona;

/**
 * setea el estado del sujeto
 * @param persona el array se pasa como parametro.
 * @return el estado del sujeto
 *
 */

void sujetoEstado(ePersona persona[], int tam, int estado);

/**
 * ordena los nombres de sujetos ingresados
 * @param persona el array se pasa como parametro.
 * @return lista ordenada alfabeticamente de los nombres basado en la tabla ascii
 *
 */


void ordenarPorNombre(ePersona persona[], int tam);

/**
 * Obtiene el primer indice libre del array.
 * @param persona el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona persona[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param persona el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona persona[], int tam, int dni);

/**
 * recibe un char
 * @param mensaje que ingresa el sujeto
 * @return un entero
 *
 */

int obtenerEntero(char mensaje[]);

/**
 * recibe un char en forma de mensaje
 * @param mensaje que ingresa el sujeto
 * @return un char
 *
 */

char getChar(char mensaje[]);

/**
 * recibe un char
 * @param str un char que transforma en entero
 * @return un numero entero
 *
 */

int esNumerico(char str[]) ;

/**
 * recibe un char
 * @param str un char que transforma en letra
 * @return una letra
 *
 */

int esSoloLetras(char str[]);

/**
 * recibe un mensaje en char
 * @param se ingresa un mensaje
 * @return un string
 *
 */

void getString(char mensaje[],char input[]);

/**
 * recibe un mensaje en char
 * @param se ingresa un mensaje
 * @return un string de letras
 *
 */

int getStringLetras(char mensaje[],char input[]);

/**
 * recibe un mensaje en char
 * @param se ingresa un mensaje
 * @return  un string de numeros
 *
 */

int getStringNumero(char mensaje[],char input[]);




#endif // FUNCIONES_H_INCLUDED
