#include "Calculadora.h"

int validarNumero(char texto[])
{
	int largo;
	int i;
	int contador;
	int control;
	int retorno;

	largo=strlen(texto);

	for(i=0;i<largo;i++)
	{
		contador=isdigit(texto[i]);
		if(contador==FALSE && texto[0]!='-')
		{
			control=FALSE;
			break;
		}
	}

	if(control>=TRUE)
	{
		retorno=TRUE;
	}
	else
	{
		retorno=FALSE;
	}

	return retorno;
}

float suma(float num1,float num2)
{
	float resultado;

	resultado=num1+num2;

return resultado;
}

float resta(float num1,float num2)
{
	float resultado;

	resultado=num1-num2;

return resultado;
}

float multiplicacion(float num1,float num2)
{
	float resultado;

	resultado=num1*num2;

return resultado;
}

float division(float num1,float num2)
{
	float resultado;

	resultado=num1/num2;


return resultado;
}

int factorizar(int numero)
{
	 int i;
	 int resultado;

	 resultado=1;

	 for(i=1;i<=numero;i++)
	 {
       resultado=resultado*i;
	 }

return resultado;
}
