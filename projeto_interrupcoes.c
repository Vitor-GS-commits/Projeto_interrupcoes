#include <stdio.h>
#include "pico/stdlib.h"
#include <math.h>
#include <stdlib.h>
#include "libs/leds.h"
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include "pio_matrix.pio.h"
#include "hardware/clocks.h"
#include "libs/animations.h"

// Definições de pinos
#define led_red 13
#define button_A 5
uint const button_B = 6; 


// variáveis globais
float intensity = 0.3f;
PIO pio;
uint sm;
int contador = 0; //contador de botões
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)


// função de interrupção soma 1 ao contador ou subtrai 1
static void gpio_irq_handler(uint gpio, uint32_t events);

int main()
{
    pio = pio0;

    // inicialização do pico
    stdio_init_all();

    // inicialização do led vermelho
    gpio_init(led_red);
    gpio_set_dir(led_red, GPIO_OUT);

    // inicialização dos botões de interrupção
    gpio_init(button_A);
    gpio_set_dir(button_A, GPIO_IN);
    gpio_pull_up(button_A);
    gpio_init(button_B);
    gpio_set_dir(button_B, GPIO_IN);
    gpio_pull_up(button_B);

    gpio_set_irq_enabled_with_callback(button_A, GPIO_IRQ_EDGE_RISE, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(button_B, GPIO_IRQ_EDGE_RISE, true, &gpio_irq_handler);
    
    // configurações da PIO
    printf("iniciando a transmissão PIO");
    uint offset = pio_add_program(pio, &pio_matrix_program);
    sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, LED_PIN);

    

        while (true) {
            printf("contador: %d\n", contador);
            //função que desenha o número no display
            desenha_numero(contador, pio, sm, intensity);
            gpio_put(led_red, true);
            sleep_ms(100);
            gpio_put(led_red,false);
            sleep_ms(100);
        }
}

void gpio_irq_handler(uint gpio, uint32_t events){
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    printf("contador = %d\n", contador);
    // Verifica se passou tempo suficiente desde o último evento
    if (current_time - last_time > 200000) // 200 ms de debouncing
    {
        last_time = current_time; // Atualiza o tempo do último evento
        //condição para somar ou subtrair 1 do contador
            if(gpio == button_A){
                contador++;
                printf("contador: %d\n", contador);
                if (contador == 10)
                {
                    contador = 9;
                }
            }
            if(gpio == button_B){
                contador--;
                printf("contador: %d\n", contador);
                if (contador == -1)
                {
                    contador = 0;
                }
            }
    }
    
}