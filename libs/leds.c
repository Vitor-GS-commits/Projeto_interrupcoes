#include "leds.h"

// Rotina para definição da intensidade de cores do LED
uint32_t matrix_rgb(uint r, uint g, uint b, float intensity)
{
    uint8_t R = (uint8_t)(r * intensity);
    uint8_t G = (uint8_t)(g * intensity);
    uint8_t B = (uint8_t)(b * intensity);
    return (G << 24) | (R << 16) | (B << 8);
}

// Rotina para acionar a matriz de LEDs - WS2812B
void draw_pio(pixel *draw, PIO pio, uint sm, float intensity)
{
    for (int16_t i = 0; i < PIXELS; i++)
    {
        uint32_t valor_led = matrix_rgb(draw[i].red, draw[i].green, draw[i].blue, intensity);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
}
