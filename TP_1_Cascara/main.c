#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float A;
    float B;
    float sum;
    float rest;
    float div;
    float mult;
    int factor;
    int num;
    int todo;
    int primerOp = 0;
    int segundoOp = 0;
    //int i;
    while(seguir=='s')
    {

        printf("1- Ingresar 1er operando (A=%0.f)\n", A);
        printf("2- Ingresar 2do operando (B=%0.f)\n", B);
        printf("3- Calcular la suma (A+B=%0.f)\n", sum);
        printf("4- Calcular la resta (A-B=%0.f)\n", rest);
        printf("5- Calcular la division (A/B=%2.f)\n", div);
        printf("6- Calcular la multiplicacion (A*B=%2.f)\n", mult);
        printf("7- Calcular el factorial (A!=%i)\n", factor);
        printf("8- Calcular todas las operacione %d\n", todo);
        printf("9- Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
               if (A = ingresarNum())
               {
                    primerOp = 1;
                    printf("El primer numero es : %f\n", A);
               }
                getch();
                system("cls");
                break;
            case 2:
                if(B = ingresarNum())
                {
                    segundoOp = 1;
                    printf("El segundo numero es : %f\n", B);
                }
                getch();
                system("cls");
                break;
            case 3:
                if(primerOp == 0 && segundoOp == 0)
                    {
                        sum = printf("Error, no hay numero ingresado.");
                    }
                else
                    {
                        sum = suma(A, B);
                    }

                getch();
                system("cls");
                break;
            case 4:
                if(primerOp == 0 && segundoOp == 0)
                    {
                        rest = printf("Error, no hay numero ingresado.");
                    }
                else
                    {
                        rest = resta(A, B);
                    }

                getch();
                system("cls");
                break;
            case 5:
                if(primerOp == 0 && segundoOp == 0)
                    {
                        div = printf("Error, no hay numero ingresado.");
                    }
                else
                    {
                        if(B != 0)
                            {
                                div = division(A, B);
                            }
                        else
                            {
                                printf("No se puede dividir por cero");
                            }
                    }


                getch();
                system("cls");
                break;
            case 6:
                if(primerOp == 0 && segundoOp == 0)
                    {
                        mult = printf("Error, no hay numero ingresado.");
                    }
                else
                    {
                        mult =  multiplicacion(A, B);
                    }

                getch();
                system("cls");
                break;
            case 7:
                if(primerOp == 0)
                    {
                        factor = printf("Error, no hay numero A ingresado.");
                    }
                else
                    {
                        num = (int)A;
                        if(num >= 0)
                            {
                                factor = factorial(num );
                            }
                        else
                            {
                                printf("Error, los negativos no tienen factorial, reingrese A");
                            }
                    }

                getch();
                system("cls");
                break;
            case 8:
                if(primerOp == 0 && segundoOp == 0)
                    {
                        todo = printf("Error, no hay numero ingresado.");
                    }
                else
                    {
                        todo = todoJunto(A, B);
                    }

                getch();
                system("cls");
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
