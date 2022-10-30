/*
 * 	   Trabajo Procatico 2
 *
 * Nombre: Guido Agustin Insua
 * Legajo: 112419
 * DNI: 42806238
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesConfederacion.h"
#include "funcionesJugador.h"
#include "funcionesInforme.h"
#include "funcionesDeIngreso.h"

#define TAMCONFE 20
#define TAMJUGADOR 3000

int main()
{
	setbuf(stdout,NULL);

	eConfederacion confederaciones[TAMCONFE] =
			{
					{100,"CONMEBOL","SUDAMERICA",1916,1},
					{101,"UEFA","EUROPA",1954,1},
					{102,"AFC","ASIA",1954,1},
					{103,"CAF","AFRICA",1957,1},
					{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961,1},
					{105,"OFC","OCEANIA",1966,1},
			};
	eJugador jugadores[TAMJUGADOR];

	int idAutoIncremental;
	int idAutoIncrementalConfederacion;
	int opcion;
	char continuar;
	int cantidad;

	idAutoIncremental = 8;
	idAutoIncrementalConfederacion = 106;

	iniciarIsEmpty(jugadores, TAMJUGADOR, confederaciones, TAMCONFE);

	do
	{
		mostrarMenu(&opcion);

		switch(opcion)
		{
			case 1: //Alta

				altaJugador(jugadores, TAMJUGADOR, confederaciones, TAMCONFE, &idAutoIncremental);
			break;

			case 2: //Baja

				buscarCantidadJugadores(jugadores, TAMJUGADOR, &cantidad);
				if(cantidad > 0)
				{
					bajaJugador(jugadores, TAMJUGADOR, confederaciones, TAMCONFE);
				}
				else
				{
					printf("\nERROR, Primero tiene que cargar un jugador");
				}
			break;

			case 3: //Modificacion

				buscarCantidadJugadores(jugadores, TAMJUGADOR, &cantidad);
				if(cantidad > 0)
				{
					modificarJugador(jugadores, TAMJUGADOR, confederaciones, TAMCONFE);
				}
				else
				{
					printf("\nERROR, Primero tiene que cargar un jugador");
				}
			break;

			case 4: //Informes

				buscarCantidadJugadores(jugadores, TAMJUGADOR, &cantidad);
				if(cantidad > 0)
				{
					informarDatos(jugadores, TAMJUGADOR, confederaciones, TAMCONFE);
				}
				else
				{
					printf("\nERROR, Primero tiene que cargar un jugador");
				}
			break;

			case 5: //ABM Confederacion

				opcionesMenuConfederacion(confederaciones, TAMCONFE, &idAutoIncrementalConfederacion);
			break;

			default: //Salir

				pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea salir? (s/n): ", "\nERROR, Ingrese 's' o 'n'");

				if(continuar == 's')
				{
					printf("\nAh salio con exito.");
				}
				else
				{
					opcion = 6;
				}
			break;
		}

	}while(opcion != 6);

	return 0;
}
