
#ifndef FUNCIONESJUGADOR_H_
#define FUNCIONESJUGADOR_H_

typedef struct
{
	int id;  //PK
	char nombre[TAMCADENA];
	char posicion[TAMCADENA];
	short numeroCamiseta;
	int idConfederacion;  //FK
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

/// \fn int mostrarMenu(int*)
/// \brief Imprime un menu con las opciones para ABM, y manda por puntero la eleccion
///
/// \param opcion, char puntero donde se guarda la eleccion
/// \return , retorna 0 si sale todo correcto o -1 se se pasa mal algun parametro
int mostrarMenu(int* opcion);

/// \fn int iniciarIsEmpty(eJugador*, int, eConfederacion*, int)
/// \brief Pone el campo isEmpty del array jugadores y confederaciones en 0
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return , retorna 0 si sale todo correcto o -1 se se pasa mal algun parametro
int iniciarIsEmpty(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int buscarJugadorVacio(eJugador*, int, int*)
/// \brief Recorre el array de jugadores y pasa por puntero el indice del primer jugador con isEmpty en 0
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param indice , int puntero por donde se pasa la posicion del jugador
/// \return retorna 0 si sale todo correcto, 1 si no hay jugadores vacios y -1 se se pasa mal algun parametro
int buscarJugadorVacio(eJugador* jugadores,int tamJugadores,int* indice);

/// \fn int altaJugador(eJugador*, int, eConfederacion*, int, int*)
/// \brief Pide los datos de un jugador y los carga en el primer indice del array jugador que este vacio
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \param idJugador , int el id auto incremental de los jugadores
/// \return retorna 0 si el jugador se carga con exito, 1 si el jugador no se carga, -2 si no hay mas espacio en el array y -1 si se pasa mal algun parametro
int altaJugador(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones,int* idJugador);

/// \fn int buscarExistenciaJugador(eJugador*, int, int*, int)
/// \brief Recorre el array de jugadores y los compara el el id pasado por parametro, si lo encuentra pasa el indice por puntero
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param indice , int puntero por donde se pasa la posicion del jugador
/// \param idJugador , int el id del jugador que se esta buscando
/// \return , retorna 0 si se encuentra el jugador, 1 si no se encuentra y -1 si se pasa mal algun parametro
int buscarExistenciaJugador(eJugador* jugadores,int tamJugadores,int* indice,int idJugador);

/// \fn int pedirUnJugador(eJugador*, int, eConfederacion*, int, int*, int*)
/// \brief Muestra los jugadores ingresados y pide el id de un jugador
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \param idJugador , int puntero por donde se pasa el id del jugador
/// \param indiceJugador , int puntero por donde se pasa la posicion del jugador
/// \return retorna 0 si logra pasar el jugador, 1 si el jugador no existe y -1 si se pasa mal algun parametro
int pedirUnJugador(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones,int* idJugador,int* indiceJugador);

/// \fn int bajaJugador(eJugador*, int, eConfederacion*, int)
/// \brief Pide el id de un jugador y pone su isEmpty en 0
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return , retorna 0 si el jugador se da de baja, 1 si se cancela la baja y -1 si se pasa mal algun parametro
int bajaJugador(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int mostrarMenuModificacion(int*)
/// \brief Imprime un menu con las opciones para modificar el jugador, y manda por puntero la eleccion
///
/// \param opcion, char puntero donde se guarda la eleccion
/// \return , retorna 0 si sale todo correcto o -1 se se pasa mal algun parametro
int mostrarMenuModificacion(int* opcion);

/// \fn int modificarJugador(eJugador*, int, eConfederacion*, int)
/// \brief Pide un jugador y modifica lo que el usuario ingrese
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return , retorna 0 si todo sale exitoso y -1 si se pasa mal algun parametro
int modificarJugador(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int buscarCantidadJugadores(eJugador*, int, int*)
/// \brief Recorre el array de jugadores y suma todos los que esten cargados, pasa por puntero la cantidad
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param cantidad , int puntero por donde se pasa la cantidad de jugadores cargados
/// \return , retorna 0 si todo sale exitoso y -1 si se pasa mal algun parametro
int buscarCantidadJugadores(eJugador* jugadores,int tamJugadores,int* cantidad);

#endif /* FUNCIONESJUGADOR_H_ */
