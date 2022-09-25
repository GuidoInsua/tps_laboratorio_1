
#ifndef FUNCIONESDEINGRESO_H_
#define FUNCIONESDEINGRESO_H_

/**
 * \fn int pedirEntero(int*, int, int, char[], char[])
 * \brief Pide el ingreso de un numero entro, valida que sea un numero y que este en un rango
 *
 * \param direccion , int puntero donde se va a guardar el numero ingresado
 * \param minimo , int valor minimo que puede ser ingresado
 * \param maximo , int valor maximo que puede ser ingresado
 * \param mensaje , cadena el texto que se quiere imprimir para pedir el numero
 * \param mensajeError , cadena el texto que se quiere imprimir si hay algun error
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int pedirEntero(int* direccion, int minimo, int maximo, char mensaje[], char mensajeError[]);

/**
 * \fn int pedirFlotante(float*, float, float, char[], char[])
 * \brief Pide el ingreso de un numero flotante, valida que sea un numero y que este en un rango
 *
 * \param direccion , float puntero donde se va a guardar el numero ingresado
 * \param minimo , float valor minimo que puede ser ingresado
 * \param maximo , float valor maximo que puede ser ingresado
 * \param mensaje , cadena el texto que se quiere imprimir para pedir el numero
 * \param mensajeError , cadena el texto que se quiere imprimir si hay algun error
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int pedirFlotante(float* direccion, float minimo, float maximo, char mensaje[], char mensajeError[]);

/**
 * \fn int pedirCharDosOpciones(char*, char, char, char[], char[])
 * \brief Pide el ingreso de un caracter y valida que sea una de dos opciones dadas
 *
 * \param direccion , char puntero donde se va a guardar el char ingresado
 * \param opcionUno , char primera opcion que se puede ingresar
 * \param opcionDos , char segunda opcion que se puede ingresar
 * \param mensaje , cadena el texto que se quiere imprimir para pedir el numero
 * \param mensajeError , cadena el texto que se quiere imprimir si hay algun error
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int pedirCharDosOpciones(char* direccion, char opcionUno, char opcionDos, char mensaje[], char mensajeError[]);

#endif /* FUNCIONESDEINGRESO_H_ */
