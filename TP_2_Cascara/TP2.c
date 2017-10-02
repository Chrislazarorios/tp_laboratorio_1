#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "TP2.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

ePersona cargarPersona(char nombre[], int edad, int dni)
{
    ePersona persona;

    strcpy(persona.nombre,nombre);
    persona.edad = edad;
    persona.dni = dni;
    persona.estado = 1;


    return persona;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void borrarPersona(ePersona persona[], int tam)
 {
     int i;
     char respuesta;
     int dni;
     int posicion;

     printf("Ingrese el DNI de la persona a borrar : ");
     scanf("%d", &dni);

     posicion = buscarPorDni(persona, dni, tam);

     for(i = 0; i < tam; i++)
     {

         if(persona[i].estado == 1 && posicion == persona[i].dni)
         {
             printf("Se eliminara a Nombre : %s - Edad : %d - DNI : %d \n", persona[i].nombre, persona[i].edad, persona[i].dni);
             printf("Desea eliminarla? s/n \n");
             fflush(stdin);
             respuesta = tolower(getche());
             printf("\n");


             while(respuesta != 's' && respuesta != 'n')
             {
                 printf("Error, ingrese s o n \n");
                 fflush(stdin);
                 respuesta = tolower(getche());
             }
             if(respuesta == 's')
             {
                 persona[i].estado = 0;
                 persona[i].dni = 0;
                 persona[i].edad = 0;
                 printf("Persona eliminada!!\n");
             }
             else
             {
                 printf("Persona NO eliminada!!\n");
             }
         }

     }


     if(buscarPorDni(persona, dni, tam) == -1)
         {
             printf("El DNI no existe\n");
         }

 }


 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

  void mostrarPersonas(ePersona persona[], int tam)
  {
      int i;

      for(i = 0; i < tam; i++)
      {
          if(persona[i].estado == 1)
          {
              printf("Nombre : %s - Edad : %d - DNI : %d\n", persona[i].nombre, persona[i].edad, persona[i].dni);
          }
      }

  }




/**
 * \brief Obtiene el primer indice libre del array.
 * @param persona el array se pasa como parametro.
 * @return el primer indice disponible
 */

int encontrarEspacioLibre(ePersona persona[], int tam)
{
    int i;
    int indiceLibre;
    int flag = 0;

    for(i = 0; i < tam; i++)
    {
        if(persona[i].estado == 0)
            {
                indiceLibre = i;
                flag = 1;
                break;
            }
    }

    if(flag == 0)
    {
        printf("No hay espacios libres!!");
        indiceLibre = -1;
    }

    return indiceLibre;
}


/**
 * \brief ordena los nombres de sujetos ingresados
 * @param persona el array se pasa como parametro.
 * @return lista ordenada alfabeticamente de los nombres basado en la tabla ascii
 *
 */

void ordenarPorNombre(ePersona persona[], int tam)

{
    ePersona personaAux;

    int i;
    int j;
    int opcion;

    printf("1 - Ordenar de forma ascendente (A - Z)\n");
    printf("2 - Ordenar de forma descendente (Z - A)\n");
    scanf("%d", &opcion);

    while(opcion != 1 && opcion != 2)
    {
        printf("Error, seleccione opcion 1 o 2 : ");
        scanf("%d", &opcion);
    }

    if(opcion == 1)
    {
        for(i = 0; i < tam - 1; i++)
        {
            if(persona[i].estado == 0)
            {
                continue;
            }
            for(j = i + 1; j < tam; j++)
            {
                if(persona[j].estado == 0)
                {
                    continue;
                }
                if(strcmp(persona[i].nombre, persona[j].nombre) == 1)
                {
                    personaAux = persona[i];
                    persona[i] = persona[j];
                    persona[j] = personaAux;
                }
            }
        }
    }

    else
    {
        if(opcion == 2)
        {
            for(i = 0; i < tam - 1; i++)
            {
                if(persona[i].estado == 0)
                {
                    continue;
                }
                for(j = i + 1; j < tam; j++)
                {
                    if(persona[j].estado == 0)
                    {
                        continue;
                    }
                    if(strcmp(persona[i].nombre, persona[j].nombre) == -1)
                    {
                        personaAux = persona[i];
                        persona[i] = persona[j];
                        persona[j] = personaAux;
                    }
                }
            }

        }

    }



}


/**
 * \brief Obtiene el indice que coincide con el dni buscado por parametro.
 * @param persona el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

int buscarPorDni(ePersona persona[], int dni, int tam)
    {
        int i;
        int posicion;
        int flag = 0;

        for (i = 0; i < tam; i++)
        {
            if((persona[i].dni == dni) && (persona[i].estado == 1))
                {
                    posicion = persona[i].dni;
                    flag = 1;
                }

        }

        if(flag == 0)
        {
            posicion = -1;
        }

        return posicion;
    }


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void grafico(int menoresDe18, int de19A35, int mayoresDe35)
{
    int i;
    int j;
    int edadMax = 0;
    int edades[3] = {menoresDe18, de19A35, mayoresDe35};

    for(i = 0; i < 3; i++)
    {

        if(edades[i] > edadMax)
        {
            edadMax = edades[i];
        }



    }


    printf("\n");

    for(i = edadMax; i > 0; i--)
    {
        printf("%d", i);

        for(j = 0; j < 3; j++)
        {
            if(edades[j] >= i)
            {
                printf("\t%c", 158);
            }
            else
            {
                printf("\t ");
            }
        }
        printf("\n");
    }
    printf("\t<19\t19-35\t >35\n");

    system("pause");
    system("cls");
}

