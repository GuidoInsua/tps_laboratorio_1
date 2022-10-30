
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesConfederacion.h"
#include "funcionesJugador.h"
#include "funcionesInforme.h"
#include "funcionesDeIngreso.h"

//-------------------------------------------------------------------------------------------------------------------------

int listarUnJugador(eJugador unJugador,eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;
	char nombreConfederacion[TAMCADENA];

	retorno = -1;

	if(confederaciones != NULL && tamConfederaciones > 0)
	{
		retorno = 1;

		if(unJugador.isEmpty == 1)
		{
			buscarNombreConfederacion(confederaciones, tamConfederaciones, unJugador.idConfederacion, nombreConfederacion);
			printf("| %-*d| %-*s| %-*s| %-*u| %-*.2f| %-*s|   \t%-*u|\n",4,unJugador.id,24,unJugador.nombre,16,unJugador.posicion,11,unJugador.numeroCamiseta,11,unJugador.salario,14,nombreConfederacion,7,unJugador.aniosContrato);
			retorno = 0;
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int listarJugadores(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0)
	{
		printf("\n================================================================================================================");
		printf("\n| %-*s| \t%-*s| %-*s| %-*s| %-*s| %-*s| %-*s|",4,"Id",16,"NOMBRE",16,"POSICION",11,"N CAMISETA",11,"SUELDO",14,"CONFEDERACION",17,"AÑOS de CONTRATO");
		printf("\n----------------------------------------------------------------------------------------------------------------\n");

		for(int i=0;i<tamJugadores;i++)
		{
			listarUnJugador(*(jugadores+i), confederaciones, tamConfederaciones);
		}

		printf("================================================================================================================\n");

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int ordenarJugadoresPorId(eJugador* jugadores,int tamJugadores)
{
	int retorno;
	eJugador jugadorAuxiliar;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0)
	{
		for(int i=0;i<tamJugadores-1;i++)
		{
			for(int j=i+1;j<tamJugadores;j++)
			{
				if((*(jugadores+i)).id > (*(jugadores+j)).id)
				{
					jugadorAuxiliar = *(jugadores+j);
					*(jugadores+j) = *(jugadores+i);
					*(jugadores+i) = jugadorAuxiliar;
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int mostarMenuInformes(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------------------------+");
		printf("\n|\t\t    %-*s|",27,"INFORMES");
		printf("\n+----------------------------------------------+");
		printf("\n| %-*s|",45,"1. Jugadores ordenados");
		printf("\n| %-*s|",45,"2. Confederaciones con jugadores");
		printf("\n| %-*s|",45,"3. Total y promedio de los salarios");
		printf("\n| %-*s|",45,"4. Confederacion con mas anios de contrato");
		printf("\n| %-*s|",45,"5. Porcentaje de jugadores por confederacion");
		printf("\n| %-*s|",45,"6. Region con mas jugadores");
		printf("\n| %-*s|",45,"7. Volver");
		printf("\n+----------------------------------------------+");

		pedirEntero(&buffer, 1, 7, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 7");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int informarDatos(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;
	int opcion;
	float arrayPorcentaje[tamConfederaciones];
	char descripcion[TAMCADENA];

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0)
	{
		do
		{
			mostarMenuInformes(&opcion);
			switch(opcion)
			{
				case 1:

					ordenarJugadoresConfederacionNombre(jugadores, tamJugadores, confederaciones, tamConfederaciones);
					listarJugadores(jugadores, tamJugadores, confederaciones, tamConfederaciones);
				break;

				case 2:

					listarConfederacionesConJugador(jugadores, tamJugadores, confederaciones, tamConfederaciones);
				break;

				case 3:

					informarSalarios(jugadores, tamJugadores);
				break;

				case 4:

					buscarConfederacionConMasAnios(jugadores, tamJugadores, confederaciones, tamConfederaciones);
				break;

				case 5:

					buscarPorcentajeJugadoresPorConfederacion(jugadores, tamJugadores, confederaciones, tamConfederaciones,arrayPorcentaje);

					printf("\n+-------------+----------+");
					printf("\n|%-*s|%-*s|",12,"CONFEDERACION",9,"PORCENTAJE");
					printf("\n+-------------+----------+");
					for(int i=0;i<tamConfederaciones;i++)
					{
						if((*(confederaciones+i)).isEmpty == 1)
						{
							buscarNombreConfederacion(confederaciones, tamConfederaciones, i+100, descripcion);
							printf("\n| %-*s|  %-*.2f|",12,descripcion,8,*(arrayPorcentaje+i));
						}
					}
					printf("\n+-------------+----------+");
				break;

				case 6:

					buscarRegionConMasJugadores(jugadores, tamJugadores, confederaciones, tamConfederaciones);
				break;

				default:

					printf("\nVolviendo...");
				break;
			}
		}while(opcion != 7);

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int ordenarJugadoresConfederacionNombre(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;
	char bufferPrimerConfederacion[TAMCADENA];
	char bufferSegundaConfederacion[TAMCADENA];
	eJugador jugadorAuxiliar;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0)
	{
		retorno = 1;

		for(int i=0;i<tamJugadores-1;i++)
		{
			for(int j=i+1;j<tamJugadores;j++)
			{
				buscarNombreConfederacion(confederaciones, tamConfederaciones, (*(jugadores+i)).idConfederacion, bufferPrimerConfederacion);
				buscarNombreConfederacion(confederaciones, tamConfederaciones, (*(jugadores+j)).idConfederacion, bufferSegundaConfederacion);

				if( strcmp(bufferPrimerConfederacion,bufferSegundaConfederacion) > 0 ||
				   (strcmp(bufferPrimerConfederacion,bufferSegundaConfederacion) == 0 && strcmp((*(jugadores+i)).nombre,(*(jugadores+j)).nombre) > 0))
				{
					jugadorAuxiliar = *(jugadores+j);
					*(jugadores+j) = *(jugadores+i);
					*(jugadores+i) = jugadorAuxiliar;

					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int listarUnaConfederacion(eJugador* jugadores,int tamJugadores,int idConfederacion,char* nombre)
{
	int retorno;
	int bandera;

	retorno = -1;
	bandera = 1;

	if(jugadores != NULL && tamJugadores > 0 && idConfederacion > 0 && nombre != NULL)
	{
		for(int i=0;i<tamJugadores;i++)
		{
			if((*(jugadores+i)).idConfederacion == idConfederacion && (*(jugadores+i)).isEmpty == 1)
			{
				if(bandera == 1)
				{
					printf("\n+---------------+-----------------------+--------+");
					printf("\n| %-*s| %-*s|   %-*u|",14,nombre,22,(*(jugadores+i)).nombre,5,(*(jugadores+i)).numeroCamiseta);
					bandera = 0;
				}
				else
				{
					printf("\n|               | %-*s|   %-*u|",22,(*(jugadores+i)).nombre,5,(*(jugadores+i)).numeroCamiseta);
				}

			}
		}

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int listarConfederacionesConJugador(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;
	char descripcion[TAMCADENA];

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0)
	{
		printf("\n==================================================");
		printf("\n| %-*s| \t%-*s| %-*s|",14,"CONFEDERACION",16,"NOMBRE",7,"N CAM");

		for(int i=0;i<tamConfederaciones;i++)
		{
			if((*(confederaciones+i)).isEmpty == 1)
			{
				buscarNombreConfederacion(confederaciones, tamConfederaciones, (*(confederaciones+i)).id, descripcion);
				listarUnaConfederacion(jugadores, tamJugadores, (*(confederaciones+i)).id, descripcion);

			}
		}
		printf("\n+---------------+-----------------------+--------+");

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int informarSalarios(eJugador* jugadores,int tamJugadores)
{
	int retorno;
	float salarioTotal;
	float salarioPromedio;
	int jugadoresSalarioAlto;
	int cantidadJugadores;

	salarioTotal = 0;
	cantidadJugadores = 0;
	jugadoresSalarioAlto = 0;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0)
	{
		for(int i=0;i<tamJugadores;i++)
		{
			if((*(jugadores+i)).isEmpty == 1)
			{
				salarioTotal = salarioTotal + (*(jugadores+i)).salario;
				cantidadJugadores++;
			}
		}

		salarioPromedio = salarioTotal / cantidadJugadores;

		for(int i=0;i<tamJugadores;i++)
		{
			if((*(jugadores+i)).isEmpty == 1 && (*(jugadores+i)).salario > salarioPromedio)
			{
				jugadoresSalarioAlto++;
			}
		}

		printf("\nEl salario total es: $%.2f",salarioTotal);
		printf("\nEl salario promedio es: $%.2f",salarioPromedio);
		printf("\nLa cantidad de jugadores que superan el salario promedio es: %d",jugadoresSalarioAlto);

		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarTotalPorConfederacion(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones,int* array,int opcion)
{
	int retorno;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0 && array != NULL)
	{
		for(int k=0;k<tamConfederaciones;k++)
		{
			*(array+k) = 0;
		}

		for(int i=0;i<tamConfederaciones;i++)
		{
			for(int j=0;j<tamJugadores;j++)
			{
				if((*(jugadores+j)).idConfederacion == (*(confederaciones+i)).id && (*(jugadores+j)).isEmpty == 1 && (*(confederaciones+i)).isEmpty == 1)
				{
					if(opcion == 1)
					{
						*(array+i) = *(array+i) + (*(jugadores+j)).aniosContrato;
					}
					else
					{
						*(array+i) = *(array+i) + 1;
					}
				}
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int ordenarArrayPararelos(int* primerArray,int* segundoArray,int tamArray)
{
	int retorno;
	float primerAux;
	float segundoAux;


	retorno = -1;

	if(primerArray != NULL && segundoArray != NULL && tamArray > 0)
	{
		for(int i=0;i<tamArray-1;i++)
		{
			for(int j=i+1;j<tamArray;j++)
			{
				if(*(primerArray+i) < *(primerArray+j))
				{
					primerAux = *(primerArray+i);
					*(primerArray+i) = *(primerArray+j);
					*(primerArray+j) = primerAux;

					segundoAux = *(segundoArray+i);
					*(segundoArray+i) = *(segundoArray+j);
					*(segundoArray+j) = segundoAux;
				}
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarConfederacionConMasAnios(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;
	int mayorConfederacion;
	int arrayAniosConfederaciones[tamConfederaciones];
	int bufferConfederaciones[tamConfederaciones];
	char descripcion[TAMCADENA];

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0)
	{
		for(int k=0;k<tamConfederaciones;k++)
		{
			*(bufferConfederaciones+k) = k+100;
		}

		buscarTotalPorConfederacion(jugadores, tamJugadores, confederaciones, tamConfederaciones, arrayAniosConfederaciones,1);

		ordenarArrayPararelos(arrayAniosConfederaciones, bufferConfederaciones, tamConfederaciones);

		mayorConfederacion = *(arrayAniosConfederaciones+0);

		if(mayorConfederacion > *(arrayAniosConfederaciones+1))
		{

			buscarNombreConfederacion(confederaciones, tamConfederaciones, *(bufferConfederaciones+0), descripcion);

			printf("\nLa confederacion con mas anios es %s con %d anios",descripcion,mayorConfederacion);
		}
		else
		{
			printf("\nLas confederaciones con la mayor cantidad de anios son: ");

			for(int i=0;i<tamConfederaciones;i++)
			{
				if(mayorConfederacion == *(arrayAniosConfederaciones+i))
				{
					buscarNombreConfederacion(confederaciones, tamConfederaciones, *(bufferConfederaciones+i), descripcion);
					printf("%s / ",descripcion);
				}
			}

			printf("\nCon %d anios cada una",mayorConfederacion);
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarPorcentajeJugadoresPorConfederacion(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones,float* arrayPorcentaje)
{
	int retorno;
	int arrayCantidadJugadores[tamConfederaciones];
	int cantidadJugadores;

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0 && arrayPorcentaje != NULL)
	{
		buscarTotalPorConfederacion(jugadores, tamJugadores, confederaciones, tamConfederaciones, arrayCantidadJugadores, 0);
		buscarCantidadJugadores(jugadores, tamJugadores, &cantidadJugadores);

		for(int i=0;i<tamConfederaciones;i++)
		{
			*(arrayPorcentaje+i) = (float) (*(arrayCantidadJugadores+i) * 100) / cantidadJugadores;
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarNombreRegion(eConfederacion* confederaciones,int tamConfederaciones,int idConfederacion,char* nombre)
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
				strcpy(nombre,(*(confederaciones+i)).region);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarRegionConMasJugadores(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno;
	int arrayCantidadJugadores[tamConfederaciones];
	int bufferRegiones[tamConfederaciones];
	int mayorRegion;
	char descripcion[TAMCADENA];

	retorno = -1;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfederaciones > 0)
	{
		buscarTotalPorConfederacion(jugadores, tamJugadores, confederaciones, tamConfederaciones, arrayCantidadJugadores, 0);

		for(int k=0;k<tamConfederaciones;k++)
		{
			*(bufferRegiones+k) = k+100;
		}

		ordenarArrayPararelos(arrayCantidadJugadores, bufferRegiones, tamConfederaciones);

		mayorRegion = *(arrayCantidadJugadores+0);

		if(mayorRegion > *(arrayCantidadJugadores+1))
		{

			buscarNombreConfederacion(confederaciones, tamConfederaciones, *(bufferRegiones+0), descripcion);

			printf("\nLa region con mas jugadores es %s con %d jugadores",descripcion,mayorRegion);
		}
		else
		{
			printf("\nLas regiones con la mayor cantidad de jugadores son: ");

			for(int i=0;i<tamConfederaciones;i++)
			{
				if(mayorRegion == *(arrayCantidadJugadores+i))
				{
					buscarNombreConfederacion(confederaciones, tamConfederaciones, *(bufferRegiones+i), descripcion);
					printf("%s / ",descripcion);
				}
			}

			printf("\nCon %d jugadores cada una",mayorRegion);
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------
