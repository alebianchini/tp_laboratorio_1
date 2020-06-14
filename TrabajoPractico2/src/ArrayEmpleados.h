/*
 * ArrayEmpleados.h
 *
 *  Created on: 12 may. 2020
 *      Author: Alejo
 */

#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_

typedef struct{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
}Empleado;

/**
 * \brief Inicializa el array
 * \param array Array de empleados a ser inicializado
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int initEmpleados(Empleado* array, int limite);
/**
 * \brief Imprime los datos de un empleado
 * \param pElemento Puntero al elemento que se busca imprimir
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int imprimirEmpleado(Empleado* pElemento);
/**
 * \brief Imprime el array de empleados
 * \param array Array de empleados a ser mostrado
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int imprimirEmpleados(Empleado* array,int limite);
/**
 * \brief Da de alta un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al empleado
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int altaEmpleado(Empleado* array,int limite,int indice,int* id);
/**
 * \brief Buscar la primer posicion vacia del array
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el indice de la posicion vacia o -1 (ERROR)
 *
 */
int getIndiceVacio(Empleado* array,int limite);
/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int modificarEmpleado(Empleado* array,int limite,int indice);
/**
 * \brief Busca un ID en un array y devuelve la posicion en que se encuentra
 * \param array cliente Array de cliente
 * \param limite tamaño del array
 * \param valorBuscado ID a ser actualizada
 * \return Return (-1) si no encuentra el valor buscado o Error - (i) si encuentra el valor buscado.
 *
 */
int buscarId(Empleado array[],int limite,int valorBuscado);
/**
 * \brief Da de baja un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser dada de baja
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int bajaEmpleado(Empleado* array,int limite,int indice);
/**
 * \brief Ordenar el array de empleados por apellido o sector
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int ordenarPorApellidoSector(Empleado* array,int limite);
/**
 * \brief Calcula la suma total de los salarios, el promedio y cuantos salarios hay por encima del promedio
 * \param array Array de empleados a ser recorrido
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int informeSalarios(Empleado* array, int limite);
/**
 * \brief Menú completo del programa de empleados
 * \param ArrayEmpleados Array a ser recorrido
 * \param limite Limite del array de empleados
 * \param idEmpleados Identificador a ser asignado para cada empleado
 * \param opcion Valor que ingresa el usuario para moverse por el menu
 * \param auxiliarId variable utilizada para buscar un ID específico
 * \param auxiliarIndice variable utilizada para ubicarse en un elemento especifico del array
 *
 */
void menuEmpleados(Empleado* arrayEmpleados, int limite, int* idEmpleados, int* opcion, int* auxiliarId, int* auxiliarIndice);
/**
 * \brief Corrobora que haya al menos UN indice ocupado en el array
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna 0 si hay algun indice ocupado en el array, en caso contrario -1.
 *
 */
int getIndiceLleno(Empleado* array,int limite);

#endif /* ARRAYEMPLEADOS_H_ */
