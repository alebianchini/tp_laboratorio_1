#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRE_LEN 128
typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * \brief Crea un nuevo elemento del tipo empleado en memoria dinámica
 * \return Retorna el espacio de memoria que le fue asignado
 *
 */
Employee* employee_new();
/**
 * \brief Crea un nuevo elemento del tipo empleado en memoria dinámica, y además llena sus campos con los datos correspondientes (recibiendolos como strings)
 * \param idStr ID que será asignado a dicho campo del empleado
 * \param nombreStr Nombre que será asignado a dicho campo del empleado
 * \param horasTrabajadasStr HorasTrabajadas que será asignado a dicho campo del empleado
 * \param sueldo Sueldo que será asignado a dicho campo del empleado
 * \return Retorna un puntero al elemento creado o un puntero a NULL
 *
 */
Employee* employee_newParametrosStr(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
/**
 * \brief Crea un nuevo elemento del tipo empleado en memoria dinámica, y además llena sus campos con los datos correspondientes
 * \param id ID que será asignado a dicho campo del empleado
 * \param nombre Nombre que será asignado a dicho campo del empleado
 * \param horasTrabajadas HorasTrabajadas que será asignado a dicho campo del empleado
 * \param sueldo Sueldo que será asignado a dicho campo del empleado
 * \return Retorna un puntero al elemento creado o un puntero a NULL
 *
 */
Employee* employee_newParametros(int id, char* nombre,int horasTrabajadas,int sueldo);
/**
 * \brief Elimina un elemento del tipo empleado de la memoria dinámica
 *
 */
void employee_delete();

/**
 * \brief Setea el campo id de un elemento del tipo empleado a traves de su puntero
 * \param this Puntero al Empleado en cuestion
 * \param id Valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_setId(Employee* this,int id);
/**
 * \brief Obtiene el valor del campo id de un elemento del tipo empleado a traves de su puntero
 * \param this Puntero al Empleado en cuestion
 * \param id Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_getId(Employee* this,int* id);
/**
 * \brief Setea el campo id de un elemento del tipo empleado a traves de su puntero (seteandolo como un string)
 * \param this Puntero al Empleado en cuestion
 * \param id Puntero al valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_setIdStr(Employee* this,char* id);
/**
 * \brief Obtiene el valor del campo id de un elemento del tipo empleado a traves de su puntero (obteniendolo como un string)
 * \param this Puntero al Empleado en cuestion
 * \param id Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_getIdStr(Employee* this,char* id);

/**
 * \brief Setea el campo nombre de un elemento del tipo empleado a traves de su puntero
 * \param this Puntero al Empleado en cuestion
 * \param nombre Puntero a la variable que posee el valor que sera cargado
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/**
 * \brief Obtiene el valor del campo nombre de un elemento del tipo empleado a traves de su puntero
 * \param this Puntero al Empleado en cuestion
 * \param nombre Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * \brief Setea el campo horasTrabajadas de un elemento del tipo empleado a traves de su puntero
 * \param this Puntero al Empleado en cuestion
 * \param horasTrabajadas Valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/**
 * \brief Obtiene el valor del campo horasTrabajadas de un elemento del tipo empleado a traves de su puntero
 * \param this Puntero al Empleado en cuestion
 * \param horasTrabajadas Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/**
 * \brief Setea el campo horasTrabajadas de un elemento del tipo empleado a traves de su puntero (seteandolo como un string)
 * \param this Puntero al Empleado en cuestion
 * \param horasTrabajadas Puntero al valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas);
/**
 * \brief Obtiene el valor del campo horasTrabajadas de un elemento del tipo empleado a traves de su puntero (obteniendolo como un string)
 * \param this Puntero al Empleado en cuestion
 * \param horasTrabajadas Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_getHorasTrabajadasStr(Employee* this,char* horasTrabajadas);

/**
 * \brief Setea el campo sueldo de un elemento del tipo empleado a traves de su puntero
 * \param this Puntero al Empleado en cuestion
 * \param sueldo Valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/**
 * \brief Setea el campo sueldo de un elemento del tipo empleado a traves de su puntero (seteandolo como un string)
 * \param this Puntero al Empleado en cuestion
 * \param sueldo Puntero al valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);
/**
 * \brief Setea el campo sueldo de un elemento del tipo empleado a traves de su puntero (seteandolo como un string)
 * \param this Puntero al Empleado en cuestion
 * \param sueldo Puntero al valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_setSueldoStr(Employee* this,char* sueldo);
/**
 * \brief Obtiene el valor del campo sueldo de un elemento del tipo empleado a traves de su puntero (obteniendolo como un string)
 * \param this Puntero al Empleado en cuestion
 * \param sueldo Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int employee_getSueldoStr(Employee* this,char* sueldo);

/**
 * \brief Imprime un elemento de la lista
 * \param this Puntero al elemento
 *
 */
void employee_printDetail(Employee* this);
/**
 * \brief Modifica campos dentro de un elemento de la lista
 * \param this Puntero al elemento
 *
 */
int employee_editDetail(Employee* this);
/**
 * \brief Criterio de ordenamiento por Nombre
 * \param thisA puntero primer elemento
 * \param thisB puntero al segundo elemento
 *
 */
int employee_swapByName(void* thisA, void* thisB);
/**
 * \brief Criterio de ordenamiento por Salario
 * \param thisA puntero primer elemento
 * \param thisB puntero al segundo elemento
 *
 */
int employee_swapBySalary(void* thisA, void* thisB);
/**
 * \brief Criterio de ordenamiento por ID
 * \param thisA puntero primer elemento
 * \param thisB puntero al segundo elemento
 *
 */
int employee_swapById(void* thisA, void* thisB);
/**
 * \brief Consulta al usuario por consola si confirma la baja de un empleado
 * \param this Puntero al elemento en cuestion
 *
 */
int employee_confirmDelete(Employee* this);

#endif // employee_H_INCLUDED
