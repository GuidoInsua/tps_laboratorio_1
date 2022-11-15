
/*
 * 	   Trabajo Procatico 3
 *
 * Nombre: Guido Agustin Insua
 * Legajo: 112419
 * DNI: 42806238
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Controller.h"
#include "parser.h"
#include "funcionesDeUsuario.h"
#include "funcionesDeIngreso.h"

int main()
{
	setbuf(stdout,NULL);
    int option;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSeleciones = ll_newLinkedList();
    char continuar;
    int idJugadorAutoIncremental;
    int seGuardo = 1;

    do{
    	mostrarMenu(&option);
        switch(option)
        {
            case 1: //Cargar archivos

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		printf("\nLos archivos ya fueron cargados");
            	}
            	else
            	{
					controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
					controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSeleciones);
					controller_cargarIdAutoIncrementalDesdeTexto("idAutoIncremental.txt", &idJugadorAutoIncremental);
					seGuardo = 0;
            	}
            break;

            case 2: //Alta jugador

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		controller_agregarJugador(listaJugadores,&idJugadorAutoIncremental);
            		seGuardo = 0;
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
            break;

            case 3: //Modificar jugador

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		controller_editarJugador(listaJugadores,listaSeleciones);
            		seGuardo = 0;
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
            break;

            case 4: //Baja jugador

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		controller_removerJugador(listaJugadores,listaSeleciones);
            		seGuardo = 0;
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
            break;

            case 5: //Listados

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		mostrarListados(listaJugadores, listaSeleciones);
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
            break;

            case 6: //Convocar jugador

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		mostrarOpcionConvocar(listaJugadores, listaSeleciones);
            		seGuardo = 0;
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
            break;

            case 7: //Ordenar

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		mostrarOpcionOrdenar(listaJugadores, listaSeleciones);
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
            break;

            case 8: //Generar binario

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		mostrarOpcionesGuardarBinario(listaJugadores,listaSeleciones);
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
            break;

            case 9: //Cargar binario

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		mostrarOpcionesCargarBinario(listaSeleciones);
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
            break;

            case 10: //Guardar archivos

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
            		controller_guardarSeleccionesModoTexto("selecciones.csv", listaSeleciones);
            		controller_guardarIdAutoIncrementalModoTexto("idAutoIncremental.txt", idJugadorAutoIncremental);

            		seGuardo = 1;
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
            break;

            default: //Salir

            	if(seGuardo == 0)
            	{
            		printf("\nNo guardo los cambios");
            	}

            	pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea salir? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

            	if(continuar == 's')
            	{
            		printf("\nSaliendo");
            	}
            	else
            	{
            		option = 1;
            	}

            break;
        }
    }while(option != 11);

    ll_deleteLinkedList(listaJugadores);
    ll_deleteLinkedList(listaSeleciones);
    return 0;
}

