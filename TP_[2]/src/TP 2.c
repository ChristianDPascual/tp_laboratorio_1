/*
 * Christian Pascual 1B
 */
#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "UTN.h"
#define TAM 1000
#define TRUE 0
#define FALSE -1

int main(void){
	setbuf(stdout,NULL);
	int opcion;
	char cOpcion;
	int control=0;
	Employee listaEmployee[TAM];
	int opcionOrden;
	char tipoOrden;

	if(initEmployees(listaEmployee,TAM)==TRUE)
	{
	 do
	 {
		printf("Ingrese la opcion que desea utilizar:\n");
		printf("1-ALTAS Empleados\n");
		printf("2-MODIFICAR empleados\n");
		printf("3-BAJA empleado por ID\n");
		printf("4-INFORMAR empleados\n");
		printf("5-FINALIZAR Programa\n");
		fflush(stdin);
		scanf("%c",&cOpcion);
		opcion=atoi(&cOpcion);

		while(opcion<1 || opcion>5)
		{
			printf("ERROR, ingrese una opcion valida (1-5)\n");
			fflush(stdin);
			scanf("%c",&cOpcion);

			opcion=atoi(&cOpcion);
		}
		if(opcion==1 || opcion==5)
		{
			control=1;
		}

		if(control==1)
		{
		  switch(opcion)
		  {
	     	case 1:
	     		if(charge_Employee(listaEmployee, TAM)==TRUE)
	     		{
	     			printf("\nSe cargo con exito el empleado\n\n");
	     		}
	     		else
	     		{
	     			printf("\nNo se realizo la operacion\n\n");
	     		}
	     		break;
	     	case 2:
	     		if(changeEmployees(listaEmployee, TAM)==TRUE)
	     		{
	     			printf("\nSe Modifico con exito el empleado\n\n");
	     		}
	     		else
	     		{
	     			printf("\nNo se realizo la operacion\n\n");
	     		}
	     		break;
	     	case 3:
	     		if(eliminateEmployees(listaEmployee, TAM)==TRUE)
	     		{
	     			 printf("\nSe elimino al empleado\n\n");
	     		}
	     		else
	     		{
	     			 printf("\nNo se realizo la operacion\n\n");
	     	    }
	     		break;
	     	case 4:
	     		     do
	     			 {
	     				printf("Ingrese la opcion que desea utilizar:\n");
	     				printf("1-Ordenar apellidos de la A-Z\n");
	     				printf("2-Ordenar apellidos de la Z-A\n");
	     				printf("3-Ordenar por sector menor a mayor ID\n");
	     				printf("4-Ordenar por sector mayor a menor\n");
	     				printf("5-Imprimir total y promedio sueldos, y cantidad de empleados que lo supera\n");
	     				printf("6-Volver al menu anterior\n");
	     				fflush(stdin);
	     				scanf("%c",&tipoOrden);
	     				opcionOrden=atoi(&tipoOrden);

	     				while(opcionOrden<1 ||opcionOrden>6)
	     				{
	     					printf("ERROR, ingrese una opcion valida (1-6)\n");
	     					fflush(stdin);
	     					scanf("%c",&tipoOrden);
	     					opcionOrden=atoi(&tipoOrden);
	     				}
	     				if(sortEmployees(listaEmployee, TAM,opcionOrden)==0)
	     				{
	     					printf("se imprimio con exito la informacion\n\n");
	     				}
	     			 }while(opcionOrden!=6);
	     		break;
		  }
	    }
		else
		{
			printf("No hay ningun dato cargardo, Primero ingreselos datos\n");
		}
	 }while(opcion!=5);
	}
	else
	{
		printf("ERROR, no se pudo inicializar el programa\n");
	}

	return EXIT_SUCCESS;
}
