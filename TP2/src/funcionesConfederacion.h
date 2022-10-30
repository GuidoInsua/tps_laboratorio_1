
#ifndef FUNCIONESCONFEDERACION_H_
#define FUNCIONESCONFEDERACION_H_

#define TAMCADENA 50

typedef struct
{
	int id;  //PK
	char nombre[TAMCADENA];
	char region[TAMCADENA];
	int anioCreacion;
	int isEmpty; //Agrego isEmpty para el ABM de Confederacion
}eConfederacion;

/// \fn int buscarNombreConfederacion(eConfederacion*, int, int, char*)
/// \brief Recorre el array de confederaciones y pasa por puntero el nombre de la confederacion con el mismo id
///
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \param idConfederacion , int el id de la confederacion de la cual se busca el nombre
/// \param nombre , char cadena por donde se pasa el nombre de la confederacions
/// \return retorna 0 si se pasa el nombre, 1 si no existe el id o -1 si se pasa mal algun parametro
int buscarNombreConfederacion(eConfederacion* confederaciones,int tamConfederaciones,int idConfederacion,char* nombre);

/// \fn int mostrarConfederaciones(eConfederacion*, int)
/// \brief
///
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return
int mostrarConfederaciones(eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int pedirIdConfederacion(eConfederacion*, int, int*, char*, char*, int*)
/// \brief
///
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \param respuesta
/// \param mensaje
/// \param mensajeError
/// \param indice
/// \return
int pedirIdConfederacion(eConfederacion* confederaciones,int tamConfederaciones,int* respuesta,char* mensaje,char* mensajeError,int* indice);

/// \fn int mostrarMenuConfederaciones(int*)
/// \brief
///
/// \param opcion
/// \return
int mostrarMenuConfederaciones(int* opcion);

/// \fn int opcionesMenuConfederacion(eConfederacion*, int, int*)
/// \brief
///
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \param idAutoIncremental
/// \return
int opcionesMenuConfederacion(eConfederacion* confederaciones,int tamConfederaciones,int* idAutoIncremental);

/// \fn int buscarConfederacionVacia(eConfederacion*, int, int*)
/// \brief
///
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \param indice
/// \return
int buscarConfederacionVacia(eConfederacion* confederaciones,int tamConfederaciones,int* indice);

/// \fn int altaConfederacion(eConfederacion*, int, int*)
/// \brief
///
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \param idAutoIncremental
/// \return
int altaConfederacion(eConfederacion* confederaciones,int tamConfederaciones,int* idAutoIncremental);

/// \fn int bajaConfederacion(eConfederacion*, int)
/// \brief
///
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return
int bajaConfederacion(eConfederacion* confederaciones,int tamConfederaciones);

/// \fn int mostrarMenuModificacionConfederacion(int*)
/// \brief
///
/// \param opcion
/// \return
int mostrarMenuModificacionConfederacion(int* opcion);

/// \fn int modificarConfederacion(eConfederacion*, int)
/// \brief
///
/// \param confederaciones , puntero a array de tipo eConfederaciones, donde van a estar las confederaciones cargadas
/// \param tamConfederaciones , int tamanio del array 'confederaciones' de tipo eConfederaciones
/// \return
int modificarConfederacion(eConfederacion* confederaciones,int tamConfederaciones);

#endif /* FUNCIONESCONFEDERACION_H_ */
