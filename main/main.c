#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

// resposta
const int BTN_PIN = 15;
const int LED_PIN = 14;
const int FASE1_PIN = 2;
const int FASE2_PIN = 3;
const int FASE3_PIN = 4;
const int FASE4_PIN = 5;

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);
    
    gpio_init(FASE1_PIN);
    gpio_set_dir(FASE1_PIN, GPIO_OUT);
    gpio_init(FASE2_PIN);
    gpio_set_dir(FASE2_PIN, GPIO_OUT);
    gpio_init(FASE3_PIN);
    gpio_set_dir(FASE3_PIN, GPIO_OUT);
    gpio_init(FASE4_PIN);
    gpio_set_dir(FASE4_PIN, GPIO_OUT);


    while (true) {
        
        if (!gpio_get(BTN_PIN)) {
            gpio_put(LED_PIN, 1);
            for (int i = 0; i < 512; i++){
                gpio_put(FASE1_PIN, 1);
                sleep_ms(2);
                gpio_put(FASE1_PIN, 0);
                gpio_put(FASE2_PIN, 1);
                sleep_ms(2);
                gpio_put(FASE2_PIN, 0);  
                gpio_put(FASE3_PIN, 1);
                sleep_ms(2);
                gpio_put(FASE3_PIN, 0);
                gpio_put(FASE4_PIN, 1);
                sleep_ms(2);
                gpio_put(FASE4_PIN, 0);   
            }
            gpio_put(LED_PIN, 0);

            
        while (!gpio_get(BTN_PIN)) {
                };
        }
    
    } 
}
