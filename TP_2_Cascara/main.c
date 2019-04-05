#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP2.h"
#define TAM 20


int main()
{
    int i;
    int espacioLibre;
    char seguir = 's';
    int opcion = 0;
    char nombre[TAM][51];
    int edad[TAM];
    int dni[TAM];
    int flagDni = 0;
    int menores18 = 0;
    int de19A35 = 0;
    int mayores35 = 0;

    ePersona persona[TAM];




    for(i = 0; i < TAM; i++)
    {
        persona[i].estado = 0;
        persona[i].dni = 0;
        persona[i].edad = 0;

    }

    while(seguir=='s')
    {
        printf("1- Agregar persona \n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                espacioLibre = encontrarEspacioLibre(persona, TAM);



                if(espacioLibre == -1)
                    {
                        printf("No hay espacio libre!!\n");
                        break;
                    }

                printf("\nAgregar persona : \n");

                if(espacioLibre != -1)
                {
                    printf("Ingrese nombre : ");
                    fflush(stdin);
                    gets(nombre[espacioLibre]);

                    printf("Ingrese edad : ");
                    scanf("%d", &edad[espacioLibre]);
                    if(edad[espacioLibre] < 1 || edad[espacioLibre] > 100)
                    {
                        printf("Error, ingrese una edad entre 1 y 100");
                        scanf("%d", &edad[espacioLibre]);
                    }

                    printf("Ingrese DNI : ");
                    scanf("%d", &dni[espacioLibre]);

                    for(i = 0; i < TAM; i++)
                    {
                        if(persona[i].dni == dni[espacioLibre])
                        {
                            printf("Error, el DNI ya existe!!\n");
                            flagDni = 1;
                        }
                    }

                    if(flagDni == 0)
                    {
                        persona[espacioLibre] = cargarPersona(nombre[espacioLibre], edad[espacioLibre], dni[espacioLibre]);
                    }
                    break;
                }

                system("pause");
                system("cls");

                break;

            case 2:


                borrarPersona(persona, TAM);
                for(i = 0; i < TAM; i++)
                {
                    if(persona[i].estado == 0)
                    {
                        flagDni = 0;
                    }
                }

                system("pause");
                system("cls");

                break;

            case 3:

                ordenarPorNombre(persona, TAM);
                mostrarPersonas(persona, TAM);

                system("pause");
                system("cls");

                break;

            case 4:

                for(i = 0; i < TAM; i++)
                {
                    if(persona[i].estado == 1)
                    {
                        if(persona[i].edad > 1 && persona[i].edad < 19)
                        {
                            menores18++;
                        }
                        else
                        {
                            if(persona[i].edad >= 19 && persona[i].edad <= 35)
                            {
                                de19A35++;
                            }
                            else
                            {
                                if(persona[i].edad > 35 && persona[i].edad <= 100)
                                {
                                    mayores35++;
                                }

                            }

                        }
                    }



                }

                grafico(menores18, de19A35, mayores35);



                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error, opcion inexistente, reingrese (1-5) : ");
                scanf("%d", &opcion);
                system("pause");
                system("cls");
                break;

        }
    }

    return 0;
}

