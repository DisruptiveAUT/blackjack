// cartas_funciones.h

#ifndef CARTAS_FUNCIONES_H
#define CARTAS_FUNCIONES_H

typedef void (*FuncionCarta)(int indice, int x, int y);

// Declaración de los arrays externos
extern FuncionCarta funcionesMostrar[12];
extern FuncionCarta funcionesBorrar[12];

#endif
