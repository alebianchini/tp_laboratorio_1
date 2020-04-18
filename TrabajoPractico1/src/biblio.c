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

/**
* \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
* \param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
* \param longitud Define el tamaño de la cadena
* \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no.
*/
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

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
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

/**
* \brief Verifica si la cadena ingresada es numerica
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/
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

/**
* \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje de Error a ser mostrado
* \param minimo Es el numero maximo a ser aceptado
* \param maximo Es el minimo minimo a ser aceptado
* \param reintentos es el numero de reintentos que tendra el usuario
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/
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

/**
* \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje de Error a ser mostrado
* \param reintentos es el numero de reintentos que tendra el usuario
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/
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

/**
* \brief Realiza la suma de dos variables enteras.
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \param x es el primer valor ingresado por el usuario
* \param y es el segundo valor ingresado por el usuario
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/
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

/**
* \brief Realiza la resta de dos variables enteras.
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \param x es el primer valor ingresado por el usuario
* \param y es el segundo valor ingresado por el usuario
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/
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

/**
* \brief Realiza la multiplicacion de dos variables enteras.
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \param x es el primer valor ingresado por el usuario
* \param y es el segundo valor ingresado por el usuario
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/
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

/**
* \brief Realiza la division de dos variables enteras, dando un resultado flotante.
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \param x es el primer valor ingresado por el usuario
* \param y es el segundo valor ingresado por el usuario
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/
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
