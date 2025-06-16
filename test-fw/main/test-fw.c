#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_check.h"
#include "driver/gpio.h"

#define TAG "ding-dong"

#define CHANNEL_COUNT 8
static uint8_t pins[CHANNEL_COUNT] = { 2, 3, 4, 5, 6, 7, 8, 10 };
void init_io(void);

void app_main(void)
{
    ESP_LOGI(TAG, "hello");
    init_io();

    uint8_t idx = 0;
    while(1) {
        ESP_LOGI(TAG, "Actuating %u", idx);
        gpio_set_level(pins[idx], 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        gpio_set_level(pins[idx], 0);
        if (idx == CHANNEL_COUNT-1)
        {
            idx = 0;
        }
        else
        {
            idx++;
        }
    }
}

void init_io(void) {

    size_t i;
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_down_en = 1;
    io_conf.pull_up_en = 0;
    for(i = 0 ; i < CHANNEL_COUNT ; i++) {
        io_conf.pin_bit_mask = (1ULL << pins[i]);
        gpio_config(&io_conf);
    }
}
