#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN.h"

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
	setbuf(stdout,NULL);
	int option=0;
	int control=0;
	int largo;

	LinkedList* listaEmpleados = ll_newLinkedList();//constructor, crea una lista de empleado tipo linkedist

    do{
    	printf("MENU:\n");
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
   		printf("3. Alta de empleado\n");
   		printf("4. Modificar datos de empleado\n");
   		printf("5. Baja de empleado\n");
   		printf("6. Listar empleados\n");
   		printf("7. Ordenar empleados\n");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
   		printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
   		printf("10. Salir.\n");
   		scanf("%d", &option);

   		while(!(option>=1 && option<=10))
   		{
    		printf("ERROR, ingrese una opcion valida (1-10)");
   			scanf("%d", &option);
   		}


   		if(controlarOpciones(option,control)==1)
   		{
   		 control++;
         switch(option)
         {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==0)
                {

                		printf("El archivo se cargo exitosamente\n");

                }
                else
                {
                	printf("el archivo no se cargo\n");
                }
                break;
            case 2:
            	if(controller_loadFromBinary("data.csv",listaEmpleados)==0)
            	{
            		printf("El archivo se cargo exitosamente\n");
                }
            	else
                {
            		printf("el archivo no se cargo\n");
                }
            	break;
            case 3:
            	if(controller_addEmployee(listaEmpleados)==0)
            	{
            		if(agregarDatosNuevoEmpleado(listaEmpleados)==0)
            		{
            			printf("Se agrego exitosamente el empleado\n");
            		}
            	}
               	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	if(controller_removeEmployee(listaEmpleados)!=1)
            	{
            		printf("El id ingresado no existe\n");
            	}
            	break;
            case 6:
            	if((controller_ListEmployee(listaEmpleados)==0) && (largo=ll_len(listaEmpleados))>0)
            	{
            	    mostrarEmpleados(listaEmpleados,largo);
            	}
               	break;
            case 7:
            	if((controller_sortEmployee(listaEmpleados)==0) && (ordenarEmpleados(listaEmpleados)==0))
            	{
            		printf("El ordenamiento fue exitoso\n");
            	}
            	else
            	{
            		printf("Ocurrio un error con el ordenamiento\n");
            	}
            	break;
            case 8:
            	if(controller_saveAsText("data.csv", listaEmpleados)==0)
            	{
            		printf("El archivo se guardo exitosamente\n");
            	}
                 break;
            case 9:
            	if(controller_saveAsBinary("data.csv", listaEmpleados)==0)
            	{
            		printf("El archivo se guardo exitosamente\n");
            	}
                 break;
            case 10:
            	printf("El programa ha finalizado\n");
            	break;
         }
   	    }

    }while(option != 10);

    return 0;
}
