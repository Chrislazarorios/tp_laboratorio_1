#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void sujetoEstado(ePersona persona[], int tam, int estado)
{

    int i;
    for (i = 0; i < tam; i++) {

        persona[i].estado = estado;

    }

}

int buscarPorDni(ePersona persona[], int tam, int dni)
    {
        int i;
        for (i = 0; i < tam; i++)
        {
            if((persona[i].dni = dni) && (persona[i].estado == 1))
                {
                    return i;
                }

        }

         return 0;
    }

int obtenerEspacioLibre(ePersona persona[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(persona[i].estado == 0)
            {
                return i;
            }
    }

    return -1;
}



void ordenarPorNombre(ePersona persona[], int tam)

{
    ePersona personaAux;

    int i;
    int j;

    for(i = 0; i < tam - 1; i++)
    {
        if(persona[i].estado == 0)
        {
            continue;
        }
        for(j = i + 1; j < tam; j++)
        {
            if(persona[i].estado == 0)
            {
                continue;
            }
            if(strcmp(persona[j].nombre,persona[i].nombre) < 0)
            {
                personaAux = persona[j];
                persona[j] = persona[i];
                persona[i] = personaAux;
            }
        }
    }


}


int obtenerEntero(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}


void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



int getStringNumero(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
