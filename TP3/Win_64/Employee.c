#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

static int idGen = 0;

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

int employee_generaId(void)
{
    return idGen++;
}

 void employee_setIdInicial(int value)
{
    idGen = value;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* emp = employee_new();
    if(emp != NULL)
    {
        employee_setIdStr(emp, idStr);
        employee_setNombre(emp, nombreStr);
        employee_setHorasTrabajadasStr( emp, horasTrabajadasStr);
        employee_setSueldoStr( emp, sueldoStr);
    }


    return emp;
}

int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)//faltan
    {
//        if(validId)
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_setIdStr(Employee* this,char* id)
{
    int retorno = -1;
    int idAux;
    if(this != NULL) //faltan
    {
//        if(validId)
            idAux = atoi(id);
            this->id = idAux;
            retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int ret = -1;

    if(this != NULL)
    {
        *id = this->id;
        ret = 0;
    }

    return ret;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
    int retorno = -1;
    int horasAux;
    if(this != NULL)
    {
        horasAux = atoi(horasTrabajadas);
        this->horasTrabajadas = horasAux;
        retorno = 0;
    }
    return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ret = -1;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        ret = 0;
    }

    return ret;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoStr(Employee* this,char* sueldo)
{
    int retorno = -1;
    int sueldoAux;
    if(this != NULL)
    {
        sueldoAux = atoi(sueldo);
        this->sueldo = sueldoAux;
        retorno = 0;
    }
    return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret = -1;

    if(this != NULL)
    {
        *sueldo = this->horasTrabajadas;
        ret = 0;
    }

    return ret;
}



