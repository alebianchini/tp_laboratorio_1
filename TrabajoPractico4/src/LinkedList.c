#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);
/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode;
	int i;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;
		for(i=0 ; i<nodeIndex ; i++)
		{
			pNode = pNode->pNextNode;
		}
	}
    return pNode;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode;
    Node* actualNode;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	newNode = (Node*) malloc(sizeof(Node));
    	if(newNode != NULL)
    	{
    		if(nodeIndex == 0){
    			newNode->pNextNode = this->pFirstNode;
    			this->pFirstNode = newNode;
    			newNode->pElement = pElement;
    			this->size++;
    			returnAux = 0;
    		}
    		else{
    			actualNode = getNode(this, (nodeIndex - 1));
    			newNode->pNextNode = actualNode->pNextNode;
    			actualNode->pNextNode = newNode;
    			newNode->pElement = pElement;
    			this->size++;
    			returnAux=0;
    		}
    	}
    }
    return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(!addNode(this, this->size, pElement))
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxiliar;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxiliar = getNode(this, index);
    	if(auxiliar != NULL)
    	{
    		returnAux = auxiliar->pElement;
    	}
    }
    return returnAux;
}


int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxiliar;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxiliar = getNode(this, index);
    	if(auxiliar != NULL)
    	{
    		auxiliar->pElement = pElement;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxiliar;
    Node* nodoAnterior;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxiliar = getNode(this, index);
    	if(index > 0 && auxiliar != NULL){
    	nodoAnterior = getNode(this, (index - 1));
    	nodoAnterior->pNextNode = auxiliar->pNextNode;
    	free(auxiliar);
    	this->size--;
    	returnAux = 0;
    	}
    	else if(auxiliar != NULL)
    	{
    		this->pFirstNode = auxiliar->pNextNode;
    		free(auxiliar);
    		this->size--;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this != NULL)
    {
    	returnAux = 0;
    	for(i=ll_len(this) - 1; i>=0; i--)
    	{
    		ll_remove(this, i);
    	}
    }
    return returnAux;
}


int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(!ll_clear(this))
    	{
    		free(this);
    		returnAux = 0;
    	}
    }
    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    int i;
    if(this != NULL)
    {
    	for(i=0; i<ll_len(this); i++)
    	{
    		pNode = getNode(this, i);
    		if(pNode->pElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(ll_len(this) > 0){
    		returnAux = 0;
    	}
    	else{
    		returnAux = 1;
    	}
    }
    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(!addNode(this, index, pElement))
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL){
    		returnAux = pNode->pElement;
    		ll_remove(this, index);
    	}
    }
    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 0;
    	if(ll_indexOf(this, pElement) > -1){
    		returnAux = 1;
    	}
    }
    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    Node* pNode;
    int i;
    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	pNode = this2->pFirstNode;
    	for(i=0; i<ll_len(this2); i++)
    	{
    		if(!ll_contains(this, pNode->pElement)){
    			returnAux = 0;
    			break;
    		}
    		pNode = pNode->pNextNode;
    	}
    }
    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNode;
    int i;
    if(this != NULL && from >=0 && from<ll_len(this) && to>from && to<=ll_len(this))
    {
    	if((cloneArray = ll_newLinkedList()) != NULL)
    	{
    		for(i=from; i<to; i++)
    		{
    			pNode = getNode(this, i);
    			addNode(cloneArray, i, pNode->pElement);
    		}
    	}
    }
    return cloneArray;
}


LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElementA;
    void* pElementB;
    void* auxiliar = NULL;
    int longitud = ll_len(this);
    int flagSwap = 1;
    int i;
    if(this != NULL && pFunc != NULL && order>= 0 && order<=1 && longitud > 0)
    {
    	switch(order) //case 1 (ascendente) case 0 (descendente)
    	{
    	case 1:
    		do{
    			flagSwap = 0;
    			for(i=0; i<longitud-1; i++)
    			{
    				pElementA = ll_get(this, i);
    				pElementB = ll_get(this, i+1);
    				if(pFunc(pElementA, pElementB) == 1)
    				{
    					auxiliar = pElementA;
    					ll_set(this,i,pElementB);
    					ll_set(this,i+1,auxiliar);
    					flagSwap = 1;
    				}
    			}
    			longitud--;
    		}while(flagSwap);
    		returnAux = 0;
    		break;
    	case 0:
    		do{
    			flagSwap = 0;
    			for(i=0; i<longitud-1; i++)
    			{
    				pElementA = ll_get(this, i);
    				pElementB = ll_get(this, i+1);
    				if(pFunc(pElementA, pElementB) == -1)
    				{
    					auxiliar = pElementA;
    					ll_set(this,i,pElementB);
    					ll_set(this,i+1,auxiliar);
    					flagSwap = 1;
    				}
    			}
    			longitud--;
    		}while(flagSwap);
    		returnAux = 0;
    		break;
    	}
    }
    return returnAux;
}


LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
{
	int i;

	if(this != NULL && fn != NULL)
	{
		for(i=0; i<ll_len(this); i++)
		{
			fn(ll_get(this, i));
		}
	}

	return this;
}

int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int returnAux =-1;
	int i;
	int r;
	int acumulador = 0;
	if(this != NULL && fn != NULL)
	{
		for(i=0; i<ll_len(this); i++)
		{
			r = fn(ll_get(this, i));
			acumulador = acumulador + r;
		}
		returnAux = acumulador;
	}
	return returnAux;
}





