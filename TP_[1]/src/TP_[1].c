#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Calculadora.h"
#define TAM 20
#define FALSE 0
#define TRUE 1


int main(void){

	int control;
	int contadorA=0;
	int contadorB=0;
    int contadorC=0;
	char opcion[4];
	float numero1;
	float numero2;
	float resultados;
	int numeroA;
	int numeroB;
	int NumeroDeOpcion;
	char respuesta[TAM];

	setbuf(stdout,NULL);

	do{

	printf("\nElija la opcion:\n");
	printf("1-Ingresar primer operando\n");
	printf("2-Ingresar segundo operando\n");
	printf("3-Calcular todas las operaciones\n");
	printf("4-Informar resultados\n");
	printf("5-Salir\n\n");
	fflush(stdin);
	scanf("%[^\n]",opcion);
	NumeroDeOpcion=atoi(opcion);
	while((validarNumero(opcion)==FALSE) || (NumeroDeOpcion<1 || NumeroDeOpcion>5))
	{
		printf("Ingrese una opcion valida(1-5):\n");
		fflush(stdin);
		scanf("%[^\n]",opcion);
		NumeroDeOpcion=atoi(opcion);
	}

	switch(NumeroDeOpcion)
	{
	case 1:
		if(contadorC==FALSE)
		{
		do{
		 printf("Ingrese el primer numero:\n");
		 fflush(stdin);
		 scanf("%[^\n]",respuesta);
		}while((control=validarNumero(respuesta))!=TRUE);
        if(control>=TRUE)
        {
        	numero1=atof(respuesta);
        	contadorA=TRUE;
        	printf("El numero ingresado es %.2f\n",numero1);
        }
		}
		else
		{
			printf("Los numeros ya fueron ingresados\n");
		}
		break;
	case 2:
		if(contadorC==FALSE)
		{
			do{
			 printf("Ingrese el segundo numero:\n");
			 fflush(stdin);
			 scanf("%[^\n]",respuesta);
			 }while((control=validarNumero(respuesta))!=TRUE);
			 if(control>=TRUE)
	         {
				numero2=atof(respuesta);
			   	contadorB=TRUE;
	         	printf("El numero ingresado es %.2f\n",numero2);
	        }
	     }
		else
		{

				printf("Los numeros ya fueron ingresados\n");
		}

		break;
	case 3:
		if(contadorA==TRUE && contadorB==TRUE && contadorC==FALSE)
		{
			contadorC=TRUE;
			printf("Calculando la suma de %.2f y %.2f\n",numero1,numero2);
			printf("Calculando la resta de %.2f y %.2f\n",numero1,numero2);
			printf("Calculando la multiplicacion de %.2f y %.2f\n",numero1,numero2);
			printf("Calculando la division de %.2f y %.2f\n",numero1,numero2);
			printf("Calculando el factorial de %.2f y %.2f\n",numero1,numero2);

		}
		else
		{
			if(contadorC==TRUE)
			{
			 printf("Los calculos ya se realizaron\n");
			}
			else
			{
				printf("Ingrese primero los numeros\n");
			}
		}

		break;
	case 4:
		if(contadorC==1 && contadorA==1 && contadorC==1)
		{
			numeroA=(int)numero1;
			numeroB=(int)numero2;
			resultados=suma(numero1,numero2);
			printf("La suma de %.2f y %.2f es %.2f\n",numero1,numero2,resultados);
			resultados=resta(numero1,numero2);
			printf("La resta de %.2f y %.2f es %.2f\n",numero1,numero2,resultados);
		    resultados=multiplicacion(numero1,numero2);
			printf("La multiplicacion de %.2f y %.2f es %.2f\n",numero1,numero2,resultados);

		    	if(numero2!=0)
				{
		    	resultados=division(numero1,numero2);
				printf("La division de %.2f y %.2f es %.2f\n",numero1,numero2,resultados);
				}
		    	else
				{
		    		printf("No se puede dividir por cero\n");
				}

		    	if(numero1>0 && (numero1-numeroA)==0)
				{
		    		resultados=factorizar(numeroA);
		    		printf("El factorial de %.2f es %.0f\n",numero1,resultados);
				}
				else
				{
					printf("El numero %.2f no se puede factorizar\n",numero1);
				}

		    	if(numero2>0 && (numero2-numeroB)==0)
				{
		    		resultados=factorizar(numeroB);
					printf("El factorial de %.2f es %.0f\n",numero2,resultados);
				}
				else
				{
					printf("El numero %.2f no se puede factorizar\n",numero2);
				}

			contadorA=FALSE;
			contadorB=FALSE;
			contadorC=FALSE;

		}
		else
		{
			if(contadorC==FALSE && (contadorA==FALSE || contadorB==FALSE))
			{
				printf("Ingrese los operandos primero\n");
			}
			else
			{
				if(contadorC==FALSE && contadorA==TRUE && contadorB==TRUE)
				{
					printf("Primero ejecute las operaciones\n");
				}
			}
		}

		break;
	case 5:
		printf("Calculadora finalizada\n");
		break;
	}
	}while(NumeroDeOpcion!=5);


	return EXIT_SUCCESS;
}
