
#ifndef FUNCIONESDEUSUARIO_H_
#define FUNCIONESDEUSUARIO_H_

int mostrarMenu(int* opcion);
int pedirPosicion(char* posicion,char* mensaje,char* mensajeError);
int pedirNacionalidad(char* nacionalidad,char* mensaje,char* mensajeError);
int pedirDatosJugador(char* nombre,char* edad,char* posicion,char* nacionalidad,int tamNombre);
int mostrarMenuListados(int* opcion);
int mostrarListados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int mostrarMenuModificacion(int* opcion);
int modificarNombreJugador(Jugador* unJugador,int tamNombre);
int modificarEdadJugador(Jugador* unJugador);
int modificarPosicionJugador(Jugador* unJugador,int tamPosicion);
int modificarNacionalidadJugador(Jugador* unJugador,int tamNacionalidad);
int mostrarMenuConvocar(int* opcion);
int mostrarOpcionConvocar(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int mostrarMenuOrdenar(int* opcion);
int mostrarOpcionOrdenar(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int mostrarOpcionesGuardarBinario(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int mostrarOpcionesCargarBinario(LinkedList* pArrayListSeleccion);

#endif /* FUNCIONESDEUSUARIO_H_ */
