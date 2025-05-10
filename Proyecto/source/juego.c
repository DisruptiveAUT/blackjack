// Curso 2024-2025




#include <nds.h> 		// Libreria de la nds
#include <stdio.h>		// Libreria de entrada/salida estándar de C
#include <stdlib.h>		// Libreria estándar de C para reserva de memoria y conversiones numéricas
#include <unistd.h>		// Libreria para asegurar la compatibilidad entre sistemas operativos

// Librerias desarrolladas por nosotros para el proyecto
	
#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"
#include "sprites.h"

//int tiempo;

void juego()
{	

	int Conf_Tec = 0x400C; //a insertar en TECLAS_CNT activa START Y SELECT 0100 0000 0000 1100 
	int Conf_Tempo = 0xC1; //a insertar en TIMER0_CNT 1100 0001
	int latch = 48060 ; //latch pasar a timer0_DAT
	ConfigurarTeclado(Conf_Tec);
	ConfigurarTemporizador( latch , Conf_Tempo);
	EstablecerVectorInt();
	HabilitarIntTeclado();
	HabilitarIntTempo();
	PonerEnMarchaTempo();
	EstablecerVectorInt();
	int cartasCrupier = 0; //valor numerico de la mano en total
	int cartasJugador = 0; //valor numerico de la mano en total
	int contadorBaraja = 0; //cantidad de cartas robadas
	int contadorCrupier = 0; //cantidad de cartas robadas (apunta siempre al siguiente)
	int contadorJugador = 0; //cantidad de cartas robadas (apunta siempre al siguiente)
	int seg = 0;
	int dinero = 100; 
	int apuesta = 0;
	bool crupierMostradas = false;  
	Carta manoJugadorLimpio[5]; 
	Carta manoCrupierLimpio[5];
	void vaciarVariables(){
		 cartasCrupier = 0;
		 cartasJugador = 0;
		 contadorBaraja = 0;
		 contadorCrupier = 0;
		 contadorJugador = 0;
		 seg = 0;	
		 apuesta = 0; 
		 crupierMostradas = false;
		 manoJugador = manoJugadorLimpio;
		 manoCrupier = manoCrupierLimpio;
		 construirBaraja(baraja);
		 shuffle(baraja, sizeof(baraja)/sizeof(baraja[0]));
	}
	
	srand(time(NULL));
	Carta baraja [52];
	construirBaraja(baraja);
	shuffle(baraja, sizeof(baraja)/sizeof(baraja[0]));
	touchPosition pos_pantalla;
	void robarCartaJugador(){
		manoJugador[contadorJugador] =  robarCarta( contadorBaraja, baraja);
			cartasJugador = cartasJugador + manoJugador[contadorJugador].valorNum; 
			if (cartasJugador > 21 && manoJugador[contadorJugador].valorNum == 11){
				cartasJugador = cartasJugador - 10; 
			}
			contadorJugador++;
			
			
	}
	void robarCartaCrupier(){
		manoCrupier[contadorCrupier] = robarCarta (contadorBaraja, baraja);
			cartasCrupier = cartasCrupier + manoCrupier[contadorCrupier].valorNum; 
			if (cartasCrupier > 21 && manoCrupier[contadorCrupier].valorNum == 11){
				cartasCrupier = cartasCrupier - 10; 
			}
			contadorCrupier++;
	}

	while(1)
	{	
		iprintf("\x1b[11;5HDinero apostado=%d", apuesta);
		iprintf("\x1b[10;5HDinero restante=%d", dinero);
	if (ESTADO == INICIO){
		portada();
	
		if ((pos_pantalla.px >= 29 && pos_pantalla.px <= 229 &&
			pos_pantalla.py >= 46 && pos_pantalla.py <= 101)){ //si se pulsa START o se le da al boton central
	
		ESTADO = APOSTAR;
		}
	// FINAL CONDICIONAL DE ESTADO INICIO
	

	}  else if (ESTADO == APOSTAR){
		seleccionarApuesta();
			
			if((pos_pantalla.px >= 15 && pos_pantalla.px <= 47 &&
				pos_pantalla.py >= 100 && pos_pantalla.py <= 132) && dinero >= 1){//boton de anadir 1 ficha
				apuesta = apuesta + 1;
				dinero = dinero - 1;
			} else if((pos_pantalla.px >= 62 && pos_pantalla.px <= 94 &&
				pos_pantalla.py >= 100 && pos_pantalla.py <= 132) && dinero >= 10){//boton de anadir 10 fichas
				apuesta = apuesta + 10;
				dinero = dinero - 10;
			} else if((pos_pantalla.px >= 109 && pos_pantalla.px <= 141 &&
				pos_pantalla.py >= 100 && pos_pantalla.py <= 132) && dinero >= 20){//boton de anadir 20 fichas
				apuesta = apuesta + 20;
				dinero = dinero - 20;
			} else if((pos_pantalla.px >= 156 && pos_pantalla.px <= 188 &&
				pos_pantalla.py >= 100 && pos_pantalla.py <= 132) && dinero >= 50){//boton de anadir 50 fichas
				apuesta = apuesta + 50;
				dinero = dinero - 50;
			} else if((pos_pantalla.px >= 203 && pos_pantalla.px <= 235 &&
				pos_pantalla.py >= 100 && pos_pantalla.py <= 132) && dinero != 0){//boton de all in
				apuesta = apuesta + dinero;
				dinero = 0;
			} 
		
		//FINAL CONDICIONAL DE ESTADO APOSTAR
	} else if (ESTADO == JUGAR){
		diseno();
		if (contadorBaraja < 4 ){

		
		for (int i = 0; i < 2; i++){ //las dos cartas obligatorias del Jugador 
			manoJugador[i] = robarCarta( contadorBaraja, baraja);
			contadorBaraja++;	
			contadorJugador++;
			if (manoJugador[i].valorNum == 11){// si es un as
				if (cartasJugador + manoJugador[i].valorNum > 21 ){ //el as cuenta como 11 o 1 segun convenga
					cartasJugador = cartasJugador + 1;
				}else {
					cartasJugador = cartasJugador + 11;
				}
			}else {
				cartasJugador = cartasJugador + manoJugador[i].valorNum;
			}
			ponerCartaJugador(manoJugador[i], i); // poner las primeras dos cartas robadas del jugador en sus espacios

		}
		for (int i = 0; i < 2; i++ ){ //las dos cartas obligatorias del crupier
			manoCrupier[i] = robarCarta( contadorBaraja, baraja);
			contadorBaraja++;
			contadorCrupier++;
			if (manoCrupier[i].valorNum == 11){
				if (cartasCrupier + manoCrupier[i].valorNum > 21 ){ //el as cuenta como 11 o 1 segun convenga
					cartasCrupier = cartasCrupier + 1;
				}else {
					cartasCrupier = cartasCrupier + 11;
				}
			}else {
				cartasCrupier = cartasCrupier + manoCrupier[i].valorNum;
			}
		}

		} 

		if( (pos_pantalla.px >= 198 && pos_pantalla.px <= 246 &&
			pos_pantalla.py >= 96 && pos_pantalla.py <= 128 ) || cartasJugador >= 21) { //si se decide ya jugar pulsando el boton stay o el jugador ya ha superado 21
				crupierMostradas = true;
				while (cartasCrupier < 17){ //el crupier deja de robar si tiene 17 o mas
					robarCartaCrupier();
				}
				for (int i = 0; i < contadorCrupier-1; i++){
					ponerCartaCrupier(manoCrupier[i], i); //muestra todas a la vez

				}
			if (calcularPartida(cartasJugador, cartasCrupier)){// si se pierde la partida cambiar estado 
				ESTADO = GANAR;
				dinero = dinero + (2*apuesta); 
				victoria();
			}else if(!(calcularPartida(cartasJugador, cartasCrupier))){
				ESTADO = FIN;
				partidaPerdida();
				vaciarVariables();
			}
		}else if (pos_pantalla.px >= 198 && pos_pantalla.px <= 246 &&
			pos_pantalla.py >= 64 && pos_pantalla.py < 96 ) { //pulsa el boton de hit
			
			robarCartaJugador();
			ponerCartaJugador(manoJugador[contadorJugador-1], contadorJugador-1);
			
		}
			
	}else if (ESTADO == PAUSA){
		if (pos_pantalla.px >= 46 && pos_pantalla.px <= 78 &&
			pos_pantalla.py >= 58 && pos_pantalla.py <= 90){// si se pulsa el boton de reanudar
			ESTADO = JUGAR;
			diseno();
			for (int i = 0; i < contadorJugador - 1; i++){
				ponerCartaJugador(manoJugador[i], i);
			}
			if(crupierMostradas == true){
				for (int i = 0; i < contadorCrupier - 1; i++){
					ponerCartaCrupier(manoCrupier[i], i);
				}
			}
		}else if (pos_pantalla.px >= 175 && pos_pantalla.px <= 207 &&
			pos_pantalla.py >= 58 && pos_pantalla.py <= 90){// si se pulsa el boton de finalizar
			ESTADO = INICIO;
			construirBaraja(baraja); //barajar cartas y reiniciar
			shuffle(baraja, sizeof(baraja)/sizeof(baraja[0]));
			vaciarVariables();
			portada();
		}
	}else if (ESTADO == FIN){
		if (dinero <= 0){
			mostrarPerdido();
			partidaPerdida()
			dinero = 100;
			vaciarVariables();
			mostrarInicio();
			ESTADO = INICIO;
			portada();
		}
		if (TeclaPulsada() == A || pos_pantalla.px >= 1 && pos_pantalla.px <= 254 &&
			pos_pantalla.py >= 1 && pos_pantalla.py <= 192){ //tocar la pantalla o pulsar a
			ESTADO = APOSTAR;
			vaciarVariables();
			portada();
		}
	}else if (ESTADO == GANAR){
			victoria();
			vaciarVariables();
			if (pos_pantalla.px >= 1 && pos_pantalla.px <= 254 &&
				pos_pantalla.py >= 1 && pos_pantalla.py <= 192){ //tocar la pantalla o pulsar a
				ESTADO = APOSTAR;
				seleccionarApuesta();
			}
			
	}
	
	//DeshabilitarInterrrupciones();
	// Inhibir las interrupciones al final
	} //FINAL WHILE PRINCIPAL 
}

/***********************2024-2025*******************************/


