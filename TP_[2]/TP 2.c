/*
 ============================================================================
TRABAJO PRACTICO 2 Christian Pascual 1B
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define LONG 3
#define TRUE 0
#define FALSE 1
#define TEXT_SIZE 51

int main(void){

	Employee oneEmployee[LONG];
	int estay_IsEmpty;
	int i;
	int option;

	estay_IsEmpty=initEmployees(oneEmployee, LONG);
	showMessage(estay_IsEmpty);
	option=showMenu();
	chosen_Option(oneEmployee, LONG, option);


	for(i=0;i<LONG;i++)
	{
		printf("estado %d \n",oneEmployee[i].IsEmpty);
	}

	printf("estado %d",estay_IsEmpty);




	return 0;
}
