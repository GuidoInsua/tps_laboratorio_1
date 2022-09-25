/*
 * 	   Trabajo Procatico 1
 *
 * Nombre: Guido Agustin Insua
 * Legajo: 112419
 * DNI: 42806238
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesUsuario.h"
#include "funcionesDeIngreso.h"
#include "funcionesJugador.h"

#define TAMPOS 4
#define TAMCAM 22
#define TAMCON 6

//posiciones -> 0=Arquero 1=Defensor 2=Mediocampo 3=Delantero
//confederaciones -> 0=AFC 1=CAF 2=CONCACAF 3=CONMEBOL 4=UEFA 5=OFC

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;
	char salir;
	char ingresoCostos;
	char cargoJugadores;
	char realizoCalculos;
	float costoHospedaje;
	float costoComida;
	float costoTransporte;
	float costoTotalMantenimiento;
	float costoTotalAumento;
	int cantidadJugadores;
	int posiciones[TAMPOS];
	int camisestas[TAMCAM];
	int confederaciones[TAMCON];
	float promediosConfederaciones[TAMCON];

	ingresoCostos = 'n';
	cargoJugadores = 'n';
	realizoCalculos = 'n';

	costoHospedaje = 0;
	costoComida = 0;
	costoTransporte = 0;
	costoTotalMantenimiento = 0;
	costoTotalAumento = 0;
	cantidadJugadores = 0;

	iniciarJugadores(posiciones, camisestas, confederaciones, TAMPOS, TAMCAM, TAMCON);

	do
	{
		mostrarMenuPrincipal(&opcion, costoHospedaje, costoComida, costoTransporte, posiciones);

		switch(opcion)
		{
			case 1: //Ingreso costos

				do
				{
					mostrarMenuCostos(&opcion, costoHospedaje, costoComida, costoTransporte);

					switch(opcion)
					{
						case 1:

							pedirFlotante(&costoHospedaje, 1, 9999999, "\nIngrese el costo de hospedaje: ", "\nERROR, Ingrese un valor entre 1 y 9.999.999");
						break;

						case 2:

							pedirFlotante(&costoComida, 1, 9999999, "\nIngrese el costo de comida: ", "\nERROR, Ingrese un valor entre 1 y 9.999.999");
						break;

						case 3:

							pedirFlotante(&costoTransporte, 1, 9999999, "\nIngrese el costo de transporte: ", "\nERROR, Ingrese un valor entre 1 y 9.999.999");
						break;

						default:

							printf("\nVolviendo...");
						break;
					}
				}while(opcion != 4);

				ingresoCostos = 's';
				opcion = 0;
			break;

			case 2: //Carga jugador

				if(cantidadJugadores < TAMCAM)
				{
					cargarJugadores(posiciones, camisestas, confederaciones, TAMPOS, TAMCAM, TAMCON);
					cantidadJugadores++;
					printf("\n\tJugador cargado con exito");
				}
				else
				{
					printf("\nYa ingreso los 22 jugadores");
				}

				cargoJugadores = 's';
			break;

			case 3: //Realizar calculos

				if(ingresoCostos == 's' && cargoJugadores == 's')
				{

					costoTotalMantenimiento = costoHospedaje + costoComida + costoTransporte;

					calcularPromedioConfederaciones(promediosConfederaciones, confederaciones, TAMCON, cantidadJugadores);

					if(promediosConfederaciones[0] > 0.5)
					{
						costoTotalAumento = costoTotalMantenimiento * 0.35;
					}

					printf("\n\tLos calculos se realizaron con exito");
					realizoCalculos = 's';
				}
				else
				{
					printf("\nERROR, Primero tiene que ingresar algun costo y cargar un jugador");
				}
			break;

			case 4: //Informar resultados

				if(ingresoCostos == 's' && cargoJugadores == 's')
				{
					if(realizoCalculos == 's')
					{
						imprimirResultados(promediosConfederaciones, costoTotalMantenimiento, costoTotalAumento, TAMCON);
					}
					else
					{
						printf("\nERROR, Primero tiene que realizar los calculos");
					}
				}
				else
				{
					printf("\nERROR, Primero tiene que ingresar algun costo y cargar un jugador");
				}
			break;

			default: //Salir

				pedirCharDosOpciones(&salir, 's', 'n', "\nEsta seguro que desa salir (s/n)?: ", "\nERROR, Ingrese 's' para salir o 'n' para volver");

				if(salir == 'n')
				{
					opcion = 0;
				}
				else
				{
					printf("\nAh salido con exito.");
				}

			break;
		}
	}while(opcion != 5);

	return 0;
}
