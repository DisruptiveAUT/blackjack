// cartas_funciones.h

#ifndef CARTAS_FUNCIONES_H
#define CARTAS_FUNCIONES_H

typedef void (*FuncionCarta)(int indice, int x, int y);

// Declaración de los arrays externos
extern FuncionCarta funcionesMostrar[6];
extern FuncionCarta funcionesBorrar[6];

#endif
