#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eArticulo.h"
#include "utn.h"


int parser_fromText(FILE* pFile , LinkedList* pLista)
{
	int retorno=-1;
	char bufferId[4096];
	char bufferArticulo[4096];
	char bufferPrecio[4096];
	char bufferMedida[4096];
	char bufferIdRubro[4096];
	int flag=0;

	if(pFile != NULL)
	{
		retorno=0;
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferArticulo, bufferMedida, bufferPrecio, bufferIdRubro) == 5)
			{
				if(flag == 0){
					flag = 1;
					continue;
				}
				ll_add(pLista, eArticulo_newParametrosStr(bufferId, bufferArticulo, bufferPrecio, bufferMedida, bufferIdRubro));
			}
		}while(!feof(pFile));
		printf("\n****CARGA EXITOSA****\n");
	}

    return retorno;
}

