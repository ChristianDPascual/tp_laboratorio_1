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
	    Employee* pEmpleado;
		char ID[100];
		char nombre[100];
		char Sueldo[100];
		char Horas[100];
		int retorno;
		retorno=-1;

		if(pFile!=NULL && pArrayListEmployee!=NULL)
		{
		  retorno=0;
		  fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",ID,nombre,Horas,Sueldo);
		  while(!feof(pFile))
		  {
			   fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",ID,nombre,Horas,Sueldo);
			   pEmpleado=employee_new();
		       pEmpleado=employee_newParametros(ID,nombre,Horas,Sueldo);
		       ll_add(pArrayListEmployee,pEmpleado);
		  }
		}
        return retorno;
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
	 Employee* pEmpleado;
			char ID[100];
			char nombre[100];
			char Sueldo[100];
			char Horas[100];
			int retorno;
			retorno=-1;

			if(pFile!=NULL && pArrayListEmployee!=NULL)
			{
			  retorno=0;
			  fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",ID,nombre,Horas,Sueldo);
			  while(!feof(pFile))
			  {
				   fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",ID,nombre,Horas,Sueldo);
				   pEmpleado=employee_new();
			       pEmpleado=employee_newParametros(ID,nombre,Horas,Sueldo);
			       ll_add(pArrayListEmployee,pEmpleado);
			  }
			}
	        return retorno;
}
