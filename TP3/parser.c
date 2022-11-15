
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

/// \fn int parser_JugadorFromText(FILE*, LinkedList*)
/// \brief
///
/// \param pFile
/// \param pArrayListJugador
/// \return
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno;
	int cantidad;
	char buffer[6][200];
	Jugador* unJugador = NULL;

	retorno = -1;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		fscanf(pFile,"%[^\n]\n",*(buffer+0)); //Falsa lectura

		while(!feof(pFile))
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4),*(buffer+5));

			if(cantidad == 6)
			{
				unJugador = jug_newParametros(*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4),*(buffer+5));

				if(unJugador != NULL)
				{
					ll_add(pArrayListJugador,(Jugador*)unJugador);
					retorno = 0;
				}
				else
				{
					printf("\nERROR");
					retorno = 1;
				}
			}
			else
			{
				jug_delete(unJugador);
				unJugador = NULL;
				break;
			}
		}
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int parser_JugadorFromBinary(FILE*, LinkedList*)
/// \brief
///
/// \param pFile
/// \param pArrayListSeleccion
/// \return
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno;
	Jugador* unJugador = NULL;
	int cantidad;

	retorno = -1;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		unJugador = (Jugador*)malloc(sizeof(Jugador)*1);
		if(unJugador != NULL)
		{
			retorno = 1;

			fseek(pFile, 0, SEEK_SET);

			printf("\n+-----+------------------------------+----+-------------------------+-----------------+--------------------+\n");
			printf("| %-*s| %-*s|%-*s| %-*s| %-*s| %-*s|\n",4,"ID",29,"Nombre",4,"Edad",24,"Posicion",16,"Nacionalidad",19,"Seleccion");
			printf("+-----+------------------------------+----+-------------------------+-----------------+--------------------+\n");

			while(!feof(pFile))
			{
				cantidad = fread(unJugador,sizeof(Jugador),1,pFile);
				if(cantidad == 1)
				{
					controller_listarUnJugador(unJugador, pArrayListSeleccion,'n');
					retorno = 0;
				}
			}

			printf("+-----+------------------------------+----+-------------------------+-----------------+--------------------+\n");
		}
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int parser_SeleccionFromText(FILE*, LinkedList*)
/// \brief
///
/// \param pFile
/// \param pArrayListSeleccion
/// \return
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno;
	int cantidad;
	char buffer[6][200];
	Seleccion* unaSeleccion = NULL;

	retorno = -1;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		fscanf(pFile,"%[^\n]\n",*(buffer+0)); //Falsa lectura

		while(!feof(pFile))
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));

			if(cantidad == 4)
			{
				unaSeleccion = selec_newParametros(*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));

				if(unaSeleccion != NULL)
				{
					ll_add(pArrayListSeleccion,(Seleccion*)unaSeleccion);
					retorno = 0;
				}
				else
				{
					printf("\nERROR");
					retorno = 1;
				}
			}
			else
			{
				selec_delete(unaSeleccion);
				unaSeleccion = NULL;
				break;
			}
		}
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int parser_idFromText(FILE*, int*)
/// \brief
///
/// \param pFile
/// \param idJugadorAutoIncremental
/// \return
int parser_idFromText(FILE* pFile,int* idJugadorAutoIncremental)
{
	int cantidad;
	char id[20];
	int retorno;

	retorno = -1;

	if(pFile != NULL && idJugadorAutoIncremental != NULL)
	{
		cantidad = fscanf(pFile,"%[^\n]",id);

		if(cantidad == 1)
		{
			*idJugadorAutoIncremental = atoi(id);
			retorno = 0;
		}
		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int parser_JugadorToBinary(FILE*, LinkedList*, LinkedList*, char*)
/// \brief
///
/// \param pFile
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \param confederacion
/// \return
int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, char* confederacion)
{
	int retorno;
	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;
	int idSeleccion;
	char nombreConfederacion[TAMCADENA];

	retorno = -1;

	if(pFile != NULL && pArrayListJugador != NULL && pArrayListSeleccion != NULL && confederacion != NULL)
	{
		retorno = 1;

		for(int i=0;i<ll_len(pArrayListJugador);i++)
		{
			unJugador = ll_get(pArrayListJugador, i);

			jug_getIdSeleccion(unJugador, &idSeleccion);

			if(idSeleccion != 0)
			{
				unaSeleccion = selec_buscarUnaSeleccion(pArrayListSeleccion, idSeleccion);

				selec_getConfederacion(unaSeleccion, nombreConfederacion);

				if(strcmp(nombreConfederacion,confederacion) == 0)
				{
					fwrite(unJugador,sizeof(Jugador),1,pFile);
					retorno = 0;
				}
			}
		}
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int parser_JugadorToText(FILE*, LinkedList*)
/// \brief
///
/// \param pFile
/// \param pArrayListJugador
/// \return
int parser_JugadorToText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno;
	char buffer[6][200];
	Jugador* unJugador = NULL;
	int id;
	int edad;
	int idSeleccion;

	retorno = -1;

	if(pFile != NULL && pArrayListJugador != NULL)
	{

		fprintf(pFile,"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");

		for(int i=0;i<ll_len(pArrayListJugador);i++)
		{
			unJugador = ll_get(pArrayListJugador, i);

			jug_getId(unJugador, &id);
			jug_getNombreCompleto(unJugador, *(buffer+1));
			jug_getEdad(unJugador, &edad);
			jug_getPosicion(unJugador, *(buffer+3));
			jug_getNacionalidad(unJugador, *(buffer+4));
			jug_getIdSeleccion(unJugador, &idSeleccion);

			itoa(id,*(buffer+0),10);
			itoa(edad,*(buffer+2),10);
			itoa(idSeleccion,*(buffer+5),10);

			fprintf(pFile,"%s,%s,%s,%s,%s,%s\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4),*(buffer+5));
		}

		retorno = 0;
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int parser_SeleccionToText(FILE*, LinkedList*)
/// \brief
///
/// \param pFile
/// \param pArrayListSeleccion
/// \return
int parser_SeleccionToText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno;
	char buffer[4][200];
	Seleccion* unaSeleccion = NULL;
	int id;
	int convocados;

	retorno = -1;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{

		fprintf(pFile,"id,pais,confederacion,convocados\n");

		for(int i=0;i<ll_len(pArrayListSeleccion);i++)
		{
			unaSeleccion = ll_get(pArrayListSeleccion, i);

			selec_getId(unaSeleccion, &id);
			selec_getPais(unaSeleccion, *(buffer+1));
			selec_getConfederacion(unaSeleccion, *(buffer+2));
			selec_getConvocados(unaSeleccion, &convocados);

			itoa(id,*(buffer+0),10);
			itoa(convocados,*(buffer+3),10);

			fprintf(pFile,"%s,%s,%s,%s\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));
		}

		retorno = 0;
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int parser_idToText(FILE*, int)
/// \brief
///
/// \param pFile
/// \param idJugadorAutoIncremental
/// \return
int parser_idToText(FILE* pFile,int idJugadorAutoIncremental)
{
	char id[20];
	int retorno;

	retorno = -1;

	if(pFile != NULL && idJugadorAutoIncremental > 0)
	{
		itoa(idJugadorAutoIncremental,id,10);

		fprintf(pFile,id);

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

