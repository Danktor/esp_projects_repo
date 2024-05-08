#include <stdint.h>
#include <stdio.h>
//#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "../../../my_libraries/esp-idf-lib/components/ultrasonic/ultrasonic.h"

#define TRIGGER_PIN 25
#define ECHO_PIN 26



void app_main(void)
{
    uint32_t max_distance = 200;
    uint32_t distance;
    ultrasonic_sensor_t sensor;
    sensor.trigger_pin = TRIGGER_PIN;
    sensor.echo_pin = ECHO_PIN;
    ultrasonic_init(&sensor);
    while(1){
        if(ultrasonic_init(&sensor)!=ESP_OK)
            printf("El sensor esta mal conectado/no funciona\n");
        if(ultrasonic_measure_cm(&sensor,max_distance,&distance)!=ESP_OK){
            printf("El sensor esta mal conectado/no funciona\n");
        }
        else{
            printf("Distancia (cm): %lu\n",distance);
        }
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
