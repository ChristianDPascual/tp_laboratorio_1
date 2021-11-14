#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN.h"
#define FALSO 0
#define VERDADERO 1
/*
int employee_getId(Employee* this,int* id);
int employee_getNombre(Employee* this,char* nombre);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_getSueldo(Employee* this,int* sueldo);

 */
int controlarOpciones(int opciones, int contador)
{
	int ok;

	ok=0;

	if((opciones==2) || (opciones==1)|| (contador>0) || (opciones==10))
	 {
		ok=1;
	 }
	else
	{
		    printf("Primero debe cargar los datos del empleado\n");
	}

	return ok;
}
void mostrarUnEmpleados(Employee* unEmpleado)
{
	int id;
	char nombre[128];
	int horas;
	int sueldo;

	if(unEmpleado!=NULL)
	{
		employee_getId(unEmpleado,&id);
		employee_getNombre(unEmpleado,nombre);
		employee_getHorasTrabajadas(unEmpleado,&horas);
		employee_getSueldo(unEmpleado,&sueldo);

		printf("ID: %d --- nombre: %s --- horas trabajadas: %d --- sueldo: %d\n",id,nombre,horas,sueldo);
	}


	}

void mostrarEmpleados(LinkedList* pListaEmpleados,int Tamanio)
{
	int i;
	int id;
	char nombre[128];
	int horas;
	int sueldo;

	Employee* pUnEmpleado;

	if(ll_isEmpty(pListaEmpleados)==0 && Tamanio>0)
	{
	  for(i=0;i<Tamanio;i++)
	  {
		pUnEmpleado=ll_get(pListaEmpleados,i);
		employee_getId(pUnEmpleado,&id);
		employee_getNombre(pUnEmpleado,nombre);
		employee_getHorasTrabajadas(pUnEmpleado,&horas);
		employee_getSueldo(pUnEmpleado,&sueldo);

		printf("ID: %d, nombre: %s, horas trabajadas: %d, sueldo: %d\n",id,nombre,horas,sueldo);
	  }
	}

}

int agregarDatosNuevoEmpleado(LinkedList* pArrayListEmployee)
{
	Employee* pNuevoEmpleado;
	int ok=-1;
    char id[128];
    int ubicacion;
	char nombre[128];
	char horas[128];
	char sueldo[128];
	int valor;
	int auxiliar=0;
	int i;

	printf("Ingrese el ID del empleado que desea crear:\n");
	fflush(stdin);
	scanf("%[^\n]", id);
	ubicacion=(atoi(id)-1);

	while((ubicacion<1) || (compararID(pArrayListEmployee,&ubicacion))!=-1)
	{
		printf("ERROR, el id ingresado no existe o no es valido(debe ser mayor a 1000)\n");
		printf("Ingrese el ID del empleado que desea crear:\n");
		fflush(stdin);
		scanf("%[^\n]", id);
		ubicacion=(atoi(id)-1);
	}

	printf("Ingrese el nombre del empleado\n");
	fflush(stdin);
	scanf("%[^\n]",nombre);

	for(i=0;i<strlen(nombre);i++)
	{
		valor=isalpha(nombre[i]);
		if(valor==0)
		{
			auxiliar=-1;

		}
	}

	while(auxiliar<0)
	{
		    auxiliar=0;
		    printf("ERROR, ingrese un nombre valido\n");
			fflush(stdin);
			scanf("%[^\n]",nombre);
			for(i=0;i<strlen(nombre);i++)
			{
				valor=isalpha(nombre[i]);
				if(valor==0)
				{
					auxiliar=-1;
				}
			}
	}

	printf("Ingrese las horas trabajadas:\n");
	fflush(stdin);
	scanf("%[^\n]", horas);
	auxiliar=atoi(horas);
	while(auxiliar<1)
	{
		printf("ERROR,ingrese el nuevo horario debe ser mayor a cero\n");
		fflush(stdin);
		scanf("%[^\n]",horas);
		auxiliar=atoi(horas);
	}


	printf("Ingrese el sueldo:\n");
	fflush(stdin);
	scanf("%[^\n]", sueldo);
	auxiliar=atoi(sueldo);
	while(auxiliar<1)
	{
		printf("ERROR,ingrese el nuevo horario debe ser mayor a cero\n");
		fflush(stdin);
		scanf("%[^\n]",sueldo);
		auxiliar=atoi(sueldo);
	}

	pNuevoEmpleado=employee_new();
	if((pNuevoEmpleado=employee_newParametros(id,nombre,horas,sueldo))!=NULL)
	{
		printf("%d--%s--%d--%d\n",pNuevoEmpleado->id,pNuevoEmpleado->nombre,pNuevoEmpleado->horasTrabajadas,pNuevoEmpleado->sueldo);
		ll_add(pArrayListEmployee, pNuevoEmpleado);
		ok=0;
	}
	return ok;
}

int compararID(LinkedList* pArrayListEmployee, int* indice)
{
	Employee* pBuscarEmpleado;
	int index=-1;
	int i;
	int largo;

	largo=ll_len(pArrayListEmployee);

	for(i=0;i<largo;i++)
	{
		pBuscarEmpleado=ll_get(pArrayListEmployee,i);
			if(pBuscarEmpleado->id==(*indice+1))
     		{
		    			index=1;
		    			break;
			}
	}

    return index;
}

int eliminarEmpleado(LinkedList* listaEmpleados)
{
	Employee* aux;
	int i;
	int largo;
	int ok=0;
	int ubicacion;
	char id[128];
	char respuesta[3];

	largo=ll_len(listaEmpleados);
	printf("ingrese el id\n");
	fflush(stdin);
	scanf("%[^\n]",id);
	ubicacion=(atoi(id));

	for(i=0;i<largo;i++)
	{
		aux=ll_get(listaEmpleados, i);
		if(aux->id==ubicacion)
		{
			printf("desea eliminar el empleado (si/no)\n");
			mostrarUnEmpleados(aux);
			fflush(stdin);
			scanf("%[^\n]",respuesta);
		    while(stricmp(respuesta,"no") && stricmp(respuesta,"si"))
			{
				printf("ERROR, desea continuar(si/no)?\n");
				fflush(stdin);
				scanf("%[^\n]",respuesta);
			}
			if(stricmp(respuesta,"si")==0)
			{
				ll_remove(listaEmpleados,i);
				ok=1;
			}
			else
			{
				printf("El empleado no se elimino\n");
				ok=1;
			}
			break;

		}

	}

	return ok;
}

int modificarEmpleado(LinkedList* listadoEmpleados)
{
	Employee* unEmpleado;
	int ok=-1;
	int ubicacion;
	int index=-1;
	int opcion;
	char id[128];
	char respuesta[3];
	char nombre[128];
	int i;
	int largo;
	int cambio;
	char nuevoNombre[128];
	char nuevoSueldo[128];
	char nuevoHorario[128];
	char nuevoID[128];
	int auxiliar;
	int valor;


	largo=ll_len(listadoEmpleados);
	printf("1 BUSCAR EL EMPLEADO POR ID\n");
	printf("2 BUSCAR EL EMPLEADO POR NOMBRE\n");
	scanf("%d",&opcion);
	switch(opcion)
	{
	case 1:
		printf("ingrese el id\n");
		fflush(stdin);
		scanf("%[^\n]",id);
		ubicacion=(atoi(id)-1);

		while(ubicacion<0)
		{
			printf("ERROR, el id ingresado no es valido(debe ser mayor o igual a 1)\n");
			printf("ingrese el id\n");
			fflush(stdin);
			scanf("%[^\n]",id);
			ubicacion=(atoi(id)-1);
		}

		for(i=0;i<largo;i++)
		{
			unEmpleado=ll_get(listadoEmpleados, i);
			if(unEmpleado->id==ubicacion+1)
			{
				ubicacion=i;
				index=1;
			}
		}
		if(index==1)
		{

			unEmpleado=ll_get(listadoEmpleados, ubicacion);
			mostrarUnEmpleados(unEmpleado);
			printf("desea continuar(si/no)?\n");
			fflush(stdin);
			scanf("%[^\n]",respuesta);
			while(stricmp(respuesta,"no") && stricmp(respuesta,"si"))
			{
				printf("ERROR, desea continuar(si/no)?\n");
				fflush(stdin);
				scanf("%[^\n]",respuesta);
			}
			if(stricmp(respuesta,"no")==0)
			{
				index=-1;
			}
		}
		else
		{
			printf("El empleado con esa ID no existe\n");
		}
		break;
	case 2:
		printf("Ingrese el nombre del empleado\n");
		fflush(stdin);
		scanf("%[^\n]",nombre);

		for(i=0;i<largo;i++)
		{
			unEmpleado=ll_get(listadoEmpleados, i);
			if((stricmp(unEmpleado->nombre,nombre))==0)
			{
				printf("este es el empleado?(si/no): \n");
				mostrarUnEmpleados(unEmpleado);
				fflush(stdin);
				scanf("%[^\n]",respuesta);
				while(stricmp(respuesta,"no") && stricmp(respuesta,"si"))
				{
						printf("ERROR, desea continuar(si/no)?\n");
						fflush(stdin);
						scanf("%[^\n]",respuesta);
				}
				if(stricmp(respuesta,"si")==0)
				{
					ubicacion=i;
					index=1;
					break;
				}
			}
		}
		if(index==-1)
		{
			printf("El empleado con ese nombre no existe\n");
		}
	    break;
	   }

		if(index==1)
		{
			do{
				  printf("Ingrese el numero de la opcion que desea utilizar\n");
				  printf("1-Cambiar ID\n");
				  printf("2-Cambiar nombre\n");
				  printf("3-Cambiar horas trabajdas\n");
				  printf("4-Cambiar sueldo\n");
				  printf("5-Volver al menu principal\n");
				  scanf("%d",&cambio);
				  while(cambio<1 ||cambio>5)
				  {
					  printf("ERROR, ingrese una opcion valida: ");
					  scanf("%d",&cambio);
				  }

				  switch(cambio)
				  {
				    case 1:
				    	printf("ingrese el nuevo id:\n");
				    	fflush(stdin);
				    	scanf("%[^\n]",nuevoID);
				    	auxiliar=atoi(nuevoID)-1;

				    	while(auxiliar<0)
				    	{
				    		printf("ERROR,ingrese el nuevo id (debe comenzar apartir del 1)\n");
					    	fflush(stdin);
					    	scanf("%[^\n]",nuevoID);
					    	auxiliar=atoi(nuevoID)-1;
				    	}

				    	if(compararID(listadoEmpleados,&auxiliar)!=-1)
				    	{
				    		if(acomodarID(listadoEmpleados,ubicacion,auxiliar)==1)
				    		{
				    			printf("el id se ha cambiado exitosamente \n");
				    		}
				    	}
				    	else
				    	{
				    		if(employee_setId(unEmpleado,auxiliar)==0)
				    		{
				    			printf("el id se ha cambiado exitosamente \n");
				    		}
				    	}

				    	break;
				    case 2:
				    	printf("Ingrese el nuevo nombre del empleado\n");
				    	fflush(stdin);
				    	scanf("%[^\n]",nuevoNombre);

				    	for(i=0;i<strlen(nuevoNombre);i++)
				    	{
				    		valor=isalpha(nuevoNombre[i]);
				    		if(valor==0)
				    		{
				    			auxiliar=-1;
				    		}
				    	}
				    	while(auxiliar<0)
				    	{
				    		auxiliar=0;
				    		printf("ERROR, ingrese un nombre valido\n");
				    		fflush(stdin);
				    		scanf("%[^\n]",nuevoNombre);
				    		for(i=0;i<strlen(nuevoNombre);i++)
				    		{
				    			valor=isalpha(nuevoNombre[i]);
				    			if(valor==0)
				    			{
				    				auxiliar=-1;
				    			}
				    		}
				    	}

				    	if(auxiliar!=-1 && employee_setNombre(unEmpleado,nuevoNombre)==0)
				    	{
				    		printf("el nombre se ha cambiado exitosamente \n");
				    	}
				    	break;
				    case 3:
				    	printf("Ingrese el nuevo horario:\n");
				    	fflush(stdin);
				    	scanf("%[^\n]", nuevoHorario);
				    	auxiliar=atoi(nuevoHorario);
				    	for(i=0;i<strlen(nuevoHorario);i++)
				    	{
				    		valor=isdigit(nuevoHorario[i]);
				    		if(valor!=1)
				    		{
				    			auxiliar=-1;
				    		}
				    	}
				    	while(auxiliar<0)
				    	{
				    		printf("ERROR,ingrese un horario valido o mayor a cero\n");
				    		fflush(stdin);
				    		scanf("%[^\n]",nuevoHorario);
				    		auxiliar=atoi(nuevoHorario);
				    		for(i=0;i<strlen(nuevoHorario);i++)
				    		{
				    			valor=isdigit(nuevoHorario[i]);
				    			if(valor!=1)
				    			{
				    				auxiliar=-1;
				    				}
				    			}
				    	}

				    	if(employee_setHorasTrabajadas(unEmpleado,auxiliar)==0)
				    	{
				    		printf("el horario se ha cambiado exitosamente \n");
				    	}
				    	break;
				    case 4:
				    	printf("Ingrese el nuevo sueldo:\n");
				    	fflush(stdin);
				    	scanf("%[^\n]", nuevoSueldo);
				    	auxiliar=atoi(nuevoSueldo);

				    	for(i=0;i<strlen(nuevoSueldo);i++)
				    	{
				    		valor=isdigit(nuevoSueldo[i]);
				    		if(valor!=1)
				    		{
				    			auxiliar=-1;
				    		}
				    	}
				    	while(auxiliar<0 && valor!=1 )
				    	{
				    		printf("ERROR,ingrese un sueldo valido o mayor a cero\n");
				    		fflush(stdin);
				    		scanf("%[^\n]", nuevoSueldo);
				    		auxiliar=atoi( nuevoSueldo);
				    		valor=isdigit(nuevoSueldo[i]);
				    		if(valor!=1)
				    		{
				    			auxiliar=-1;
				    		}
				    	}

				    	if(employee_setSueldo(unEmpleado,auxiliar)==0)
				    	{
				    		printf("el sueldo se ha cambiado exitosamente \n");
				    	}
				    	break;
				    case 5:
				    	break;
				  }
			}while((cambio<1 ||cambio>5) || (cambio!=5));
			ok=0;
		}

	return ok;
}


int acomodarID(LinkedList* listaID,int ID1,int ID2)
{
	int ok=-1;
	Employee* pEmpleado1;
	Employee* pEmpleado2;
	char respuesta[3];
	int i;
	int j;
	int largo;
	int bandera=0;

	largo=ll_len(listaID);
	pEmpleado1=ll_get(listaID, ID1);

	if(compararID(listaID,&ID2)!=-1)
	{
		pEmpleado2=ll_get(listaID, ID2-1);
		printf(">>>>>>>>>>>>ALERTA<<<<<<<<<<<<<\n");
		printf("Ese ID se encuentra siendo utilizado por otro empleado\n");
		mostrarUnEmpleados(pEmpleado2);
		printf("si lo mueve a esa posicion los demas ID a partir del seleccionado aumentaran o disminuiran una posicion\n");
		printf("desea moverlo de todos modos (si/no)?\n");
		fflush(stdin);
		scanf("%[^\n]",respuesta);
		while(stricmp(respuesta,"no") && stricmp(respuesta,"si"))
		{
			printf("ERROR, desea continuar(si/no)?\n");
			fflush(stdin);
			scanf("%[^\n]",respuesta);
		}
		if(stricmp(respuesta,"si")==0)
		{
			if(employee_setId(pEmpleado1,ID2)==0)
			{
		    if(ID1<ID2)
			{
				for(i=ID2;i<largo-1;i++)
				{
				    for(j=i+1;j<largo;j++)
				    {
				    	if(bandera==1)
				    	{
				    		pEmpleado1=ll_get(listaID, i);
				    		pEmpleado2=ll_get(listaID, j);
				    		if(pEmpleado1->id<=pEmpleado2->id)
				    		{
				    			pEmpleado1->id=i+2;
				    			pEmpleado2->id=j+2;
				    			break;
				    		}
				    	}
				    	else
				    	{
				    		ll_remove(listaID,ID1);
				    		pEmpleado1->id=j;
				    		pEmpleado2->id=j+1;
				    		ll_push(listaID, (ID2-1), pEmpleado1);
				    		bandera=1;
				    		ok=1;
				    		break;
				    	}
				    }

				}
			}
		    if(ID1>ID2 && ID1<largo)
		    {
		    	for(i=ID1;i>0;i--)
		    	{
		    		for(j=i-1;j>-1;j--)
		    		{
		    			if(bandera==1)
		    			{
		    				pEmpleado1=ll_get(listaID, i);
		    				pEmpleado2=ll_get(listaID, j);
		    				if(pEmpleado1->id>=pEmpleado2->id)
		    				{
		    					pEmpleado1->id=i+1;
		    					pEmpleado2->id=i;
		    					break;
		    				}
		    			}
		    			else
		    			{
		    				ll_remove(listaID,ID1);
		    				pEmpleado2=ll_get(listaID, j);
		    				pEmpleado1->id=ID2+1;
		    				pEmpleado2->id=i+1;
		    				ll_push(listaID, ID2, pEmpleado1);
		    				bandera=1;
		    				ok=1;
		    				break;
		    			}
		    		}
		    	}
		    }
			}

		}

	}

	return ok;
}

int ordenarEmpleados(LinkedList* ordenarLista)
{
	int ok=-1;
	int opcion;
	int contador=0;
	int largo;
	LinkedList* copiaLista;
	int(*pfuncion)(void*,void*);
	largo=ll_len(ordenarLista);

	do{
	  printf("ELIJA EL METODO DE ORDENAMIENTO QUE DESEA UTILIZAR\n");
	  printf("1- Alfabeticamente A-Z\n");
	  printf("2- Alfabeticamente Z-A\n");
	  printf("3- ID menor a mayor\n");
	  printf("4- ID mayor a menor\n");
	  printf("5- Horas trabajadas de menor a mayor\n");
	  printf("6- Horas trabajadas de mayor a menor\n");
	  printf("7- Sueldos de menor a mayor\n");
	  printf("8- Sueldos de mayor a menor\n");
	  printf("9- Volver al menu principal\n");
	  scanf("%d",& opcion);
	  while(opcion<1 || opcion>9)
	  {
		  printf("la opcion ingresada es invalidad, intente nuevamente\n");
		  scanf("%d",& opcion);
 	  }
	  if(opcion>0)
	  {
		  copiaLista=ll_clone(ordenarLista);
		  switch(opcion)
		  {
		  int cont;
		     case 1:
		    	 pfuncion=employee_CompareByName;
		    	 if((cont=ll_containsAll(ordenarLista,copiaLista))==1)
		    	 {

		    		if(ll_sort(copiaLista, pfuncion, 1)==0)
		    		{
		    			mostrarEmpleados(copiaLista,largo);
		    			ll_deleteLinkedList(copiaLista);
		    			ok=0;
		    			contador=1;
		    		}
		    	 }

		    	 break;
		     case 2:
		    	 pfuncion=employee_CompareByName;
		    	 if((cont=ll_containsAll(ordenarLista,copiaLista))==1)
		    	 {
		    		 if(ll_sort(copiaLista, pfuncion, 0)==0)
		    		 {
		    			 mostrarEmpleados(copiaLista,largo);
		    			 ll_deleteLinkedList(copiaLista);
		    			 ok=0;
		    			 contador=1;
		    		 }
		    	 }
		    	 break;
		     case 3:
		    	 pfuncion=employee_CompareByID;
		    	 if((cont=ll_containsAll(ordenarLista,copiaLista))==1)
		    	 	{
		    	 		if(ll_sort(copiaLista, pfuncion, 1)==0)
		    	 		{
		    	 			mostrarEmpleados(copiaLista,largo);
		    	 			ll_deleteLinkedList(copiaLista);
		    	 			ok=0;
		    	 			contador=1;
		    	 		}
		    	 	}
		    	 break;
		     case 4:
		    	 pfuncion=employee_CompareByID;
		    	 if((cont=ll_containsAll(ordenarLista,copiaLista))==1)
		    	 {
		    	 		if(ll_sort(copiaLista, pfuncion, 0)==0)
		    	 		{
		    	 			mostrarEmpleados(copiaLista,largo);
		    	 			ll_deleteLinkedList(copiaLista);
		    	 			ok=0;
		    	 			contador=1;

		    	 		}
		    	 }

		    	 break;
		     case 5:
		    	 pfuncion=employee_CompareByHORAS;
		    	 if((cont=ll_containsAll(ordenarLista,copiaLista))==1)
		    	 {
		    	 		if(ll_sort(copiaLista, pfuncion, 1)==0)
		    	 		{
		    	 			mostrarEmpleados(copiaLista,largo);
		    	 			ll_deleteLinkedList(copiaLista);
		    	 			ok=0;
		    	 			contador=1;
		    	 		}
		    	 }
             break;
		     case 6:
		    	 pfuncion=employee_CompareByHORAS;
		    	  if((cont=ll_containsAll(ordenarLista,copiaLista))==1)
		    	 {
		    		  if(ll_sort(copiaLista, pfuncion, 0)==0)
		    		  {
		    			  mostrarEmpleados(copiaLista,largo);
		    			  ll_deleteLinkedList(copiaLista);
		    			  ok=0;
		    			  contador=1;
		    		  }
		    	 }
		    	 break;
		     case 7:
		    	 pfuncion=employee_CompareBySueldo;
		    	 if((cont=ll_containsAll(ordenarLista,copiaLista))==1)
		    	 {
		    		 if(ll_sort(copiaLista, pfuncion, 1)==0)
		    		 {
		    			 mostrarEmpleados(copiaLista,largo);
		    			 ll_deleteLinkedList(copiaLista);
		    			 ok=0;
		    			 contador=1;
		    		 }
		    	 }
		    	 break;
		     case 8:
		    	 pfuncion=employee_CompareBySueldo;
		    	 if((cont=ll_containsAll(ordenarLista,copiaLista))==1)
		    	 {
		    		 if(ll_sort(copiaLista, pfuncion, 0)==0)
		    		 {
		    			 mostrarEmpleados(copiaLista,largo);
		    			 ll_deleteLinkedList(copiaLista);
		    			 ok=0;
		    			 contador=1;
		    		 }
		    	 }
		    	 break;
		  }
	  }
	}while(opcion!=9 && contador!=1);


	return ok;
}

int guardarArchivoTXT(char* Arch, LinkedList* listaEmpleados)
{
	int ok=-1;
	int largo;
	int i;
	Employee* aux;
	FILE* pArchivo;
	char id[3]="id";
	char nombre[7]="nombre";
	char horas[20]="horasTrabajadas";
	char sueldo[7]="sueldo";

	if(Arch!=NULL && listaEmpleados!=NULL)
	{
	pArchivo=fopen(Arch,"w");
	  ok=0;
	  largo=ll_len(listaEmpleados);
	  fprintf(pArchivo,"%s,%s,%s,%s\n",id, nombre, horas,sueldo);

	  for(i=0;i<largo;i++)
	  {
	     aux=ll_get(listaEmpleados,i);
	     fprintf(pArchivo,"%d,%s,%d,%d\n",aux->id, aux->nombre, aux->horasTrabajadas,aux->sueldo);
	     }
	   }

	 fclose(pArchivo);

	return ok;
}

int guardarArchivoBIN(char* Arch, LinkedList* listaEmpleados)
{
	int ok=-1;
	int largo;
	int i;
	Employee* aux;
	FILE* pArchivo;
	char id[3]="id";
	char nombre[7]="nombre";
	char horas[20]="horasTrabajadas";
	char sueldo[7]="sueldo";

	if(Arch!=NULL && listaEmpleados!=NULL)
	{
		 pArchivo=fopen(Arch,"wb");
		 ok=0;
		 largo=ll_len(listaEmpleados);
		 fprintf(pArchivo,"%s,%s,%s,%s\n",id, nombre, horas,sueldo);
		 for(i=0;i<largo;i++)
		 {

		       aux=ll_get(listaEmpleados,i);
		       fprintf(pArchivo,"%d,%s,%d,%d\n",aux->id, aux->nombre, aux->horasTrabajadas,aux->sueldo);

		  }

	 fclose(pArchivo);
	}

		return ok;
}
