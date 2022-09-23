
#include <stdio.h>
#include <stdlib.h>
#include "funcionesDeIngreso.h"

int mostrarMenuPrincipal(int *opcion)
{
	int retorno;
	int bufferOpcion;

	if(opcion != NULL)
	{
		printf("\n\n\t\tMenu Principal\n");
		printf("\n1. Ingreso de los costos de Mantenimiento"
			   "\n Costo de Hospedaje -> $0"
			   "\n Costo de Comida -> $0"
			   "\n Costo de Transporte -> $0");
		printf("\n2. Carga de jugadores"
				"\n Arqueros -> 0"
				"\n Defensores -> 0"
				"\n Mediocampistas -> 0"
				"\n Delanteros -> 0");
		printf("\n3. Realizar todos los calculos");
		printf("\n4. Informar todos los calculos");
		printf("\n5. Salir");

		pedirEntero(&bufferOpcion, 1, 5, "\n--Ingrese su opcion: ", "\nERROR, Ingrese un numero entre 1 y 5");

		*opcion = bufferOpcion;

		retorno = 0;
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}

int mostrarMenuCostos(int *opcion)
{
	int retorno;
	int bufferOpcion;

	if(opcion != NULL)
	{
		printf("\n\t\tCostos de Mantenimiento\n");
		printf("\n1. Costo de Hospedaje -> $0");
		printf("\n2. Costo de Comida -> $0");
		printf("\n3. Costo de Transporte -> $0");
		printf("\n4. Volver");

		pedirEntero(&bufferOpcion, 1, 4, "\n--Ingrese su opcion: ", "\nERROR, Ingrese un numero entre 1 y 4");

		*opcion = bufferOpcion;

		retorno = 0;
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}

int mostrarMenuJugadores(int *opcion)
{
	int retorno;
	int bufferOpcion;

	if(opcion != NULL)
	{
		printf("\n\t\tJugadores\n");
		printf("\n1. Arqueros -> $0");
		printf("\n2. Defensores -> $0");
		printf("\n3. Mediocampistas -> $0");
		printf("\n4. Delanteros -> $0");
		printf("\n5. Volver");

		pedirEntero(&bufferOpcion, 1, 5, "\n--Ingrese su opcion: ", "\nERROR, Ingrese un numero entre 1 y 5");

		*opcion = bufferOpcion;

		retorno = 0;
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}
