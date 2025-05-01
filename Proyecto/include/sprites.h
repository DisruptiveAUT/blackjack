// Curso 2024-2025

extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

extern void memoriaReserva();

extern void EstablecerPaletaPrincipal();
/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla principal. El valor 0 es transparente y los valores sin definir, negros */


extern void EstablecerPaletaSecundaria();
/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla secundaria. El valor 0 es transparente y los valores sin definir negros */


extern void GuardarSpritesMemoria();
/* Carga en memoria los Sprites dibujados */


extern void MostrarRombo(int indice, int x, int y);
/* Esta función dibuja un rombo en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarRombo(int indice, int x, int y);
/* Esta función borra de la pantalla el rombo con el índice que se le indique como parámetro */


extern void MostrarRomboGrande(int indice, int x, int y);
/* Esta función dibuja un rombo grande en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarRomboGrande(int indice, int x, int y);
/* Esta función borra de la pantalla el rombo grande con el índice que se le indique como parámetro */


//Dos de picas
extern void Mostrar2picas(int indice, int x, int y);
/* Esta función dibuja un 2 de picas en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar2picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de picas con el índice que se le indique como parámetro */


//Dos de corazones
extern void Mostrar2corazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void Borrar2corazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Dos de diamantes
extern void Mostrar2diamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar2diamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Dos de treboles
extern void Mostrar2treboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar2treboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Tres de picas
extern void Mostrar3picas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar3picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Tres de corazones
extern void Mostrar3corazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar3corazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Tres de diamantes
extern void Mostrar3diamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar3diamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Tres de treboles
extern void Mostrar3treboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar3treboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Cuatro de picas
extern void Mostrar4picas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar4picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Cuatro de corazones
extern void Mostrar4corazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar4corazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Cuatro de diamantes
extern void Mostrar4diamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar4diamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Cuatro de treboles
extern void Mostrar4treboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar4treboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Cinco de picas
extern void Mostrar5picas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar5picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Cinco de corazones
extern void Mostrar5corazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar5corazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Cinco de diamantes
extern void Mostrar5diamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar5diamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Cinco de treboles
extern void Mostrar5treboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar5treboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Seis de picas
extern void Mostrar6picas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar6picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Seis de corazones
extern void Mostrar6corazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar6corazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Seis de diamantes
extern void Mostrar6diamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar6diamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Seis de treboles
extern void Mostrar6treboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar6treboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Siete de picas
extern void Mostrar7picas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar7picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Siete de corazones
extern void Mostrar7corazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar7corazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Siete de diamantes
extern void Mostrar7diamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar7diamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Siete de treboles
extern void Mostrar7treboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar7treboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Ocho de picas
extern void Mostrar8picas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar8picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Ocho de corazones
extern void Mostrar8corazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar8corazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Ocho de diamantes
extern void Mostrar8diamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar8diamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Ocho de treboles
extern void Mostrar8treboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar8treboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Nueve de picas
extern void Mostrar9picas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar9picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Nueve de corazones
extern void Mostrar9corazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar9corazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Nueve de diamantes
extern void Mostrar9diamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar9diamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Nueve de treboles
extern void Mostrar9treboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar9treboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Diez de picas
extern void Mostrar10picas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar10picas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Diez de corazones
extern void Mostrar10corazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar10corazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Diez de diamantes
extern void Mostrar10diamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar10diamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Diez de treboles
extern void Mostrar10treboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void Borrar10treboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//J de picas
extern void MostrarJpicas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarJpicas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//J de corazones
extern void MostrarJcorazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarJcorazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//J de diamantes
extern void MostrarJdiamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarJdiamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//J de treboles
extern void MostrarJtreboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarJtreboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Reina de picas
extern void MostrarQpicas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarQpicas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Reina de corazones
extern void MostrarQcorazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarQcorazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Reina de diamantes
extern void MostrarQdiamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarQdiamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Reina de treboles
extern void MostrarQtreboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarQtreboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Rey de picas
extern void MostrarKpicas(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarKpicas(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Rey de corazones
extern void MostrarKcorazones(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarKcorazones(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Rey de diamantes
extern void MostrarKdiamantes(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarKdiamantes(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


//Rey de treboles
extern void MostrarKtreboles(int indice, int x, int y);
/* Esta función dibuja un 2 de corazones en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */


extern void BorrarKtreboles(int indice, int x, int y);
/* Esta función borra de la pantalla el 2 de corazones con el índice que se le indique como parámetro */


/***********************2024-2025*******************************/