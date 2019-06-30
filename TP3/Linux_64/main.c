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
    char ArchivoText[128];
    char ArchivoBinary[128];
    do{
        utn_getUnsignedInt("\n\n1) Cargar datos en modo texto\n2) Cargar datos en modo binario\n3) Alta empleado\n4) Modificar empleado\n5) Baja empleado\n6) Listar empleado\n7) Ordenar empleado\n8) Guardar datos en modo texto\n9) Guardar datos en modo binario\n10) Salir\n","\nError",1,sizeof(int),1,11,1,&option);

        switch(option)
        {
            case 1:
                utn_getTexto("\nIngrese nombre de archivo a abrir en modo texto:","\nError ",1,30,3,ArchivoText);
                controller_loadFromText(ArchivoText,listaEmpleados);
                break;

            case 2:
                utn_getTexto("\nIngrese nombre de archivo a abrir en modo binario:","\nError ",1,30,3,ArchivoBinary);
                controller_loadFromBinary(ArchivoBinary,listaEmpleados);
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
                utn_getTexto("\nIngrese nombre de archivo a guardar en modo texto: ","\nError ",1,30,3,ArchivoText);
                controller_saveAsText(ArchivoText,listaEmpleados);
                break;

            case 9:
                utn_getTexto("\nIngrese nombre de archivo a guardar en modo binario: ","\nError ",1,30,3,ArchivoBinary);
                controller_saveAsBinary(ArchivoBinary,listaEmpleados);
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
