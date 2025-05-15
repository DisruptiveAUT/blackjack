// cartas_funciones.h

#ifndef CARTAS_FUNCIONES_H
#define CARTAS_FUNCIONES_H

typedef void (*FuncionCarta)(int indice, int x, int y);

// Declaración de los arrays externos
extern FuncionCarta funcionesMostrar[4];
extern FuncionCarta funcionesBorrar[4];

#endif
