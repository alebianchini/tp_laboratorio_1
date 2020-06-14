/*
 * ArrayEmpleados.c
 *
 *  Created on: 12 may. 2020
 *      Author: Alejo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmpleados.h"
#include "utn.h"
#define NOMBRE_LEN 51


int initEmpleados(Empleado* array, int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return retorno;
}

int imprimirEmpleado(Empleado* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - NOMBRE: %s - APELLIDO: %s - SALARIO: $%.2f - SECTOR: %d",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->salario,pElemento->sector);
	}
	return retorno;
}

int imprimirEmpleados(Empleado* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			imprimirEmpleado(&array[i]);
		}
	}
	return retorno;
}

int altaEmpleado(Empleado* array,int limite,int indice,int* id)
{
	int retorno=-1;
	Empleado bufferEmpleado;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(utn_getNombre(bufferEmpleado.nombre,NOMBRE_LEN,"\nNombre del empleado?\n","\nDato invalido\n",2) == 0 &&
		   utn_getNombre(bufferEmpleado.apellido, NOMBRE_LEN,"\nApellido?\n","\nDato invalido\n",2) == 0 &&
		   utn_getNumeroFlotante(&bufferEmpleado.salario,"\nSalario?\n","\nSalario invalido\n",1,300000,2) == 0 &&
		   utn_getNumero(&bufferEmpleado.sector,"\nNúmero de sector?\n","\nNumero invalido\n",0, 10, 2) == 0)
		{
			retorno=0;
			bufferEmpleado.id = *id;
			bufferEmpleado.isEmpty = 0;
			array[indice] = bufferEmpleado;
			(*id)++;
		}
	}
	return retorno;
}

int getIndiceVacio(Empleado* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int modificarEmpleado(Empleado* array,int limite,int indice)
{
	int retorno=-1;
	int seguir;
	int opcion;
	Empleado bufferEmpleado;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		do
		{
			if(!utn_getNumero(&opcion,"\n\n1.Modificar nombre"
									"\n2.Modificar apellido"
									"\n3.Modificar salario"
									"\n4.Modificar sector\n",
									"\nError opcion invalida\n",1,4,3))
			{
				switch(opcion)
				{
				case 1:
					if(utn_getNombre(bufferEmpleado.nombre,NOMBRE_LEN,"\nNombre del empleado?\n","\nDato invalido\n",3) == 0)
					{
						retorno=0;
						strncpy(array[indice].nombre,bufferEmpleado.nombre,NOMBRE_LEN);
					}
					break;
				case 2:
					if(utn_getNombre(bufferEmpleado.apellido, NOMBRE_LEN,"\nApellido del empleado?\n","\nDato invalido\n",3) == 0)
					{
						retorno=0;
						strncpy(array[indice].apellido,bufferEmpleado.apellido,NOMBRE_LEN);
					}
					break;
				case 3:
					if(utn_getNumeroFlotante(&bufferEmpleado.salario,"\nSalario del empleado?\n","\nSalario invalido\n",1,300000,3) == 0)
					{
						retorno=0;
						array[indice].salario = bufferEmpleado.salario;
					}
					break;
				case 4:
					if(utn_getNumero(&bufferEmpleado.sector,"\nNúmero de sector?\n","\nNumero invalido\n",0, 10, 3) == 0)
					{
						retorno=0;
						array[indice].sector = bufferEmpleado.sector;
					}
					break;
				}
			}
			utn_getNumero(&seguir,"\nDesea realizar otra modificación sobre este empleado?\n '1': SI - '0': NO\n","\nNumero invalido\n",0, 1, 4);
		}while(seguir == 1);
	}
	return retorno;
}

int buscarId(Empleado array[],int limite,int valorBuscado)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int bajaEmpleado(Empleado* array,int limite,int indice)
{
	int retorno=-1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		retorno=0;
	}
	return retorno;
}

int ordenarPorApellidoSector(Empleado* array,int limite)
{
	int retorno=-1;
	int flagSwap;
	int i;
	Empleado buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			retorno = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].apellido, array[i+1].apellido,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1] = buffer;
				}
				else if(strncmp(array[i].apellido, array[i+1].apellido,NOMBRE_LEN) == 0)
				{
					if(array[i].sector > array[i+1].sector)
					{
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1] = buffer;
					}
				}
			}
			limite--;
		}while(flagSwap);
	}
	return retorno;
}

int informeSalarios(Empleado* array, int limite)
{
	int retorno=-1;
	int i;
	float acumulador=0;
	int contador=0;
	float promedio;
	int contadorEmp=0;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0)
			{
				acumulador = (float)acumulador + array[i].salario;
				contador++;
			}
		}
		promedio = (float)acumulador / contador;
		for(i=0;i<limite;i++)
		{
			if(array[i].salario > promedio && array[i].isEmpty == 0)
			{
				contadorEmp++;
			}
		}
		retorno = 0;
		printf("\nSuma total de los salario de los empleados: $%2.f\n"
				"\nPromedio de los salarios: $%2.f\n"
				"\nCantidad de empleados que cobran por encima del promedio: %d\n",acumulador,promedio,contadorEmp);
	}

	return retorno;
}

int getIndiceLleno(Empleado* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

void menuEmpleados(Empleado* arrayEmpleados, int limite, int* idEmpleados, int* opcion, int* auxiliarId, int* auxiliarIndice)
{
	do
	{
		if(getIndiceLleno(arrayEmpleados, limite) != 0)
		{
			printf("Por favor, cargue un primer empleado");
			*auxiliarIndice = getIndiceVacio(arrayEmpleados,limite);
			if(auxiliarIndice >= 0)
			{
				if(altaEmpleado(arrayEmpleados,limite,*auxiliarIndice,idEmpleados) == 0)
				{
					printf("\nCarga realizada con exito\n");
				}
			}
		}
		else if(!utn_getNumero(  opcion,"\n\n1.Dar de alta un empleado"
							"\n2.Modificar un empleado"
							"\n3.Eliminar un empleado"
							"\n4.Ordenar lista de empleados por nombre y sector"
							"\n5.Informe completo sobre salarios de los empleados"
							"\n6.Imprimir lista de empleados"
							"\n7.Salir\n\n",
							"\nError opcion invalida",1,7,2))
		{
			switch(*opcion)
			{
			case 1:
				*auxiliarIndice = getIndiceVacio(arrayEmpleados,limite);
				if(auxiliarIndice >= 0)
				{
					if(altaEmpleado(arrayEmpleados,limite,*auxiliarIndice,idEmpleados) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR\n");
				}
				break;
			case 2:
				imprimirEmpleados(arrayEmpleados,limite);
				if(utn_getNumero(auxiliarId,"\nIndique el ID del empleado a modificar: ","\nID invalido",1,*idEmpleados,2) == 0)
				{
					*auxiliarIndice = buscarId(arrayEmpleados,limite,*auxiliarId);
					if( auxiliarIndice >= 0 &&
						modificarEmpleado(arrayEmpleados,limite,*auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;
			case 3:
				imprimirEmpleados(arrayEmpleados,limite);
				if(utn_getNumero(auxiliarId,"\nIndique el ID del empleado a ser eliminado: ","\nID invalido",0,*idEmpleados,2) == 0)
				{
					*auxiliarIndice = buscarId(arrayEmpleados,limite,*auxiliarId);
					if( auxiliarIndice >= 0 &&
							bajaEmpleado(arrayEmpleados,limite,*auxiliarIndice) == 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				if(ordenarPorApellidoSector(arrayEmpleados,limite) == 0)
				{
					printf("\nOrdenamiento realizado con exito\n");
				}
				break;
			case 5:
				informeSalarios(arrayEmpleados,limite);
				break;
			case 6:
				imprimirEmpleados(arrayEmpleados,limite);
				break;
			}
		}
	}while(*opcion != 7);
}







