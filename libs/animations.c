#include "animations.h"
#include <stdlib.h>
#include <time.h>
// CORES PARA AS ANIMAÇÕES

const pixel black = {0, 0, 0};
const pixel white = {213, 210, 210};
const pixel green = {32, 216, 26};
const pixel dark_green = {6, 80, 36};
const pixel brown = {181, 68, 81};
const pixel red = {252, 6, 6};
const pixel roxo = {15, 0, 15};
const pixel orange = {255, 65, 0};
const pixel blue = {65, 105, 225};
const pixel yellow = {241, 255, 0};
const pixel gray = {169, 169, 169};
const pixel azul = {0, 0, 255};

// Exemplo de desenho para cada dígito numa matriz 5x5
// Usamos as cores: "black" para LED desligado e "orange" para LED ligado.

// 0 – formato oval com borda acesa
void numero_0(PIO pio, uint sm, float intensity) {
    frame frames[1] = {
        { // 0
          // Linha 1
          black, orange, orange, orange, black,
          // Linha 2 (inverso – espelhada, mas como é simétrica, fica igual)
          orange, black, black, black, orange,
          // Linha 3
          orange, black, black, black, orange,
          // Linha 4 (inverso – espelhada da linha 2)
          orange, black, black, black, orange,
          // Linha 5
          black, orange, orange, orange, black
        }
    };
    draw_pio(frames[0], pio, sm, intensity);
}

// 1 – traço vertical central
void numero_1(PIO pio, uint sm, float intensity) {
    frame frames[1] = {
        { // 1
          // Linha 1
          black, azul, azul, azul, black,
          // Linha 2 (inverso)
          black, black, azul, black, black,
          // Linha 3
          black, black, azul, black, black,
          // Linha 4 (inverso)
          black, azul, azul, black, black,
          // Linha 5
          black, black, azul, black, black
        }
    };
    draw_pio(frames[0], pio, sm, intensity);
}

// 2 – conforme seu exemplo: linhas 2 e 4 invertidas (espelhadas)
void numero_2(PIO pio, uint sm, float intensity) {
    frame frames[1] = {
        { // 2
          // Linha 1
          black, green, green, green, black,
          // Linha 2 (inverso – espelhada: imagem de “lado direito aceso”)
          black, green, black, black, black,
          // Linha 3
          black, green, green, green, black,
          // Linha 4 (inverso – espelhada da linha 2: imagem de “lado esquerdo aceso”)
          black, black, black, green, black,
          // Linha 5
          black, green, green, green, black
        }
    };
    draw_pio(frames[0], pio, sm, intensity);
}

// 3 – formato similar ao 2, mas com ambas as laterais direitas acesas
void numero_3(PIO pio, uint sm, float intensity) {
    frame frames[1] = {
        { // 3
          // Linha 1
          black, roxo, roxo, roxo, black,
          // Linha 2 (inverso – espelhada: lado direito aceso)
          black, black, black, roxo, black,
          // Linha 3
          black, roxo, roxo, roxo, black,
          // Linha 4 (inverso – espelhada: repete a linha 2)
          black, black, black, roxo, black,
          // Linha 5
          black, roxo, roxo, roxo, black
        }
    };
    draw_pio(frames[0], pio, sm, intensity);
}

// 4 – geralmente tem traços verticais em ambos os lados na parte superior e horizontal no meio
void numero_4(PIO pio, uint sm, float intensity) {
    frame frames[1] = {
        { // 4
          // Linha 1
          black, red, black, black, black,
          // Linha 2 (inverso – espelhada; neste caso o padrão é simétrico)
          black, black, black, red, black,
          // Linha 3 (linha do meio acesa)
          black, red, red, red, black,
          // Linha 4 (inverso – espelhada: mostra predominância do lado direito)
          black, red, black, red, black,
          // Linha 5 (inverso – repete a lógica da linha 4)
          black, red, black, red, black
        }
    };
    draw_pio(frames[0], pio, sm, intensity);
}

// 5 – forma que lembra o 2, mas com a inversão oposta nas linhas 2 e 4
void numero_5(PIO pio, uint sm, float intensity) {
    frame frames[1] = {
        { // 5
          // Linha 1
          black, orange, orange, orange, black,
          // Linha 2 (inverso – espelhada: lado esquerdo aceso)
          black, black, black, orange, black,
          // Linha 3
          black, orange, orange, orange, black,
          // Linha 4 (inverso – espelhada: lado direito aceso)
          black, orange, black, black, black,
          // Linha 5
          black, orange, orange, orange, black
        }
    };
    draw_pio(frames[0], pio, sm, intensity);
}

// 6 – geralmente tem parte esquerda acesa e depois adiciona a parte direita na parte inferior
void numero_6(PIO pio, uint sm, float intensity) {
    frame frames[1] = {
        { // 6
          // Linha 1
          black, azul, azul, azul, black,
          // Linha 2 (inverso – espelhada: lado esquerdo aceso)
          black, azul, black, azul, black,
          // Linha 3
          black, azul, azul, azul, black,
          // Linha 4 (inverso – espelhada: mistura vertical para dar curva)
          black, azul, black, black, black,
          // Linha 5
          black, azul, azul, azul, black
        }
    };
    draw_pio(frames[0], pio, sm, intensity);
}

// 7 – formato com topo aceso e predominância do lado direito
void numero_7(PIO pio, uint sm, float intensity) {
    frame frames[1] = {
        { // 7
          // Linha 1
          black, red, black, black, black,
          // Linha 2 (inverso – espelhada: lado direito aceso)
          black, black, black, red, black,
          // Linha 3
          black, red, black, black, black,
          // Linha 4 (inverso – espelhada: repete a linha 2)
          black, black, black, red, black,
          // Linha 5
          black, red, red, red, black
        }
    };
    draw_pio(frames[0], pio, sm, intensity);
}

// 8 – forma “fechada” com ambos os lados acesos (padrões simétricos)
void numero_8(PIO pio, uint sm, float intensity) {
    frame frames[1] = {
        { // 8
          // Linha 1
          black, orange, orange, orange, black,
          // Linha 2 (inverso – espelhada; padrão simétrico)
          black, orange, black, orange, black,
          // Linha 3
          black, orange, orange, orange, black,
          // Linha 4 (inverso – espelhada; igual à linha 2)
          black, orange, black, orange, black,
          // Linha 5
          black, orange, orange, orange, black
        }
    };
    draw_pio(frames[0], pio, sm, intensity);
}

// 9 – similar ao 8, mas com ênfase na parte inferior direita
void numero_9(PIO pio, uint sm, float intensity) {
    frame frames[1] = {
        { // 9
          // Linha 1
          black, azul, azul, azul, black,
          // Linha 2 (inverso – espelhada: mistura dos lados)
          black, black, black, azul, black,
          // Linha 3
          black, azul, azul, azul, black,
          // Linha 4 (inverso – espelhada: destaca o lado direito)
          black, azul, black, azul, black,
          // Linha 5
          black, azul, azul, azul, black
        }
    };
    draw_pio(frames[0], pio, sm, intensity);
}

// Função para desenhar o número dinamicamente (chama a função do dígito desejado)
void desenha_numero(int num, PIO pio, uint sm, float intensity) {
    switch (num) {
        case 0: numero_0(pio, sm, intensity); break;
        case 1: numero_1(pio, sm, intensity); break;
        case 2: numero_2(pio, sm, intensity); break;
        case 3: numero_3(pio, sm, intensity); break;
        case 4: numero_4(pio, sm, intensity); break;
        case 5: numero_5(pio, sm, intensity); break;
        case 6: numero_6(pio, sm, intensity); break;
        case 7: numero_7(pio, sm, intensity); break;
        case 8: numero_8(pio, sm, intensity); break;
        case 9: numero_9(pio, sm, intensity); break;
        default: break;
    }
}

