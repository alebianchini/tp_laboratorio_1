/*
 ============================================================================
 Name        : TrabajoPractico4.c
 Author      : Alejo Bianchini
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "eArticulo.h"
#include "Controller.h"

int main(void) {
	setbuf(stdout, NULL);
	int option;
	LinkedList* listaEArticulos = ll_newLinkedList();
	char nombreArchivo[50];
	do{
		if(!utn_getNumero(&option,"\n\n1.Cargar datos de los articulos desde un archivo .csv (modo texto)"
	   							  "\n2.Listar los articulos"
	   							  "\n3.Ordenar los articulos"
	   							  "\n4.Asignarle el descuento correspondiente a los precios"
								  "\n5.Guardar la lista de articulos en el archivo mapeado.csv (modo texto)"
								  "\n6.Informes"
	   							  "\n7.Salir\n\n",
								  "\nError opcion invalida",1,7,3))
		{
			switch(option)
			{
			case 1:
				if(!utn_getDescripcion(nombreArchivo, 50, "\nIngrese el nombre del archivo .csv que desea leer: ", "\nNombre invalido\n", 3))
				{
					controller_loadFromText(nombreArchivo, listaEArticulos);
				}
				break;
			case 2:
				controller_ListEArticulos(listaEArticulos);
				break;
			case 3:
				controller_sortEArticulos(listaEArticulos);
				break;
			case 4:
				controller_mapEArticulos(listaEArticulos);
				break;
			case 5:
				controller_saveAsText("mapeado.csv",listaEArticulos);
				break;
			case 6:
				controller_informesEArticulos(listaEArticulos);
				break;
			}
		}
	}while(option != 7);

	ll_deleteLinkedList(listaEArticulos);

	return EXIT_SUCCESS;
}
