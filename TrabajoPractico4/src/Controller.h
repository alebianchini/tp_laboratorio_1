/*
 * Controller.h
 *
 *  Created on: 25 jun. 2020
 *      Author: Alejo
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Carga los datos de los articulos desde un archivo .csv (modo texto).
 *
 * \param char* path Puntero al archivo del cual se leeran los datos
 * \param LinkedList* pLista Puntero a la lista donde se guardaran los datos leidos
 * \return int 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_loadFromText(char* path , LinkedList* pLista);

/** \brief Listar empleados
 *
 * \param LinkedList* pLista Puntero a la lista que se imprimira
 * \return int 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_ListEArticulos(LinkedList* pLista);

/** \brief Listar empleados con los descuentos aplicados
 *
 * \param LinkedList* pLista Puntero a la lista que se imprimira
 * \return int 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_ListEArticulosConDescuento(LinkedList* pLista);

/** \brief Ordenar los articulos
 *
 * \param LinkedList* pLista Puntero a la lista que sera ordenada
 * \return int 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_sortEArticulos(LinkedList* pLista);

/** \brief Modifica el campo precio de los articulos asignandole un descuento en caso de ser necesario
 *
 * \param LinkedList* pLista Puntero a la lista que sera modificada
 * \return int 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_mapEArticulos(LinkedList* pLista);

/** \brief Guarda la lista de articulos en el archivo mapeado.csv (modo texto).
 *
 * \param char* path Puntero al archivo en el cual se escribiran los datos
 * \param LinkedList* pLista Puntero a la lista de la cual se obtendran dichos datos
 * \return int 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_saveAsText(char* path , LinkedList* pLista);

/** \brief Cuenta la cantidad de elementos de la lista que cumplen con cierta condicion
 *
 * \param LinkedList* pLista Puntero a la lista que sera analizada
 * \return int 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_informesEArticulos(LinkedList* pLista);

#endif /* CONTROLLER_H_ */
