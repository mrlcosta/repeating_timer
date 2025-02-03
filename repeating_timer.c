#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definindo os pinos do LED RGB

#define LED_GREEN  11
#define LED_YELLOW 12 //azul na placa
#define LED_RED  13

// Estados do semáforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficLightState;

static TrafficLightState current_state = RED;  // Estado inicial do semáforo

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterando o estado do semáforo a cada 3 segundos
    switch (current_state) {
        case RED:
            current_state = GREEN;
            gpio_put(LED_RED, 0);       // Apaga o LED vermelho
            gpio_put(LED_GREEN, 1);    // Acende o LED amarelo
            break;
        case GREEN:
            current_state = YELLOW;
            gpio_put(LED_YELLOW, 1);    // Apaga o LED amarelo
            gpio_put(LED_GREEN, 0);     // Acende o LED verde
            break;
        case YELLOW:
            current_state = RED;
            gpio_put(LED_YELLOW, 0);     // Apaga o LED verde
            gpio_put(LED_RED, 1);       // Acende o LED vermelho
            break;
    }
    return true;  // Retorna true para repetir o temporizador
}

int main() {
    // Inicializando a porta serial para comunicação
    stdio_init_all();

    // Inicializando os pinos dos LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicializa o semáforo com o LED vermelho aceso
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    // Criando e configurando o temporizador para chamar a função de callback a cada 3 segundos (3000ms)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        // Imprimindo mensagem a cada 1 segundo
        printf("Estado do semaforo: ");
        switch (current_state) {
            case RED:
                printf("Vermelho\n");
                break;
            case YELLOW:
                printf("Amarelo\n");
                break;
            case GREEN:
                printf("Verde\n");
                break;
        }
        sleep_ms(1000);  // Espera 1 segundo antes de imprimir novamente
    }

    return 0;
}

