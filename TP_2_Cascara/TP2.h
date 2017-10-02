#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[51];
    int edad;
    int dni;
    int estado;

}ePersona;

ePersona cargarPersona(char[], int, int);

void mostrarPersonas(ePersona[], int);

void borrarPersona(ePersona[], int);

int buscarPorDni(ePersona persona[], int dni, int tam);

int encontrarEspacioLibre(ePersona persona[], int tam);

void ordenarPorNombre(ePersona persona[], int tam);

void grafico(int, int, int);





#endif // FUNCIONES_H_INCLUDED
