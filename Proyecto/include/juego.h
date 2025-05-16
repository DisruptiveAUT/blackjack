// Curso 2024-2025

/*---------------------------------------------------------------------------------
juego.h
---------------------------------------------------------------------------------*/
void juego();
//Funcion principal

void vaciarVariables();
//Funcion para resetear los valores de las variables

void robarCartaJugador();
//Funcion para añadirle cartas al jugador

void robarCartaCrupier();
//Funcion para añadirle cartas al crupier

bool llamadaCalcularPartida();
//Funcion que devuelve el resultado de calcularPartida

//Variables globales

extern int cartasCrupier;
//Valor numerico de las cartas del crupier

extern int cartasJugador;
//Valor numerico de las cartas del jugador

extern int contadorBaraja;
//Cantidad de cartas sacadas de la baraja

extern int contadorCrupier;
//Cantidad de cartas del crupier

extern int contadorJugador;
//Catidad de cartas del jugador

extern int seg;
//Contador de segundos 

extern int dinero;
//Dinero disponible

extern int apuesta;
//Dinero apostado

extern bool crupierMostradas;
//Si las cartas del crupier estan mostradas o no

extern struct Carta manoJugador[5];
//Cartas del jugador

extern struct Carta manoCrupier[5];
//Cartas del crupier

extern struct Carta manoJugadorLimpio[5];
//Struct de cartas vacio

extern struct Carta manoCrupierLimpio[5];
//Struct de cartas vacio

extern struct Carta baraja[52];
//Baraja con todas las cartas a utilizar

/***********************2024-2025*******************************/
