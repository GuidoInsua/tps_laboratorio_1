
#ifndef FUNCIONESUSUARIO_H_
#define FUNCIONESUSUARIO_H_

/**
 * \fn int mostrarMenuPrincipal(int*, float, float, float, int[])
 * \brief Imprime el menu principal con las opciones posibles y pasa por puntero la eleccion
 *
 * \param opcion ,puntero a la eleccion del usuario
 * \param hospedaje ,flotante con el costo del hospedaje
 * \param comida ,flotante con el costo de la comida
 * \param transporte ,flotante con el costo del transporte
 * \param posiciones ,array con la cantidadad de jugadores en cada posicion
 * \return Retorna 0 si todo fue exitoso, o -1 si se paso mal algun parametro
 */
int mostrarMenuPrincipal(int *opcion,float hospedaje,float comida,float transporte,int posiciones[]);

/**
 * \fn int mostrarMenuCostos(int*, float, float, float)
 * \brief Imprime un menu con solo los costos, pide que costo ingresar y pasa por puntero la eleccion
 *
 * \param opcion ,puntero a la eleccion del usuario
 * \param hospedaje ,flotante con el costo del hospedaje
 * \param comida ,flotante con el costo de la comida
 * \param transporte ,flotante con el costo del transporte
 * \return Retorna 0 si todo fue exitoso, o -1 si se paso mal algun parametro
 */
int mostrarMenuCostos(int *opcion,float hospedaje,float comida,float transporte);

/**
 * \fn int iniciarJugadores(int[], int[], int[], int, int, int)
 * \brief Pone a todas las posiciones, camisetas y confederaciones en 0
 *
 * \param posiciones ,array con la cantidadad de jugadores en cada posicion
 * \param camisetas ,array con las camisetas de los jugadores
 * \param confederaciones ,array can la cantidad de jugadores en cada confederacion
 * \param tamP ,int tamaño del array posiciones
 * \param tamR ,int tamaño del array camisetas
 * \param tamC ,int tamaño del array confederaciones
 * \return Retorna 0 si todo fue exitoso, o -1 si se paso mal algun parametro
 */
int iniciarJugadores(int posiciones[],int camisetas[],int confederaciones[],int tamP,int tamR,int tamC);

/**
 * \fn int cargarJugadores(int[], int[], int[], int, int, int)
 * \brief pide y carga una posicion de tres arrays con la posicion, camiseta y confederacion de un jugador
 *
 * \param posiciones ,array con la cantidadad de jugadores en cada posicion
 * \param camisetas ,array con las camisetas de los jugadores
 * \param confederaciones ,array can la cantidad de jugadores en cada confederacion
 * \param tamP ,int tamaño del array posiciones
 * \param tamR ,int tamaño del array camisetas
 * \param tamC ,int tamaño del array confederaciones
 * \return Retorna 0 si todo fue exitoso, o -1 si se paso mal algun parametro
 */
int cargarJugadores(int posiciones[],int camisetas[],int confederaciones[],int tamP,int tamR,int tamC);

/**
 * \fn int imprimirRespultados(float[], float, float, int)
 * \brief Imprime los resultados del promedio de jugadores por cada confederacion y el costo total de mantenimiento
 *
 * \param promedios , array con cada promedio por confederacion
 * \param costoTotalMantenimiento , float con el costo total de mantenimiento
 * \param costoTotalAumento , float con el posible aumento de mantenimiento
 * \param tam , tamaño del array promedios
 * \return Retorna 0 si todo fue exitoso, o -1 si se paso mal algun parametro
 */
int imprimirResultados(float promedios[],float costoTotalMantenimiento,float costoTotalAumento,int tam);

#endif /* FUNCIONESUSUARIO_H_ */
