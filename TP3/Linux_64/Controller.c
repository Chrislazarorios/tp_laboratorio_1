#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)

{
    int ret = -1;
    FILE* pFile;
    pFile = fopen(path,"r");
    if(pFile == NULL)
    {
        printf("El archivo no existe");
    }
    else
    {
        if(!parser_EmployeeFromText(pFile , pArrayListEmployee))
        {
            ret = 0;
        }
    }

    fclose(pFile);
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pFile;
    pFile = fopen(path,"rb");

    if(pFile == NULL)
    {
        printf("El archivo no existe");
    }
    else
    {
        if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
        {
            ret = 0;
        }
    }

    fclose(pFile);
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* employee;

    int ret = -1;
    int auxId;
    char auxNombre[128];
    char auxHorasTrabajoStr[128];
    char auxSueldoStr[128];
    int len;

    if(pArrayListEmployee != NULL)
    {
        employee = employee_new();

        len = ll_len(pArrayListEmployee);

//        auxId = employee_generaId();
        auxId = len+1;
        utn_getName("Ingrese nombre : ","Error",0,128,3,auxNombre);
        utn_getTexto("\nIngrese sueldo : ","\nError",1,50,3,auxSueldoStr);
        utn_getTexto("\nIngrese horas : ","\nError",1,50,3,auxHorasTrabajoStr);

        if(employee != NULL && !employee_setId(employee,auxId) && !employee_setNombre(employee,auxNombre) && !employee_setSueldoStr(employee,auxSueldoStr) && !employee_setHorasTrabajadasStr(employee,auxHorasTrabajoStr))
        {
            if(!ll_add(pArrayListEmployee,employee))
            {
                ret = 0;
            }
            else
            {
                printf("Error al agregar empleado");
            }
        }
    }

    return ret;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    Employee* employee;

    int auxId;
    char auxNombre[128];
    int auxHorasTrabajo;
    int auxSueldo;
    char opcion;
    char opcionAux;
    int posicion;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        utn_getUnsignedInt("\nID de empleado a modificar: ","\nError",1,sizeof(int),1,20,3,&auxId);
        posicion = controller_findEmployeeById(pArrayListEmployee, auxId);
        if(posicion == -1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                employee = ll_get(pArrayListEmployee, posicion);

                utn_getChar("\nQue desea modificar?: \nA: Nombre \nB: Horas trabajadas \nC: Sueldo \nS: salir\nElija una opcion(A/B/C/D/S):","\nError",'A','Z',1,&opcion);
                opcionAux = toupper(opcion);
                switch(opcionAux)
                {
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre de empleado: ","\nError",1,128,3, auxNombre);                      //mensaje + cambiar campo nombre
                        employee_setNombre(employee, auxNombre);
                        break;
                    case 'B':
                        utn_getUnsignedInt("\nIngrese nueva cantidad de horas trabajadas: ","\nError",1,sizeof(int),0,20,3,&auxHorasTrabajo);
                        employee_setHorasTrabajadas(employee, auxHorasTrabajo);
                        break;
                    case 'C':
                        utn_getUnsignedInt("\nIngrese nuevo salario de empleado: ","\nError",1,sizeof(int),0,20,3,&auxSueldo);           //mensaje + cambiar campo varInt
                        employee_setSueldo(employee, auxSueldo);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcionAux!='S');

            ret = 0;
        }
    }

    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxId;
    int ret = -1;
    int posicion;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        utn_getUnsignedInt("\nID de empleado a remover: ","\nError",1,sizeof(int),1,20,3,&auxId);

        posicion = controller_findEmployeeById(pArrayListEmployee, auxId);
        if(posicion == -1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListEmployee, posicion);
            ret = 0;
        }
    }

    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *><
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int i;
    Employee* employee;

    int auxId;
    char auxNombre[128];
    int auxHorasTrabajo;
    int auxSueldo;
    int len;

    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(i = 0; i <= len; i++)
        {
            employee = ll_get(pArrayListEmployee, i);
            employee_getId(employee, &auxId);
            employee_getNombre(employee, auxNombre);
            employee_getHorasTrabajadas(employee, &auxHorasTrabajo);
            employee_getSueldo(employee, &auxSueldo);

            if(employee != NULL)
            {
                printf("Id: %d\nNombre: %s\nHoras trabajadas: %d\nSueldo: %d\n",auxId,auxNombre,auxHorasTrabajo,auxSueldo);
                ret = 0;
            }
        }
    }

    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, controller_comparisonString,1)
    }

    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int i;
    int len;
    //auxiliares para getters
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajo;
    int auxSueldo;

    Employee* pEmpl; // creamos un puntero a empleado para guardar el resultado de ll_get


    FILE* fp = fopen(path, "w+");
    if(fp != NULL)
    {
        fprintf(fp, "id,nombre,horasTrabajadas,sueldo\n");

        len = ll_len(pArrayListEmployee); // obtengo tamano de linkedlist a traves de funcion

        for(i = 0;i < len;i++)
        {
            pEmpl = ll_get(pArrayListEmployee, i); // retorna un puntero a empleado, es decir, un empleado entero(un globito con los elementos de un empleado)
//            fprintf(fp, "%d, %s, %d, %d\n", pEmpl->id, pEmpl->nombre, pEmpl->horasTrabajadas, pEmpl->sueldo);//cambiamos este fprintf por una funcion

            employee_getId(pEmpl, &auxId);
            employee_getNombre(pEmpl, auxNombre);
            employee_getHorasTrabajadas(pEmpl, &auxHorasTrabajo);
            employee_getSueldo(pEmpl, &auxSueldo);
            fprintf(fp, "%d,%s,%d,%d\n", auxId, auxNombre, auxHorasTrabajo, auxSueldo);

            ret = 0;
        }

        fclose(fp);
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int i;
    //auxiliares para getters
//    int auxId;
//    char auxNombre[50];
//    int auxHorasTrabajo;
//    int auxSueldo;

    Employee* pEmpl; // creamos un puntero a empleado para guardar el resultado de ll_get

    int len;
    FILE* fp = fopen(path, "w+"); // en windows es w+b, en linux puede ir w+ o w+b, en linux es lo mismo
    if(fp != NULL)
    {
//        fprintf(fp, "id,nombre,horasTrabajadas,sueldo\n");

        len = ll_len(pArrayListEmployee); // obtengo tamano de linkedlist a traves de funcion

        for(i = 0;i < len;i++)
        {
            pEmpl = ll_get(pArrayListEmployee, i); // retorna un puntero a empleado, es decir, un empleado entero(un globito con los elementos de un empleado)
//            fprintf(fp, "%d, %s, %d, %d\n", pEmpl->id, pEmpl->nombre, pEmpl->horasTrabajadas, pEmpl->sueldo);//cambiamos este fprintf por una funcion

//            employee_getId(pEmpl, &auxId);
//            employee_getNombre(pEmpl, auxNombre);
//            employee_getHorasTrabajadas(pEmpl, &auxHorasTrabajo);
//            employee_getSueldo(pEmpl, &auxSueldo);
//            fprintf(fp, "%d, %s, %d, %d\n", auxId, auxNombre, auxHorasTrabajo, auxSueldo);

            // parametros de FWRITE
            // primer parametro recibe el puntero al array de donde quiero obtener los datos a escribir
            // segundo parametro es el tamano del tipo de dato del array de donde voy a leer para escribir
            // cantidad de elementos a escribir, en este caso 1 porque voy a escribir un empleado (un globito con todos los elementos de empleado, nombre,id,sueldo,etc)
            // puntero a FILE
            fwrite(pEmpl,sizeof(Employee), 1, fp);

            ret = 0;
        }

        fclose(fp);
    }
    return ret;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id)
{
    int ret = -1;
    int i;
    Employee* employee;
    int auxId;
    int len;

    if (pArrayListEmployee != NULL && id >= 0)
    {
        len = ll_len(pArrayListEmployee);

        for (i = 0;i < len;i++)
        {
            employee = ll_get(pArrayListEmployee,i);
            employee_getId(employee,&auxId);
            if (id==auxId)
            {
                ret = i;
                break;
            }
        }
    }
    else
    {
        printf("\nLa lista esta vacia");
    }
    return ret;
}

int controller_comparisonString(void *this,void *that)
{
    int ret = -1;
    int comparison = strcmp(((Employee*)this)->nombre,((Employee*)that)->nombre);
    if (comparison < 0)
    {
        ret = 1;
    }
    else if (comparison > 0)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}
