/*
 * eArticulo.c
 *
 *  Created on: 25 jun. 2020
 *      Author: Alejo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eArticulo.h"

/**
 * \brief Verifica si la cadena ingresada es un string que cumpla con los caracteres permitidos
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidString(char* cadena,int longitud);
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esNumerica(char* cadena, int limite);
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int isValidFlotante(char* cadena);
/**
 * \brief Verifica si la cadena ingresada es un string que cumpla con los caracteres permitidos (inclusive los numeros)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidStringWithNum(char* cadena,int longitud);
/**
 * \brief Devuelve la descripcion del rubro segun el rubroId que tenga
 * \param rubroId id numerico que hace referencia al rubro
 * \param pResultado Puntero a la variable donde se va a guardar la descripcion del rubro
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
static int eArticulo_cambioRubro(int rubroId, char* pResultado);

/*************************************************************************/

eArticulo* eArticulo_new()
{
	eArticulo* auxiliarP = NULL;
	auxiliarP = (eArticulo*) malloc(sizeof(eArticulo));
	return auxiliarP;
}

void eArticulo_delete(eArticulo* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int eArticulo_setId(eArticulo* this, int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int eArticulo_setIdStr(eArticulo* this, char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = eArticulo_setId(this,atoi(id));
		}
	}
	return retorno;
}

int eArticulo_getId(eArticulo* this, int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int eArticulo_getIdStr(eArticulo* this, char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}

int eArticulo_setArticulo(eArticulo* this, char* articulo)
{
	int retorno = -1;
	if(this != NULL && articulo != NULL)
	{
		if(isValidString(articulo,50))
		{
			retorno = 0;
			strncpy(this->articulo,articulo,50);
		}
	}
	return retorno;
}

int eArticulo_getArticulo(eArticulo* this,char* articulo)
{
	int retorno = -1;
	if(this != NULL && articulo != NULL)
	{
		retorno = 0;
		strncpy(articulo,this->articulo,50);
	}
	return retorno;
}

int eArticulo_setPrecio(eArticulo* this, float precio)
{
	int retorno = -1;
	if(this != NULL && precio > 0)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}

int eArticulo_setPrecioStr(eArticulo* this, char* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		if(isValidFlotante(precio))
		{
			retorno = eArticulo_setPrecio(this,atof(precio)); //REVISAR LO DEL ATOF
		}
	}
	return retorno;
}

int eArticulo_getPrecio(eArticulo* this, float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}

int eArticulo_getPrecioStr(eArticulo* this, char* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		sprintf(precio,"%.2f",this->precio);
	}
	return retorno;
}

int eArticulo_setMedida(eArticulo* this, char* medida)
{
	int retorno = -1;
	if(this != NULL && medida != NULL)
	{
		if(isValidStringWithNum(medida,15))
		{
			retorno = 0;
			strncpy(this->medida,medida,15);
		}
	}
	return retorno;
}

int eArticulo_getMedida(eArticulo* this,char* medida)
{
	int retorno = -1;
	if(this != NULL && medida != NULL)
	{
		retorno = 0;
		strncpy(medida,this->medida,15);
	}
	return retorno;
}

int eArticulo_setRubroId(eArticulo* this, int rubroId)
{
	int retorno = -1;
	if(this != NULL && rubroId >= 0)
	{
		retorno = 0;
		this->rubroId = rubroId;
	}
	return retorno;
}

int eArticulo_setRubroIdStr(eArticulo* this, char* rubroId)
{
	int retorno = -1;
	if(this != NULL && rubroId != NULL)
	{
		if(esNumerica(rubroId,10))
		{
			retorno = eArticulo_setRubroId(this,atoi(rubroId));
		}
	}
	return retorno;
}

int eArticulo_getRubroId(eArticulo* this, int* rubroId)
{
	int retorno = -1;
	if(this != NULL && rubroId != NULL)
	{
		retorno = 0;
		*rubroId = this->rubroId;
	}
	return retorno;
}

int eArticulo_getRubroIdStr(eArticulo* this, char* rubroId)
{
	int retorno = -1;
	if(this != NULL && rubroId != NULL)
	{
		retorno = 0;
		sprintf(rubroId,"%d",this->rubroId);
	}
	return retorno;
}

eArticulo* eArticulo_newParametrosStr(char* idStr, char* articulo, char* precioStr, char* medida, char* rubroIdStr)
{
	eArticulo* this = NULL;
	this = eArticulo_new();
	if(this != NULL && idStr != NULL && articulo != NULL && precioStr != NULL && medida != NULL && rubroIdStr != NULL)
	{
		if( eArticulo_setIdStr(this, idStr) == -1 ||
			eArticulo_setArticulo(this, articulo) == -1 ||
			eArticulo_setPrecioStr(this, precioStr) == -1 ||
			eArticulo_setMedida(this, medida) == -1 ||
			eArticulo_setRubroIdStr(this, rubroIdStr) == -1)
		{
			eArticulo_delete(this);
			this = NULL;
		}
	}
	return this;
}

eArticulo* eArticulo_newParametros(int id, char* articulo, float precio, char* medida, int rubroId)
{
	eArticulo* this = NULL;
	this = eArticulo_new();
	if(this != NULL && articulo != NULL && id >= 0 && precio > 0 && medida != NULL && rubroId > 0 && rubroId < 5)
	{
		if( eArticulo_setId(this, id) == -1 ||
			eArticulo_setArticulo(this, articulo) == -1 ||
			eArticulo_setPrecio(this, precio) == -1 ||
			eArticulo_setMedida(this, medida) == -1 ||
			eArticulo_setRubroId(this, rubroId) == -1)
		{
			eArticulo_delete(this);
			this = NULL;
		}
	}
	return this;
}

void eArticulo_printDetail(eArticulo* this)
{
	int bufferId;
	char bufferArticulo[50];
	float bufferPrecio;
	char bufferMedida[15];
	int rubroId;
	char rubro[35];

	if( !eArticulo_getId(this, &bufferId) &&
		!eArticulo_getArticulo(this, bufferArticulo) &&
		!eArticulo_getPrecio(this, &bufferPrecio) &&
		!eArticulo_getMedida(this, bufferMedida) &&
		!eArticulo_getRubroId(this, &rubroId))
	{
		if(!eArticulo_cambioRubro(rubroId, rubro)){
		printf("|%d\t|%-34.34s\t|%-7.6s\t|$%-10.2f\t\t|%-30.30s\n",bufferId, bufferArticulo, bufferMedida, bufferPrecio, rubro);
		}
	}
}

int eArticulo_swapByArticulo(void* thisA, void* thisB)
{
	int retorno = 0;
	char articuloA[50];
	char articuloB[50];
	eArticulo_getArticulo(thisA, articuloA);
	eArticulo_getArticulo(thisB, articuloB);

	if(strncmp(articuloA,articuloB,50) >0)
	{
		retorno = 1;
	}
	else if(strncmp(articuloB,articuloA,50) >0)
	{
		retorno = -1;
	}
	return retorno;
}

/*********************************************************************/

static int eArticulo_cambioRubro(int rubroId, char* pResultado)
{
	int retorno=-1;

	if(rubroId >= 1 && rubroId <= 4)
	{
		switch(rubroId){
		case 1:
			strncpy(pResultado, "Cuidado de Ropa", 35);
			break;
		case 2:
			strncpy(pResultado, "Limpieza y Desinfeccion", 35);
			break;
		case 3:
			strncpy(pResultado, "Cuidado Personal e Higiene", 35);
			break;
		case 4:
			strncpy(pResultado, "Cuidado del Automotor", 35);
			break;
		}
		retorno = 0;
	}

	return retorno;
}

static int esNumerica(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int isValidString(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' )) && (cadena[i] != ' ') && (cadena[i] != '-' ) && (cadena[i] != ':' ) && (cadena[i] != '/' ) && (cadena[i] != '.' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int isValidStringWithNum(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' )) && (cadena[i] < '0' || cadena[i] > '9' ) && (cadena[i] != ' ') && (cadena[i] != '-' ) && (cadena[i] != ':' ) && (cadena[i] != '/' ) && (cadena[i] != '.' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int isValidFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
