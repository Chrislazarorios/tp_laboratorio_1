#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char nombreArchivoTexto[128];
    char nombreArchivoBinario[128];
    do{
        switch(option)
        {
            case 1: //
                utn_getTexto("\nIngrese nombre de archivo a abrir (data.csv):","\nError ",1,20,1,nombreArchivoTexto);
                controller_loadFromText(nombreArchivoTexto,listaEmpleados);
                break;

            case 2: //
                utn_getTexto("\nIngrese nombre de archivo a abrir (dataBinario.csv):","\nError ",1,20,1,nombreArchivoBinario);
                controller_loadFromBinary(nombreArchivoBinario,listaEmpleados);
                break;

            case 3:
                controller_addEmployee(listaEmpleados);
                break;

            case 4:
                controller_editEmployee(listaEmpleados);
                break;

            case 5:
                controller_removeEmployee(listaEmpleados);
                break;

            case 6:
                controller_ListEmployee(listaEmpleados);
                break;

            case 7:
                controller_sortEmployee(listaEmpleados);
                break;

            case 8:
                utn_getTexto("\nIngrese nombre de archivo a guardar: ","\nError ",1,20,1,nombreArchivoTexto);
                controller_saveAsText(nombreArchivoTexto,listaEmpleados);
                break;

            case 9:
                utn_getTexto("\nIngrese nombre de archivo a guardar: ","\nError ",1,20,1,nombreArchivoBinario);
                controller_saveAsBinary(nombreArchivoBinario,listaEmpleados);
                break;

            case 10://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }while(option != 10);
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
