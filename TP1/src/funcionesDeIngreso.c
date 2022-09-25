
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int miFgets(char*,int);
static int miFgets(char* cadena, int tam)
{
	int retorno;
	char bufferCadena[4000];

	if(cadena != NULL && tam > 0)
	{
		fflush(stdin);
		if( fgets(bufferCadena,sizeof(bufferCadena),stdin) != NULL &&
		    strnlen(bufferCadena,sizeof(bufferCadena)) <= tam)
		{
			if(bufferCadena[strnlen(bufferCadena,sizeof(bufferCadena))-1] == '\n')
			{
				bufferCadena[strnlen(bufferCadena,sizeof(bufferCadena))-1] = '\0';
			}

			if(strnlen(bufferCadena,sizeof(bufferCadena)) <= tam)
			{
				strncpy(cadena,bufferCadena,tam);
				retorno = 0;
			}
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

static int esInt(char*,int);
static int esInt(char* cadena, int tam)
{
	int retorno;

	if(cadena != NULL && tam > 0)
	{
		for(int i=0;cadena[i] != '\0';i++)
		{
			if((i==0 && (cadena[i] == '+' || cadena[i] == '-')) || isdigit(cadena[i]) != 0)
			{
				retorno = 0;
				continue;
			}
			else
			{
				retorno = 1;
				break;
			}
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

static int esFloat(char*,int);
static int esFloat(char* cadena, int tam)
{
	int retorno;
	char seIngresoComa;

	seIngresoComa = 'n';

	if(cadena != NULL && tam > 0)
	{
		for(int i=0;cadena[i] != '\0';i++)
		{
			if((i==0 && (cadena[i] == '+' || cadena[i] == '-')) || isdigit(cadena[i]) != 0)
			{
				retorno = 0;
				continue;
			}
			else
			{
				if(i != 0 && isdigit(cadena[i-1]) != 0 && cadena[i] == '.' && seIngresoComa == 'n')
				{
					retorno = 0;
					seIngresoComa = 's';
					continue;
				}
				else
				{
					retorno = 1;
					break;
				}
			}
		}
	}

	return retorno;
}

static int obtenerCadenaInt(int*);
static int obtenerCadenaInt(int* bufferDireccion)
{
	int retorno;
	char bufferCadena[50];

	if( bufferDireccion != NULL &&
		miFgets(bufferCadena,sizeof(bufferCadena)) == 0 &&
		esInt(bufferCadena,sizeof(bufferCadena)) == 0)
	{
		retorno = 0;
		*bufferDireccion = atoi(bufferCadena);
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

static int obtenerCadenaFloat(float*);
static int obtenerCadenaFloat(float* bufferDireccion)
{
	int retorno;
	char bufferCadena[50];

	if( bufferDireccion != NULL &&
		miFgets(bufferCadena,sizeof(bufferCadena)) == 0 &&
		esFloat(bufferCadena,sizeof(bufferCadena)) == 0)
	{
		retorno = 0;
		*bufferDireccion = atof(bufferCadena);
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int pedirEntero(int* direccion, int minimo, int maximo, char mensaje[], char mensajeError[])
{
	int retorno;
	int bufferEntero;

	if(direccion != NULL && minimo <= maximo && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			if( obtenerCadenaInt(&bufferEntero) == 0 &&
				bufferEntero >= minimo &&
				bufferEntero <= maximo)
			{
				*direccion = bufferEntero;
				retorno = 0;
			}
			else
			{
				printf("%s",mensajeError);
				retorno = 1;
			}

		}while(retorno != 0);
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int pedirFlotante(float* direccion, float minimo, float maximo, char mensaje[], char mensajeError[])
{
	int retorno;
	float bufferFlotante;

	if(direccion != NULL && minimo <= maximo && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			if( obtenerCadenaFloat(&bufferFlotante) == 0 &&
				bufferFlotante >= minimo &&
				bufferFlotante <= maximo)
			{
				*direccion = bufferFlotante;
				retorno = 0;
			}
			else
			{
				printf("%s",mensajeError);
				retorno = 1;
			}

		}while(retorno != 0);
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int pedirCharDosOpciones(char* direccion, char opcionUno, char opcionDos, char mensaje[], char mensajeError[])
{
	int retorno;
	char bufferChar;

	if(direccion != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);
			if(bufferChar == opcionUno || bufferChar == opcionDos)
			{
				*direccion = bufferChar;
				retorno = 0;
			}
			else
			{
				printf("%s",mensajeError);
				retorno = 1;
			}

		}while(retorno != 0);
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}


