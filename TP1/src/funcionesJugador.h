
#ifndef FUNCIONESJUGADOR_H_
#define FUNCIONESJUGADOR_H_

/**
 * \fn int buscarVacio(int[], int, int*)
 * \brief Recorre un array de enteros buscando un 0 y si lo encuentra devuelve por puntero el indice del array donde esta el 0
 *
 * \param array , array donde busca el 0
 * \param tam , int el tamaño del array
 * \param indice ,int puntero donde manda el indice del array en el que se encuentra el 0
 * \return Retorna 0 si todo fue exitoso, 1 si no hay ningun 0 en el array y -1 si se paso mal algun parametro
 */
int buscarVacio(int array[],int tam,int* indice);

/**
 * \fn int ingresarPosicion(int[], int)
 * \brief Pide ingresar la posicion del jugador y verifica que no se supere la cantidad maxima para cada posicion
 *
 * \param posiciones , array con la cantidad de jugadores por posicion
 * \param tam , int el tamaño del array posiciones
 * \return Retorna 0 si todo fue exitoso, o -1 si se paso mal algun parametro
 */
int ingresarPosicion(int posiciones[],int tam);

/**
 * \fn int ingresarCamiseta(int[], int)
 * \brief Pide ingresar la camiseta de un jugador y verifica que no se haya ingresado antes
 *
 * \param camisetas , array con las camisetas ingresadas
 * \param tam , el tamaño del array camisetas
 * \return Retorna 0 si todo fue exitoso, 1 si no hay mas espacios vacios en el array y -1 si se paso mal algun parametro
 */
int ingresarCamiseta(int camisetas[],int tam);

/**
 * \fn int calcularPromedioConfederaciones(float[], int[], int, int)
 * \brief Calcula el promedio de jugadores por cada confederacion
 *
 * \param promedios , array donde se van a guardar los promedios
 * \param confederaciones , array con la cantidad de jugadores por confederacion
 * \param tam , el tamaño de ambos arrays
 * \param cantidadJugadores
 * \return Retorna 0 si todo fue exitoso, o -1 si se paso mal algun parametro
 */
int calcularPromedioConfederaciones(float promedios[],int confederaciones[],int tam,int cantidadJugadores);

#endif /* FUNCIONESJUGADOR_H_ */
