#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Employee.h"
#include "utn.h"

int main()
{
    int opcion;
    int contadorIdemployee = 0;
    int flag = -1;

    Employee arrayEmployee[ARRAY_SIZE]; //cambiar

    if(!initEmployees(arrayEmployee, ARRAY_SIZE))          //cambiar
    {
        printf("\nArray de empleados iniciado exitosamente\n");
    }

    do
    {
        utn_getUnsignedInt("\n\n1) Alta Empleado\n2) Modificar Empleado\n3) Baja Empleado\n4) Informar\n5) Salir\n","\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                if(!addEmployee(arrayEmployee, ARRAY_SIZE, &contadorIdemployee))
                {
                    printf("\n\nEmpleado ingresado exitosamente! ya puede acceder a las demas opciones\n");
                    flag = 0;
                }

                break;

            case 2: //Modificar
                if(!flag)
                {
                    modifyEmployee(arrayEmployee, ARRAY_SIZE);
                }
                else
                {
                    printf("\nError, aun no se ingresaron empleados\n");
                }

                break;

            case 3: //Baja
                if(!flag)
                {
                    removeEmployee(arrayEmployee, ARRAY_SIZE);
                }
                else
                {
                    printf("\nError, aun no se ingresaron empleados\n");
                }

                break;

            case 4://Informes
                if(!flag)
                {
                    informesEmployee(arrayEmployee, ARRAY_SIZE);
                }
                else
                {
                    printf("\nError, aun no se ingresaron empleados\n");
                }
                break;

            case 5://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=5);

    return 0;
}
