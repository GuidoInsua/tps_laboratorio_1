
#include <stdio.h>
#include <stdlib.h>
#include "funcionesDeIngreso.h"
#include "funcionesJugador.h"

int mostrarMenuPrincipal(int *opcion,float hospedaje,float comida,float transporte,int posiciones[])
{
	int retorno;
	int bufferOpcion;

	if(opcion != NULL && hospedaje >= 0 && comida >= 0 && transporte >= 0 && posiciones != NULL)
	{
		printf("\n\n\t\tMenu Principal\n");
		printf("\n1. Ingreso de los costos de Mantenimiento"
			   "\n Costo de Hospedaje -> $%.2f"
			   "\n Costo de Comida -> $%.2f"
			   "\n Costo de Transporte -> $%.2f",hospedaje,comida,transporte);
		printf("\n2. Carga de jugadores"
				"\n Arqueros -> %d"
				"\n Defensores -> %d"
				"\n Mediocampistas -> %d"
				"\n Delanteros -> %d",posiciones[0],posiciones[1],posiciones[2],posiciones[3]);
		printf("\n3. Realizar todos los calculos");
		printf("\n4. Informar todos los calculos");
		printf("\n5. Salir");

		pedirEntero(&bufferOpcion, 1, 5, "\n--Ingrese su opcion: ", "\nERROR, Ingrese un numero entre 1 y 5");

		*opcion = bufferOpcion;

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int mostrarMenuCostos(int *opcion,float hospedaje,float comida,float transporte)
{
	int retorno;
	int bufferOpcion;

	if(opcion != NULL && hospedaje >= 0 && comida >= 0 && transporte >= 0)
	{
		printf("\n\t\tCostos de Mantenimiento\n");
		printf("\n1. Costo de Hospedaje -> $%.2f",hospedaje);
		printf("\n2. Costo de Comida -> $%.2f",comida);
		printf("\n3. Costo de Transporte -> $%.2f",transporte);
		printf("\n4. Volver");

		pedirEntero(&bufferOpcion, 1, 4, "\n--Ingrese su opcion: ", "\nERROR, Ingrese un numero entre 1 y 4");

		*opcion = bufferOpcion;

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int iniciarJugadores(int posiciones[],int camisetas[],int confederaciones[],int tamP,int tamR,int tamC)
{
	int retorno;

	if(posiciones != NULL && camisetas != NULL && confederaciones != NULL && tamP > 0 && tamR > 0 && tamC > 0)
	{
		for(int i=0;i<tamP;i++)
		{
			posiciones[i] = 0;
		}

		for(int i=0;i<tamR;i++)
		{
			camisetas[i] = 0;
		}

		for(int i=0;i<tamC;i++)
		{
			confederaciones[i] = 0;
		}

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int cargarJugadores(int posiciones[],int camisetas[],int confederaciones[],int tamP,int tamR,int tamC)
{
	int retorno;
	int bufferConfederacion;

	if(posiciones != NULL && camisetas != NULL && confederaciones != NULL && tamP > 0 && tamR > 0 && tamC > 0)
	{
		ingresarPosicion(posiciones, tamP);

		ingresarCamiseta(camisetas, tamR);

		pedirEntero(&bufferConfederacion, 1, 6, "\n---1=UEFA 2=CONMEBOL 3=CONCACAF 4=AFC 5=OFC 6=CAF--- \n\tIngrese a que confederacion pertenece: ", "\nERROR, Ingrese un numero entre 1 y 6");
		confederaciones[bufferConfederacion-1]++;

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int imprimirResultados(float promedios[],float costoTotalMantenimiento,float costoTotalAumento,int tam)
{
	int retorno;
	float total;

	if(promedios != NULL && costoTotalMantenimiento > 0 && costoTotalAumento >=0 && tam > 0)
	{
		printf("\n\t\tInformar todos los Resultados");
		printf( "\nPorcentaje Uefa %.2f"
				"\nPorcentaje Conmebol %.2f"
				"\nPorcentaje Concacaf %.2f"
				"\nPorcentaje Afc %.2f"
				"\nPorcentaje Ofc %.2f"
				"\nPorcentaje Caf %.2f",promedios[0],promedios[1],promedios[2],promedios[3],promedios[4],promedios[5]);

		if(promedios[0] > 0.5)
		{
			total = costoTotalMantenimiento + costoTotalAumento;
			printf("\nEl costo total de mantenimineto era de %.2f y recibio un aumento de %.2f, su nuevo valor es de %.2f",costoTotalMantenimiento,costoTotalAumento,total);
		}
		else
		{
			printf("\nCosto total de mantenimineto = %.2f",costoTotalMantenimiento);
		}

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}




