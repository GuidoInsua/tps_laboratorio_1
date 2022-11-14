
#ifndef PARSER_H_
#define PARSER_H_

int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_idFromText(FILE* pFile,int* idJugadorAutoIncremental);
int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, char* confederacion);
int parser_JugadorToText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_SeleccionToText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_idToText(FILE* pFile,int idJugadorAutoIncremental);

#endif /* PARSER_H_ */
