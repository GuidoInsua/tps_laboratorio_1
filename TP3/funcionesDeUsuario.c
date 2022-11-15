
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

/// \fn int mostrarMenu(int*)
/// \brief Imprime el menu principal
///
/// \param opcion , puntero int por donde se pasa la eleccion
/// \return retorna 0 si todo sale bien o -1 si se pasa mal algun parametro
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

/// \fn int pedirPosicion(char*, char*, char*)
/// \brief
///
/// \param posicion
/// \param mensaje
/// \param mensajeError
/// \return
int pedirPosicion(char* posicion,char* mensaje,char* mensajeError)
{
	int retorno;
	char posiciones[11][200] = {"Portero","Defensa central","Lateral izquierdo","Lateral derecho","Pivote","Mediocentro","Mediocentro ofensivo","Mediapunta","Delantero centro","Interior derecho","Extremo derecho"};
	int opcionPosicion;

	retorno = -1;

	if(posicion != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("\n+--------------------------+");
		printf("\n|        Posiciones        |");
		printf("\n+--------------------------+");
		printf("\n| 1 = %-*s|",21,*(posiciones+0));
		printf("\n| 2 = %-*s|",21,*(posiciones+1));
		printf("\n| 3 = %-*s|",21,*(posiciones+2));
		printf("\n| 4 = %-*s|",21,*(posiciones+3));
		printf("\n| 5 = %-*s|",21,*(posiciones+4));
		printf("\n| 6 = %-*s|",21,*(posiciones+5));
		printf("\n| 7 = %-*s|",21,*(posiciones+6));
		printf("\n| 8 = %-*s|",21,*(posiciones+7));
		printf("\n| 9 = %-*s|",21,*(posiciones+8));
		printf("\n| 10 = %-*s|",20,*(posiciones+9));
		printf("\n| 11 = %-*s|",20,*(posiciones+10));
		printf("\n+--------------------------+");

		pedirEntero(&opcionPosicion, 1, 11, mensaje, mensajeError);

		strcpy(posicion,*(posiciones+opcionPosicion-1));

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int pedirNacionalidad(char*, char*, char*)
/// \brief
///
/// \param nacionalidad
/// \param mensaje
/// \param mensajeError
/// \return
int pedirNacionalidad(char* nacionalidad,char* mensaje,char* mensajeError)
{
	int retorno;
	char nacionalidades[12][200] = {"Aleman","Argentino","Austrialiano","Brasilero","Camerunes","Estado Unidense","Ingles","Mexicano","Portugues","Qatari","Senegales","Uruguayo"};
	int opcionNacionalidad;

	retorno = -1;

	if(nacionalidad != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("\n+--------------------------+");
		printf("\n|      Nacionalidades      |");
		printf("\n+--------------------------+");
		printf("\n| 1 = %-*s|",21,*(nacionalidades+0));
		printf("\n| 2 = %-*s|",21,*(nacionalidades+1));
		printf("\n| 3 = %-*s|",21,*(nacionalidades+2));
		printf("\n| 4 = %-*s|",21,*(nacionalidades+3));
		printf("\n| 5 = %-*s|",21,*(nacionalidades+4));
		printf("\n| 6 = %-*s|",21,*(nacionalidades+5));
		printf("\n| 7 = %-*s|",21,*(nacionalidades+6));
		printf("\n| 8 = %-*s|",21,*(nacionalidades+7));
		printf("\n| 9 = %-*s|",21,*(nacionalidades+8));
		printf("\n| 10 = %-*s|",20,*(nacionalidades+9));
		printf("\n| 11 = %-*s|",20,*(nacionalidades+10));
		printf("\n| 12 = %-*s|",20,*(nacionalidades+11));
		printf("\n+--------------------------+");

		pedirEntero(&opcionNacionalidad, 1, 11, mensaje, mensajeError);

		strcpy(nacionalidad,*(nacionalidades+opcionNacionalidad-1));

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int pedirDatosJugador(char*, char*, char*, char*, int)
/// \brief Pide el nombre, edad, posicion y nacionalidad de un jugador
///
/// \param nombre , char cadena por donde se pasa el nombre
/// \param edad , char cadena por donde se pasa la edad
/// \param posicion , char cadena por donde se pasa la posicion
/// \param nacionalidad , char cadena por donde se pasa la nacionalidad
/// \param tamNombre , int tamanio que puede tomar la cadena nombre
/// \return retorna 0 si sale todo bien o -1 si se pasa mal algun parametro
int pedirDatosJugador(char* nombre,char* edad,char* posicion,char* nacionalidad,int tamNombre)
{
	int retorno;
	char bufferNombre[tamNombre];
	int bufferEdad;
	char bufferPosicion[tamNombre];
	char bufferNacionalidad[tamNombre];

	retorno = -1;

	if(nombre != NULL && edad != NULL && posicion != NULL && nacionalidad != NULL && tamNombre > 0)
	{
		pedirStringAlfabetico(bufferNombre, tamNombre, "\nIngrese el nombre completo del jugador: ", "\nERROR, Ingrese solo letras y no mas de 100", 's');
		pedirEntero(&bufferEdad, 18, 100, "\nIngrese la edad del jugador: ", "\nERROR, Ingrese un numero entre 18 y 100");
		pedirPosicion(bufferPosicion, "\nIngrese la posicion del jugador: ", "\nERROR, Ingrese un numero del 1 al 11");
		pedirNacionalidad(bufferNacionalidad, "\nIngrese la nacionalidad del jugador: ", "\nERROR, Ingrese un numero entre 1 y 12");

		convertirUprLwrExtendido(bufferNombre, tamNombre);
		convertirUprLwrExtendido(bufferPosicion, tamNombre);
		convertirUprLwrExtendido(bufferNacionalidad, tamNombre);

		strcpy(nombre,bufferNombre);
		itoa(bufferEdad,edad,10);
		strcpy(posicion,bufferPosicion);
		strcpy(nacionalidad,bufferNacionalidad);

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int mostrarMenuListados(int*)
/// \brief Imprime el menu de opciones para listar
///
/// \param opcion , puntero int por donde se pasa la eleccion
/// \return retorna 0 si salio todo bien o -1 si se pasa mal algun parametro
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

/// \fn int mostrarListados(LinkedList*, LinkedList*)
/// \brief
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return
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

					ll_sort(pArrayListJugador, jug_ordenarJugadorPorId, 1);
					controller_listarJugadores(pArrayListJugador,pArrayListSeleccion,'n');
				break;

				case 2: //Listar selecciones

					ll_sort(pArrayListSeleccion, selec_ordenarSeleccionPorId, 1);
					controller_listarSelecciones(pArrayListSeleccion);
				break;

				case 3: //Listar convocados

					ll_sort(pArrayListJugador, jug_ordenarJugadorPorId, 1);
					controller_listarJugadores(pArrayListJugador,pArrayListSeleccion,'s');
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

/// \fn int mostrarMenuModificacion(int*)
/// \brief
///
/// \param opcion
/// \return
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

/// \fn int modificarNombreJugador(Jugador*, int)
/// \brief
///
/// \param unJugador
/// \param tamNombre
/// \return
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

/// \fn int modificarEdadJugador(Jugador*)
/// \brief
///
/// \param unJugador
/// \return
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

/// \fn int modificarPosicionJugador(Jugador*, int)
/// \brief
///
/// \param unJugador
/// \param tamPosicion
/// \return
int modificarPosicionJugador(Jugador* unJugador,int tamPosicion)
{
	int retorno;
	char bufferPosicion[tamPosicion];
	char continuar;

	retorno = -1;

	if(unJugador != NULL && tamPosicion > 0)
	{
		pedirPosicion(bufferPosicion, "\nIngrese la nueva posicion del jugador: ", "\nERROR, Ingrese un numero del 1 al 11");

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

/// \fn int modificarNacionalidadJugador(Jugador*, int)
/// \brief
///
/// \param unJugador
/// \param tamNacionalidad
/// \return
int modificarNacionalidadJugador(Jugador* unJugador,int tamNacionalidad)
{
	int retorno;
	char bufferNacionalidad[tamNacionalidad];
	char continuar;

	retorno = -1;

	if(unJugador != NULL && tamNacionalidad > 0)
	{
		pedirNacionalidad(bufferNacionalidad, "\nIngrese la nueva nacionalidad del jugador: ", "\nERROR, Ingrese un numero entre 1 y 12");

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

/// \fn int mostrarMenuConvocar(int*)
/// \brief
///
/// \param opcion
/// \return
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

/// \fn int mostrarOpcionConvocar(LinkedList*, LinkedList*)
/// \brief
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return
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

/// \fn int mostrarMenuOrdenar(int*)
/// \brief
///
/// \param opcion
/// \return
int mostrarMenuOrdenar(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------------+");
		printf("\n|\t      %-*s|",21,"  MENU");
		printf("\n+----------------------------------+");
		printf("\n| %-*s|",33,"1. Jugadores por nacionalidad");
		printf("\n| %-*s|",33,"2. Selecciones por confederacion");
		printf("\n| %-*s|",33,"3. Jugadores por edad");
		printf("\n| %-*s|",33,"4. Jugadores por nombre");
		printf("\n| %-*s|",33,"5. Volver");
		printf("\n+----------------------------------+");

		pedirEntero(&buffer, 1, 5, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 5");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int mostrarOpcionOrdenar(LinkedList*, LinkedList*)
/// \brief
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return
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

					ll_sort(pArrayListJugador, jug_ordenarJugadorPorNacionalidad, 1);
					controller_listarJugadores(pArrayListJugador,pArrayListSeleccion,'n');
				break;

				case 2: //Seleccion por confederacion

					ll_sort(pArrayListSeleccion, selec_ordenarSeleccionPorConfederacion, 1);
					controller_listarSelecciones(pArrayListSeleccion);
				break;

				case 3: //Jugador por edad

					ll_sort(pArrayListJugador, jug_ordenarJugadorPorEdad, 1);
					controller_listarJugadores(pArrayListJugador,pArrayListSeleccion,'n');
				break;

				case 4: //Jugador por nombre

					ll_sort(pArrayListJugador, jug_ordenarJugadorPorNombre, 1);
					controller_listarJugadores(pArrayListJugador,pArrayListSeleccion,'n');
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

/// \fn int mostrarOpcionesGuardarBinario(LinkedList*, LinkedList*)
/// \brief
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return
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

/// \fn int mostrarOpcionesCargarBinario(LinkedList*)
/// \brief
///
/// \param pArrayListSeleccion
/// \return
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

//-----------------------------------------------------------------------------------------------
