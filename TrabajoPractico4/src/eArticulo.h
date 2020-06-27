/*
 * eArticulo.h
 *
 *  Created on: 25 jun. 2020
 *      Author: Alejo
 */

#ifndef EARTICULO_H_
#define EARTICULO_H_

typedef struct{
	int id;
	char articulo[50];
	float precio;
	char medida[15];
	int rubroId;
}eArticulo;

/**
 * \brief Crea un nuevo elemento del tipo eArticulo en memoria dinámica
 * \return Retorna el espacio de memoria que le fue asignado
 *
 */
eArticulo* eArticulo_new();
/**
 * \brief Elimina un elemento del tipo eArticulo de la memoria dinámica
 *
 */
void eArticulo_delete(eArticulo* this);
/**
 * \brief Setea el campo id de un elemento del tipo eArticulo a traves de su puntero
 * \param this Puntero al Articulo en cuestion
 * \param id Valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_setId(eArticulo* this, int id);
/**
 * \brief Setea el campo id de un elemento del tipo eArticulo a traves de su puntero (seteandolo como un string)
 * \param this Puntero al Articulo en cuestion
 * \param id Puntero al valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_setIdStr(eArticulo* this, char* id);
/**
 * \brief Obtiene el valor del campo id de un elemento del tipo eArticulo a traves de su puntero
 * \param this Puntero al Articulo en cuestion
 * \param id Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_getId(eArticulo* this, int* id);
/**
 * \brief Obtiene el valor del campo id de un elemento del tipo eArticulo a traves de su puntero (obteniendolo como un string)
 * \param this Puntero al Articulo en cuestion
 * \param id Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_getIdStr(eArticulo* this, char* id);
/**
 * \brief Setea el campo articulo de un elemento del tipo eArticulo a traves de su puntero
 * \param this Puntero al Articulo en cuestion
 * \param articulo Puntero a la variable que posee el valor que sera cargado
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_setArticulo(eArticulo* this, char* articulo);
/**
 * \brief Obtiene el valor del campo articulo de un elemento del tipo eArticulo a traves de su puntero
 * \param this Puntero al Articulo en cuestion
 * \param articulo Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_getArticulo(eArticulo* this,char* articulo);
/**
 * \brief Setea el campo precio de un elemento del tipo eArticulo a traves de su puntero
 * \param this Puntero al Articulo en cuestion
 * \param precio Puntero al valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_setPrecio(eArticulo* this, float precio);
/**
 * \brief Setea el campo precio de un elemento del tipo eArticulo a traves de su puntero (seteandolo como un string)
 * \param this Puntero al Articulo en cuestion
 * \param precio Puntero al valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_setPrecioStr(eArticulo* this, char* precio);
/**
 * \brief Obtiene el valor del campo precio de un elemento del tipo eArticulo a traves de su puntero
 * \param this Puntero al Articulo en cuestion
 * \param precio Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_getPrecio(eArticulo* this, float* precio);
/**
 * \brief Obtiene el valor del campo precio de un elemento del tipo eArticulo a traves de su puntero (obteniendolo como un string)
 * \param this Puntero al Articulo en cuestion
 * \param precio Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_getPrecioStr(eArticulo* this, char* precio);
/**
 * \brief Obtiene el valor del campo medida de un elemento del tipo eArticulo a traves de su puntero
 * \param this Puntero al Articulo en cuestion
 * \param medida Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_setMedida(eArticulo* this, char* medida);
/**
 * \brief Obtiene el valor del campo medida de un elemento del tipo eArticulo a traves de su puntero
 * \param this Puntero al Articulo en cuestion
 * \param medida Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_getMedida(eArticulo* this,char* medida);
/**
 * \brief Setea el campo rubroId de un elemento del tipo eArticulo a traves de su puntero
 * \param this Puntero al Articulo en cuestion
 * \param rubroId Puntero al valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_setRubroId(eArticulo* this, int rubroId);
/**
 * \brief Setea el campo rubroId de un elemento del tipo eArticulo a traves de su puntero (seteandolo como un string)
 * \param this Puntero al Articulo en cuestion
 * \param rubroId Puntero al valor que se va a cargar
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_setRubroIdStr(eArticulo* this, char* rubroId);
/**
 * \brief Obtiene el valor del campo rubroId de un elemento del tipo eArticulo a traves de su puntero
 * \param this Puntero al Articulo en cuestion
 * \param rubroId Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_getRubroId(eArticulo* this, int* rubroId);
/**
 * \brief Obtiene el valor del campo rubroId de un elemento del tipo eArticulo a traves de su puntero (obteniendolo como un string)
 * \param this Puntero al Articulo en cuestion
 * \param rubroId Puntero a una variable donde se guardara ese valor
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int eArticulo_getRubroIdStr(eArticulo* this, char* rubroId);
/**
 * \brief Crea un nuevo elemento del tipo eArticulo en memoria dinámica, y además llena sus campos con los datos correspondientes (recibiendolos como strings)
 * \param idStr ID que será asignado a dicho campo del articulo
 * \param articulo string que será asignado a dicho campo del articulo
 * \param precioStr precio que será asignado a dicho campo del articulo
 * \param medida Medida que será asignado a dicho campo del articulo
 * \param rubroIdStr ID que será asignado a dicho campo del articulo
 * \return Retorna un puntero al elemento creado o un puntero a NULL
 *
 */
eArticulo* eArticulo_newParametrosStr(char* idStr, char* articulo, char* precioStr, char* medida, char* rubroIdStr);
/**
 * \brief Crea un nuevo elemento del tipo eArticulo en memoria dinámica, y además llena sus campos con los datos correspondientes
 * \param id ID que será asignado a dicho campo del articulo
 * \param articulo string que será asignado a dicho campo del articulo
 * \param precio precio que será asignado a dicho campo del articulo
 * \param medida Medida que será asignado a dicho campo del articulo
 * \param rubroId ID que será asignado a dicho campo del articulo
 * \return Retorna un puntero al elemento creado o un puntero a NULL
 *
 */
eArticulo* eArticulo_newParametros(int id, char* articulo, float precio, char* medida, int rubroId);
/**
 * \brief Imprime los campos de un elemento del tipo eArticulo
 * \param this Puntero al Articulo en cuestion
 * \return void
 *
 */
void eArticulo_printDetail(eArticulo* this);
/**
 * \brief Determina cual de los strings recibidos es mayor y cual es menor
 * \param thisA Puntero al primer string
 * \param thisB Puntero al segundo string
 * \return int 0 son iguales. 1 o -1
 *
 */
int eArticulo_swapByArticulo(void* thisA, void* thisB);

#endif /* EARTICULO_H_ */
