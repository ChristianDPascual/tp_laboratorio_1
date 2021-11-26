
#ifndef UTN_H_
#define UTN_H_

/**
 * @fn int mostrarUnEmpleado(Employee[], int, int)
 * @brief muestra un empleado solo
 *
 * @param struct employee
 * @param la cantidad de empleados
 * @param la id del empleado que se desea mostrar
 * @return int retora 0 si salio bien y -1 si hubo un inconveniente
 */
int mostrarUnEmpleado(Employee[],int,int);

/**
 * @fn int generadorID(Employee[], int)
 * @brief genera una nueva ID
 *
 * @param struct employee
 * @param la cantidad de empleados
 * @return int retora 0 si salio bien y -1 si hubo un inconveniente
 */
int generadorID(Employee[] ,int);

/**
 * @fn int validarNombres(char[])
 * @brief valida los nombres
 *
 * @param recibe el nombre a validar
 * @return devuelve 0 si salio bien y -1 si salio mal
 */
int validarNombres(char[]);

/**
 * @fn int validarMonto(char[])
 * @brief valida el numero  ingresado
 * @param el char es el numero
 * @return devuelve 0 si salio bien y -1 si salio mal
 */
int validarMontoFloat(char[]);

#endif /* UTN_H_ */
