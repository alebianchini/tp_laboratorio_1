/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : Alejo Bianchini
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmpleados.h"
#include "utn.h"

#define CANTIDAD_EMPLEADOS 1000

int main(void) {
setbuf(stdout, NULL);

Empleado arrayEmpleados[CANTIDAD_EMPLEADOS];
int idEmpleados=1;
int opcion;
int auxiliarIndice;
int auxiliarId;

if(initEmpleados(arrayEmpleados,CANTIDAD_EMPLEADOS) == 0)
{
	printf("Array inicializado correctamente. \n\n");
}
menuEmpleados(arrayEmpleados,CANTIDAD_EMPLEADOS, &idEmpleados, &opcion, &auxiliarId, &auxiliarIndice);

return EXIT_SUCCESS;
}
