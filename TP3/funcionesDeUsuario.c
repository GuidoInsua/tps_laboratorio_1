
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

int mostrarMenu(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------+");
		printf("\n|\t %-*s|",20,"  MENU");
		printf("\n+----------------------------+");
		printf("\n| %-*s|",27,"1. Cargar archivos");
		printf("\n| %-*s|",27,"2. Alta jugador");
		printf("\n| %-*s|",27,"3. Modificar jugador");
		printf("\n| %-*s|",27,"4. Baja Jugador");
		printf("\n| %-*s|",27,"5. Listados");
		printf("\n| %-*s|",27,"6. Convocar jugadores");
		printf("\n| %-*s|",27,"7. Ordenar y listar");
		printf("\n| %-*s|",27,"8. Generar archivo binario");
		printf("\n| %-*s|",27,"9. Cargar archivo binario");
		printf("\n| %-*s|",27,"10. Guardar archivos .csv");
		printf("\n| %-*s|",27,"11. Salir");
		printf("\n+----------------------------+");

		pedirEntero(&buffer, 1, 11, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 11");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int pedirDatosJugador(char* nombre,char* edad,char* posicion,char* nacionalidad,int tamNombre,int tamCadena)
{
	int retorno;
	char bufferNombre[tamNombre];
	int bufferEdad;
	char bufferPosicion[tamCadena];
	char bufferNacionalidad[tamCadena];

	retorno = -1;

	if(nombre != NULL && edad != NULL && posicion != NULL && nacionalidad != NULL)
	{
		pedirStringAlfabetico(bufferNombre, tamNombre, "\nIngrese el nombre completo del jugador: ", "\nERROR, Ingrese solo letras y no mas de 100", 's');
		pedirEntero(&bufferEdad, 18, 100, "\nIngrese la edad del jugador: ", "\nERROR, Ingrese un numero entre 18 y 100");
		pedirStringAlfabetico(bufferPosicion, tamCadena, "\nIngrese la posicion del jugador: ", "\nERROR, Ingrese solo letras y no mas de 30", 's');
		pedirStringAlfabetico(bufferNacionalidad, tamCadena, "\nIngrese la nacionalidad del jugador: ", "\nERROR, Ingrese solo letras y no mas de 30", 's');

		convertirUprLwrExtendido(bufferNombre, tamNombre);
		convertirUprLwrExtendido(bufferPosicion, tamCadena);
		convertirUprLwrExtendido(bufferNacionalidad, tamCadena);

		strcpy(nombre,bufferNombre);
		itoa(bufferEdad,edad,10);
		strcpy(posicion,bufferPosicion);
		strcpy(nacionalidad,bufferNacionalidad);

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int mostrarMenuListados(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------+");
		printf("\n|\t %-*s|",20,"  MENU");
		printf("\n+----------------------------+");
		printf("\n| %-*s|",27,"1. Listar jugadores");
		printf("\n| %-*s|",27,"2. Listar selecciones");
		printf("\n| %-*s|",27,"3. Jugadores convocados");
		printf("\n| %-*s|",27,"4. Volver");
		printf("\n+----------------------------+");

		pedirEntero(&buffer, 1, 4, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 4");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int mostrarListados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno;
	int opcion;

	retorno = -1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		do
		{
			mostrarMenuListados(&opcion);

			switch(opcion)
			{
				case 1: //Listar jugadores

					ll_sort(pArrayListJugador, ordenarJugadorPorId, 1);
					controller_listarJugadores(pArrayListJugador,pArrayListSeleccion);
				break;

				case 2: //Listar selecciones

					ll_sort(pArrayListSeleccion, ordenarSeleccionPorId, 1);
					controller_listarSelecciones(pArrayListSeleccion);
				break;

				case 3: //Listar convocados

					ll_sort(pArrayListJugador, ordenarJugadorPorId, 1);
					controller_listarJugadoresConvocados(pArrayListJugador,pArrayListSeleccion);
				break;

				default:

					printf("\nVolviendo...");
				break;
			}

		}while(opcion != 4);

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int mostrarMenuModificacion(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------+");
		printf("\n|\t %-*s|",20,"  MENU");
		printf("\n+----------------------------+");
		printf("\n| %-*s|",27,"1. Modificar nombre");
		printf("\n| %-*s|",27,"2. Modificar edad");
		printf("\n| %-*s|",27,"3. Modificar posicion");
		printf("\n| %-*s|",27,"4. Modificar nacionalidad");
		printf("\n| %-*s|",27,"5. Volver");
		printf("\n+----------------------------+");

		pedirEntero(&buffer, 1, 5, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 5");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

Jugador* pedirUnJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion,int* indiceEncontrado)
{
	Jugador* unJugador = NULL;
	Jugador* auxJugador = NULL;
	int cantidadCargados;
	int idPedido;
	int bufferId;
	int existe;

	existe = 1;

	if(pArrayListJugador != NULL)
	{
		ll_sort(pArrayListJugador, ordenarJugadorPorId, 1);
		controller_listarJugadores(pArrayListJugador,pArrayListSeleccion);

		pedirEntero(&idPedido, 0, 10000, "\nIngrese el id del jugador: ", "\nERROR, Ingrese un numero entre 0 y 10.000");

		cantidadCargados = ll_len(pArrayListJugador);

		for(int i=0;i<cantidadCargados;i++)
		{
			auxJugador = ll_get(pArrayListJugador, i);

			jug_getId(auxJugador, &bufferId);

			if(idPedido == bufferId)
			{
				unJugador = auxJugador;
				*indiceEncontrado = i;
				existe = 0;
				break;
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

int modificarNombreJugador(Jugador* unJugador,int tamNombre)
{
	int retorno;
	char bufferNombre[tamNombre];
	char continuar;

	retorno = -1;

	if(unJugador != NULL && tamNombre > 0)
	{
		pedirStringAlfabetico(bufferNombre, tamNombre, "\nIngrese el nuevo nombre del jugador: ", "\nERROR, Ingrese solo letras y no mas de 100", 's');

		pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea modificar el nombre? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

		if(continuar == 's')
		{
			convertirUprLwrExtendido(bufferNombre, tamNombre);

			jug_setNombreCompleto(unJugador, bufferNombre);
			printf("\nModificacion exitosa");
			retorno = 0;
		}
		else
		{
			printf("\nModificacion cancelada");
			retorno = 1;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int modificarEdadJugador(Jugador* unJugador)
{
	int retorno;
	int bufferEdad;
	char continuar;

	retorno = -1;

	if(unJugador != NULL)
	{
		pedirEntero(&bufferEdad, 18, 100, "\nIngrese la nueva edad del jugador: ", "\nERROR, Ingrese un numero entre 18 y 100");

		pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea modificar el nombre? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

		if(continuar == 's')
		{
			jug_setEdad(unJugador, bufferEdad);
			printf("\nModificacion exitosa");
			retorno = 0;
		}
		else
		{
			printf("\nModificacion cancelada");
			retorno = 1;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int modificarPosicionJugador(Jugador* unJugador,int tamPosicion)
{
	int retorno;
	char bufferPosicion[tamPosicion];
	char continuar;

	retorno = -1;

	if(unJugador != NULL && tamPosicion > 0)
	{
		pedirStringAlfabetico(bufferPosicion, tamPosicion, "\nIngrese la nueva posicion del jugador: ", "\nERROR, Ingrese solo letras y no mas de 30", 's');

		pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea modificar el nombre? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

		if(continuar == 's')
		{
			convertirUprLwrExtendido(bufferPosicion, tamPosicion);

			jug_setPosicion(unJugador, bufferPosicion);
			printf("\nModificacion exitosa");
			retorno = 0;
		}
		else
		{
			printf("\nModificacion cancelada");
			retorno = 1;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int modificarNacionalidadJugador(Jugador* unJugador,int tamNacionalidad)
{
	int retorno;
	char bufferNacionalidad[tamNacionalidad];
	char continuar;

	retorno = -1;

	if(unJugador != NULL && tamNacionalidad > 0)
	{
		pedirStringAlfabetico(bufferNacionalidad, tamNacionalidad, "\nIngrese la nueva nacionalidad del jugador: ", "\nERROR, Ingrese solo letras y no mas de 30", 's');

		pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea modificar el nombre? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

		if(continuar == 's')
		{
			convertirUprLwrExtendido(bufferNacionalidad, tamNacionalidad);

			jug_setNacionalidad(unJugador, bufferNacionalidad);
			printf("\nModificacion exitosa");
			retorno = 0;
		}
		else
		{
			printf("\nModificacion cancelada");
			retorno = 1;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int mostrarMenuConvocar(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------+");
		printf("\n|\t %-*s|",20,"  MENU");
		printf("\n+----------------------------+");
		printf("\n| %-*s|",27,"1. Convocar jugador");
		printf("\n| %-*s|",27,"2. Quitar de seleccion");
		printf("\n| %-*s|",27,"3. Volver");
		printf("\n+----------------------------+");

		pedirEntero(&buffer, 1, 3, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 3");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int mostrarOpcionConvocar(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno;
	int opcion;

	retorno = -1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		do
		{
			mostrarMenuConvocar(&opcion);

			switch(opcion)
			{
				case 1: //Convocar

					controller_convocarJugador(pArrayListJugador, pArrayListSeleccion);
				break;

				case 2: //Quitar seleccion

					controller_quitarJugadorSeleccion(pArrayListJugador, pArrayListSeleccion);
				break;

				default:

					printf("\nVolviendo...");
				break;
			}

		}while(opcion != 3);

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

Seleccion* pedirUnaSeleccion(LinkedList* pArrayListSeleccion,int* indiceEncontrado)
{
	Seleccion* unaSeleccion = NULL;
	Seleccion* auxSeleccion = NULL;
	int cantidadCargados;
	int idPedido;
	int bufferId;
	int existe;

	existe = 1;

	if(pArrayListSeleccion != NULL)
	{
		ll_sort(pArrayListSeleccion, ordenarSeleccionPorId, 1);
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

Seleccion* buscarUnaSeleccion(LinkedList* pArrayListSeleccion,int idSeleccion)
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

int ordenarJugadorPorId(void* primerJugador,void* segundoJugador)
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

int ordenarSeleccionPorId(void* primerSeleccion,void* segundaSeleccion)
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

int ordenarJugadorPorNacionalidad(void* primerJugador,void* segundoJugador)
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

int ordenarJugadorPorNombre(void* primerJugador,void* segundoJugador)
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

int ordenarJugadorPorEdad(void* primerJugador,void* segundoJugador)
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

int ordenarSeleccionPorConfederacion(void* primerSeleccion,void* segundaSeleccion)
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

int mostrarMenuOrdenar(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------+");
		printf("\n|\t %-*s|",20,"  MENU");
		printf("\n+----------------------------+");
		printf("\n| %-*s|",27,"1. Jugadores por nacionalidad");
		printf("\n| %-*s|",27,"2. Selecciones por confederacion");
		printf("\n| %-*s|",27,"3. Jugadores por edad");
		printf("\n| %-*s|",27,"4. Jugadores por nombre");
		printf("\n| %-*s|",27,"5. Volver");
		printf("\n+----------------------------+");

		pedirEntero(&buffer, 1, 5, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 5");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int mostrarOpcionOrdenar(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno;
	int opcion;

	retorno = -1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		do
		{
			mostrarMenuOrdenar(&opcion);

			switch(opcion)
			{
				case 1: //Jugador por nacionalidad

					ll_sort(pArrayListJugador, ordenarJugadorPorNacionalidad, 1);
					controller_listarJugadores(pArrayListJugador,pArrayListSeleccion);
				break;

				case 2: //Seleccion por confederacion

					ll_sort(pArrayListSeleccion, ordenarSeleccionPorConfederacion, 1);
					controller_listarSelecciones(pArrayListSeleccion);
				break;

				case 3: //Jugador por edad

					ll_sort(pArrayListJugador, ordenarJugadorPorEdad, 1);
					controller_listarJugadores(pArrayListJugador,pArrayListSeleccion);
				break;

				case 4: //Jugador por nombre

					ll_sort(pArrayListJugador, ordenarJugadorPorNombre, 1);
					controller_listarJugadores(pArrayListJugador,pArrayListSeleccion);
				break;

				default:

					printf("\nVolviendo...");
				break;
			}

		}while(opcion != 5);

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

int mostrarOpcionesGuardarBinario(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno;
	int confederacion;

	retorno = -1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		printf("\n+---------------+");
		printf("\n|Confederaciones|");
		printf("\n+---------------+");
		printf("\n|  1 = AFC      |");
		printf("\n|  2 = CAF      |");
		printf("\n|  3 = CONCACAF |");
		printf("\n|  4 = CONMEBOL |");
		printf("\n|  5 = UEFA     |");
		printf("\n+---------------+");

		pedirEntero(&confederacion, 1, 5, "\nIngrese la confederacion que desea guardar: ", "\nERROR, Ingrese un numero entre 1 y 5");

		switch(confederacion)
		{
			case 1: //AFC

				controller_guardarJugadoresModoBinario("jugadoresAFC.bin", pArrayListJugador, pArrayListSeleccion, "AFC");
			break;

			case 2: //CAF

				controller_guardarJugadoresModoBinario("jugadoresCAF.bin", pArrayListJugador, pArrayListSeleccion, "CAF");
			break;

			case 3: //CONCACAF

				controller_guardarJugadoresModoBinario("jugadoresCONCACAF.bin", pArrayListJugador, pArrayListSeleccion, "CONCACAF");
			break;

			case 4: //CONMEBOL

				controller_guardarJugadoresModoBinario("jugadoresCONMEBOL.bin", pArrayListJugador, pArrayListSeleccion, "CONMEBOL");
			break;

			default: //UEFA

				controller_guardarJugadoresModoBinario("jugadoresUEFA.bin", pArrayListJugador, pArrayListSeleccion, "UEFA");
			break;
		}
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

int mostrarOpcionesCargarBinario(LinkedList* pArrayListSeleccion)
{
	int retorno;
	int confederacion;

	retorno = -1;

	if(pArrayListSeleccion != NULL)
	{
		printf("\n+---------------+");
		printf("\n|Confederaciones|");
		printf("\n+---------------+");
		printf("\n|  1 = AFC      |");
		printf("\n|  2 = CAF      |");
		printf("\n|  3 = CONCACAF |");
		printf("\n|  4 = CONMEBOL |");
		printf("\n|  5 = UEFA     |");
		printf("\n+---------------+");

		pedirEntero(&confederacion, 1, 5, "\nIngrese la confederacion que desea cargar: ", "\nERROR, Ingrese un numero entre 1 y 5");

		switch(confederacion)
		{
			case 1: //AFC

				controller_cargarJugadoresDesdeBinario("jugadoresAFC.bin", pArrayListSeleccion);
			break;

			case 2: //CAF

				controller_cargarJugadoresDesdeBinario("jugadoresCAF.bin", pArrayListSeleccion);
			break;

			case 3: //CONCACAF

				controller_cargarJugadoresDesdeBinario("jugadoresCONCACAF.bin", pArrayListSeleccion);
			break;

			case 4: //CONMEBOL

				controller_cargarJugadoresDesdeBinario("jugadoresCONMEBOL.bin", pArrayListSeleccion);
			break;

			default: //UEFA

				controller_cargarJugadoresDesdeBinario("jugadoresUEFA.bin", pArrayListSeleccion);
			break;
		}
	}

    return retorno;
}
