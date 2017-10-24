#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include "FreeRTOSConfig.h"

static void printerThread( void *pvParameters ){
  while(1){
    vTaskDelay(1000/portTICK_PERIOD_MS);
    Serial.println("task");
  }
}

void setup() {
  Serial.begin(115200);
  xTaskCreate( printerThread, "test", 128, NULL, tskIDLE_PRIORITY, NULL );
  // put your setup code here, to run once:
  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  delay(1000);
}