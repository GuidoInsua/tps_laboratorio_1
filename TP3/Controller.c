
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

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* pFile;
	int retorno;

	retorno = -1;
	pFile=fopen(path,"r");

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		if(parser_JugadorFromText(pFile ,pArrayListJugador) == 0)
		{
			printf("\nJugadores cargados");
			retorno = 0;
		}
		else
		{
			printf("\nERROR, Jugadores no cargados");
			retorno = 1;
		}

		fclose(pFile);
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pFile;
	int retorno;

	retorno = -1;
	pFile=fopen(path,"rb");

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		retorno = parser_JugadorFromBinary(pFile, pArrayListSeleccion);

		if(retorno == 0)
		{
			printf("\nJugadores impresos");
		}
		else
		{
			printf("\nEl archivo esta vacio");
		}

		fclose(pFile);
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador,int* idAutoIncremental)
{
    int retorno;
    Jugador* unJugador = NULL;
    char id[20];
    char nombre[TAMNOMBRE];
    char edad[20];
    char posicion[TAMCADENA];
    char nacionalidad[TAMCADENA];
    char opcion;

    retorno = -1;

    if(pArrayListJugador != NULL)
    {
    	if(pedirDatosJugador(nombre, edad, posicion, nacionalidad, TAMNOMBRE, TAMCADENA) == 0)
    	{
    		pedirCharDosOpciones(&opcion, 's', 'n', "\nEsta seguro que desea ingresar este jugador? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

    		if(opcion == 's')
    		{
    			itoa(*idAutoIncremental,id,10);
    			unJugador = jug_newParametros(id, nombre, edad, posicion, nacionalidad, "0");

				if(unJugador != NULL)
				{
					ll_add(pArrayListJugador,(Jugador*)unJugador);
					printf("\nJugador cargado con exito");
					(*idAutoIncremental)++;
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
    			printf("\nCarga jugador cancelada");
    			retorno = 2;
    		}
    	}
    }

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno;
	int opcion;
	Jugador* unJugador = NULL;
	int indice;

	retorno = -1;

	if(pArrayListJugador != NULL)
	{
		unJugador = pedirUnJugador(pArrayListJugador,pArrayListSeleccion,&indice);

		if(unJugador != NULL)
		{
			do
			{
				mostrarMenuModificacion(&opcion);

				switch(opcion)
				{
					case 1:

						modificarNombreJugador(unJugador, TAMNOMBRE);
					break;

					case 2:

						modificarEdadJugador(unJugador);
					break;

					case 3:

						modificarPosicionJugador(unJugador, TAMCADENA);
					break;

					case 4:

						modificarNacionalidadJugador(unJugador, TAMCADENA);
					break;

					default:

						printf("\nVolviendo...");
					break;
				}

			}while(opcion != 5);

			retorno = 0;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno;
	Jugador* unJugador = NULL;
	char continuar;
	int indice;

	retorno = -1;

	if(pArrayListJugador != NULL)
	{
		unJugador = pedirUnJugador(pArrayListJugador,pArrayListSeleccion,&indice);

		if(unJugador != NULL)
		{
			pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea dar de baja al jugador? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

			if(continuar == 's')
			{
				ll_remove(pArrayListJugador,indice);
				printf("\nBaja exitosa");
				retorno = 0;
			}
			else
			{
				printf("\nBaja cancelada");
				retorno = 1;
			}
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno;
	int cantidadCargados;
	Jugador* unJugador = NULL;

	retorno = -1;

	if(pArrayListJugador != NULL)
	{
		cantidadCargados = ll_len(pArrayListJugador);

		printf("+-----+------------------------------+----+-------------------------+-----------------+--------------------+\n");
		printf("| %-*s| %-*s|%-*s| %-*s| %-*s| %-*s|\n",4,"ID",29,"Nombre",4,"Edad",24,"Posicion",16,"Nacionalidad",19,"Seleccion");
		printf("+-----+------------------------------+----+-------------------------+-----------------+--------------------+\n");

		for(int i=0;i<cantidadCargados;i++)
		{
			unJugador = ll_get(pArrayListJugador, i);

			controller_listarUnJugador(unJugador, pArrayListSeleccion);

			retorno = 0;
		}
		printf("+-----+------------------------------+----+-------------------------+-----------------+--------------------+\n");
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

//-----------------------------------------------------------------------------------------------

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* pFile;
	int retorno;

	retorno = -1;
	pFile=fopen(path,"w");

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		if(parser_JugadorToText(pFile ,pArrayListJugador) == 0)
		{
			printf("\nJugadores guardados");
			retorno = 0;
		}
		else
		{
			printf("\nERROR, Jugadores no guardados");
			retorno = 1;
		}

		fclose(pFile);
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, char* confederacion)
{
	FILE* pFile;
	int retorno;

	retorno = -1;
	pFile=fopen(path,"wb");

	if(pFile != NULL && pArrayListJugador != NULL && confederacion != NULL)
	{
		retorno = parser_JugadorToBinary(pFile, pArrayListJugador, pArrayListSeleccion, confederacion);

		if(retorno == 0)
		{
			printf("\nJugadores de %s guardados en binario",confederacion);
		}
		else
		{
			printf("\nArchivo creado pero no se encontraron jugadores convocados");
		}

		fclose(pFile);
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pFile;
	int retorno;

	retorno = -1;
	pFile=fopen(path,"r");

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		if(parser_SeleccionFromText(pFile, pArrayListSeleccion) == 0)
		{
			printf("\nSelecciones cargadas");
			retorno = 0;
		}
		else
		{
			printf("\nERROR, Selecciones no cargadas");
			retorno = 1;
		}

		fclose(pFile);
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}

//-----------------------------------------------------------------------------------------------

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno;
	Seleccion* unaSeleccion = NULL;
	int bufferId;
	char bufferPais[TAMCADENA];
	char bufferConfederacion[TAMCADENA];
	int bufferConvocados;
	int cantidadCargadas;

	retorno = -1;

	if(pArrayListSeleccion != NULL)
	{
		cantidadCargadas = ll_len(pArrayListSeleccion);

		printf("+-----+------------------------------+--------------------+----------+\n");
		printf("| %-*s| %-*s| %-*s|%-*s|\n",4,"ID",29,"Pais",19,"Confederacion",9,"Convocados");
		printf("+-----+------------------------------+--------------------+----------+\n");

		for(int i=0;i<cantidadCargadas;i++)
		{
			unaSeleccion = ll_get(pArrayListSeleccion, i);

			selec_getId(unaSeleccion, &bufferId);
			selec_getPais(unaSeleccion, bufferPais);
			selec_getConfederacion(unaSeleccion, bufferConfederacion);
			selec_getConvocados(unaSeleccion, &bufferConvocados);

			printf("| %-*d| %-*s| %-*s| %-*d|\n",4,bufferId,29,bufferPais,19,bufferConfederacion,9,bufferConvocados);
		}

		printf("+-----+------------------------------+--------------------+----------+\n");

		retorno = 0;
	}
	return retorno;
}

//-----------------------------------------------------------------------------------------------

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

//-----------------------------------------------------------------------------------------------

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pFile;
	int retorno;

	retorno = -1;
	pFile=fopen(path,"w");

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		if(parser_SeleccionToText(pFile ,pArrayListSeleccion) == 0)
		{
			printf("\nSelecciones guardadas");
			retorno = 0;
		}
		else
		{
			printf("\nERROR, Selecciones no guardadas");
			retorno = 1;
		}

		fclose(pFile);
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

int controller_cargarIdAutoIncrementalDesdeTexto(char* path,int* idJugadorAutoIncremental)
{
	FILE* pFile;
	int retorno;

	retorno = -1;

	pFile = fopen(path,"r");

	if(pFile != NULL && idJugadorAutoIncremental != NULL)
	{
		if(parser_idFromText(pFile, idJugadorAutoIncremental) == 0)
		{
			printf("\nId cargado");
			retorno = 0;
		}
		else
		{
			printf("\nERROR, Id no cargado");
			retorno = 1;
		}

		fclose(pFile);
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno;
	int cantidadCargados;

	retorno = -1;

	if(pArrayListJugador != NULL)
	{
		cantidadCargados = ll_len(pArrayListJugador);

		printf("+-----+------------------------------+----+-------------------------+-----------------+--------------------+\n");
		printf("| %-*s| %-*s|%-*s| %-*s| %-*s| %-*s|\n",4,"ID",29,"Nombre",4,"Edad",24,"Posicion",16,"Nacionalidad",19,"Seleccion");
		printf("+-----+------------------------------+----+-------------------------+-----------------+--------------------+\n");

		for(int i=0;i<cantidadCargados;i++)
		{
			retorno = controller_listarUnJugadorConvocado(pArrayListJugador, pArrayListSeleccion, i);
		}
		printf("+-----+------------------------------+----+-------------------------+-----------------+--------------------+\n");

		if(retorno == 1)
		{
			printf("\nNo se encontraron jugadores convocados");
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno;
	int indice;
	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;
	char continuar;
	int idSeleccion;
	int convocados;

	retorno = -1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		unJugador = pedirUnJugador(pArrayListJugador ,pArrayListSeleccion, &indice);

		if(unJugador != NULL)
		{
			jug_getIdSeleccion(unJugador, &idSeleccion);

			if(idSeleccion == 0)
			{
				unaSeleccion = pedirUnaSeleccion(pArrayListSeleccion, &indice);

				if(unaSeleccion != NULL)
				{
					selec_getConvocados(unaSeleccion, &convocados);

					if(convocados < 22)
					{
						pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere convocar al jugador? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
						if(continuar == 's')
						{
							selec_getId(unaSeleccion, &idSeleccion);
							jug_setIdSeleccion(unJugador, idSeleccion);
							selec_setConvocados(unaSeleccion, convocados+1);

							printf("\nJugador convocado con exito");
							retorno = 0;
						}
						else
						{
							printf("\nNo se convoco al jugador");
							retorno = 1;
						}
					}
					else
					{
						printf("\nERROR, La seleccion ingresada ya tiene 22 jugadores convocados, no puede convocar mas");
					}
				}
			}
			else
			{
				printf("\nERROR, El jugador ingresado ya esta convocado");
			}
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int controller_quitarJugadorSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno;
	int indice;
	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;
	char continuar;
	int idSeleccion;
	int convocados;

	retorno = -1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		unJugador = pedirUnJugador(pArrayListJugador, pArrayListSeleccion, &indice);

		if(unJugador != NULL)
		{
			jug_getIdSeleccion(unJugador, &idSeleccion);

			if(idSeleccion != 0)
			{
				unaSeleccion = buscarUnaSeleccion(pArrayListSeleccion, idSeleccion);

				if(unaSeleccion != NULL)
				{
					pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere quitar al jugador de la seleccion? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
					if(continuar == 's')
					{
						jug_setIdSeleccion(unJugador, 0);
						selec_getConvocados(unaSeleccion, &convocados);
						selec_setConvocados(unaSeleccion, convocados-1);

						printf("\nJugador removido de la seleccion con exito");
						retorno = 0;
					}
					else
					{
						printf("\nNo se quito al jugador de la seleccion");
						retorno = 1;
					}
				}
			}
			else
			{
				printf("\nERROR, El jugador ingresado no esta convocado");
			}
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int controller_listarUnJugador(Jugador* unJugador,LinkedList* pArrayListSeleccion)
{
	int retorno;
	Seleccion* unaSeleccion = NULL;
	int bufferId;
	char bufferNombreCompleto[TAMNOMBRE];
	int bufferEdad;
	char bufferPosicion[TAMCADENA];
	char bufferNacionalidad[TAMCADENA];
	int bufferIdSeleccion;
	char bufferNombreSeleccion[TAMCADENA];

	retorno = -1;

	if(unJugador != NULL && pArrayListSeleccion != NULL)
	{
		jug_getId(unJugador, &bufferId);
		jug_getNombreCompleto(unJugador, bufferNombreCompleto);
		jug_getEdad(unJugador, &bufferEdad);
		jug_getPosicion(unJugador, bufferPosicion);
		jug_getNacionalidad(unJugador, bufferNacionalidad);
		jug_getIdSeleccion(unJugador, &bufferIdSeleccion);

		if(bufferIdSeleccion == 0)
		{
			strcpy(bufferNombreSeleccion,"Sin convocar");
		}
		else
		{
			unaSeleccion = buscarUnaSeleccion(pArrayListSeleccion, bufferIdSeleccion);

			selec_getPais(unaSeleccion, bufferNombreSeleccion);
		}

		printf("| %-*d| %-*s| %-*d| %-*s| %-*s| %-*s|\n",4,bufferId,29,bufferNombreCompleto,3,bufferEdad,24,bufferPosicion,16,bufferNacionalidad,19,bufferNombreSeleccion);

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int controller_listarUnJugadorConvocado(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion,int indice)
{
	int retorno;
	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;
	int bufferId;
	char bufferNombreCompleto[TAMNOMBRE];
	int bufferEdad;
	char bufferPosicion[TAMCADENA];
	char bufferNacionalidad[TAMCADENA];
	int bufferIdSeleccion;
	char bufferNombreSeleccion[TAMCADENA];

	retorno = -1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL && indice >= 0)
	{
		retorno = 1;
		unJugador = ll_get(pArrayListJugador, indice);

		jug_getId(unJugador, &bufferId);
		jug_getNombreCompleto(unJugador, bufferNombreCompleto);
		jug_getEdad(unJugador, &bufferEdad);
		jug_getPosicion(unJugador, bufferPosicion);
		jug_getNacionalidad(unJugador, bufferNacionalidad);
		jug_getIdSeleccion(unJugador, &bufferIdSeleccion);

		if(bufferIdSeleccion != 0)
		{
			unaSeleccion = buscarUnaSeleccion(pArrayListSeleccion, bufferIdSeleccion);

			selec_getPais(unaSeleccion, bufferNombreSeleccion);

			printf("| %-*d| %-*s| %-*d| %-*s| %-*s| %-*s|\n",4,bufferId,29,bufferNombreCompleto,3,bufferEdad,24,bufferPosicion,16,bufferNacionalidad,19,bufferNombreSeleccion);

			retorno = 0;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int controller_guardarIdAutoIncrementalModoTexto(char* path,int idJugadorAutoIncremental)
{
	FILE* pFile;
	int retorno;

	retorno = -1;

	pFile = fopen(path,"w");

	if(pFile != NULL && idJugadorAutoIncremental != NULL)
	{
		if(parser_idToText(pFile, idJugadorAutoIncremental) == 0)
		{
			printf("\nId guardado");
			retorno = 0;
		}
		else
		{
			printf("\nERROR, Id no guardado");
			retorno = 1;
		}

		fclose(pFile);
	}

    return retorno;
}


//-----------------------------------------------------------------------------------------------
