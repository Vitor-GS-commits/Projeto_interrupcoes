#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "libs/leds.h"



// Funções para desenhar os dígitos individuais (matriz 5x5)
void numero_0(PIO pio, uint sm, float intensity);
void numero_1(PIO pio, uint sm, float intensity);
void numero_2(PIO pio, uint sm, float intensity);
void numero_3(PIO pio, uint sm, float intensity);
void numero_4(PIO pio, uint sm, float intensity);
void numero_5(PIO pio, uint sm, float intensity);
void numero_6(PIO pio, uint sm, float intensity);
void numero_7(PIO pio, uint sm, float intensity);
void numero_8(PIO pio, uint sm, float intensity);
void numero_9(PIO pio, uint sm, float intensity);

// Função para desenhar um número dinamicamente (0-9)
// Exemplo de uso: desenha_numero(5, pio, sm, intensity);
void desenha_numero(int num, PIO pio, uint sm, float intensity);

#endif