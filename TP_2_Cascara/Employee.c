#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "Employee.h"
#include "utn.h"

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
    int retorno=-1;
    if(list!= NULL && len>0)
    {
        for(;len>0;len--)
        {
            list[len-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Finds first empty index in array
* \param list employee*
* \param len int
* \param position int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int findEmptyEmployee(Employee* list, int len, int *position)
{
    int retorno=-1;
    int i;
    if(list!= NULL && len>=0 && position!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
            {
                retorno = 0;
                *position = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param contadorID int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int* contadorID)
{
    int retorno=-1;
    int posicion;


    if(list!=NULL && len>0 && contadorID!=NULL)
    {
        if(findEmptyEmployee(list,len,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {

            (*contadorID)++;
            list[posicion].id=*contadorID;                                                       //campo ID
            list[posicion].isEmpty = 0;
            utn_getName("\nIngrese nombre de empleado: ","\nError",1,20,3,list[posicion].name);                      //mensaje + cambiar campo varString
            utn_getName("\nIngrese apellido de empleado: ","\nError",1,20,3,list[posicion].lastName);                      //mensaje + cambiar campo varString
            utn_getFloat("\nIngrese sueldo del empleado: ","\nError",1,10,1,10,3,&list[posicion].salary);             //mensaje + cambiar campo varFloat
            utn_getUnsignedInt("\nIngrese sector del empleado: ","\nError",1,sizeof(int),1,1,1,&list[posicion].sector);           //mensaje + cambiar campo varInt



            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Sueldo: %.2f\n Sector: %d",
                   posicion, list[posicion].id,list[posicion].name,list[posicion].lastName,list[posicion].salary,list[posicion].sector);

            retorno=0;
        }
    }

    return retorno;
}


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id, int *position)
{
    int retorno=-1;
    int i;
    if(list!= NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
                continue;
            else if(list[i].id==id)                                                   //cambiar campo ID
            {
                retorno=0;
                *position = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len)
{
    int retorno=-1;
    int posicion;
    int id;
    if(list!=NULL && len>0)
    {
        printEmployees(list, len);
        utn_getUnsignedInt("\nID de empleado a remover: ","\nError",1,sizeof(int),1,len,1,&id);          //cambiar si no se busca por ID
        if(findEmployeeById(list,len,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            list[posicion].isEmpty=1;
            list[posicion].id=0;                                                                   //cambiar campo id
            strcpy(list[posicion].name,"");                                                   //cambiar campo varString
            strcpy(list[posicion].lastName,"");                                               //cambiar campo varLongString
            list[posicion].sector=0;                                                               //cambiar campo varInt
            list[posicion].salary=0;                                                             //cambiar campo varFloat
            retorno=0;

            printf("Empleado eliminado exitosamente.");
        }
    }
    return retorno;
}

int modifyEmployee(Employee* list, int len)
{
    int retorno=-1;
    int posicion;
    int auxId;                                                                                         //cambiar si no se busca por ID
    char opcion;
    char opcionAux;

    if(list!=NULL && len>0)
    {
        printEmployees(list, len);
        utn_getUnsignedInt("\nID de empleado a modificar: ","\nError",1,sizeof(int),1,len,1,&auxId);         //cambiar si no se busca por ID
        if(findEmployeeById(list,len,auxId,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Sueldo: %.2f\n Sector: %d\n",
                   posicion, list[posicion].id,list[posicion].name,list[posicion].lastName,list[posicion].salary, list[posicion].sector);
                utn_getChar("\nQue desea modificar?: \nA: Nombre \nB: Apellido \nC: Sueldo \nD: Sector \nS: salir\nElija una opcion(A/B/C/D/S):","\nError",'A','Z',1,&opcion);
                opcionAux = toupper(opcion);
                switch(opcionAux)
                {
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre de empleado: ","\nError",1,20,3,list[posicion].name);                      //mensaje + cambiar campo nombre
                        break;
                    case 'B':
                        utn_getName("\nIngrese nuevo apellido para empleado: ","\nError",1,20,3,list[posicion].lastName);
                        break;
                    case 'C':
                        utn_getFloat("\nIngrese nuevo salario de empleado: ","\nError",1,6,1,4,3,&list[posicion].salary);           //mensaje + cambiar campo varInt
                        break;
                    case 'D':
                        utn_getUnsignedInt("\nIngrese nuevo sector de empleado: ","\nError",1,4,1,4,3,&list[posicion].sector);           //mensaje + cambiar campo varInt
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcionAux!='S');

            retorno=0;
        }
    }
    return retorno;
}


/** \brief Sort the elements in the array of employees
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len)
{
    int retorno=-1;
    int i, j;
    int opcion;

    Employee employeeAux;

    if(list!=NULL && len>=0)
    {

        utn_getUnsignedInt("Como desea ordenar? Elija una opcion : \n1 - Ordenar de forma ascendente (A - Z)\n2 - Ordenar de forma descendente (Z - A)\n","\nError", 1, sizeof(int), 1, 1, 3, &opcion);


        while(opcion != 1 && opcion != 2)
        {
            utn_getUnsignedInt("Error, seleccione opcion 1 o 0 : \n","\nError", 1, sizeof(int), 1, 1, 3, &opcion);
        }


        switch(opcion)
        {
            case 1:
                for(i = 0; i < len - 1; i++)
                {
                    if(list[i].isEmpty == 1)
                    {
                        continue;
                    }
                    for(j = i + 1; j < len; j++)
                    {
                        if(list[j].isEmpty == 1)
                        {
                            continue;
                        }
                        if(strcmp(list[i].lastName, list[j].lastName) == 1) // Ordena de forma ascendente por apellido
                        {

                            employeeAux = list[i];
                            list[i] = list[j];
                            list[j] = employeeAux;

                        }
                        else if(strcmp(list[i].lastName, list[j].lastName) == 0)
                        {
                            if(list[i].sector > list[j].sector) // Ordena de forma ascendente por sector
                            {

                                employeeAux = list[i];
                                list[i] = list[j];
                                list[j] = employeeAux;

                            }
                        }
                    }
                }
                printEmployees(list, len);
                break;
            case 2:
                for(i = 0; i < len - 1; i++)
                {
                    if(list[i].isEmpty == 1)
                    {
                        continue;
                    }
                    for(j = i + 1; j < len; j++)
                    {
                        if(list[j].isEmpty == 1)
                        {
                            continue;
                        }
                        if(strcmp(list[i].lastName, list[j].lastName) == -1) // Ordena de forma descendente por apellido
                        {

                            employeeAux = list[i];
                            list[i] = list[j];
                            list[j] = employeeAux;

                        }
                        else if(strcmp(list[i].lastName, list[j].lastName) == 0)
                        {
                            if(list[i].sector < list[j].sector)// Ordena de forma descendente por sector
                            {

                                employeeAux = list[i];
                                list[i] = list[j];
                                list[j] = employeeAux;

                            }
                        }
                    }
                }
                printEmployees(list, len);
                break;
            default:
                    printf("\nOpcion no valida");
        }



        retorno=0;
    }
    return retorno;
}


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int len)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == 1)
                continue;
            else if(list[i].isEmpty == 0)
            {
                printf("\n ID: %d\n Nombre: %s\n Apellido: %s\n Sueldo: %.2f\n Sector: %d\n",
                   list[i].id,list[i].name,list[i].lastName,list[i].salary, list[i].sector);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief print the total and average salary of employees
*
* \param list Employee*
* \param length int
* \return int
*
*/

int promedioEmployees(Employee* list, int len)
{
    float promSalary;
    float totalSalary = 0;
    int contador = 0;
    int superaPromedio = 0;
    int i;
    int ret = -1;

    if(list != NULL && len >= 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                contador++;
                totalSalary = totalSalary + list[i].salary;
            }

        }

        promSalary = totalSalary / (float)contador;
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0 && list[i].salary > promSalary)
            {
                superaPromedio++;
            }
        }
        printf("\nTotal de salarios : %.2f\nPromedio de salarios : %.2f\n", totalSalary, promSalary);
        printf("Cantidad de empleados que superan el salario promedio : %d ", superaPromedio);
        ret = 0;
    }

    return ret;
}

/** \brief allows you to choose which report you want to see
*
* \param list Employee*
* \param length int
* \return int
*
*/

int informesEmployee(Employee list[], int len)
{
    int opcion;
    int ret = -1;
    if(list!=NULL && len>=0)
    {

        utn_getUnsignedInt("Que informe desea realizar? Elija una opcion : \n1 - Listar empleados ordenados alfabeticamente\n2 - Total y promedio de salarios\n","\nError", 1, sizeof(int), 1, 1, 3, &opcion);


        while(opcion != 1 && opcion != 2)
        {
            utn_getUnsignedInt("Error, seleccione opcion 1 o 2 : \n","\nError", 1, sizeof(int), 1, 1, 3, &opcion);
        }


        switch(opcion)
        {
            case 1:
                if(!sortEmployees(list, len))
                {
                    ret = 0;
                }

                break;
            case 2:
                if(!promedioEmployees(list, len))
                {
                    ret = 0;
                }

                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    return ret;
}

