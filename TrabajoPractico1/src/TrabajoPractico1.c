/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

int main(void)
{
setbuf(stdout, NULL);
	int a = 0;
	int bufferA;
	int b = 0;
	int bufferB;
	int bufferSuma;
	int bufferResta;
	int bufferProducto;
	float bufferCociente;
	int opcion;
	int respuestaSwitch;

	do
			{
				respuestaSwitch = utn_getNumero(&opcion,"1-Ingresar primer entero\n2-Ingresar segundo entero\n3-Realizar calculos y mostrarlos en pantalla\n4-Salir\n","Error tiene que ser un numero de 1 a 4\n",1,4,3);
				if(respuestaSwitch == 0)
				{
					switch(opcion)
					{
						case 1:
							if(utn_getEntero(&bufferA,"Numero?\n","Eso no es un numero\n",3) == 0)
							{
								a = bufferA;
							}
							break;
						case 2:
							if(utn_getEntero(&bufferB,"Numero?\n","Eso no es un numero\n",3) == 0)
							{
								b = bufferB;
							}
							break;
						case 3:
							if(getSuma(&bufferSuma, a, b) == 0)
							{
								printf("El resultado de %d + %d es: %d\n", a, b, bufferSuma);
							}

							if(getResta(&bufferResta, a, b) == 0)
							{
								printf("El resultado de %d - %d es: %d\n", a, b, bufferResta);
							}

							if(getProducto(&bufferProducto, a, b) == 0)
							{
								printf("El resultado de %d * %d es: %d\n", a, b, bufferProducto);
							}

							if(getCociente(&bufferCociente, a, b) == 0)
							{
								printf("El resultado de %d / %d es: %.2f\n", a, b, bufferCociente);
							}
							else
							{
								printf("No se puede dividir por 0\n");
							}
					}
				}
			}while(opcion != 4);

	return EXIT_SUCCESS;
}
