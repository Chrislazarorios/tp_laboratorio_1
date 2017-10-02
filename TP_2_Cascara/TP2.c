#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "TP2.h"

/** \brief carga datos de la estructura y cambia el estado a uno
 *
 * \param nombre es el nombre que se cargara en la variable nombre de la estructura
 * \param edad es la edad que se cargara en la variable edad de la estructura
 * \param dni es el dni que se cargara en la variable dni de la estructura
 * \return una estructura persona
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


/** \brief borra una persona cargada a partir del DNI
 *
 * \param persona es el array de la estructura ePersona seleccionada
 * \param tam es el tamaño del array
 * \return void
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


 /** \brief muestra los datos cargados en el array de la estructura persona
  *
  * \param persona es el array de la estructura ePersona
  * \param tam es el tamaño del array
  * \return void
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
 * \param persona es el array de la estructura ePersona
 * \param tam es el tamaño del array
 * \return el primer indice disponible
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
 * \brief ordena los nombres de sujetos ingresados de forma ascendente y descendente
 * \param persona es el array de la estructura ePersona
 * \param tam es el tamaño del array
 * \return void
 *
 */

void ordenarPorNombre(ePersona persona[], int tam)

{
    ePersona personaAux;

    int i;
    int j;
    int opcion;

    printf("Como desea ordenar? Elija una opcion : \n");
    printf("1 - Ordenar de forma ascendente (A - Z)\n");
    printf("2 - Ordenar de forma descendente (Z - A)\n");
    scanf("%d", &opcion);

    while(opcion != 1 && opcion != 2)
    {
        printf("Error, seleccione opcion 1 o 2 : \n");
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
 * \param persona es el array de la estructura ePersona
 * \param dni el dni a ser buscado en el array.
 * \param tam es el tamaño del array
 * \return el dni buscado
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


/**
 * \brief grafica las personas cargadas segun su rango de edad
 * \param menoresDe18 variable donde se guarda la cantidad de personas en ese rango de edad
 * \param de19A35 variable donde se guarda la cantidad de personas en ese rango de edad
 * \param mayoresDe35 variable donde se guarda la cantidad de personas en ese rango de edad
 * \return void
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

