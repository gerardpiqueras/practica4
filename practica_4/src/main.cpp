

// --------------------------------------------------------------------- //

#include <Arduino.h>

void ledON (void * pvParameters);
void ledOFF(void * pvParameters);
int LED =2; 

SemaphoreHandle_t semaforo;

void setup(){

Serial.begin(9600);
pinMode(LED, OUTPUT);
semaforo= xSemaphoreCreateMutex();

xTaskCreate(
    ledON,
    "LED ON",
    10000,
    NULL,
    1,
    NULL);

xTaskCreate(
    ledOFF,
    "LED OFF",
    10000,
    NULL,
    1,
    NULL);

}

void loop(){}

void ledON (void * pvParameters){
    for(;;){
        xSemaphoreTake(semaforo, portMAX_DELAY);
        digitalWrite(LED, HIGH);
        delay(3000);
        xSemaphoreGive(semaforo);
    }
}

void ledOFF (void * pvParameters){
    for(;;){
        xSemaphoreTake(semafor, portMAX_DELAY);
        digitalWrite(LED, LOW);
        delay(1500);
        xSemaphoreGive(semaforo);
    }
}
