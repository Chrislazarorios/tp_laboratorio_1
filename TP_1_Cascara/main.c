#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <inttypes.h>
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
    float todo;
    int primerFlag = 0;
    int segundoFlag = 0;
    int flagSuma = 0;
    int flagResta = 0;
    int flagDiv = 0;
    int flagMult = 0;
    int flagFactor = 0;
    int flagTodo = 0;
    while(seguir=='s')
    {
        if(primerFlag == 1)
        {
            printf("1- Ingresar 1er operando (A = %.2f)\n", A);
        }
        else
        {
            printf("1- Ingresar 1er operando (A = x)\n");
        }

        if(segundoFlag == 0)
        {
            printf("2- Ingresar 2do operando (B = y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B = %.2f)\n", B);
        }

        if(flagSuma == 0)
        {
            printf("3- Calcular la suma (A + B = 0)\n");
        }
        else
        {
            printf("3- Calcular la suma (A + B = %.2f)\n", sum);
        }

        if(flagResta == 0)
        {
            printf("4- Calcular la resta (A - B = 0)\n");
        }
        else
        {
            printf("4- Calcular la resta (A - B = %.2f)\n", rest);
        }

        if(flagDiv == 0)
        {
            printf("5- Calcular la division (A / B = 0)\n");
        }
        else
        {
            printf("5- Calcular la division (A / B = %.2f)\n", div);
        }

        if(flagMult == 0)
        {
            printf("6- Calcular la multiplicacion (A * B = 0)\n");
        }
        else
        {
            printf("6- Calcular la multiplicacion (A * B = %.2f)\n", mult);
        }

        if(flagFactor == 0)
        {
            printf("7- Calcular el factorial (A! = 0)\n");
        }
        else
        {
            printf("7- Calcular el factorial (A! = %i)\n", factor);
        }

        if(flagTodo == 0)
        {
            printf("8- Calcular todas las operaciones\n");
        }
        else
        {
            printf("8- Calcular todas las operaciones (%.2f)\n", todo);
        }

        printf("9- Salir\n\n");

        printf("Elija una opcion (1 - 9) : \n");

        scanf("%d", &opcion);

        while(opcion<1 || opcion>9)
        {
            printf("Error! Ingrese una opcion del menu : ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:


                A = ingresarNum();
                printf("El primer numero es : %f\n", A);
                primerFlag = 1;

                system("pause");
                system("cls");
                break;
            case 2:

                B = ingresarNum();
                printf("El segundo numero es : %f\n", B);
                segundoFlag = 1;
                system("pause");
                system("cls");
                break;
            case 3:

                if(primerFlag == 0 && segundoFlag == 0)
                    {
                        sum = printf("Error, no hay numero ingresado, ingrese operandos : \n");
                        A = ingresarNum();
                        printf("El primer numero es : %f\n", A);
                        B = ingresarNum();
                        printf("El segundo numero es : %f\n", B);
                        sum = suma(A,B);
                    }
                else
                    {
                        sum = suma(A, B);
                        primerFlag = 1;
                        segundoFlag = 1;
                    }

                flagSuma = 1;
                flagResta = 0;
                flagDiv = 0;
                flagMult = 0;
                flagFactor = 0;
                flagTodo = 0;
                system("pause");
                system("cls");
                break;
            case 4:

                if(primerFlag == 0 && segundoFlag == 0)
                    {
                        rest = printf("Error, no hay numero ingresado, ingrese operandos\n");
                        A = ingresarNum();
                        printf("El primer numero es : %f\n", A);
                        B = ingresarNum();
                        printf("El segundo numero es : %f\n", B);
                        rest = resta(A,B);

                    }
                else
                    {
                        rest = resta(A, B);
                        primerFlag = 1;
                        segundoFlag = 1;
                    }

                flagSuma = 0;
                flagResta = 1;
                flagDiv = 0;
                flagMult = 0;
                flagFactor = 0;
                flagTodo = 0;
                system("pause");
                system("cls");
                break;
            case 5:

                if(primerFlag == 0 && segundoFlag == 0)
                    {
                        rest = printf("Error, no hay numero ingresado, ingrese operandos\n");
                        A = ingresarNum();
                        printf("El primer numero es : %f\n", A);
                        B = ingresarNum();
                        printf("El segundo numero es : %f\n", B);
                        div = division(A,B);
                    }

                if(primerFlag == 1 && segundoFlag == 1)
                    {
                        if(B != 0)
                            {
                                div = division(A, B);
                                primerFlag = 1;
                                segundoFlag = 1;
                            }
                        else
                            {
                                printf("No se puede dividir por cero, ingrese otro denominador\n");
                                B = ingresarNum();
                                printf("El segundo numero es : %f\n", B);
                                div = division(A, B);
                            }
                    }
                else if(primerFlag == 1 && segundoFlag == 0)
                    {
                        div = printf("Error, no se puede dividir sin denominador \n");
                        B = ingresarNum();
                        printf("El segundo numero es : %f\n", B);
                        div = division(A, B);
                        segundoFlag = 1;
                    }


                flagSuma = 0;
                flagResta = 0;
                flagDiv = 1;
                flagMult = 0;
                flagFactor = 0;
                flagTodo = 0;
                system("pause");
                system("cls");
                break;
            case 6:

                if(primerFlag == 0 && segundoFlag == 0)
                    {
                        mult = printf("Error, no hay numero ingresado.\n");
                        A = ingresarNum();
                        printf("El primer numero es : %f\n", A);
                        B = ingresarNum();
                        printf("El segundo numero es : %f\n", B);
                        mult = multiplicacion(A,B);
                    }
                else
                    {
                        mult =  multiplicacion(A, B);
                        primerFlag = 1;
                        segundoFlag = 1;
                    }

                flagSuma = 0;
                flagResta = 0;
                flagDiv = 0;
                flagMult = 1;
                flagFactor = 0;
                flagTodo = 0;
                system("pause");
                system("cls");
                break;
            case 7:

                if(primerFlag == 0)
                    {
                        factor = printf("Error, no hay numero A, ingrese : \n");
                        A = ingresarNum();
                        printf("El primer numero es : %f\n", A);
                        num = (int)A;
                        factor = factorial(num);
                    }
                else
                    {
                        num = (int)A;
                        if(num >= 0 && num <= 20)
                            {
                                factor = factorial(num );
                                primerFlag = 1;

                            }
                        else
                        {
                            while(num > 20)
                                {
                                    printf("Error, A debe ser menor a 20, reingrese A : \n");
                                    A = ingresarNum();
                                    printf("El primer numero es : %f\n", A);
                                    num = (int)A;
                                    if(num <= 20 && num >= 0)
                                    {
                                        factor = factorial(num);
                                    }
                                }

                            while(num < 0)
                                {
                                    printf("Error, los negativos no tienen factorial, reingrese A : \n");
                                    A = ingresarNum();
                                    printf("El primer numero es : %f\n", A);
                                    num = (int)A;
                                    if(num <= 20 && num >= 0 )
                                    {
                                        factor = factorial(num);
                                    }
                                }

                        }

                    }

                flagSuma = 0;
                flagResta = 0;
                flagDiv = 0;
                flagMult = 0;
                flagFactor = 1;
                flagTodo = 0;
                system("pause");
                system("cls");
                break;
            case 8:

                if(primerFlag == 0 && segundoFlag == 0)
                    {
                        todo = printf("Error, no hay numeros ingresados. Ingrese operandos : \n");
                        A = ingresarNum();
                        printf("El primer numero es : %f\n", A);
                        B = ingresarNum();
                        printf("El segundo numero es : %f\n", B);
                        todo = todoJunto(A,B);
                        primerFlag = 1;
                        segundoFlag = 1;

                    }
                else
                    {
                        todo = todoJunto(A, B);
                        primerFlag = 1;
                        segundoFlag = 1;
                    }

                flagSuma = 0;
                flagResta = 0;
                flagDiv = 0;
                flagMult = 0;
                flagFactor = 0;
                flagTodo = 1;
                system("pause");
                system("cls");
                break;
            case 9:
                seguir = 'n';
                break;
        }
        system("cls");
    }


    return 0;
}
