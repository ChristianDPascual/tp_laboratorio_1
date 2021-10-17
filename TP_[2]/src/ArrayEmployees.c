#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "UTN.h"
#define CARGADO 1
#define TRUE 0
#define FALSE -1
#define TEXT_SIZE 51
#define TAM 1000

int initEmployees(Employee List[] , int length)
{
	int i;
	int result=FALSE;

	for(i=0;i<length;i++)
	{
		if(List[i].IsEmpty!=FALSE)
		{
		   List[i].IsEmpty=TRUE;
		}
		 result=TRUE;
	}

    return result;
}


int charge_Employee(Employee lista[], int tamanio)
{

	int ok=FALSE;
	int sector;
	int controlSalario;
	int opcionControl=0;
	int i;
	char nombre[TEXT_SIZE];
	char apellido[TEXT_SIZE];
	char salario[TEXT_SIZE];
	char sectores[TEXT_SIZE];
	char cOpcion;
	char respuesta[3];
	float sueldo=0;

	     if(tamanio>0)
		 {
	    	 do{
		     printf("Ingrese el nombre del empleado:\n");
		     fflush(stdin);
		     scanf("%[^\n]",nombre);
	    	 }while(validarNombres(nombre)!=TRUE);

	    	 do{
	    	 printf("Ingrese el apellido del empleado:\n");
	    	 fflush(stdin);
	    	 scanf("%[^\n]",apellido);
	    	 }while(validarNombres(apellido)!=TRUE);

	    	 printf("Ingrese el salario del empleado\n");
	    	 fflush(stdin);
	    	 scanf("%[^\n]",salario);
	    	 controlSalario=validarMontoFloat(salario);
	    	 sueldo=atof(salario);
	    	 while(controlSalario!=TRUE)
	    	 {
	    		 controlSalario=0;
				 printf("ERROR, ingrese el salario del empleado\n");
	  			 fflush(stdin);
	  			 scanf("%[^\n]",salario);
	  			 controlSalario=validarMontoFloat(salario);
	  			 sueldo=atof(salario);
	    	 }

	    	 printf("Elija el sector\n");
	    	 printf("1-Maestranza\n");
	    	 printf("2-Mantenimiento\n");
	    	 printf("3-Cobranzas\n");
	    	 printf("4-Ventas\n");
	    	 printf("5-RRHH\n");
	    	 printf("6-Gerencia\n");
	    	 fflush(stdin);
	    	 scanf("%c",&cOpcion);
	    	 opcionControl=atoi(&cOpcion);

	   		 while(opcionControl<1 || opcionControl>6)
	   		 {

	  			printf("ERROR, seleccione un sector valido (1-6)\n");
	    		fflush(stdin);
	    		scanf("%c",&cOpcion);
	    		opcionControl=atoi(&cOpcion);
	    	}

	   		switch(opcionControl)
	   		{
	   		   case 1:
	   			   sector=1;
	   			   strcpy(sectores,"Maestranza");
	   			   break;
	   		   case 2:
	   			   sector=2;
	   			   strcpy(sectores,"Mantenimiento");
	   			   break;
	   		   case 3:
	   			   sector=3;
	   			   strcpy(sectores,"Cobranzas");
			       break;
	   		   case 4:
	   			   sector=4;
	   			   strcpy(sectores,"Ventas");
	   			   break;
	   		   case 5:
	   			   sector=5;
	   			   strcpy(sectores,"RRHH");
	   			   break;
	   		   case 6:
	   			   sector=6;
	   			   strcpy(sectores,"Gerencia");
	   			   break;
	   		}


		 printf("esta de acuerdo con los datos del empleado?(si/no): \n");
		 printf("nombre %s, apellido %s, salario %.2f, sector %d %s\n",nombre,apellido,sueldo,sector,sectores);
		 fflush(stdin);
		 scanf("%[^\n]",respuesta);
		 while(stricmp(respuesta,"no") && stricmp(respuesta,"si"))
		 {
		 	printf("ERROR, desea cargar el contribuyente(si/no)?\n");
		 	fflush(stdin);
		 	scanf("%[^\n]",respuesta);
		 }
		 if(stricmp(respuesta,"si")==0)
		 {
			 ok=TRUE;
			 for(i=0;i<tamanio;i++)
			 {
			 	if(lista[i].IsEmpty==0)
			 	{
			 		lista[i].id=generadorID(lista,tamanio);
			 	    strcpy(lista[i].name,nombre);
			 	    strcpy(lista[i].last_Name,apellido);
			 	    lista[i].salary=sueldo;
			 	    lista[i].sector=sector;
			 	    lista[i].IsEmpty=CARGADO;
			 	    printf("\nEl ID generado es el siguente %d\n\n",lista[i].id);
			 	    break;
			 	 }
			 }
		}
	}

	return ok;
}


int printEmployees(Employee lista[], int tamanio)
{
	int ok=FALSE;
	int i;
	int contador=0;

	for(i=0;i<tamanio;i++)
	{
		if(lista[i].IsEmpty==CARGADO)
		{
			contador++;
			printf("ID %d, nombre %s, apellido %s, sueldo %.2f, sector %d\n",lista[i].id,
					                                                       lista[i].name,
																		   lista[i].last_Name,
																		   lista[i].salary,
																		   lista[i].sector);
		}
	}

	if(contador>0)
	{
		ok=TRUE;
	}

	return ok;
	}
int findEmployeeByID(Employee lista[], int tamanio, int direccion)
{
	int ok=FALSE;
	int i;

	for(i=0;i<tamanio;i++)
	{
		if(lista[i].id==direccion && lista[i].IsEmpty==CARGADO)
		{
			ok=TRUE;
			break;
		}
	}

	return ok;
	}

int changeEmployees(Employee lista[], int tamanio)
{
	int ok=FALSE;
	int ID;
	int sector;
	int controlSalario;
	int i;
	int controlOpcion;
	int valor=0;
	int ayuda=0;
	char nombre[TEXT_SIZE];
	char apellido[TEXT_SIZE];
	char salario[TEXT_SIZE];
	char cID[5];
	char respuesta[3];
	float sueldo=0;
	char Opcion;


	do{
	  printf("Ingrese la ID del empleado que desea modificar\n");
	  fflush(stdin);
	  scanf("%[^\n]",cID);
	  ID=atoi(cID);
	  while((ID<1000 || ID>9999))
	  {
		printf("Error, la ID ingresada no es valida(1000-9999)\n");
		fflush(stdin);
		scanf("%[^\n]",cID);
		ID=atoi(cID);
	  }
	  if((findEmployeeByID(lista, tamanio,ID)==TRUE))
	  {
		  valor=1;
	  }
	  else
	  {
		  printf("El empleado con esa ID, no existe\n");
		  ayuda++;
		  if(ayuda==5)
		  {
			  printf("Desea ver todos los empleados cargados?(si/no): \n");
			  fflush(stdin);
			  scanf("%[^\n]",respuesta);
			  while(stricmp(respuesta,"no") && stricmp(respuesta,"si"))
			  {
			    printf("ERROR, Desea ver todos los empleados cargados(si/no)?\n");
			 	fflush(stdin);
			  	scanf("%[^\n]",respuesta);
			  }
			  if(stricmp(respuesta,"si")==0)
			  {
				  if(printEmployees(lista, tamanio)==TRUE)
				  {
					  ayuda=0;
				  }
				  else
				  {
					  printf("No hay emplados cargados\n");
					  return ok;
				  }
			  }
			  else
			  {
				  return ok;
			  }

		  }
	  }
	}while(valor!=1);
	if(mostrarUnEmpleado(lista, tamanio,ID)==TRUE)
	{
		 printf("Es el empleado que desea modificar?(si/no): \n");
		 fflush(stdin);
		 scanf("%[^\n]",respuesta);
		 while(stricmp(respuesta,"no") && stricmp(respuesta,"si"))
		 {
			 printf("ERROR, Es el empleado que desea modificar?(si/no):\n");
		 	 fflush(stdin);
		  	 scanf("%[^\n]",respuesta);
		 }
		 if(stricmp(respuesta,"si")==0)
		 {
		   do
		   {
			 printf("Elija la opcion que desea modificar\n");
			 printf("1-Nombre\n");
			 printf("2-Apellido\n");
	    	 printf("3-Salario\n");
	    	 printf("4-Sector\n");
	    	 printf("5-Finalizar Cambios\n");
	    	 fflush(stdin);
	    	 scanf("%c",&Opcion);
	    	 controlOpcion=atoi(&Opcion);
	    	 printf("ocpion %d\n",controlOpcion);
			 while(controlOpcion<1 || controlOpcion>5)
	   		 {
				 printf("ERROR, seleccione un sector valido (1-5)\n");
		   		 fflush(stdin);
		   		 scanf("%c",&Opcion);
		   		 controlOpcion=atoi(&Opcion);
		   	}
			 switch(controlOpcion)
			 {
			     case 1:
			    	 do{
			    		 printf("Ingrese el nombre del empleado:\n");
			    	     fflush(stdin);
					     scanf("%[^\n]",nombre);
			    	 }while(validarNombres(nombre)!=TRUE);
			    	 for(i=0;i<tamanio;i++)
			    	 {
			    	 	if(lista[i].id==ID)
			    	 	{
			    	 	    strcpy(lista[i].name,nombre);
			    	 		ok=TRUE;
			    	 		break;
			    	 	}
			    	 }
			    	 break;
			     case 2:
			    	 do{
	    	 	    	 printf("Ingrese el apellido del empleado:\n");
		 	 	    	 fflush(stdin);
			   	    	 scanf("%[^\n]",apellido);
			    	 }while(validarNombres(apellido)!=TRUE);
			    	 for(i=0;i<tamanio;i++)
			    	 {
			    	 	if(lista[i].id==ID)
			    	 	{
			    	 	   strcpy(lista[i].last_Name,apellido);
			    	 	   ok=TRUE;
			    	 	   break;
			    	 	}
			    	 }
			    	 break;
			     case 3:
			    	 printf("Ingrese el salario del empleado\n");
			    	 fflush(stdin);
			    	 scanf("%[^\n]",salario);
			    	 controlSalario=validarMontoFloat(salario);
			    	 sueldo=atof(salario);
			    	 while(controlSalario!=TRUE)
			    	 {
			    		 controlSalario=0;
			   			 printf("ERROR, ingrese el salario del empleado\n");
	 	 	  			 fflush(stdin);
	 	 	  			 scanf("%[^\n]",salario);
			  			 controlSalario=validarMontoFloat(salario);
	   	 	  			 sueldo=atof(salario);
			    	 }
			    	 for(i=0;i<tamanio;i++)
			    	 {
			    	 		if(lista[i].id==ID)
			    	 		{
			    	 	   		lista[i].salary=sueldo;
			    	 		    ok=TRUE;
			    	 			break;
			    	 		}
			    	 }
			    	 break;
			     case 4:
			    	 controlOpcion=0;
			    	 printf("Elija el sector\n");
			    	 printf("1-Maestranza\n");
			    	 printf("2-Mantenimiento\n");
			    	 printf("3-Cobranzas\n");
			    	 printf("4-Ventas\n");
			    	 printf("5-RRHH\n");
			    	 printf("6-Gerencia\n");
			    	 fflush(stdin);
			    	 scanf("%c",&Opcion);
			    	 controlOpcion=atoi(&Opcion);

			   		 while(controlOpcion<1 || controlOpcion>6)
			   		 {
			   			 printf("ERROR, seleccione un sector valido (1-6)\n");
			       		 fflush(stdin);
			       		 scanf("%c",&Opcion);
			       		controlOpcion=atoi(&Opcion);
			       	}
			   		switch(controlOpcion)
			  	   	{
			   		   case 1:
			   			   sector=1;
	  		   			   break;
	  		   		   case 2:
			   			   sector=2;
    		   			   break;
			  		   case 3:
	  		   			   sector=3;
			    	       break;
			   		   case 4:
			   			   sector=4;
	 		   			   break;
	 		   		   case 5:
			   			   sector=5;
	  		   			   break;
			   		   case 6:
	 		   			   sector=6;
			   			   break;
	 		   		}
			   	 for(i=0;i<tamanio;i++)
				 {
					  if(lista[i].id==ID)
			   		  {
	   			  	 	    lista[i].sector=sector;
			   		 	    ok=TRUE;
					 	    break;
			   		  }
			   	  }
			   	     break;
			 }

		   }while(controlOpcion!=5);
		 }
		 else
		 {
			 return ok;
		 }
	}

	return ok;
	}
int eliminateEmployees(Employee lista[], int tamanio)
{
	int ok=FALSE;
	int ID;
	int valor=0;
	int ayuda=0;
	char cID[5];
	char respuesta[3];

	do{
		  printf("Ingrese la ID del empleado que desea modificar\n");
		  fflush(stdin);
		  scanf("%[^\n]",cID);
		  ID=atoi(cID);
		  while((ID<1000 || ID>9999))
		  {
			printf("Error, la ID ingresada no es valida(1000-9999)\n");
			fflush(stdin);
			scanf("%[^\n]",cID);
			ID=atoi(cID);
		  }
		  if((findEmployeeByID(lista, tamanio,ID)==TRUE))
		  {
			  valor=1;
		  }
		  else
		  {
			  printf("El empleado con esa ID, no existe\n");
			  ayuda++;
			  if(ayuda==5)
			  {
				  printf("Desea ver todos los empleados cargados?(si/no): \n");
				  fflush(stdin);
				  scanf("%[^\n]",respuesta);
				  while(stricmp(respuesta,"no") && stricmp(respuesta,"si"))
				  {
				    printf("ERROR, Desea ver todos los empleados cargados(si/no)?\n");
				 	fflush(stdin);
				  	scanf("%[^\n]",respuesta);
				  }
				  if(stricmp(respuesta,"si")==0)
				  {
					  if(printEmployees(lista, tamanio)==TRUE)
					  {
						  ayuda=0;
					  }
					  else
					  {
						  printf("No hay emplados cargados\n");
						  return ok;
					  }
				  }
				  else
				  {
					  return ok;
				  }

			  }
		  }
		}while(valor!=1);
		if(mostrarUnEmpleado(lista, tamanio,ID)==TRUE)
		{
			 printf("Es el empleado que desea eliminar?(si/no): \n");
			 fflush(stdin);
			 scanf("%[^\n]",respuesta);
			 while(stricmp(respuesta,"no") && stricmp(respuesta,"si"))
			 {
				 printf("ERROR, Es el empleado que desea eliminar?(si/no):\n");
			 	 fflush(stdin);
			  	 scanf("%[^\n]",respuesta);
			 }
			 if(stricmp(respuesta,"si")==0)
			 {
				 if(removeEmployee(lista, tamanio,ID)==0)
				 {
					 ok=TRUE;
				 }
			 }
			 else
			 {
				  return ok;
			 }

		}

	return ok;
	}
int removeEmployee(Employee lista[], int tam,int index)
{
	int ok=FALSE;
	int i;

	for(i=0;i<tam;i++)
	{
		if(lista[i].id==index && lista[i].IsEmpty==CARGADO)
		{
			lista[i].IsEmpty=TRUE;
			ok=TRUE;
			break;
		}
	}

    return ok;
}

int sortEmployees(Employee lista[],int tam,int orden)
{
	int ok=FALSE;
	Employee aux;
	int i;
	int j;
	float acumuladorSalario=0;
	float PromedioSalario=0;
	int contadorPersonas=0;
	int personalMayorPromedioSUeldo=0;

	if(tam>0)
	{
	switch(orden)
	{
	case 1:
		for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				if(stricmp(lista[i].last_Name,lista[j].last_Name)>0 && (lista[i].IsEmpty==CARGADO && lista[j].IsEmpty==CARGADO))
				{
					aux=lista[i];
					lista[i]=lista[j];
					lista[j]=aux;
				}
			}
		}
		if(printEmployees(lista, tam)==TRUE)
		{
			ok=TRUE;
		}
		else
		{
			printf("\nNo se pudo mostrar la lista\n\n");
			return ok;
		}
		break;
	case 2:
		for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				if(stricmp(lista[i].last_Name,lista[j].last_Name)<0 && (lista[i].IsEmpty==CARGADO && lista[j].IsEmpty==CARGADO))
				{
					aux=lista[i];
					lista[i]=lista[j];
					lista[j]=aux;
				}
			}
		}
		if(printEmployees(lista, tam)==TRUE)
		{
			ok=TRUE;
		}
		else
		{
			printf("\nNo se pudo mostrar la lista\n\n");
			return ok;
		}
		break;
	case 3:
		for(i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					if(lista[i].sector>lista[j].sector && (lista[i].IsEmpty==CARGADO && lista[j].IsEmpty==CARGADO))
					{
						aux=lista[i];
						lista[i]=lista[j];
						lista[j]=aux;
					}
				}
			}
		if(printEmployees(lista, tam)==TRUE)
		{
			ok=TRUE;
		}
		else
		{
			printf("\nNo se pudo mostrar la lista\n\n");
			return ok;
		}
		break;
	case 4:
		for(i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					if(lista[i].sector<lista[j].sector && (lista[i].IsEmpty==CARGADO && lista[j].IsEmpty==CARGADO))
					{
						aux=lista[i];
						lista[i]=lista[j];
						lista[j]=aux;
					}
				}
			}
		if(printEmployees(lista, tam)==TRUE)
		{
			ok=TRUE;
		}
		else
		{
			printf("\nNo se pudo mostrar la lista\n\n");
			return ok;
		}
		break;
	case 5:
		for(i=0;i<tam;i++)
		{
			if(lista[i].IsEmpty==CARGADO)
			{
				acumuladorSalario=acumuladorSalario+lista[i].salary;
				contadorPersonas++;
			}
		}
		PromedioSalario=acumuladorSalario/contadorPersonas;
		for(i=0;i<tam;i++)
		{
			if(lista[i].IsEmpty==CARGADO && lista[i].salary>PromedioSalario)
			{
				personalMayorPromedioSUeldo++;
			}
		}
		ok=TRUE;
		printf("El total de los salarios es de %.2f\n",acumuladorSalario);
		printf("El promedio del salario es %.2f\n",PromedioSalario);
		printf("EL total del personal que supera el promedio es de %d\n",personalMayorPromedioSUeldo);
		break;
	}
	}

	return ok;
	}
