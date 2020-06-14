#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Obtiene el ID máximo de la lista
 * \param pArrayListEmployee puntero a la lista en cuestion
 * \return Retorna el id obtenido o -1 (ERROR)
 *
 */
int controller_getMaxId(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	LinkedList* listaAux = ll_newLinkedList();
	//listaAux = *pArrayListEmployee;
	for(i=0; i<ll_len(pArrayListEmployee);i++)
	{
		ll_add(listaAux, ll_get(pArrayListEmployee,i));
	}
	ll_sort(listaAux, employee_swapById, 1);
	Employee* this = ll_get(listaAux,ll_len(listaAux)-1);
	employee_getId(this, &retorno);
	return retorno;
}


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
					ll_add(pArrayListEmployee, employee_newParametrosStr(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo));
				}
			}while(!feof(fpArchivo));
			printf("\n****CARGA EXITOSA****\n");
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
	int retorno=-1;
	FILE* fpArchivo;
	char bufferId[4096];
	char bufferNombre[4096];
	char bufferHorasTrabajadas[4096];
	char bufferSueldo[4096];
	int flag=0;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		fpArchivo = fopen(path,"rb");
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
					ll_add(pArrayListEmployee, employee_newParametrosStr(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo));
				}
			}while(!feof(fpArchivo));
			printf("\n****CARGA EXITOSA****\n");
			fclose(fpArchivo);
		}
	}
	return retorno;
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
	int bufferId;
	char bufferNombre[NOMBRE_LEN];
	int bufferHorasTrabajadas;
	int bufferSueldo;
	Employee* this;
	if( !utn_getNombre(bufferNombre,NOMBRE_LEN,"\nIngrese el nombre del nuevo empleado: ","\nNombre invalido",3) &&
		!utn_getNumero(&bufferHorasTrabajadas,"\nIngrese las horas trabajadas: ","\nNumero invalido",1,999,3) &&
		!utn_getNumero(&bufferSueldo,"\nIngrese el sueldo del empleado: ","\nNumero invalido",1,500000,3))
	{
		bufferId = controller_getMaxId(pArrayListEmployee)+1;
		this = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
		if(this != NULL)
		{
			ll_add(pArrayListEmployee,this);
			printf("\n****Carga exitosa. ID asignado: %d ****", bufferId);
			retorno=0;
		}
	}
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
	if(!ll_isEmpty(pArrayListEmployee))
	{
		int auxId;
		int i;
		int bufferId;
		int auxIndice=-1;
		Employee* this;
		if(pArrayListEmployee != NULL)
		{
			if(!utn_getNumero(&auxId,"Indique el ID del Empleado que desea modificar: ", "Opcion invalida\n", 1, ll_len(pArrayListEmployee), 2))
			{
				for(i = 0; i<ll_len(pArrayListEmployee); i++)
				{
					this = ((Employee*)ll_get(pArrayListEmployee, i));
					if(!employee_getId(this, &bufferId) && auxId == bufferId)
					{
						auxIndice = ll_indexOf(pArrayListEmployee, this);
						break;
					}
				}
				if(auxIndice >= 0 && !employee_editDetail(this))
				{
					ll_set(pArrayListEmployee, auxIndice, this);
				}
			}
		}
	}
	else{
		printf("\n*****No hay empleados cargados a la lista*****\n");
	}
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
	if(!ll_isEmpty(pArrayListEmployee))
	{
		int auxId;
		int i;
		int bufferId;
		int auxIndice=-1;
		Employee* this;
		if(pArrayListEmployee != NULL)
		{
			if(!utn_getNumero(&auxId,"Indique el ID del Empleado que desea dar de baja: ", "ID INEXISTENTE\n", 1, ll_len(pArrayListEmployee), 2))
			{
				for(i = 0; i<ll_len(pArrayListEmployee); i++)
				{
					this = ((Employee*)ll_get(pArrayListEmployee, i));
					if(!employee_getId(this, &bufferId) && auxId == bufferId)
					{
						auxIndice = ll_indexOf(pArrayListEmployee, this);
						break;
					}
				}
				if(auxIndice >= 0 && !employee_confirmDelete(this))
				{
					ll_remove(pArrayListEmployee, auxIndice);
					employee_delete(this);
				}
				else{
					printf("\n****ID INEXISTENTE****\n");
				}
			}
		}
	}
	else{
		printf("\n*****No hay empleados cargados a la lista*****\n");
	}
	return 0;
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
	if(!ll_isEmpty(pArrayListEmployee))
	{
		int i;
		for(i = 0; i<ll_len(pArrayListEmployee); i++)
		{
			employee_printDetail(((Employee*)ll_get(pArrayListEmployee, i)));
		}
	}
	else{
		printf("\n*****No hay empleados cargados a la lista*****\n");
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
	if(!ll_isEmpty(pArrayListEmployee))
	{
		int opcion;
		if(pArrayListEmployee != NULL)
		{
			if(!utn_getNumero(&opcion, "\n1- Desea ordenar por Nombre de la A a la Z?"
									   "\n2- Desea ordenar por Nombre de la Z a la A?"
									   "\n3- Desea ordenar por Sueldo de menor a mayor?"
									   "\n4- Desea ordenar por Sueldo de mayor a menor?"
									   "\n5- Desea ordenar por ID de menor a mayor?"
									   "\n6- Desea ordenar por ID de mayor a menor?\n","\nOpcion invalida\n",1,6,2))
			{
				switch(opcion)
				{
				case 1:
					ll_sort(pArrayListEmployee, employee_swapByName, 1);
					break;
				case 2:
					ll_sort(pArrayListEmployee, employee_swapByName, 0);
					break;
				case 3:
					ll_sort(pArrayListEmployee, employee_swapBySalary, 1);
					break;
				case 4:
					ll_sort(pArrayListEmployee, employee_swapBySalary, 0);
					break;
				case 5:
					ll_sort(pArrayListEmployee, employee_swapById, 1);
					break;
				case 6:
					ll_sort(pArrayListEmployee, employee_swapById, 0);
					break;
				}
			}
		}
	}
	else{
		printf("\n*****No hay empleados cargados a la lista*****\n");
	}
	return 0;
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
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	char bufferId[12];
	char bufferNombre[NOMBRE_LEN];
	char bufferHorasTrabajadas[12];
	char bufferSueldo[12];
	Employee* this;
	if(pArrayListEmployee != NULL && path != NULL)
	{
		fpArchivo = fopen(path,"w");
		if(fpArchivo != NULL)
		{
			fputs( "id", fpArchivo);
			fputs( ",", fpArchivo);
			fputs( "nombre", fpArchivo);
			fputs( ",", fpArchivo);
			fputs( "horasTrabajadas", fpArchivo);
			fputs( ",", fpArchivo);
			fputs( "sueldo", fpArchivo);
			fputs( "\n", fpArchivo);
			retorno=0;
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				this = ((Employee*)ll_get(pArrayListEmployee, i));
				if( !employee_getIdStr(this,bufferId) &&
					!employee_getNombre(this,bufferNombre) &&
					!employee_getHorasTrabajadasStr(this,bufferHorasTrabajadas) &&
					!employee_getSueldoStr(this,bufferSueldo))
				{
					fputs( bufferId, fpArchivo);
					fputs( ",", fpArchivo);
					fputs( bufferNombre, fpArchivo);
					fputs( ",", fpArchivo);
					fputs( bufferHorasTrabajadas, fpArchivo);
					fputs( ",", fpArchivo);
					fputs( bufferSueldo, fpArchivo);
					fputs( "\n", fpArchivo);
					//fprintf(fpArchivo,"%d,%s,%d,%d\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
				}
			}
			fclose(fpArchivo);
			printf("\nGUARDADO OK");
		}
	}
	return retorno;
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
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	char bufferId[12];
	char bufferNombre[NOMBRE_LEN];
	char bufferHorasTrabajadas[12];
	char bufferSueldo[12];
	Employee* this;
	if(pArrayListEmployee != NULL && path != NULL)
	{
		fpArchivo = fopen(path,"wb");
		if(fpArchivo != NULL)
		{
			fputs( "id", fpArchivo);
			fputs( ",", fpArchivo);
			fputs( "nombre", fpArchivo);
			fputs( ",", fpArchivo);
			fputs( "horasTrabajadas", fpArchivo);
			fputs( ",", fpArchivo);
			fputs( "sueldo", fpArchivo);
			fputs( "\n", fpArchivo);
			retorno=0;
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				this = ((Employee*)ll_get(pArrayListEmployee, i));
				if( !employee_getIdStr(this,bufferId) &&
					!employee_getNombre(this,bufferNombre) &&
					!employee_getHorasTrabajadasStr(this,bufferHorasTrabajadas) &&
					!employee_getSueldoStr(this,bufferSueldo))
				{
					fputs( bufferId, fpArchivo);
					fputs( ",", fpArchivo);
					fputs( bufferNombre, fpArchivo);
					fputs( ",", fpArchivo);
					fputs( bufferHorasTrabajadas, fpArchivo);
					fputs( ",", fpArchivo);
					fputs( bufferSueldo, fpArchivo);
					fputs( "\n", fpArchivo);
					//fprintf(fpArchivo,"%d,%s,%d,%d\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
				}
			}
			fclose(fpArchivo);
			printf("\nGUARDADO OK");
		}
	}
	return retorno;
}











