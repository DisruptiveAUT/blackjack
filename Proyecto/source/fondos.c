// Curso 2024-2025

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación */

#include "fondos.h"
#include "graficos.h"
#include "diseno.h"
#include "partidaPerdida.h"
#include "portada.h"
#include "seleccionarApuesta.h"
#include "menuPausa.h"
#include "victoria.h"
#include "dineroPerdido.h"

/* Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria */
static const int DMA_CHANNEL = 3;

/* Para cada fondo que se quiera visualizar hay que escribir un procedimiento como el siguiente */

void diseno() // Esta función dibuja el fondo de la pantalla de juego
{

    dmaCopyHalfWords(DMA_CHANNEL,
                     disenoBitmap,            // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     disenoBitmapLen);        // Longitud en bytes, variable que se genera automáticamente
}

void partidaPerdida() // Esta función dibuja el fondo de la pantalla de cuando se pierde el dinero apostado
{

    dmaCopyHalfWords(DMA_CHANNEL,
                     partidaPerdidaBitmap,     // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0),  // Dirección del fondo principal
                     partidaPerdidaBitmapLen); // Longitud en bytes, variable que se genera automáticamente
}

void portada() // Esta función dibuja el fondo de la pantalla de inicio
{

    dmaCopyHalfWords(DMA_CHANNEL,
                     portadaBitmap,           // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     portadaBitmapLen);       // Longitud en bytes, variable que se genera automáticamente
}

void seleccionarApuesta() // Esta función dibuja el fondo de la pantalla de selección de apuesta
{

    dmaCopyHalfWords(DMA_CHANNEL,
                     seleccionarApuestaBitmap,     // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0),      // Dirección del fondo principal
                     seleccionarApuestaBitmapLen); // Longitud en bytes, variable que se genera automáticamente
}

void menuPausa() // Esta función dibuja el fondo de la pantalla de pausa
{

    dmaCopyHalfWords(DMA_CHANNEL,
                     menuPausaBitmap,         // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     menuPausaBitmapLen);     // Longitud en bytes, variable que se genera automáticamente
}

void victoria() // Esta función dibuja el fondo de la pantalla de victoria
{

    dmaCopyHalfWords(DMA_CHANNEL,
                     victoriaBitmap,          // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     victoriaBitmapLen);      // Longitud en bytes, variable que se genera automáticamente
}

void dineroPerdido() // Esta función dibuja el fondo de la pantalla que sale cuando pierdes todo el dinero
{

    dmaCopyHalfWords(DMA_CHANNEL,
                     dineroPerdidoBitmap,     // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     dineroPerdidoBitmapLen); // Longitud en bytes, variable que se genera automáticamente
}

/***********************2024-2025*******************************/
