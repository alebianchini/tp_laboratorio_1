#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite);
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud);

Employee* employee_new()
{
	Employee* auxiliarP = NULL;
	auxiliarP = (Employee*) malloc(sizeof(Employee));
	return auxiliarP;
}

Employee* employee_newParametrosStr(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* this = NULL;
	this = employee_new();
	if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldo != NULL)
	{
		if( employee_setIdStr(this,idStr) == -1 ||
			employee_setNombre(this,nombreStr) == -1 ||
			employee_setHorasTrabajadasStr(this,horasTrabajadasStr) == -1 ||
			employee_setSueldoStr(this,sueldo) == -1)
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return this;
}

Employee* employee_newParametros(int id, char* nombre,int horasTrabajadas,int sueldo)
{
	Employee* this = NULL;
	this = employee_new();
	if(this != NULL && nombre != NULL && id >= 0 && horasTrabajadas > 0 && sueldo > 0)
	{
		if( employee_setNombre(this,nombre) == -1 ||
			employee_setId(this,id) == -1 ||
			employee_setHorasTrabajadas(this,horasTrabajadas) == -1 ||
			employee_setSueldo(this,sueldo) == -1)
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return this;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int employee_setIdStr(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = employee_setId(this,atoi(id));
		}
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int employee_getIdStr(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0)
	{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		if(esNumerica(horasTrabajadas,10))
		{
			retorno = employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
		}
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

int employee_getHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		sprintf(horasTrabajadas,"%d",this->horasTrabajadas);
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}

int employee_setSueldoStr(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		if(esNumerica(sueldo,10))
		{
			retorno = employee_setSueldo(this,atoi(sueldo));
		}
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}

int employee_getSueldoStr(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		sprintf(sueldo,"%d",this->sueldo);
	}
	return retorno;
}

void employee_printDetail(Employee* this)
{
	int bufferId;
	char bufferNombre[NOMBRE_LEN];
	int bufferHorasTrabajadas;
	int bufferSueldo;
	if( !employee_getId(this, &bufferId) &&
		!employee_getNombre(this, bufferNombre) &&
		!employee_getHorasTrabajadas(this, &bufferHorasTrabajadas) &&
		!employee_getSueldo(this, &bufferSueldo))
	{
		printf("%d - %s - %d - %d\n",bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
	}
}

int employee_editDetail(Employee* this)
{
	printf("fede puto");
	employee_printDetail(this);
	int retorno=-1;
	int bufferId;
	char bufferNombre[NOMBRE_LEN];
	int bufferHorasTrabajadas;
	int bufferSueldo;
	int opcion;
	if( !employee_getId(this, &bufferId) &&
		!employee_getNombre(this, bufferNombre) &&
		!employee_getHorasTrabajadas(this, &bufferHorasTrabajadas) &&
		!employee_getSueldo(this, &bufferSueldo))
	{
		printf("******EMPLEADO A SER MODIFICADO********\n%d - %s - %d - %d\n",bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
		utn_getNumero(&opcion,"Que desea modificar?\n 1-Nombre\n  2-Horas Trabajadas\n  3-Sueldo\n", "Opcion invalida\n", 1, 3, 3);
		switch(opcion)
		{
		case 1:
			utn_getNombre(bufferNombre,NOMBRE_LEN,"\nIngrese el nuevo nombre: ","Nombre invalido\n",3);
			employee_setNombre(this,bufferNombre);
			retorno=0;
			break;
		case 2:
			utn_getNumero(&bufferHorasTrabajadas,"\nIngrese la nueva cantidad de horas trabajadas: ","Numero invalido\n",1,999,3);
			employee_setHorasTrabajadas(this,bufferHorasTrabajadas);
			retorno=0;
			break;
		case 3:
			utn_getNumero(&bufferSueldo,"\nIngrese el nuevo sueldo: ","Numero invalido\n",1,500000,3);
			employee_setSueldo(this,bufferSueldo);
			retorno=0;
			break;
		}
	}
	return retorno;
}









static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
