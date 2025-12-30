/*
    myownblink
    Encenderá y apagará el LED integrado en GPIO2   


*/

#include <stdint.h>
//#include <stdio.h>

#include "driver/gpio.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Librería ESP_LOG
#include "esp_log.h"

#define LED_INTEGRADO 2

uint8_t estado = 0;
uint8_t contador = 0;
static const char* TAG = "myOwnLED";

// Para delay de 500ms
uint16_t ticksDelay = 500 / portTICK_PERIOD_MS;

esp_err_t iniciarLED(void); 
esp_err_t blinkLED(void);

void app_main(void)
{

    // Escribe estado en LED
    iniciarLED();

    while(1) {
        // Hace parpadear
        blinkLED();

        /*  Imprimir en pantalla el nivel
            El siguiente es un mensaje sencillo con printf
        printf("ESTADO: %u\n", estado);
        */

        contador++;
        if(contador > 30)
            contador = 0;
        

        if(contador < 10)
            // Mensaje tipo info con esp_log (mensajes informativos)
            ESP_LOGI(TAG, "Value: %u", contador);


        else if(contador < 20 && contador > 10)
            // Mensaje tipo warning (mensaje medianamente crítico)
            ESP_LOGW(TAG, "Value: %u", contador);

        else
            // Mensaje tipo error (mensaje crítico)
            ESP_LOGE(TAG, "Value: %u", contador);

        // Espera por 1000 ms
        vTaskDelay(ticksDelay);
    }


}

esp_err_t iniciarLED(void) {

    gpio_reset_pin(LED_INTEGRADO);
    gpio_set_direction(LED_INTEGRADO, GPIO_MODE_OUTPUT);

    return ESP_OK;
}
esp_err_t blinkLED(void) {

    gpio_set_level(LED_INTEGRADO, estado);
    estado = !estado; 

    return ESP_OK;
}