#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "UTN.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pArchivo;

		if(pArrayListEmployee!=NULL && path!=NULL)
		{
			pArchivo=fopen(path,"r");

			if(parser_EmployeeFromText(pArchivo , pArrayListEmployee)==0)
			{
				retorno=0;
				fclose(pArchivo);
			}
		}

	    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pArchivo;

			if(pArrayListEmployee!=NULL && path!=NULL)
			{
				pArchivo=fopen(path,"rb");

				if(parser_EmployeeFromText(pArchivo , pArrayListEmployee)==0)
				{
					retorno=0;
					fclose(pArchivo);
				}
			}

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ok=-1;

	if(pArrayListEmployee!=NULL)
	{
		ok=0;
	}
    return ok;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ok;

	ok=0;
	if(pArrayListEmployee!=NULL)
	{
		if(modificarEmpleado(pArrayListEmployee)==0)
		{
			ok=1;
		}

	}
    return ok;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ok;

		ok=0;
		if(pArrayListEmployee!=NULL)
		{
			if(eliminarEmpleado(pArrayListEmployee)==1)
			{
				ok=1;
			}
		}
	    return ok;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ok=-1;

	if(pArrayListEmployee!=NULL)
	{
		ok=0;
	}

    return ok;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ok=-1;

	if(pArrayListEmployee!=NULL)
	{
		ok=0;
	}
    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ok=-1;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
    	if(guardarArchivoTXT(path,pArrayListEmployee)==0)
    	{

    		ok=0;
    	}
    }
    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ok=-1;

	    if(path!=NULL && pArrayListEmployee!=NULL)
	    {
	    	if(guardarArchivoBIN(path,pArrayListEmployee)==0)
	    	{
	    		ok=0;
	    	}
	    }
	    return ok;
}

