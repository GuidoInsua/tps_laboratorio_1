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

Jugador* jug_new()
{

	return (Jugador*) calloc(1,sizeof(Jugador));
}

//-----------------------------------------------------------------------------------------------

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* unJugador = NULL;

	unJugador = jug_new();

	if(unJugador != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL)
	{
		if( jug_setId(unJugador,atoi(idStr)) != 0 || jug_setNombreCompleto(unJugador, nombreCompletoStr) != 0 ||
			jug_setEdad(unJugador,atoi(edadStr)) != 0 || jug_setPosicion(unJugador, posicionStr) != 0 ||
			jug_setNacionalidad(unJugador, nacionalidadStr) != 0 || jug_setIdSeleccion(unJugador, atoi(idSelccionStr)) != 0)
		{
			jug_delete(unJugador);
			unJugador = NULL;
		}
	}

	return unJugador;
}

//-----------------------------------------------------------------------------------------------

void jug_delete(Jugador* this)
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

int jug_setId(Jugador* this,int id)
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

int jug_getId(Jugador* this,int* id)
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

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno;

	retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(this->nombreCompleto,nombreCompleto);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno;

	retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno;

	retorno = -1;

	if(this != NULL && posicion >= 0)
	{
		strcpy(this->posicion,posicion);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno;

	retorno = -1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(posicion,this->posicion);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno;

	retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(this->nacionalidad,nacionalidad);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno;

	retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad,this->nacionalidad);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int jug_setEdad(Jugador* this,int edad)
{
	int retorno;

	retorno = -1;

	if(this != NULL && edad >= 0)
	{
		this->edad = edad;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno;

	retorno = -1;

	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno;

	retorno = -1;

	if(this != NULL && idSeleccion >= 0)
	{
		this->idSeleccion = idSeleccion;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno;

	retorno = -1;

	if(this != NULL && idSeleccion != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------
