
#ifndef FUNCIONESDEUSUARIO_H_
#define FUNCIONESDEUSUARIO_H_

int mostrarMenu(int* opcion);
int pedirDatosJugador(char* nombre,char* edad,char* posicion,char* nacionalidad,int tamNombre,int tamCadena);
int mostrarMenuListados(int* opcion);
int mostrarListados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int mostrarMenuModificacion(int* opcion);
Jugador* pedirUnJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion,int* indiceEncontrado);
int modificarNombreJugador(Jugador* unJugador,int tamNombre);
int modificarEdadJugador(Jugador* unJugador);
int modificarPosicionJugador(Jugador* unJugador,int tamPosicion);
int modificarNacionalidadJugador(Jugador* unJugador,int tamNacionalidad);
int mostrarMenuConvocar(int* opcion);
int mostrarOpcionConvocar(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
Seleccion* pedirUnaSeleccion(LinkedList* pArrayListSeleccion,int* indiceEncontrado);
Seleccion* buscarUnaSeleccion(LinkedList* pArrayListSeleccion,int idSeleccion);
int ordenarJugadorPorId(void* primerJugador,void* segundoJugador);
int ordenarSeleccionPorId(void* primerSeleccion,void* segundaSeleccion);
int ordenarJugadorPorNacionalidad(void* primerJugador,void* segundoJugador);
int ordenarJugadorPorNombre(void* primerJugador,void* segundoJugador);
int ordenarJugadorPorEdad(void* primerJugador,void* segundoJugador);
int ordenarSeleccionPorConfederacion(void* primerSeleccion,void* segundaSeleccion);
int mostrarMenuOrdenar(int* opcion);
int mostrarOpcionOrdenar(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int mostrarOpcionesGuardarBinario(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int mostrarOpcionesCargarBinario(LinkedList* pArrayListSeleccion);

#endif /* FUNCIONESDEUSUARIO_H_ */
