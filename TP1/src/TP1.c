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

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;
	char salir;
	char ingresoCostos;
	char cargoJugadores;
	char realizoCalculos;

	ingresoCostos = 'n';
	cargoJugadores = 'n';
	realizoCalculos = 'n';

	do
	{
		mostrarMenuPrincipal(&opcion);

		switch(opcion)
		{
			case 1: //Ingreso costos

				do
				{
					mostrarMenuCostos(&opcion);

					switch(opcion)
					{
						case 1:
						break;

						case 2:
						break;

						case 3:
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

				do
				{
					mostrarMenuJugadores(&opcion);

					switch(opcion)
					{
						case 1:
						break;

						case 2:
						break;

						case 3:
						break;

						case 4:
						break;

						default:

							printf("\nVolviendo...");
						break;
					}
				}while(opcion !=5);

				cargoJugadores = 's';
				opcion = 0;
			break;

			case 3: //Realizar calculos

				if(ingresoCostos == 's' && cargoJugadores == 's')
				{
					printf("k");
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
						printf("k");
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
