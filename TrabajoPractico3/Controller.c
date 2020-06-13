#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* fpArchivo;
	char bufferId[4096];
	char bufferNombre[4096];
	char bufferHorasTrabajadas[4096];
	char bufferSueldo[4096];
	int flag=0;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		fpArchivo = fopen(path,"r");
		if(fpArchivo != NULL)
		{
			retorno=0;
			do
			{
				if(fscanf(fpArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo) == 4)
				{
					if(flag == 0)
					{
						flag = 1;
						continue;
					}
					printf("\n%s - %s - %s - %s",bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
					ll_add(pArrayListEmployee, employee_newParametrosStr(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo));
				}
			}while(!feof(fpArchivo));
			fclose(fpArchivo);
			int size=ll_len(pArrayListEmployee);
			printf("\nSize: %d",size);
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int bufferId=ll_len(pArrayListEmployee)+1;
	char bufferNombre[NOMBRE_LEN];
	int bufferHorasTrabajadas;
	int bufferSueldo;
	Employee* this;
	if( !utn_getNombre(bufferNombre,NOMBRE_LEN,"\nIngrese el nombre del nuevo empleado","\nNombre invalido",3) &&
		!utn_getNumero(&bufferHorasTrabajadas,"\nIngrese las horas trabajadas","\nNúmero invalido",1,999,3) &&
		!utn_getNumero(&bufferSueldo,"\nIngrese el sueldo del empleado","\nNúmero invalido",1,500000,3))
	{
		this = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
		if(this != NULL)
		{
			ll_add(pArrayListEmployee,this);
			printf("Carga exitosa");
			retorno=0;
		}
	}
	int size=ll_len(pArrayListEmployee);
	printf("\nSize: %d",size);
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int bufferId;
	Employee* this = employee_new();
	utn_getNumero(&bufferId,"Indique el ID del Empleado que desea modificar", "Opcion invalida\n", 1, ll_len(pArrayListEmployee), 3);
	this->id=1000;
	this->horasTrabajadas=60;
	strcpy(this->nombre,"Saleem");
	this->sueldo=20000;
	employee_printDetail(this);
	printf("\nindex: %d",ll_indexOf(pArrayListEmployee,this));

	//((Employee*)ll_get(pArrayListEmployee, ll_indexOf(pArrayListEmployee,this)));
	employee_editDetail(((Employee*)ll_get(pArrayListEmployee, ll_indexOf(pArrayListEmployee,this))));
	//ll_set(LinkedList* this, int index,void* pElement)
	return 0;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	for(i = 0; i<ll_len(pArrayListEmployee); i++)
	{
		employee_printDetail(((Employee*)ll_get(pArrayListEmployee, i)));
	}
	return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

