// Curso 2024-2025
#include "definiciones.h"
extern u16 *gfx;
extern u16 *gfx2;
extern u16 *gfx3;
extern u16 *gfxSub;

extern void memoriaReserva();

extern void EstablecerPaletaPrincipal();
/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla principal. El valor 0 es transparente y los valores sin definir, negros */

extern void EstablecerPaletaSecundaria();
/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla secundaria. El valor 0 es transparente y los valores sin definir negros */

extern void GuardarSpritesMemoria();
/* Carga en memoria los Sprites dibujados */

// extern void MostrarRombo(int indice, int x, int y);
/* Esta función dibuja un rombo en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

// extern void BorrarRombo(int indice, int x, int y);
/* Esta función borra de la pantalla el rombo con el índice que se le indique como parámetro */

// extern void MostrarRomboGrande(int indice, int x, int y);
/* Esta función dibuja un rombo grande en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

// Dos de picas
extern void Mostrar2picas(int indice, int x, int y);
/* Esta función dibuja un 2 de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void Borrar2picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de picas con el índice que se le indique como parámetro */

// Tres de picas
extern void Mostrar3picas(int indice, int x, int y);
/* Esta función dibuja un 3 de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void Borrar3picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 3 de picas con el índice que se le indique como parámetro */

// Cuatro de picas
extern void Mostrar4picas(int indice, int x, int y);
/* Esta función dibuja un 4 de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void Borrar4picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 4 de picas con el índice que se le indique como parámetro */

// Cinco de picas
extern void Mostrar5picas(int indice, int x, int y);
/* Esta función dibuja un 5 de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void Borrar5picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 5 de picas con el índice que se le indique como parámetro */

// Seis de picas
extern void Mostrar6picas(int indice, int x, int y);
/* Esta función dibuja un 6 de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void Borrar6picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 6 de picas con el índice que se le indique como parámetro */

// Siete de picas
extern void Mostrar7picas(int indice, int x, int y);
/* Esta función dibuja un 7 de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void Borrar7picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 7 de picas con el índice que se le indique como parámetro */

// Ocho de picas
extern void Mostrar8picas(int indice, int x, int y);
/* Esta función dibuja un 8 de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void Borrar8picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 8 de picas con el índice que se le indique como parámetro */

// Nueve de picas
extern void Mostrar9picas(int indice, int x, int y);
/* Esta función dibuja un 9 de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void Borrar9picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 9 de picas con el índice que se le indique como parámetro */

// Diez de picas
extern void Mostrar10picas(int indice, int x, int y);
/* Esta función dibuja un 10 de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void Borrar10picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 10 de picas con el índice que se le indique como parámetro */

// J de picas
extern void MostrarJpicas(int indice, int x, int y);
/* Esta función dibuja un J de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void BorrarJpicas(int indice, int x, int y);
/* Esta función borra de la pantalla el J de picas con el índice que se le indique como parámetro */

// Reina de picas
extern void MostrarQpicas(int indice, int x, int y);
/* Esta función dibuja un Q de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void BorrarQpicas(int indice, int x, int y);
/* Esta función borra de la pantalla el Q de picas con el índice que se le indique como parámetro */

// Rey de picas
extern void MostrarKpicas(int indice, int x, int y);
/* Esta función dibuja un K de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void BorrarKpicas(int indice, int x, int y);
/* Esta función borra de la pantalla el K de picas con el índice que se le indique como parámetro */

extern void mostrarCartaCrupier(struct Carta x, int manoCrupier);
//Funcion para mostrar las cartas del crupier

extern void mostrarCartaJugador(struct Carta x, int manoJugador);
//Funcion para mostrar las cartas del jugador

/***********************2024-2025*******************************/