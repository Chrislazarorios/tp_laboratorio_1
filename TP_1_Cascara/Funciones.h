#include <stdio.h>
#include <stdlib.h>

/** \brief Funcion que recibe un numero decimal. Se llama dos veces, en A y B.
 *
 * \param  No posee parametros. Los datos los decide el usuario.
 * \return Retorna el numero que ingresa el usuario en el case en que fue llamado.
 *
 */

float ingresarNum ();

/** \brief Funcion que suma los numeros decimales ingresados en case 1 y 2
 *
 * \param numero ingresado en case 1
 * \param numero ingresado en case 2
 * \return suma de ambos decimales
 *
 */

float suma (float, float );

/** \brief Funcion que resta los numeros decimales ingresados en case 1 y 2
 *
 * \param numero ingresado en case 1
 * \param numero ingresado en case 2
 * \return resta de ambos decimales
 *
 */

float resta (float, float );

/** \brief Funcion que multiplica los numeros decimales ingresados en case 1 y 2
 *
 * \param numero ingresado en case 1
 * \param numero ingresado en case 2
 * \return multiplicacion de ambos decimales
 *
 */

float multiplicacion (float, float );

/** \brief Funcion que divide los numeros decimales ingresados en case 1 y 2
 *
 * \param numero ingresado en case 1
 * \param numero ingresado en case 2
 * \return division de ambos decimales
 *
 */

float division (float, float );

/** \brief Funcion que factoriza el numero entero ingresados en case 1
 *
 * \param numero ingresado en case 1
 * \return factorizacion del numero entero ingresado
 *
 */

unsigned long long int factorial (int );

/** \brief Funcion que engloba las funciones previamente declaradas
 *
 * \param numero ingresado en case 1
 * \param numero ingresado en case 2
 * \return suma, resta, multiplica y divide los decimales ingresados, tambien factoriza el entero del case 1
 *
 */

float todoJunto (float, float);


