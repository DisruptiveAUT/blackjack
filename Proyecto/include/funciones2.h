// funciones2.h

//Funcion para robar una carta
extern struct Carta robarCarta(int cont, struct Carta x[]);

//Funcion para determinar si se ha perdido o ganado la partida
extern bool calcularPartida(int valorJugador, int valorCrupier);
