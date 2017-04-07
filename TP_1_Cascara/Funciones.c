#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

float ingresarNum()
    {
        float numero;
        printf("Ingrese un numero :");
        scanf("%f", &numero);
        return numero;
    }


float suma(float A, float B)
    {
        float resultado;
        resultado = A + B;
        printf("El resultado de la suma es : %f\n", resultado);
        return resultado;
    }

float resta(float A, float B)
    {
        float resultado;
        resultado = A - B;
        printf("El resultado de la resta es : %f\n", resultado);
        return resultado;
    }

float division(float A, float B)
    {
        while(B == 0)
            {
                printf("Error, no se puede dividir por cero, reingrese B : \n");
                scanf("%f", &B);
            }
        float resultado;
        resultado = A / B;
        printf("El resultado de la division es : %f\n", resultado);
        return resultado;
    }

float multiplicacion(float A, float B)
    {
        float resultado;
        resultado = A * B;
        printf("El resultado de la multiplicacion es : %f\n", resultado);
        return resultado;
    }

int factorial(int num)
    {
        int i;
        int fact = 1;

        for(i = num; i > 0; i--)
        {
            fact = fact * i;
        }
        printf("El factorial de %i es: %i\n", num, fact);
        return fact;
    }


float todoJunto(float A, float B)
    {
        float sum;
        float rest;
        float div;
        float mult;
        int factor;
        float num =(int)A;



        sum = suma(A, B);
        rest = resta(A, B);
        if(B != 0)
            {
                div = division(A, B);
            }
        else
            {
                printf("No se puede dividir por cero\n");
            }
        mult =  multiplicacion(A, B);

        if(num >= 0)
            {
                factor = factorial(num );
            }
        else
            {
                printf("Error, los negativos no tienen factorial, reingrese A");
            }


        return sum;
        return rest;
        return div;
        return mult;
        return factor;

    }
