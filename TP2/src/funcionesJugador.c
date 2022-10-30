
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesConfederacion.h"
#include "funcionesJugador.h"
#include "funcionesInforme.h"
#include "funcionesDeIngreso.h"

//-------------------------------------------------------------------------------------------------------------------------

int mostrarMenu(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+-----------------------+");
		printf("\n|\t %-*s|",15,"  MENU");
		printf("\n+-----------------------+");
		printf("\n| %-*s|",22,"1. Alta Jugador");
		printf("\n| %-*s|",22,"2. Baja Jugador");
		printf("\n| %-*s|",22,"3. Modificar Jugador");
		printf("\n| %-*s|",22,"4. Informar");
		printf("\n| %-*s|",22,"5. ABM confederacion");
		printf("\n| %-*s|",22,"6. Salir");
		printf("\n+-----------------------+");

		pedirEntero(&buffer, 1, 6, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 5");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int iniciarIsEmpty(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0)
	{
		for(int i=0;i<tamJugadores;i++)
		{
			(*(jugadores+i)).isEmpty = 0;
		}

		for(int i=6;i<tamConfederaciones;i++) // I = 6 para no poner en 0 las hardcodeadas
		{
			(*(confederaciones+i)).isEmpty = 0;
		}

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarJugadorVacio(eJugador* jugadores,int tamJugadores,int* indice)
{
	int retorno;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && indice != NULL)
	{
		retorno = 1;

		for(int i=0;i<tamJugadores;i++)
		{
			if((*(jugadores+i)).isEmpty == 0)
			{
				*indice = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------



int altaJugador(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones,int* idJugador)
{
	int retorno;
	char bufferNombre[TAMCADENA];
	char bufferPosicion[TAMCADENA];
	short bufferNumeroCamiseta;
	int bufferIdConfederacion;
	float bufferSalario;
	short bufferAniosContrato;
	char confirmacion;
	int indice;
	int aux;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0 && idJugador != NULL)
	{
		if(buscarJugadorVacio(jugadores, tamJugadores, &indice) == 0)
		{
			pedirStringAlfabetico(bufferNombre, TAMCADENA, "\nIngrese el nombre del jugador: ", "\nERROR, Ingrese solo letras", 's');
			pedirStringAlfabetico(bufferPosicion, TAMCADENA, "\nIngrese la posicion del jugador: ", "\nERROR, Ingrese solo letras", 's');
			pedirShort(&bufferNumeroCamiseta, 1, 99, "\nIngrese el numero de camiseta del jugador: ", "\nERROR, Ingrese un numero del 1 al 99");
			pedirIdConfederacion(confederaciones, tamConfederaciones, &bufferIdConfederacion, "\nIngrese el id de la confederacion: ", "\nERROR, Ingrese un numero entre 100 y 105",&aux);
			pedirFlotante(&bufferSalario, 1, 9999999, "\nIngrese el salario del jugador: ", "\nERROR, Ingrese un numero entre 1 y 9.999.999");
			pedirShort(&bufferAniosContrato, 1, 100, "\nIngrese la cantidad de anios del contrato: ", "\nERROR, Ingrese un numero entre 1 y 100");

			ConvertirUprLwrExtendido(bufferNombre, TAMCADENA);
			ConvertirUprLwrExtendido(bufferPosicion, TAMCADENA);

			pedirCharDosOpciones(&confirmacion, 's', 'n', "\nEsta seguro que desea cargar este jugador? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

			if(confirmacion == 's')
			{
				(*(jugadores+indice)).id = *idJugador;
				strcpy((*(jugadores+indice)).nombre,bufferNombre);
				strcpy((*(jugadores+indice)).posicion,bufferPosicion);
				(*(jugadores+indice)).numeroCamiseta = bufferNumeroCamiseta;
				(*(jugadores+indice)).idConfederacion = bufferIdConfederacion;
				(*(jugadores+indice)).salario = bufferSalario;
				(*(jugadores+indice)).aniosContrato = bufferAniosContrato;
				(*(jugadores+indice)).isEmpty = 1;

				(*idJugador)++;

				printf("\nJugador cargado con exito");
				retorno = 0;
			}
			else
			{
				retorno = 1;
				printf("\nEl jugador no fue cargado");
			}

		}
		else
		{
			printf("\nNo hay mas espacio para cargar jugadores");
			retorno = -2;
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarExistenciaJugador(eJugador* jugadores,int tamJugadores,int* indice,int idJugador)
{
	int retorno;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && indice != NULL)
	{
		retorno = 1;

		for(int i=0;i<tamJugadores;i++)
		{
			if((*(jugadores+i)).isEmpty == 1 && (*(jugadores+i)).id == idJugador)
			{
				*indice = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int pedirUnJugador(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones,int* idJugador,int* indiceJugador)
{
	int retorno;
	int bufferId;
	int bufferIndice;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0 && idJugador != NULL)
	{
		ordenarJugadoresPorId(jugadores, tamJugadores);
		listarJugadores(jugadores, tamJugadores, confederaciones, tamConfederaciones);

		pedirEntero(&bufferId, 1, 3000, "\nIngrese el id del jugador: ", "\nERROR, Ingrese un numero entre 1 y 3000");

		if(buscarExistenciaJugador(jugadores, tamJugadores, &bufferIndice, bufferId) == 0)
		{
			printf("\n-Seleccion = ");
			listarUnJugador(*(jugadores+bufferIndice), confederaciones, tamConfederaciones);

			*idJugador = bufferId;
			*indiceJugador = bufferIndice;

			retorno = 0;
		}
		else
		{
			printf("\nEl jugador no existe");
			retorno = 1;
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int bajaJugador(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;
	int id;
	int indice;
	char continuar;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0)
	{
		if(pedirUnJugador(jugadores, tamJugadores, confederaciones, tamConfederaciones, &id, &indice) == 0)
		{
			pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea dar de baja este jugador (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

			if(continuar == 's')
			{
				(*(jugadores+indice)).isEmpty = 0;
				printf("\nJugador dado de baja con exito");
				retorno = 0;
			}
			else
			{
				printf("\nBaja de jugador cancelada con exito");
				retorno = 1;
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int mostrarMenuModificacion(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+--------------------------------+");
		printf("\n|\t   %-*s|",22,"MODIFICACION");
		printf("\n+--------------------------------+");
		printf("\n| %-*s|",31,"1. Modificar Nombre");
		printf("\n| %-*s|",31,"2. Modificar Posicion");
		printf("\n| %-*s|",31,"3. Modificar Numero Camiseta");
		printf("\n| %-*s|",31,"4. Modificar Confederacion");
		printf("\n| %-*s|",31,"5. Modificar Salario");
		printf("\n| %-*s|",31,"6. Modificar anios de contrato");
		printf("\n| %-*s|",31,"7. Volver");
		printf("\n+--------------------------------+");

		pedirEntero(&buffer, 1, 7, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 7");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int modificarJugador(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;
	char bufferNombre[TAMCADENA];
	char bufferPosicion[TAMCADENA];
	short bufferNumeroCamiseta;
	int bufferIdConfederacion;
	float bufferSalario;
	short bufferAniosContrato;
	int id;
	int indice;
	int opcion;
	char continuar;
	int aux;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0)
	{
		retorno = 0;
		if(pedirUnJugador(jugadores, tamJugadores, confederaciones, tamConfederaciones, &id, &indice) == 0)
		{
			do
			{
				mostrarMenuModificacion(&opcion);

				switch(opcion)
				{
					case 1: //Nombre

						pedirStringAlfabetico(bufferNombre, TAMCADENA, "\nIngrese el nuevo nombre del jugador: ", "\nERROR, Ingrese solo letras", 's');

						pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere modificar el nombre? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
						if(continuar == 's')
						{
							strcpy((*(jugadores+indice)).nombre,bufferNombre);
							printf("\nModificacion exitosa");
						}
						else
						{
							printf("\nModificacion cancelada");
						}
					break;

					case 2: //Posicion

						pedirStringAlfabetico(bufferPosicion, TAMCADENA, "\nIngrese la nueva posicion del jugador: ", "\nERROR, Ingrese solo letras", 's');

						pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere modificar la posicion? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
						if(continuar == 's')
						{
							strcpy((*(jugadores+indice)).posicion,bufferPosicion);
							printf("\nModificacion exitosa");
						}
						else
						{
							printf("\nModificacion cancelada");
						}
					break;

					case 3: //Camiseta

						pedirShort(&bufferNumeroCamiseta, 1, 99, "\nIngrese el nuevo numero de camiseta del jugador: ", "\nERROR, Ingrese un numero del 1 al 99");

						pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere modificar el numero de camiseta? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
						if(continuar == 's')
						{
							(*(jugadores+indice)).numeroCamiseta = bufferNumeroCamiseta;
							printf("\nModificacion exitosa");
						}
						else
						{
							printf("\nModificacion cancelada");
						}
					break;

					case 4: //Confederacion

						pedirIdConfederacion(confederaciones, tamConfederaciones, &bufferIdConfederacion, "\nIngrese el nuevo id de la confederacion: ", "\nERROR, Ingrese un numero entre 100 y 105",&aux);

						pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere modificar la confederacion? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
						if(continuar == 's')
						{
							(*(jugadores+indice)).idConfederacion = bufferIdConfederacion;
							printf("\nModificacion exitosa");
						}
						else
						{
							printf("\nModificacion cancelada");
						}
					break;

					case 5: //Salario

						pedirFlotante(&bufferSalario, 1, 9999999, "\nIngrese el nuevo salario del jugador: ", "\nERROR, Ingrese un numero entre 1 y 9.999.999");

						pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere modificar el salario? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
						if(continuar == 's')
						{
							(*(jugadores+indice)).salario = bufferSalario;
							printf("\nModificacion exitosa");
						}
						else
						{
							printf("\nModificacion cancelada");
						}
					break;

					case 6: //anios contrato

						pedirShort(&bufferAniosContrato, 1, 100, "\nIngrese la nueva cantidad de anios del contrato: ", "\nERROR, Ingrese un numero entre 1 y 100");

						pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere modificar los anios del contrato? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
						if(continuar == 's')
						{
							(*(jugadores+indice)).aniosContrato = bufferAniosContrato;
							printf("\nModificacion exitosa");
						}
						else
						{
							printf("\nModificacion cancelada");
						}
					break;

					default:

						printf("\nVolviendo...");
					break;
				}

			}while(opcion != 7);
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarCantidadJugadores(eJugador* jugadores,int tamJugadores,int* cantidad)
{
	int retorno;
	int bufferCantidad;

	retorno = -1;
	bufferCantidad = 0;

	if(jugadores != NULL && tamJugadores > 0 && cantidad != NULL)
	{
		for(int i=0;i<tamJugadores;i++)
		{
			if((*(jugadores+i)).isEmpty == 1)
			{
				bufferCantidad++;
			}
		}

		*cantidad = bufferCantidad;
		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

