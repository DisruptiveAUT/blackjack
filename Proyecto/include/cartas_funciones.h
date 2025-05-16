// cartas_funciones.h

#ifndef CARTAS_FUNCIONES_H
#define CARTAS_FUNCIONES_H

typedef void (*FuncionCarta)(int indice, int x, int y); //Creacion de punteros a funciones para mostrar y borrar cartas

// Declaración de los arrays externos
extern FuncionCarta funcionesMostrar[13]; //Array de punteros para las funciones de mostrar cartas
extern FuncionCarta funcionesBorrar[13]; //Array de punteros para las funciones de borrar cartas

#endif
