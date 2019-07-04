#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    Employee *pEmpleado;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                  bufferNombre,
                                                  bufferHorasTrabajadas,
                                                  bufferSueldo);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                      bufferNombre,
                                                      bufferHorasTrabajadas,
                                                      bufferSueldo);

            pEmpleado = employee_newParametros( bufferId,
                                                bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);



            if(pEmpleado != NULL)
            {
                // agrego el empleado a la linkedlist
                ll_add(pArrayListEmployee,pEmpleado);
                ret = 0;
            }

        }
    }

    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
        int ret = -1;

    Employee* pEmpl;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do{
            //generar espacio en memoria
            pEmpl = employee_new();

            // guardarlo en el archivo
            if(fread(pEmpl, sizeof(Employee), 1, pFile) == 1)
            {
                // agregarlo a la linkedlist
                ll_add(pArrayListEmployee, pEmpl);
            }
            else
            {
                employee_delete(pEmpl);
            }

        }while(!feof(pFile));
    }


    return ret;
}
