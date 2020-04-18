/*
 * biblio.h
 *
 *  Created on: 9 abr. 2020
 *      Author: Alejo
 */

#ifndef BIBLIO_H_
#define BIBLIO_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getEntero(int* pResultado, char* mensaje, char* mensajeError, int reintentos);
int getSuma(int* pResultado, int x, int y);
int getResta(int* pResultado, int x, int y);
int getProducto(int* pResultado, int x, int y);
int getCociente(float* pResultado, int x, int y);

#endif /* BIBLIO_H_ */
