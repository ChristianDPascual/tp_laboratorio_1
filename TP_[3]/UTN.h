#ifndef UTN_H_
#define UTN_H_
/**
 * @fn int ordenarEmpleados(LinkedList*)
 * @brief Ordena los empleados segun el id que poseen llamando a la funcion ll_sort
 *
 * @param reciben el puntero a LinkedList;
 * @return retorna -1 si salio mal y 0 si salio bien la operacion
 */
int ordenarEmpleados(LinkedList*);

/**
 * @fn int agregarDatosNuevoEmpleado(LinkedList*)
 * @brief perminte ingresar y controlar los datos del empleado creado
 *
 * @param reciben el puntero a LinkedList;
 * @return retorna -1 si salio mal y 0 si salio bien la operacion
 */
int agregarDatosNuevoEmpleado(LinkedList*);

/**
 * @fn int modificarEmpleado(LinkedList*)
 * @brief
 *
 * @param
 * @return
 */
int modificarEmpleado(LinkedList*);
int controlarOpciones(int ,int);
int compararID(LinkedList* , int*);
void mostrarEmpleados(LinkedList* ,int );
void mostrarUnEmpleados(Employee*);
int eliminarEmpleado(LinkedList*);
int acomodarID(LinkedList*,int ,int );
int guardarArchivoTXT(char*, LinkedList*);
int guardarArchivoBIN(char*, LinkedList*);
#endif /* UTN_H_ */
