#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "UTN.h"
#define TAM 1000
#define CARGADO 1
#define TRUE 0
#define FALSE -1

int validarMontoFloat(char cantidad[])
{
	int ok=FALSE;
	int i;
	int comas=0;
	int valor=0;
	int auxiliar;
	float numero;

	numero=atof(cantidad);

	for(i=0;i<strlen(cantidad);i++)
	{
	   auxiliar=isdigit(cantidad[i]);
	   if(auxiliar==0)
	   {
		   valor=-1;
		   if(cantidad[i]=='.' && i>1 && comas==0)
		   {
			valor=0;
			comas++;
		   }
		   else
		   {
			   break;
		   }

	   }
	}

	if(numero>0 && valor==0)
	{
		ok=TRUE;
	}
	return ok;
}
int validarMontoInt(char cantidad[])
{
	int ok=FALSE;
	int i;
	int valor=0;
	int auxiliar;
	int numero;

	numero=atoi(cantidad);

	for(i=0;i<strlen(cantidad);i++)
	{
	   auxiliar=isdigit(cantidad[i]);
	   if(auxiliar==0)
	   {
		   valor=-1;
	   }
	}
	if(numero>0 && valor==0)
	{
		ok=TRUE;
	}

	return ok;
}

int validarNombres(char texto[])
{
	int ok=FALSE;
	int valor=1;
	int auxiliar;
	int i;

  if(strlen(texto)>0){
	for(i=0;i<strlen(texto);i++)
	{
		auxiliar=isalpha(texto[i]);
		if(auxiliar==0)
		{
			valor=-1;
		 }
	}

   while(valor<0)
   {
	   valor=1;
	   printf("ERROR, ingreselo de vuelta:\n");
	   fflush(stdin);
	   scanf("%[^\n]",texto);
	   for(i=0;i<strlen(texto);i++)
	   {
		   auxiliar=isalpha(texto[i]);
		   if(auxiliar==0)
		   {
 	   		 valor=-1;
		   }		     	   	 }
  	  }

	if(valor==1)
	{
		ok=TRUE;
	}
   }

	return ok;
}

int generadorID(Employee listado[],int tam)
{
	int id=FALSE;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(listado[i].IsEmpty==0)
			{
				id=i+1000;
				break;
			}
		}
	}

	return id;
}

int mostrarUnEmpleado(Employee listado[],int tam,int index)
{
	int ok=FALSE;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(listado[i].id==index && listado[i].IsEmpty==CARGADO)
			{
				printf("ID %d, nombre %s, apellido %s, sueldo %.2f, sector %d\n",listado[i].id,
									                                             listado[i].name,
																				 listado[i].last_Name,
																			     listado[i].salary,
																				 listado[i].sector);
				ok=TRUE;
				break;
			}
		}
	}



	return ok;
	}
