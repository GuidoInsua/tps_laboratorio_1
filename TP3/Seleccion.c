
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Controller.h"
#include "parser.h"
#include "funcionesDeUsuario.h"
#include "funcionesDeIngreso.h"

//-----------------------------------------------------------------------------------------------

Seleccion* selec_new()
{

	return (Seleccion*) calloc(1,sizeof(Seleccion));
}

//-----------------------------------------------------------------------------------------------

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* unaSeleccion = NULL;

	unaSeleccion = selec_new();

	if(unaSeleccion != NULL)
	{
		if( selec_setId(unaSeleccion, atoi(idStr)) != 0 || selec_setPais(unaSeleccion, paisStr) != 0 ||
			selec_setConfederacion(unaSeleccion, confederacionStr) != 0 || selec_setConvocados(unaSeleccion, atoi(convocadosStr)) != 0)
		{
			selec_delete(unaSeleccion);
			unaSeleccion = NULL;
		}
	}

	return unaSeleccion;
}

//-----------------------------------------------------------------------------------------------

void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
	else
	{
		printf("\nERROR, can't free NULL");
	}
}

//-----------------------------------------------------------------------------------------------

int selec_setId(Seleccion* this,int id)
{
	int retorno;

	retorno = -1;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int selec_getId(Seleccion* this,int* id)
{
	int retorno;

	retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int selec_setPais(Seleccion* this,char* pais)
{
	int retorno;

	retorno = -1;

	if(this != NULL && pais != NULL)
	{
		strcpy(this->pais,pais);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno;

	retorno = -1;

	if(this != NULL && pais != NULL)
	{
		strcpy(pais,this->pais);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int selec_setConfederacion(Seleccion* this,char* confederacion)
{
	int retorno;

	retorno = -1;

	if(this != NULL && confederacion != NULL)
	{
		strcpy(this->confederacion,confederacion);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno;

	retorno = -1;

	if(this != NULL && confederacion != NULL)
	{
		strcpy(confederacion,this->confederacion);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno;

	retorno = -1;

	if(this != NULL && convocados >= 0)
	{
		this->convocados = convocados;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno;

	retorno = -1;

	if(this != NULL && convocados >= 0)
	{
		*convocados = this->convocados;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------
