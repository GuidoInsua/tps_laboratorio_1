
#ifndef FUNCIONESINFORME_H_
#define FUNCIONESINFORME_H_

/// \fn int listarUnJugador(eJugador, eConfederacion*, int)
/// \brief Imprime los datos de un jugador
///
/// \param unJugador , eJugador el jugador que se quiere imprimir
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return , retorna 0 si logra imprimir el jugador, 1 si el jugador no existe y -1 si se pasa mal algun parametro
int listarUnJugador(eJugador unJugador,eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int listarJugadores(eJugador*, int, eConfederacion*, int)
/// \brief Imprime todos los jugadores llamando varias veces a la funcion 'listarUnJugador'
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return , retorna 0 si todo sale exitoso y -1 si se pasa mal algun parametro
int listarJugadores(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int ordenarJugadoresPorId(eJugador*, int)
/// \brief Recorre el array de jugadores y los ordena por id de menor a mayor
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \return , retorna 0 si todo sale exitoso y -1 si se pasa mal algun parametro
int ordenarJugadoresPorId(eJugador* jugadores,int tamJugadores);

/// \fn int ordenarJugadoresConfederacionNombre(eJugador*, int, eConfederacion*, int)
/// \brief recorre el array de jugadores y confederaciones y los ordena primero por confederacion y despues por nombre
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return , retorna 0 si los ordena, 1 si no hace falta ordenar y -1 si se pasa mal algun parametro
int ordenarJugadoresConfederacionNombre(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int listarUnaConfederacion(eJugador*, int, int, char*)
/// \brief Imprime los datos de una confederacion y sus jugadores
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param idConfederacion , int el id de la confederacion que se quiere imprimir
/// \param nombre , char cadena por donde se pasa el nombre de la confederacion
/// \return , retorna 0 si sale todo exitoso y -1 si se pasa mal algun parametro
int listarUnaConfederacion(eJugador* jugadores,int tamJugadores,int idConfederacion,char* nombre);

/// \fn int listarConfederacionesConJugador(eJugador*, int, eConfederacion*, int)
/// \brief Imprime todas las confederaciones con sus jugadores
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return , retorna 0 si sale todo exitoso y -1 si se pasa mal algun parametro
int listarConfederacionesConJugador(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int mostarMenuInformes(int*)
/// \brief Imprime un menu con las opciones para informes, y manda por puntero la eleccion
///
/// \param opcion, char puntero donde se guarda la eleccion
/// \return , retorna 0 si sale todo correcto o -1 se se pasa mal algun parametro
int mostarMenuInformes(int* opcion);

/// \fn int informarDatos(eJugador*, int, eConfederacion*, int)
/// \brief Informa la opcion que el usuario ingrese
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return , retorna 0 si sale todo correcto o -1 se se pasa mal algun parametro
int informarDatos(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int informarSalarios(eJugador*, int)
/// \brief Informa el salario promedio de los jugadores, el salario total y la cantidad de jugadores que superan el promedio
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \return , retorna 0 si sale todo correcto o -1 se se pasa mal algun parametro
int informarSalarios(eJugador* jugadores,int tamJugadores);

/// \fn int buscarTotalPorConfederacion(eJugador*, int, eConfederacion*, int, int*, int)
/// \brief Llena un array con el total de jugadores por confederacion o el total de anios por confederacion dependiendo de opcion 1 o 0
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \param array , int array que se quiere llenar
/// \param opcion , int opcion 1 para anios o 0 para cantidad jugadores
/// \return
int buscarTotalPorConfederacion(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones,int* array,int opcion);

/// \fn int ordenarArrayPararelos(int*, int*, int)
/// \brief Ordena dos array en pararelos en funcion del primero
///
/// \param primerArray , el primer array
/// \param segundoArray , el segundo array
/// \param tamArray , el tamanio de ambos array
/// \return
int ordenarArrayPararelos(int* primerArray,int* segundoArray,int tamArray);

/// \fn int buscarConfederacionConMasAnios(eJugador*, int, eConfederacion*, int)
/// \brief
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return
int buscarConfederacionConMasAnios(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int buscarPorcentajeJugadoresPorConfederacion(eJugador*, int, eConfederacion*, int, float*)
/// \brief
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \param arrayPorcentaje
/// \return
int buscarPorcentajeJugadoresPorConfederacion(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones,float* arrayPorcentaje);

/// \fn int buscarNombreRegion(eConfederacion*, int, int, char*)
/// \brief
///
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \param idConfederacion
/// \param nombre
/// \return
int buscarNombreRegion(eConfederacion* confederaciones,int tamConfederaciones,int idConfederacion,char* nombre);

/// \fn int buscarRegionConMasJugadores(eJugador*, int, eConfederacion*, int)
/// \brief
///
/// \param jugadores , puntero a array de tipo eJugador, donde van a estar los articulos cargados
/// \param tamJugadores , int tamanio del array 'jugadores' de tipo eJugadores
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return
int buscarRegionConMasJugadores(eJugador* jugadores,int tamJugadores,eConfederacion* confederaciones,int tamConfederaciones);


#endif /* FUNCIONESINFORME_H_ */
