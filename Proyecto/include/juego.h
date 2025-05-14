// Curso 2024-2025

/*---------------------------------------------------------------------------------
juego.h
---------------------------------------------------------------------------------*/
void juego();
void vaciarVariables();
void robarCartaJugador();
void robarCartaCrupier();
bool llamadaCalcularPartida();

// juego.h

extern int cartasCrupier;
extern int cartasJugador;
extern int contadorBaraja;
extern int contadorCrupier;
extern int contadorJugador;
extern int seg;
extern int dinero;
extern int apuesta;
extern bool crupierMostradas;

extern struct Carta manoJugador[5];
extern struct Carta manoCrupier[5];
extern struct Carta manoJugadorLimpio[5];
extern struct Carta manoCrupierLimpio[5];
extern struct Carta baraja[52];


/***********************2024-2025*******************************/

