/*
 * biblio.c
 *
 *  Created on: 9 abr. 2020
 *      Author: Alejo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"

static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);

static int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}

static int esNumerica(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;
	while(reintentos>0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getInt(&bufferInt) == 0)
		{
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int utn_getEntero(int* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
	int bufferInt;
	int retorno = -1;
	while(reintentos>0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getInt(&bufferInt) == 0)
		{
				*pResultado = bufferInt;
				retorno = 0;
				break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}


int getSuma(int* pResultado, int x, int y)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = x + y;
		retorno = 0;
	}
	return retorno;
}

int getResta(int* pResultado, int x, int y)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = x - y;
		retorno = 0;
	}
	return retorno;
}

int getProducto(int* pResultado, int x, int y)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = x * y;
		retorno = 0;
	}
	return retorno;
}

int getCociente(float* pResultado, int x, int y)
{
	int retorno = -1;

	if(pResultado != NULL && y != 0)
	{
		*pResultado = (float) x / (float) y;
		retorno = 0;
	}
	return retorno;
}
