#include <stdio.h>

#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_netif_types.h"
#include "esp_wifi_types.h"
#include "freertos/FreeRTOS.h"
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

#define ESP_WIFI_SSID "ADRO_ESP"
#define ESP_WIFI_PASS "ADRO_ESP"
#define ESP_WIFI_CHANNEL 1
#define MAX_STA_CONN 2

#define INTEGRATED_LED 2

//--------------------- GLOBAL VARIABLES -----------------------
static const char *TAG = "WebServer2";
uint8_t estado_led = 0;

//-----------------------PROTOTYPE FUNCIONS FOR GPIO-----------
esp_err_t iniciarLED(void);
esp_err_t toggle_led(void);


// -------------------- Functions for Web server-----------------

static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                                    int32_t event_id, void* event_data)
{
    switch (event_id) {
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
 * Browsers expect to GET website png img at URI /foco_on.png .
 * This can be overridden by uploading file with same name */
static esp_err_t foco_on_handler(httpd_req_t *req)
{
    extern const unsigned char foco_on_start[] asm("_binary_foco_on_png_start");
    extern const unsigned char foco_on_end[]   asm("_binary_foco_on_png_end");
    const size_t foco_on_size = (foco_on_end - foco_on_start);
    httpd_resp_set_type(req, "image/png");
    httpd_resp_send(req, (const char *)foco_on_start,foco_on_size);
    return ESP_OK;
}

// URI for foco_on.png
static const httpd_uri_t foco_on_uri = {
    .uri       = "/foco_on.png",
    .method    = HTTP_GET,
    .handler   = foco_on_handler,
    .user_ctx  = NULL
};

/* Handler to respond with an icon file embedded in flash.
 * Browsers expect to GET website png img at URI /foco_off.png .
 * This can be overridden by uploading file with same name */
static esp_err_t foco_off_handler(httpd_req_t *req)
{
    extern const unsigned char foco_off_start[] asm("_binary_foco_off_png_start");
    extern const unsigned char foco_off_end[]   asm("_binary_foco_off_png_end");
    const size_t foco_off_size = (foco_off_end - foco_off_start);
    httpd_resp_set_type(req, "image/png");
    httpd_resp_send(req, (const char *)foco_off_start, foco_off_size);
    return ESP_OK;
}

// URI for foco_on.png
static const httpd_uri_t foco_off_uri = {
    .uri       = "/foco_off.png",
    .method    = HTTP_GET,
    .handler   = foco_off_handler,
    .user_ctx  = NULL
};

/* An HTTP GET handler */
static esp_err_t root_get_handler(httpd_req_t *req) {
  
    // Para mandar el archivo view.html por https:
    extern unsigned char index_start[] asm("_binary_index_html_start");
    extern unsigned char index_end[] asm("_binary_index_html_end");
    const size_t index_size = (index_end - index_start);

    ESP_LOGI(TAG, "URI: %s", req->uri);

    if(strcmp(req->uri, "/?foco_on") == 0) {
        toggle_led();
    }

    // Type of document
    httpd_resp_set_type(req, "text/html");

    // Send HTML file header 
    httpd_resp_sendstr_chunk(req, "<!DOCTYPE html>");

    // Send the COMPLETE PAGE
    httpd_resp_send_chunk(req, (const char*) index_start, index_size);
    /* Send empty chunk to signal HTTP response completion */
    httpd_resp_sendstr_chunk(req, NULL);
    
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
static const httpd_uri_t root_uri= {
    .uri       = "/",
    .method    = HTTP_GET,
    .handler   = root_get_handler,
    .user_ctx  = NULL
};

//Function for starting the webserver
httpd_handle_t start_webserver(void)
{
    // Generate default configuration
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    // Empty handle to http_server
    httpd_handle_t server = NULL;

    // Start the httpd server
    if (httpd_start(&server, &config) == ESP_OK) {
        // Register URI handlers
        ESP_LOGI(TAG, "Server started successfully");

        // Loads root handler (index.html)
        httpd_register_uri_handler(server, &root_uri);

        // Loads foco_on.png
        httpd_register_uri_handler(server, &foco_on_uri);
        
        // Loads foco_off.png
        httpd_register_uri_handler(server, &foco_off_uri);

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
    iniciarLED();
    nvs_flash_init();
    wifi_init_softap();

    httpd_handle_t server = start_webserver();
    // To stop it: 
    //httpd_stop(server);

}

esp_err_t iniciarLED(void) {

    gpio_reset_pin(INTEGRATED_LED);
    gpio_set_direction(INTEGRATED_LED, GPIO_MODE_OUTPUT);

    return ESP_OK;
}
esp_err_t toggle_led(void) {

    gpio_set_level(INTEGRATED_LED, estado_led);
    estado_led = !estado_led; 

    return ESP_OK;
}