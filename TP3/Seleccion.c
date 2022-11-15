
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

/// \fn Seleccion selec_new*()
/// \brief
///
/// \return
Seleccion* selec_new()
{

	return (Seleccion*) calloc(1,sizeof(Seleccion));
}

//-----------------------------------------------------------------------------------------------

/// \fn Seleccion selec_newParametros*(char*, char*, char*, char*)
/// \brief
///
/// \param idStr
/// \param paisStr
/// \param confederacionStr
/// \param convocadosStr
/// \return
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* unaSeleccion = NULL;

	if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL)
	{
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
	}

	return unaSeleccion;
}

//-----------------------------------------------------------------------------------------------

/// \fn void selec_delete(Seleccion*)
/// \brief
///
/// \param this
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

/// \fn int selec_setId(Seleccion*, int)
/// \brief
///
/// \param this
/// \param id
/// \return
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

/// \fn int selec_getId(Seleccion*, int*)
/// \brief
///
/// \param this
/// \param id
/// \return
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

/// \fn int selec_setPais(Seleccion*, char*)
/// \brief
///
/// \param this
/// \param pais
/// \return
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

/// \fn int selec_getPais(Seleccion*, char*)
/// \brief
///
/// \param this
/// \param pais
/// \return
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

/// \fn int selec_setConfederacion(Seleccion*, char*)
/// \brief
///
/// \param this
/// \param confederacion
/// \return
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

/// \fn int selec_getConfederacion(Seleccion*, char*)
/// \brief
///
/// \param this
/// \param confederacion
/// \return
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

/// \fn int selec_setConvocados(Seleccion*, int)
/// \brief
///
/// \param this
/// \param convocados
/// \return
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

/// \fn int selec_getConvocados(Seleccion*, int*)
/// \brief
///
/// \param this
/// \param convocados
/// \return
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

/// \fn Seleccion selec_pedirUnaSeleccion*(LinkedList*, int*)
/// \brief
///
/// \param pArrayListSeleccion
/// \param indiceEncontrado
/// \return
Seleccion* selec_pedirUnaSeleccion(LinkedList* pArrayListSeleccion,int* indiceEncontrado)
{
	Seleccion* unaSeleccion = NULL;
	Seleccion* auxSeleccion = NULL;
	int cantidadCargados;
	int idPedido;
	int bufferId;
	int existe;

	existe = 1;

	if(pArrayListSeleccion != NULL && indiceEncontrado != NULL)
	{
		ll_sort(pArrayListSeleccion, selec_ordenarSeleccionPorId, 1);
		controller_listarSelecciones(pArrayListSeleccion);

		pedirEntero(&idPedido, 0, 10000, "\nIngrese el id de la seleccion: ", "\nERROR, Ingrese un numero entre 0 y 10.000");

		cantidadCargados = ll_len(pArrayListSeleccion);

		for(int i=0;i<cantidadCargados;i++)
		{
			auxSeleccion = ll_get(pArrayListSeleccion, i);

			selec_getId(auxSeleccion, &bufferId);

			if(idPedido == bufferId)
			{
				unaSeleccion = auxSeleccion;
				*indiceEncontrado = i;
				existe = 0;
				break;
			}
		}

		if(existe != 0)
		{
			printf("\nERROR, El id ingresado no pertenece a ninguna seleccion");
		}
	}

	return unaSeleccion;
}

//-----------------------------------------------------------------------------------------------

/// \fn Seleccion selec_buscarUnaSeleccion*(LinkedList*, int)
/// \brief
///
/// \param pArrayListSeleccion
/// \param idSeleccion
/// \return
Seleccion* selec_buscarUnaSeleccion(LinkedList* pArrayListSeleccion,int idSeleccion)
{
	Seleccion* unaSeleccion = NULL;
	Seleccion* auxSeleccion = NULL;
	int cantidadCargados;
	int bufferId;

	if(pArrayListSeleccion != NULL)
	{
		cantidadCargados = ll_len(pArrayListSeleccion);

		for(int i=0;i<cantidadCargados;i++)
		{
			auxSeleccion = ll_get(pArrayListSeleccion, i);

			selec_getId(auxSeleccion, &bufferId);

			if(idSeleccion == bufferId)
			{
				unaSeleccion = auxSeleccion;
				break;
			}
		}
	}

	return unaSeleccion;
}

//-----------------------------------------------------------------------------------------------

/// \fn int selec_ordenarSeleccionPorId(void*, void*)
/// \brief
///
/// \param primerSeleccion
/// \param segundaSeleccion
/// \return
int selec_ordenarSeleccionPorId(void* primerSeleccion,void* segundaSeleccion)
{
	int primerId;
	int segundoId;

	if(primerSeleccion != NULL && segundaSeleccion != NULL)
	{
		selec_getId(primerSeleccion, &primerId);
		selec_getId(segundaSeleccion, &segundoId);

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

/// \fn int selec_ordenarSeleccionPorConfederacion(void*, void*)
/// \brief
///
/// \param primerSeleccion
/// \param segundaSeleccion
/// \return
int selec_ordenarSeleccionPorConfederacion(void* primerSeleccion,void* segundaSeleccion)
{
	char primerConfederacion[TAMNOMBRE];
	char segundaConfederacion[TAMNOMBRE];

	if(primerSeleccion != NULL && segundaSeleccion != NULL)
	{
		selec_getConfederacion(primerSeleccion, primerConfederacion);
		selec_getConfederacion(segundaSeleccion, segundaConfederacion);

		if(strcmp(primerConfederacion,segundaConfederacion) > 0)
		{
			return 1;
		}
		if(strcmp(primerConfederacion,segundaConfederacion) < 0)
		{
			return -1;
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------
