
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesConfederacion.h"
#include "funcionesJugador.h"
#include "funcionesInforme.h"
#include "funcionesDeIngreso.h"

//-------------------------------------------------------------------------------------------------------------------------

int buscarNombreConfederacion(eConfederacion* confederaciones,int tamConfederaciones,int idConfederacion,char* nombre)
{
	int retorno;

	retorno = -1;

	if(confederaciones != NULL && tamConfederaciones > 0 && idConfederacion > 0 && nombre != NULL)
	{
		retorno = 1;

		for(int i=0;i<tamConfederaciones;i++)
		{
			if((*(confederaciones+i)).id == idConfederacion)
			{
				strcpy(nombre,(*(confederaciones+i)).nombre);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int mostrarConfederaciones(eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;

	retorno = -1;

	if(confederaciones != NULL && tamConfederaciones > 0)
	{
		printf("\n==========================================================");
		printf("\n| %-*s| %-*s|\t%-*s| %-*s|",4,"Id",9,"NOMBRE",18,"REGION",13,"AÑO CREACION");
		printf("\n----------------------------------------------------------");

		for(int i=0;i<tamConfederaciones;i++)
		{
			if((*(confederaciones+i)).isEmpty == 1)
			{
				printf("\n| %-*d| %-*s| %-*s|\t%-*d|",4,(*(confederaciones+i)).id,9,(*(confederaciones+i)).nombre,23,(*(confederaciones+i)).region,9,(*(confederaciones+i)).anioCreacion);
			}
		}

		printf("\n==========================================================");

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int pedirIdConfederacion(eConfederacion* confederaciones,int tamConfederaciones,int* respuesta,char* mensaje,char* mensajeError,int* indice)
{
	int retorno;
	int bufferId;

	retorno = -1;

	if(confederaciones != NULL && tamConfederaciones > 0 && respuesta != NULL && mensaje != NULL && mensajeError != NULL)
	{
		mostrarConfederaciones(confederaciones, tamConfederaciones);

		do
		{
			pedirEntero(&bufferId, 100, 999, mensaje, mensajeError);

			for(int i=0;i<tamConfederaciones;i++)
			{
				if((*(confederaciones+i)).id == bufferId && (*(confederaciones+i)).isEmpty == 1)
				{
					*respuesta = bufferId;
					*indice = i;
					retorno = 0;
					break;
				}
			}

			if(retorno != 0)
			{
				printf("%s",mensajeError);
			}
		}while(retorno != 0);
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int mostrarMenuConfederaciones(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------+");
		printf("\n|\t %-*s|",20,"CONFEDERACION");
		printf("\n+----------------------------+");
		printf("\n| %-*s|",27,"1. Alta Confederacion");
		printf("\n| %-*s|",27,"2. Baja Confederacion");
		printf("\n| %-*s|",27,"3. Modificar Confederacion");
		printf("\n| %-*s|",27,"4. Volver");
		printf("\n+----------------------------+");

		pedirEntero(&buffer, 1, 4, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 4");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int opcionesMenuConfederacion(eConfederacion* confederaciones,int tamConfederaciones,int* idAutoIncremental)
{
	int retorno;
	int opcion;

	retorno = -1;

	if(confederaciones != NULL && tamConfederaciones > 0 && idAutoIncremental != NULL)
	{
		do
		{
			mostrarMenuConfederaciones(&opcion);

			switch(opcion)
			{
				case 1:

					altaConfederacion(confederaciones, tamConfederaciones,idAutoIncremental);
				break;

				case 2:

					bajaConfederacion(confederaciones, tamConfederaciones);
				break;

				case 3:

					modificarConfederacion(confederaciones, tamConfederaciones);
				break;

				default:

					printf("\nVolviendo");
				break;
			}

		}while(opcion != 4);
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarConfederacionVacia(eConfederacion* confederaciones,int tamConfederaciones,int* indice)
{
	int retorno;

	retorno = -1;

	if(confederaciones != NULL && tamConfederaciones > 0 && indice != NULL)
	{
		retorno = 1;

		for(int i=0;i<tamConfederaciones;i++)
		{
			if((*(confederaciones+i)).isEmpty == 0)
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

int altaConfederacion(eConfederacion* confederaciones,int tamConfederaciones,int* idAutoIncremental)
{
	int retorno;
	char bufferNombre[TAMCADENA];
	char bufferRegion[TAMCADENA];
	int bufferAnio;
	char confirmacion;
	int indice;

	retorno = -1;

	if(confederaciones != NULL && tamConfederaciones > 0 && idAutoIncremental != NULL)
	{
		if(buscarConfederacionVacia(confederaciones, tamConfederaciones, &indice) == 0)
		{
			pedirStringAlfabetico(bufferNombre, TAMCADENA, "\nIngrese el nombre de la confederacion: ", "\nERROR, Ingrese solo letras", 's');
			pedirStringAlfabetico(bufferRegion, TAMCADENA, "\nIngrese la region de la confederacion: ", "\nERROR, Ingrese solo letras", 's');
			pedirEntero(&bufferAnio, 1800, 2022 , "\nIngrese el anio de creacion de la confederacion: ", "\nERROR, Ingrese un numero entre 1800 y 2022");

			ConvertirUprLwrExtendido(bufferRegion, TAMCADENA);

			pedirCharDosOpciones(&confirmacion, 's', 'n', "\nEsta seguro que desea cargar esta confederacion? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

			if(confirmacion == 's')
			{
				(*(confederaciones+indice)).id = *idAutoIncremental;
				strcpy((*(confederaciones+indice)).nombre,bufferNombre);
				strcpy((*(confederaciones+indice)).region,bufferRegion);
				(*(confederaciones+indice)).anioCreacion = bufferAnio;
				(*(confederaciones+indice)).isEmpty = 1;

				(*idAutoIncremental)++;

				printf("\nLa confedearacion fue cargada con exito");
				retorno = 0;
			}
			else
			{
				retorno = 1;
				printf("\nLa confedearacion no fue cargada");
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int bajaConfederacion(eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;
	int indice;
	char continuar;
	int id;

	retorno = -1;

	if(confederaciones != NULL && tamConfederaciones > 0)
	{
		if(pedirIdConfederacion(confederaciones, tamConfederaciones, &id, "\nIngrese el id de la confederacion que desea dar de baja: ", "\nERROR, No existe una confederacion con ese id",&indice) == 0)
		{
			pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea dar de baja esta confederacion (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

			if(continuar == 's')
			{
				printf("hola");
				(*(confederaciones+indice)).isEmpty = 0;
				printf("\nConfederacion dada de baja con exito");
				retorno = 0;
			}
			else
			{
				printf("\nBaja de confederacion cancelada con exito");
				retorno = 1;
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int mostrarMenuModificacionConfederacion(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------+");
		printf("\n|\t %-*s|",20,"MODIFICACION");
		printf("\n+----------------------------+");
		printf("\n| %-*s|",27,"1. Modificar nombre");
		printf("\n| %-*s|",27,"2. Modificar region");
		printf("\n| %-*s|",27,"3. Modificar anio");
		printf("\n| %-*s|",27,"4. Volver");
		printf("\n+----------------------------+");

		pedirEntero(&buffer, 1, 4, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 4");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int modificarConfederacion(eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;
	int opcion;
	char bufferNombre[TAMCADENA];
	char bufferRegion[TAMCADENA];
	int bufferAnio;
	char continuar;
	int indice;
	int id;

	retorno = -1;

	if(confederaciones != NULL && tamConfederaciones > 0)
	{
		if(pedirIdConfederacion(confederaciones, tamConfederaciones, &id, "\nIngrese el id de la confederacion que desea modificar: ", "\nERROR, No existe una confederacion con ese id",&indice) == 0)
		{
			do
			{
				mostrarMenuModificacionConfederacion(&opcion);

				switch(opcion)
				{
					case 1:

						pedirStringAlfabetico(bufferNombre, TAMCADENA, "\nIngrese el nuevo nombre de la confederacion: ", "\nERROR, Ingrese solo letras", 's');

						pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere modificar el nombre? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
						if(continuar == 's')
						{
							strcpy((*(confederaciones+indice)).nombre,bufferNombre);
							printf("\nModificacion exitosa");
						}
						else
						{
							printf("\nModificacion cancelada");
						}
					break;

					case 2:

						pedirStringAlfabetico(bufferRegion, TAMCADENA, "\nIngrese la nueva region de la confederacion: ", "\nERROR, Ingrese solo letras", 's');

						pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere modificar la region? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
						if(continuar == 's')
						{
							strcpy((*(confederaciones+indice)).region,bufferRegion);
							printf("\nModificacion exitosa");
						}
						else
						{
							printf("\nModificacion cancelada");
						}
					break;

					case 3:

						pedirEntero(&bufferAnio, 1800, 2022, "\nIngrese el nuevo anio de creacion de la confederacion: ", "\nERROR, Ingrese un numero entre 1800 y 2022");

						pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere modificar el anio? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
						if(continuar == 's')
						{
							(*(confederaciones+indice)).anioCreacion = bufferAnio;
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

			}while(opcion != 4);
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------
