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

/// \fn Jugador jug_new*()
/// \brief
///
/// \return
Jugador* jug_new()
{

	return (Jugador*) calloc(1,sizeof(Jugador));
}

//-----------------------------------------------------------------------------------------------

/// \fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
/// \brief
///
/// \param idStr
/// \param nombreCompletoStr
/// \param edadStr
/// \param posicionStr
/// \param nacionalidadStr
/// \param idSelccionStr
/// \return
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* unJugador = NULL;

	if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL)
	{
		unJugador = jug_new();

		if(unJugador != NULL)
		{
			if( jug_setId(unJugador,atoi(idStr)) != 0 || jug_setNombreCompleto(unJugador, nombreCompletoStr) != 0 ||
				jug_setEdad(unJugador,atoi(edadStr)) != 0 || jug_setPosicion(unJugador, posicionStr) != 0 ||
				jug_setNacionalidad(unJugador, nacionalidadStr) != 0 || jug_setIdSeleccion(unJugador, atoi(idSelccionStr)) != 0)
			{
				jug_delete(unJugador);
				unJugador = NULL;
			}
		}
	}

	return unJugador;
}

//-----------------------------------------------------------------------------------------------

/// \fn void jug_delete(Jugador*)
/// \brief
///
/// \param this
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

/// \fn int jug_setId(Jugador*, int)
/// \brief
///
/// \param this
/// \param id
/// \return
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

/// \fn int jug_getId(Jugador*, int*)
/// \brief
///
/// \param this
/// \param id
/// \return
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

/// \fn int jug_setNombreCompleto(Jugador*, char*)
/// \brief
///
/// \param this
/// \param nombreCompleto
/// \return
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

/// \fn int jug_getNombreCompleto(Jugador*, char*)
/// \brief
///
/// \param this
/// \param nombreCompleto
/// \return
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

/// \fn int jug_setPosicion(Jugador*, char*)
/// \brief
///
/// \param this
/// \param posicion
/// \return
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

/// \fn int jug_getPosicion(Jugador*, char*)
/// \brief
///
/// \param this
/// \param posicion
/// \return
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

/// \fn int jug_setNacionalidad(Jugador*, char*)
/// \brief
///
/// \param this
/// \param nacionalidad
/// \return
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

/// \fn int jug_getNacionalidad(Jugador*, char*)
/// \brief
///
/// \param this
/// \param nacionalidad
/// \return
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

/// \fn int jug_setEdad(Jugador*, int)
/// \brief
///
/// \param this
/// \param edad
/// \return
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

/// \fn int jug_getEdad(Jugador*, int*)
/// \brief
///
/// \param this
/// \param edad
/// \return
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

/// \fn int jug_setIdSeleccion(Jugador*, int)
/// \brief
///
/// \param this
/// \param idSeleccion
/// \return
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

/// \fn int jug_getIdSeleccion(Jugador*, int*)
/// \brief
///
/// \param this
/// \param idSeleccion
/// \return
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

/// \fn Jugador jug_pedirUnJugador*(LinkedList*, LinkedList*, int*, char)
/// \brief
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \param indiceEncontrado
/// \param convocado
/// \return
Jugador* jug_pedirUnJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion,int* indiceEncontrado,char convocado)
{
	Jugador* unJugador = NULL;
	Jugador* auxJugador = NULL;
	int cantidadCargados;
	int idPedido;
	int bufferId;
	int existe;
	int estaConvocado;

	existe = 1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL && indiceEncontrado != NULL)
	{
		ll_sort(pArrayListJugador, jug_ordenarJugadorPorId, 1);
		controller_listarJugadores(pArrayListJugador,pArrayListSeleccion,convocado);

		pedirEntero(&idPedido, 0, 10000, "\nIngrese el id del jugador: ", "\nERROR, Ingrese un numero entre 0 y 10.000");

		cantidadCargados = ll_len(pArrayListJugador);

		for(int i=0;i<cantidadCargados;i++)
		{
			auxJugador = ll_get(pArrayListJugador, i);

			jug_getId(auxJugador, &bufferId);

			if(idPedido == bufferId)
			{
				jug_getIdSeleccion(unJugador, &estaConvocado);

				if((convocado == 's' && estaConvocado != 0) || convocado != 's')
				{
					unJugador = auxJugador;
					*indiceEncontrado = i;
					existe = 0;
					break;
				}
			}
		}

		if(existe != 0)
		{
			printf("\nERROR, El id ingresado no pertenece a ningun jugador cargado");
		}
	}

	return unJugador;
}

//-----------------------------------------------------------------------------------------------

/// \fn int jug_ordenarJugadorPorId(void*, void*)
/// \brief
///
/// \param primerJugador
/// \param segundoJugador
/// \return
int jug_ordenarJugadorPorId(void* primerJugador,void* segundoJugador)
{
	int primerId;
	int segundoId;

	if(primerJugador != NULL && segundoJugador != NULL)
	{
		jug_getId(primerJugador, &primerId);
		jug_getId(segundoJugador, &segundoId);

		if(primerId > segundoId)
		{
			return 1;
		}
		if(primerId < segundoId)
		{
			return -1;
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------

/// \fn int jug_ordenarJugadorPorNacionalidad(void*, void*)
/// \brief
///
/// \param primerJugador
/// \param segundoJugador
/// \return
int jug_ordenarJugadorPorNacionalidad(void* primerJugador,void* segundoJugador)
{
	char primeraNacionalidad[TAMCADENA];
	char segundaNacionalidad[TAMCADENA];

	if(primerJugador != NULL && segundoJugador != NULL)
	{
		jug_getNacionalidad(primerJugador, primeraNacionalidad);
		jug_getNacionalidad(segundoJugador, segundaNacionalidad);

		if(strcmp(primeraNacionalidad,segundaNacionalidad) > 0)
		{
			return 1;
		}
		if(strcmp(primeraNacionalidad,segundaNacionalidad) < 0)
		{
			return -1;
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------

/// \fn int jug_ordenarJugadorPorNombre(void*, void*)
/// \brief
///
/// \param primerJugador
/// \param segundoJugador
/// \return
int jug_ordenarJugadorPorNombre(void* primerJugador,void* segundoJugador)
{
	char primerNombre[TAMNOMBRE];
	char segundoNombre[TAMNOMBRE];

	if(primerJugador != NULL && segundoJugador != NULL)
	{
		jug_getNombreCompleto(primerJugador, primerNombre);
		jug_getNombreCompleto(segundoJugador, segundoNombre);

		if(strcmp(primerNombre,segundoNombre) > 0)
		{
			return 1;
		}
		if(strcmp(primerNombre,segundoNombre) < 0)
		{
			return -1;
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------

/// \fn int jug_ordenarJugadorPorEdad(void*, void*)
/// \brief
///
/// \param primerJugador
/// \param segundoJugador
/// \return
int jug_ordenarJugadorPorEdad(void* primerJugador,void* segundoJugador)
{
	int primerEdad;
	int segundaEdad;

	if(primerJugador != NULL && segundoJugador != NULL)
	{
		jug_getEdad(primerJugador, &primerEdad);
		jug_getEdad(segundoJugador, &segundaEdad);

		if(primerEdad > segundaEdad)
		{
			return 1;
		}
		if(primerEdad < segundaEdad)
		{
			return -1;
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------
