
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListSeleccion);
int controller_agregarJugador(LinkedList* pArrayListJugador,int* idAutoIncremental);
int controller_editarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecion);
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_listarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion,char convocado);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, char* confederacion);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_cargarIdAutoIncrementalDesdeTexto(char* path,int* idJugadorAutoIncremental);
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_quitarJugadorSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarUnJugador(Jugador* unJugador,LinkedList* pArrayListSeleccion,char convocado);
int controller_guardarIdAutoIncrementalModoTexto(char* path,int idJugadorAutoIncremental);


