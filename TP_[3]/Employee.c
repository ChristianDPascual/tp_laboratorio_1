#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
	Employee* pNuevoEmpleado;

	pNuevoEmpleado=(Employee*)malloc(sizeof(Employee));

	return pNuevoEmpleado;
	}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmpleado;

	pEmpleado->id=atoi(idStr);
	strcpy(pEmpleado->nombre,nombreStr);
	pEmpleado->horasTrabajadas=atoi(horasTrabajadasStr);
	pEmpleado->sueldo=atoi(sueldoStr);

    return pEmpleado;

}

int employee_setId(Employee* this,int id)
{
	int ok;

	ok=-1;

	if(this!=NULL && id>0)
	{
		this->id=id;
		ok=0;
	}

	return ok;


}
int employee_getId(Employee* this,int* id)
{
	int valorID;

	valorID=-1;


	if(this!=NULL)
	{
		*id=this->id;
		valorID=0;
		//printf("ID: %d\n",*id);
	}
	return valorID;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int ok;

	ok=-1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		ok=0;
	}

	return ok;

}

int employee_getNombre(Employee* this,char* nombre)
{
	int ok=-1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
	}
		ok=0;

	return ok;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int ok=-1;

	if(this!=NULL && horasTrabajadas>=0)
	{
		this->horasTrabajadas=horasTrabajadas;
		ok=0;
	}
	return ok;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int ok=-1;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		ok=0;

	}
	return ok;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int ok=-1;

	if(this!=NULL && sueldo>=0)
	{
		this->sueldo=sueldo;
		ok=0;
	}
	return ok;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int ok=-1;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		ok=0;

	}
	return ok;
}


int employee_CompareByName(void* e1, void* e2)//compara el nombre de dos empleados strcmp como son void tengo q parsearlos
{
	int comp;
	comp=-1;
	Employee* emp1;
	Employee* emp2;

	emp1=(Employee*)e1;
	emp2=(Employee*)e2;


	if(e1!=NULL && e2!=NULL)
	{
	   comp=strcmp(emp1->nombre,emp2->nombre);
	}

	return comp;
	}


int employee_CompareByID(void* e1,void* e2)
{
		int comp;
		Employee* emp1;
		Employee* emp2;

		comp=9999;//ERROR devuelve 1 si es mayor emp1, -1 si es mayor emp2 y cero si son iguales
		emp1=(Employee*)e1;
		emp2=(Employee*)e2;


		if(e1!=NULL && e2!=NULL)
		{
		   if(emp1->id>emp2->id)
		   {
			   comp=1;
		   }
		   else
		   {
			   if(emp1->id<emp2->id)
			   {
				   comp=-1;
			   }
			   else
			   {
				   comp=0;
			   }
		   }
		}
		return comp;
	}

int employee_CompareByHORAS(void* e1,void* e2)
{
		int comp;
		Employee* emp1;
		Employee* emp2;

		comp=9999;//ERROR devuelve 1 si es mayor emp1, -1 si es mayor emp2 y cero si son iguales
		emp1=(Employee*)e1;
		emp2=(Employee*)e2;


		if(e1!=NULL && e2!=NULL)
		{
		   if(emp1->horasTrabajadas>emp2->horasTrabajadas)
		   {
			   comp=1;
		   }
		   else
		   {
			   if(emp1->horasTrabajadas<emp2->horasTrabajadas)
			   {
				   comp=-1;
			   }
			   else
			   {
				   comp=0;
			   }
		   }
		}
		return comp;
	}

int employee_CompareBySueldo(void* e1,void* e2)
{
		int comp;
		Employee* emp1;
		Employee* emp2;

		comp=9999;//ERROR devuelve 1 si es mayor emp1, -1 si es mayor emp2 y cero si son iguales
		emp1=(Employee*)e1;
		emp2=(Employee*)e2;


		if(e1!=NULL && e2!=NULL)
		{
		   if(emp1->sueldo>emp2->sueldo)
		   {
			   comp=1;
		   }
		   else
		   {
			   if(emp1->sueldo<emp2->sueldo)
			   {
				   comp=-1;
			   }
			   else
			   {
				   comp=0;
			   }
		   }
		}
		return comp;
	}
