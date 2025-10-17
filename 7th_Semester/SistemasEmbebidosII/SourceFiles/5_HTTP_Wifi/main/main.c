#include <stdio.h>

#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_netif_types.h"
#include "esp_wifi_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/projdefs.h"
#include "freertos/task.h"
#include "nvs_flash.h"

// WifiServer
#include <stdint.h>

#include <stdio.h>

#include <string.h>

// Librería mensajes log
#include "esp_log.h"
// Para wifi Soft-AP
#include "esp_wifi.h"
// Librería para web server
#include "esp_http_server.h"
#include "soc/soc.h"

#define ESP_WIFI_SSID "ADRO_ESP"
#define ESP_WIFI_PASS "ADRO_ESP"
#define ESP_WIFI_CHANNEL 1
#define MAX_STA_CONN 2

#define INTEGRATED_LED 2

// Define luces de semáforo
#define RED_LIGHT_PIN 21
#define YELLOW_LIGHT_PIN 22
#define GREEN_LIGHT_PIN 23

//--------------------- GLOBAL VARIABLES -----------------------
static const char *TAG = "WebServer";
uint8_t estado_led = 0;

// Estado de luces semáforo, todas inician encendidas
uint8_t estado_red_light = 1;
uint8_t estado_yellow_light = 1;
uint8_t estado_green_light = 1;

//-----------------------PROTOTYPE FUNCIONS FOR GPIO-----------
esp_err_t iniciarLED(void);
esp_err_t toggle_led(void);
esp_err_t initLightPins(void);

// -------------------- Functions for Web server-----------------

static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                                    int32_t event_id, void* event_data)
{
    switch (event_id) {
        case WIFI_EVENT_STA_START:
            ESP_LOGI(TAG, "Wifi connecting...");
            break;
        
        case WIFI_EVENT_STA_CONNECTED:
            ESP_LOGI(TAG, "Wifi connected...");
            break;
        
        case WIFI_EVENT_STA_DISCONNECTED:
            ESP_LOGW(TAG, "Wifi disconnected...");
            break;

        case IP_EVENT_STA_GOT_IP:
            ESP_LOGW(TAG, "Wifi got IP...");
            break;

        default:
            break;
    
    }
}

void wifi_init_softap()
{
    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_ap();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT(); // always start with this

    esp_wifi_init(&cfg);

    esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        NULL);

    wifi_config_t wifi_config = {
        .ap = {
            .ssid = ESP_WIFI_SSID,
            .ssid_len = strlen(ESP_WIFI_SSID),
            .channel = ESP_WIFI_CHANNEL,
            .password = ESP_WIFI_PASS,
            .max_connection = MAX_STA_CONN,
            .authmode = WIFI_AUTH_WPA2_PSK,
            .pmf_cfg = {
                .required = true,
            },
        },
    };


    esp_wifi_set_mode(WIFI_MODE_AP);
    esp_wifi_set_config(WIFI_IF_AP, &wifi_config);
    esp_wifi_start();

    ESP_LOGI(TAG, "wifi_init_softap finished. SSID:%s password:%s channel:%d",
             ESP_WIFI_SSID, ESP_WIFI_PASS, ESP_WIFI_CHANNEL);


}

/* Handler to respond with an icon file embedded in flash.
 * Browsers expect to GET website icon at URI /favicon.ico.
 * This can be overridden by uploading file with same name */

static esp_err_t favicon_get_handler(httpd_req_t *req)
{
    extern const unsigned char favicon_start[] asm("_binary_favicon_ico_start");
    extern const unsigned char favicon_end[]   asm("_binary_favicon_ico_end");
    const size_t favicon_size = (favicon_end - favicon_start);
    httpd_resp_set_type(req, "image/x-icon");
    httpd_resp_send(req, (const char *)favicon_start, favicon_size);
    return ESP_OK;
}

// URI for favicon_handler (html)
static const httpd_uri_t favicon_uri = {
    .uri       = "/favicon.ico",
    .method    = HTTP_GET,
    .handler   = favicon_get_handler,
    .user_ctx  = NULL
};

/* Handler to respond with an icon file embedded in flash.
 * Browsers expect to GET website icon at URI /mazda_mx5.png.
 * This can be overridden by uploading file with same name */

static esp_err_t mazda_mx5_get_handler(httpd_req_t *req)
{
    extern const unsigned char mazda_mx5_start[] asm("_binary_mazda_mx5_png_start");
    extern const unsigned char mazda_mx5_end[]   asm("_binary_mazda_mx5_png_end");
    const size_t mazda_mx5_size = (mazda_mx5_end - mazda_mx5_start);
    httpd_resp_set_type(req, "image/png");
    httpd_resp_send(req, (const char *)mazda_mx5_start, mazda_mx5_size);
    return ESP_OK;
}

// URI for mazda_mx5_handler (html)
static const httpd_uri_t mazda_mx5_uri = {
    .uri       = "/mazda_mx5.png",
    .method    = HTTP_GET,
    .handler   = mazda_mx5_get_handler,
    .user_ctx  = NULL
};



static esp_err_t toggle_light_handler(httpd_req_t *req) {
    
    char buf[64];
    int ret, remaining = req->content_len;

    // Extrae el parámetro "color" de la URL
    char color[16] = {0};
    size_t query_len = httpd_req_get_url_query_len(req) + 1;
    if (query_len > 1) {
        char *query = malloc(query_len);
        if (query) {
            httpd_req_get_url_query_str(req, query, query_len);
            httpd_query_key_value(query, "color", color, sizeof(color));
            free(query);
        }
    }

    // Decide qué LED cambiar
    if (strcmp(color, "red") == 0) {
        estado_red_light = !estado_red_light;
        gpio_set_level(RED_LIGHT_PIN, estado_red_light);

        // Manda nuevo estado
        httpd_resp_sendstr(req,  estado_red_light ? "1": "0");

    } else if (strcmp(color, "yellow") == 0) {
        
        estado_yellow_light = !estado_yellow_light;
        gpio_set_level(YELLOW_LIGHT_PIN, estado_yellow_light);

        // Manda nuevo estado
        httpd_resp_sendstr(req,  estado_yellow_light ? "1": "0");

    } else if (strcmp(color, "green") == 0) {
        estado_green_light = !estado_green_light;
        gpio_set_level(GREEN_LIGHT_PIN, estado_green_light);

        // Manda nuevo estado
        httpd_resp_sendstr(req,  estado_green_light ? "1": "0");

    }
    
    

    // Envía respuesta vacía
    httpd_resp_send(req, NULL, 0);
    

    // httpd_resp_send(req, NULL, 0); // Señala al servidor que la respuesta terminó

    return ESP_OK;
}

static const httpd_uri_t toggle_light_uri = {
    .uri       = "/toggle",
    .method    = HTTP_GET,
    .handler   = toggle_light_handler,
    .user_ctx  = NULL
};

/* An HTTP GET handler */
static esp_err_t hello_get_handler(httpd_req_t *req) {
  
    // Para mandar el archivo view.html por https:
    extern unsigned char view_start[] asm("_binary_view_html_start");
    extern unsigned char view_end[] asm("_binary_view_html_end");
    const size_t view_size = (view_end - view_start);


    ESP_LOGI(TAG, "URI: %s", req->uri);


    // Revisa el botón seleccionado
    if (strcmp(req->uri, "/?led-r") == 0)
    {
        toggle_led();
    }
    if (strcmp(req->uri, "/?led-g") == 0)
    {
        toggle_led();
    }
    if (strcmp(req->uri, "/?led-b") == 0)
    {
        toggle_led();
    }

    // Type of document
    httpd_resp_set_type(req, "text/html");

    // Send HTML file header 
    httpd_resp_sendstr_chunk(req, "<!DOCTYPE html>");

    // Send the COMPLETE PAGE
    httpd_resp_send_chunk(req, (const char*) view_start, view_size);
    /* Send empty chunk to signal HTTP response completion */
    httpd_resp_sendstr_chunk(req, NULL);

    //httpd_send(req, (const char*)view_start, view_size);
    
    // Original (without view.html):
    /*char* resp_str = "<!DOCTYPE HTML><html><head>\
                            <title>ESP Input Form</title>\
                            <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\
                            </head><body>\
                            <form action=\"/get\">\
                                str: <input type=\"text\" name=\"str\">\
                                <input type=\"submit\" value=\"Submit\">\
                            </form><br>\
                            <form action=\"/get\">\
                                int: <input type=\"text\" name=\"int\">\
                                <input type=\"submit\" value=\"Submit\">\
                            </form><br>\
                            </body></html>";
    httpd_resp_send(req, resp_str, HTTPD_RESP_USE_STRLEN);
*/
    return ESP_OK;

}
// URI for hello_get_handler (html)
static const httpd_uri_t hello_world_uri= {
    .uri       = "/",
    .method    = HTTP_GET,
    .handler   = hello_get_handler,
    .user_ctx  = NULL
};

//Function for starting the webserver
httpd_handle_t start_webserver(void) {
    // Generate default configuration
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    // Empty handle to http_server
    httpd_handle_t server = NULL;

    // Start the httpd server
    if (httpd_start(&server, &config) == ESP_OK) {
        // Register URI handlers
        ESP_LOGI(TAG, "Server started successfully");

        // Loads root (html)
        httpd_register_uri_handler(server, &hello_world_uri);

        // Loads favicon.ico
        httpd_register_uri_handler(server, &favicon_uri);

        // Loads toggle_light_handler
        httpd_register_uri_handler(server, &toggle_light_uri);

        // Loads MazdaMax5 image
        httpd_register_uri_handler(server, &mazda_mx5_uri);

        return server;
    }
    ESP_LOGE(TAG, "Error starting server");

    // If server failed to start, handle will be NULL
    return server;
}

// Stop server
void stop_webserver(httpd_handle_t server)
{
    // Ensure handle is non NULL
    if (server != NULL) {
    // Stop the httpd server
        httpd_stop(server);
    }
}

//----------------------------MAIN-------------------------
void app_main(void)
{
    printf("Hello soft-ap tutorial!\n");

    // Iniciar pines de luces semáforo
    initLightPins();

    // Prueba pines
    ESP_LOGW(TAG, "Encendiendo LEDS");
    gpio_set_level(RED_LIGHT_PIN, 1);
    gpio_set_level(GREEN_LIGHT_PIN, 1);
    gpio_set_level(YELLOW_LIGHT_PIN, 1);
    vTaskDelay(pdMS_TO_TICKS(1000));
    

    ESP_LOGW(TAG, "Apagando LEDS");
    gpio_set_level(RED_LIGHT_PIN, 0);
    gpio_set_level(GREEN_LIGHT_PIN, 0);
    gpio_set_level(YELLOW_LIGHT_PIN, 0);

    iniciarLED();
    nvs_flash_init();
    wifi_init_softap();

    httpd_handle_t server = start_webserver();
    // To stop it: 
    //httpd_stop(server);

}

// Inicializa los pines de control de luces

esp_err_t initLightPins(void){

    gpio_config_t io_conf = {
        .pin_bit_mask = ((1ULL << RED_LIGHT_PIN) | (1ULL << YELLOW_LIGHT_PIN) | (1ULL << GREEN_LIGHT_PIN)),        
        .mode = GPIO_MODE_OUTPUT,                   // Como salida
        .pull_up_en = GPIO_PULLUP_DISABLE,          // Disable pull-up
        .pull_down_en = GPIO_PULLDOWN_DISABLE,      // Disable pull-down
        .intr_type = GPIO_INTR_DISABLE              // Disable interrupts
    };
    
    gpio_config(&io_conf);

    return ESP_OK;
}

esp_err_t iniciarLED(void) {

    gpio_reset_pin(INTEGRATED_LED);
    gpio_set_direction(INTEGRATED_LED, GPIO_MODE_OUTPUT);

    return ESP_OK;
}
esp_err_t toggle_led(void) {

    // Consigue nuevo estado
    estado_led = !estado_led; 
    gpio_set_level(INTEGRATED_LED, estado_led);
    ESP_LOGI(TAG, "Toggle LED");

    return ESP_OK;
}