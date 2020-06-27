#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eArticulo.h"
#include "parser.h"
#include "utn.h"

/** \brief Agrega un descuento al campo precio de un articulo (en caso de cumplir con las caracteristicas indicadas)
 * \param void* pElement Puntero al elemento a ser modificado
 * \return void
 *
 */
static void controller_addDescuento(void* pElement);
/** \brief Verifica si el precio del elemento recibido es mayor a 100
 * \param void* pElement Puntero al elemento a ser analizado
 * \return int 1 si es mayor a 100. 0 si no lo es
 *
 */
static int controller_countArticulosMayorCien(void* pElement);
/** \brief Verifica si el rubroId del elemento recibido es igual a 1
 * \param void* pElement Puntero al elemento a ser analizado
 * \return int 1 si cumple con la condicion. 0 si no la cumple
 *
 */
static int controller_countArticulosRubro1(void* pElement);

int controller_loadFromText(char* path , LinkedList* pLista)
{
	int retorno=-1;
	FILE* fpArchivo;
	if(path != NULL && pLista != NULL)
	{
		retorno = 0;
		fpArchivo = fopen(path,"r");
		parser_fromText(fpArchivo , pLista);
		fclose(fpArchivo);
	}
	return retorno;
}


int controller_ListEArticulos(LinkedList* pLista)
{
	int retorno=-1;
	if(pLista != NULL && !ll_isEmpty(pLista))
	{
		retorno = 0;
		int i;
		printf("\n******LISTADO DE ARTICULOS******\n\n|%-5.4s\t|%-34.34s\t|%-7.6s\t|%-10.10s\t\t|%-30.30s\n", "ID", "ARTICULO", "MEDIDA", "PRECIO", "RUBRO");
		for(i = 0; i<ll_len(pLista); i++)
		{
			eArticulo_printDetail(((eArticulo*)ll_get(pLista, i)));
		}
	}
	else{
		printf("\n*****No hay Articulos cargados a la lista*****\n");
	}
	return retorno;
}

int controller_ListEArticulosConDescuento(LinkedList* pLista)
{
	int retorno=-1;
	if(pLista != NULL && !ll_isEmpty(pLista))
	{
		retorno = 0;
		int i;
		printf("\n******LISTADO DE ARTICULOS CON LOS DESCUENTOS INCLUIDOS******\n\n|%-5.4s\t|%-34.34s\t|%-7.6s\t|%-10.22s\t|%-30.30s\n", "ID", "ARTICULO", "MEDIDA", "PRECIO CON DESCUENTO", "RUBRO");
		for(i = 0; i<ll_len(pLista); i++)
		{
			eArticulo_printDetail(((eArticulo*)ll_get(pLista, i)));
		}
	}
	else{
		printf("\n*****No hay Articulos cargados a la lista*****\n");
	}
	return retorno;
}

int controller_sortEArticulos(LinkedList* pLista)
{
	int retorno=-1;
	int opcion;
	if(pLista != NULL && !ll_isEmpty(pLista))
	{
		if(!utn_getNumero(&opcion, "\n1- Desea ordenar por Articulo de la A a la Z?"
								   "\n2- Desea ordenar por Articulo de la Z a la A?\n","\nOpcion invalida\n",1,2,2))
		{
			retorno = 0;
			switch(opcion)
			{
			case 1:
				ll_sort(pLista, eArticulo_swapByArticulo, 1);
				break;
			case 2:
				ll_sort(pLista, eArticulo_swapByArticulo, 0);
				break;
			}
		}
	}
	else{
		printf("\n*****No hay articulos cargados a la lista*****\n");
	}
	return retorno;
}


int controller_mapEArticulos(LinkedList* pLista)
{
	int retorno=-1;
	if(pLista != NULL && !ll_isEmpty(pLista))
	{
		pLista = ll_map(pLista, controller_addDescuento);
		retorno = 0;
		controller_ListEArticulosConDescuento(pLista);
	}
	else{
		printf("\n*****No hay Articulos cargados a la lista*****\n");
	}
	return retorno;
}


int controller_saveAsText(char* path , LinkedList* pLista)
{
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	char bufferId[5];
	char bufferArticulo[50];
	char bufferPrecio[12];
	char bufferMedida[12];
	char bufferIdRubro[5];
	eArticulo* this;
	if(pLista != NULL && path != NULL && !ll_isEmpty(pLista))
	{
		fpArchivo = fopen(path,"w");
		if(fpArchivo != NULL)
		{
			fprintf(fpArchivo,"id,articulo,medida,precio,idRubro\n");
			retorno=0;
			for(i=0;i<ll_len(pLista);i++)
			{
				this = ((eArticulo*)ll_get(pLista, i));
				if( !eArticulo_getIdStr(this, bufferId) &&
					!eArticulo_getArticulo(this, bufferArticulo) &&
					!eArticulo_getMedida(this, bufferMedida) &&
					!eArticulo_getPrecioStr(this, bufferPrecio) &&
					!eArticulo_getRubroIdStr(this, bufferIdRubro))
				{
					fprintf(fpArchivo,"%s,%s,%s,%s,%s\n", bufferId, bufferArticulo, bufferMedida, bufferPrecio, bufferIdRubro);
				}
			}
			fclose(fpArchivo);
			printf("\nGUARDADO OK");
		}
	}
	else{
			printf("\n*****No hay Articulos cargados a la lista*****\n");
		}
	return retorno;
}


int controller_informesEArticulos(LinkedList* pLista)
{
	int retorno=-1;
	int resultado1;
	int resultado2;
	if(pLista != NULL && !ll_isEmpty(pLista))
	{
		resultado1 = ll_count(pLista, controller_countArticulosMayorCien);
		resultado2 = ll_count(pLista, controller_countArticulosRubro1);
		retorno = 0;
		printf("\nLa cantidad de articulos con precio mayor a $100 es: %d\n"
				"La cantidad de articulos del rubro Cuidado de Ropa es: %d\n", resultado1, resultado2);
	}
	else{
		printf("\n*****No hay Articulos cargados a la lista*****\n");
	}
	return retorno;
}


/************************************************************************************/

static void controller_addDescuento(void* pElement)
{
	int bufferRubroId;
	float bufferPrecio;
	float precioFinal;
	eArticulo* articuloAux = (eArticulo*)pElement;

	if(articuloAux != NULL)
	{
		eArticulo_getPrecio(articuloAux, &bufferPrecio);
		eArticulo_getRubroId(articuloAux, &bufferRubroId);
		if(bufferRubroId == 1 && bufferPrecio >= 120)
		{
			precioFinal = bufferPrecio - (bufferPrecio * 20 / 100);
			eArticulo_setPrecio(articuloAux, precioFinal);
		}
		else if(bufferRubroId == 2 && bufferPrecio <= 200)
		{
			precioFinal = bufferPrecio - (bufferPrecio * 10 / 100);
			eArticulo_setPrecio(articuloAux, precioFinal);
		}
	}
}

static int controller_countArticulosMayorCien(void* pElement)
{
	float bufferPrecio;
	int retorno=0;
	eArticulo* articuloAux = (eArticulo*)pElement;

	if(articuloAux != NULL)
	{
		eArticulo_getPrecio(articuloAux, &bufferPrecio);
		if(bufferPrecio >= 100)
		{
			retorno=1;
		}
	}
	return retorno;
}

static int controller_countArticulosRubro1(void* pElement)
{
	int bufferRubroId;
	int retorno=0;
	eArticulo* articuloAux = (eArticulo*)pElement;

	if(articuloAux != NULL)
	{
		eArticulo_getRubroId(articuloAux, &bufferRubroId);
		if(bufferRubroId == 1)
		{
			retorno=1;
		}
	}
	return retorno;
}
