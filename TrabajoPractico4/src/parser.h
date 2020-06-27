/*
 * parser.h
 *
 *  Created on: 12 jun. 2020
 *      Author: Alejo
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos de los articulos desde un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int
 *
 */
int parser_fromText(FILE* pFile , LinkedList* pArrayListVentas);

#endif /* PARSER_H_ */
