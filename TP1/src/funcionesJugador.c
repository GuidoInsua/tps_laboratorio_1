
#include <stdio.h>
#include <stdlib.h>
#include "funcionesDeIngreso.h"

int buscarVacio(int array[],int tam,int* indice)
{
	int retorno;

	if(array != NULL && tam > 0 && indice != NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if(array[i] == 0)
			{
				*indice = i;
				retorno = 0;
				break;
			}
			else
			{
				retorno = 1;
			}
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int ingresarPosicion(int posiciones[],int tam)
{
	int retorno;
	int bufferPosicion;

	if(posiciones != NULL && tam > 0)
	{
		do
		{
			pedirEntero(&bufferPosicion, 1, 4, "\n---1=Arquero 2=Defensor 3=Mediocampo 4=Delantero---\n\tIngrese la posicion del jugador: ", "\nERROR, Ingrese un numero entre 1 y 4");

			switch(bufferPosicion)
			{
				case 1:

					if(posiciones[bufferPosicion-1] < 2)
					{
						retorno = 0;
					}
					else
					{
						printf("\nERROR, Ya ingreso 2/2 arqueros");
						retorno = 1;
					}
				break;

				case 2:

					if(posiciones[bufferPosicion-1] < 8)
					{
						retorno = 0;
					}
					else
					{
						printf("\nERROR, Ya ingreso 8/8 defensores");
						retorno = 1;
					}
				break;

				case 3:

					if(posiciones[bufferPosicion-1] < 8)
					{
						retorno = 0;
					}
					else
					{
						printf("\nERROR, Ya ingreso 8/8 mediocampistas");
						retorno = 1;
					}
				break;

				default:

					if(posiciones[bufferPosicion-1] < 4)
					{
						retorno = 0;
					}
					else
					{
						printf("\nERROR, Ya ingreso 4/4 delanteros");
						retorno = 1;
					}
				break;
			}
		}while(retorno != 0);

		posiciones[bufferPosicion-1]++;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int ingresarCamiseta(int camisetas[],int tam)
{
	int retorno;
	int bufferCamiseta;
	int indice;

	if(camisetas != NULL && tam > 0)
	{
		if(buscarVacio(camisetas, tam, &indice) == 0)
		{
			do
			{
				pedirEntero(&bufferCamiseta, 1, 99, "\nIngrese el numero de camiseta: ", "\nERROR, Ingrese un numero entre 1 y 99");

				for(int i=0;i<tam;i++)
				{
					if(bufferCamiseta == camisetas[i])
					{
						retorno = 1;
						printf("\nERROR, La camiseta numero %d ya fue ingresada",bufferCamiseta);
						break;
					}
					else
					{
						retorno = 0;
					}
				}
			}while(retorno != 0);

			camisetas[indice] = bufferCamiseta;
		}
		else
		{
			retorno = 1;
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int calcularPromedioConfederaciones(float promedios[],int confederaciones[],int tam,int cantidadJugadores)
{
	int retorno;

	if(promedios != NULL && confederaciones != NULL && tam > 0 && cantidadJugadores > 0)
	{
		for(int i=0;i<tam;i++)
		{
			promedios[i] = (float) confederaciones[i] / cantidadJugadores;
		}

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}









