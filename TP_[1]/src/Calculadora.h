#ifndef CALCULADORA_H_
#define CALCULADORA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 20
#define FALSE 0
#define TRUE 1

/**
 * @fn int validarNumero(char[])
 * @brief Valida que el numero ingresado sea valido
 *
 * @param recibe una cadena de texto
 * @return retorna TRUE en caso de ser un numero valido o FALSE en caso de estar errado
 */
int validarNumero(char[]);

/**
 * @fn float suma(float, float)
 * @brief Realiza la suma de dos numeros
 *
 * @param primer numero
 * @param  segundo numero
 * @return retorna el resultado de la suma
 */
float suma(float, float);

/**
 * @fn float resta(float, float)
 * @brief Realiza la resta entre dos numeros
 *
 * @param primer numero
 * @param  segundo numero
 * @return retorna el resultado de la resta
 */
float resta(float, float);

/**
 * @fn float multiplicacion(float, float)
 * @brief Realiza la multiplicacion entre dos numeros
 *
 * @param primer numero
 * @param  segundo numero
 * @return retorna el resultado de la multiplicacion
 */
float multiplicacion(float, float);

/**
 * @fn float division(float, float)
 * @brief Realiza la division entre dos numeros
 *
 * @param primer numero
 * @param  segundo numero
 * @return retorna el resultado de la division
 */
float division(float, float);

/**
 * @fn int factorizar(int)
 * @brief Se encarga de sacar el factorial de un numero
 *
 * @param el numero a factorizar
 * @return retorna el resultado de la factorizacion
 */
int factorizar(int);

#endif /* CALCULADORA_H_ */
