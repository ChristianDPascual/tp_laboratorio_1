
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define TEXT_SIZE 51
typedef struct{
	int id;
	char name[TEXT_SIZE];
	char last_Name[TEXT_SIZE];
	float salary;
	int sector;
	int IsEmpty;
}Employee;

/**
 * @fn int sortEmployees(Employee[], int, int)
 * @brief Ordena los empleados segun la necesidad del usuario y tambien muestra
 * si lo desea el usuario promedio de salario y personal
 *
 * @param Employee struct
 * @param cantidad de empleados
 * @param opcion elegida
 * @return retorna TRUE(0) si todo salio bien y FALSE(-1) si ocurrio un error
 */
int sortEmployees(Employee[],int,int);
/**
 * @fn int findEmployeeByID(Employee[], int, int)
 * @brief compara la ID ingresada con las que se encuentran cargadas
 *
 * @param Employee struct
 * @param cantidad de empleados
 * @param la id que se busca
 * @return retorna TRUE(0) si todo salio bien y FALSE(-1) si ocurrio un error
 */
int findEmployeeByID(Employee[], int,int);

/**
 * @fn int removeEmployee(Employee[], int, int)
 * @brief Elimina un empleado del sistema
 *
 * @param Employee struct
 * @param cantidad de empleados
 * @param la id que se busca
 * @return retorna TRUE(0) si todo salio bien y FALSE(-1) si ocurrio un error
 */
int removeEmployee(Employee[], int,int);
/**
 * @fn int printEmployees(Employee[], int)
 * @brief busca entre el listado de empleados el empleado que se busca eliminar
 *         y lo elimina
 * @param Employee struct
 * @param cantidad de empleados
 * @return  retorna TRUE(0) si todo salio bien y FALSE(-1) si ocurrio un error
 */
int printEmployees(Employee[], int);
/**
 * @fn int changeEmployees(Employee[], int)
 * @brief Permite cambiar los datos nombre-apellido-sector y sueldo de un empleado
 *
 * @param Employee struct
 * @param cantidad de empleados
 * @return  retorna TRUE(0) si todo salio bien y FALSE(-1) si ocurrio un error
 */
int changeEmployees(Employee[], int);
/**
 * @fn int eliminateEmployees(Employee[], int)
 * @brief pregunta la id que se desea eliminar y comprueba que sea una id valida
 * para depsues poder eliminar al empleado
 *
 * @param Employee struct
 * @param cantidad de empleados
 * @return  retorna TRUE(0) si todo salio bien y FALSE(-1) si ocurrio un error
 */
int eliminateEmployees(Employee[], int);

/**
 * @fn int initEmployees(Employee[], int)
 * @brief Para indicar que todas las posiciones del array se encuentran vacias,
 * pone la bandera IsEmpty en TRUE en todas las posiciones del array
 *
 * @param Employee* IsEmpty Direccion por puntero de IsEmpty
 * @param int Largo del array
 * @return int retora 0 si salio bien y -1 si hubo un inconveniente
 */
int initEmployees(Employee[], int);

/**
 * @fn Employee charge_Employee(Employee[], int)
 * @brief permite ingesar los datos de un nuevo empleado
 *
 * @param struct con los datos que se necesitan cargar de un empleado
 * @param el tamaño del array
 * @return int retora 0 si salio bien y -1 si hubo un inconveniente
 */
int charge_Employee(Employee[], int);
/**
 * @fn int create_ID()
 * @brief crea una ID nueva distina a las demas
 *
 * @return retorna una ID valida
 */
int create_ID(Employee[]);

/**
 * @fn int check_Name(char[])
 * @brief Examina que sea un nombre valido
 *
 * @param recibe el nombre ingresado
 * @return devuelve 1 si es correcto y 2 si esta mal
 */
int check_Name(char []);


#endif /* ARRAYEMPLOYEES_H_ */
