/*
    myownblink
    Encenderá y apagará el LED integrado en GPIO2


*/

#include <stdint.h>
// #include <stdio.h>

#include "driver/gpio.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/projdefs.h"
#include "freertos/task.h"

// Librería ESP_LOG
#include "esp_log.h"

// Librería para timer
#include "freertos/timers.h"

#define LED_INTEGRADO 2

uint8_t estado = 0;
uint8_t contador = 0;
// Etiqueta para LOGs
static const char *TAG = "myOwnLED";

// Timer
TimerHandle_t timer1;

const int intTimer = 1000; // milisegundos

// Para delay de 1000ms
uint16_t ticksDelay = 500 / portTICK_PERIOD_MS;

// -------------------------------------Fucinoes--------------------------
esp_err_t iniciarLED(void);
esp_err_t blinkLED(void);
esp_err_t init_timer(void); // INciializar timer

// Función que se ejecuta al finalizar timer
void vTimerCallback(TimerHandle_t pxTimer) {
  ESP_LOGI(TAG, "Event called from timer");

  blinkLED();
}

void app_main(void) {

	init_timer();
  // Inicia LED
  iniciarLED();

  // El vCall del timer se ejecuta cada intTimer milisegundos
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

esp_err_t init_timer(void) {

  ESP_LOGI(TAG, "Creating timer1");
  // Crea timer1
  timer1 = xTimerCreate(
      "Timer1",                  // Just a text name, not used by the kernel.
      (pdMS_TO_TICKS(intTimer)), // The timer period in ticks.
      pdTRUE,        // The timers will auto-reload themselves when they expire.
      (void*)1,             // Assign each timer a unique id equal to its array index.
      vTimerCallback // Each timer calls the same callback when it expires.
  );

  if (timer1 == NULL) {
    // The timer was not created.
    ESP_LOGE(TAG, "The timer was not created.");

  } else {
    if (xTimerStart(timer1, 0) != pdPASS) { // xTimerStart inicia el timer
      // The timer could not be set into the Active state.
      ESP_LOGE(TAG, "The timer could not be set into the Active state.");
    }
  }
  return ESP_OK;
}