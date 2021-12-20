


#include "../include/main.h"


//#include <ESPmDNS.h>

char *ssid = "Pixels Camp Badger";
char *password = "1234567890";

extern void initMatrix();
extern void vMatrixTask();
extern int initWebServer();
extern String ip_addr;
extern SemaphoreHandle_t xStringSemaphore;
extern String textRX;

TaskHandle_t xHandleMatrixTask;

void idleLedTask( void * parameter )
{
  // textScroll();
}

void BtnReadTask( void * parameter )
{
  for(;;){
    uint8_t state = 000;
    state = (digitalRead(SWLEFT) << 2) | (digitalRead(SWCENTER) << 1 ) | (digitalRead(SWRIGHT));
    // Serial.print("Button state: "); Serial.println(digitalRead(SWLEFT));
    if(!digitalRead(SWLEFT)){
      textRX = ip_addr;
      xSemaphoreGive(xStringSemaphore);
    }
    delay(500);
  }

}

void idleLedTask2( void * parameter )
{
  for(;;){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  delay(500);
  }
}

void createTasks(){
  // xTaskCreate(
  //                   I2CUnloadTask,          /* Task function. */
  //                   "I2CUnloadTask",        /* String with name of task. */
  //                   1000,            /* Stack size in bytes. */
  //                   NULL,             /* Parameter passed as input of the task */
  //                   6,                /* Priority of the task. */
  //                   NULL);  
  

  xTaskCreate(
                   BtnReadTask,          /* Task function. */
                   "BtnReadTask",        /* String with name of task. */
                   1000,            /* Stack size in bytes. */
                   NULL,             /* Parameter passed as input of the task */
                   4,                /* Priority of the task. */
                   NULL);
  // xTaskCreate(
  //                  idleLedTask2,          /* Task function. */
  //                  "idleLedTask2",        /* String with name of task. */
  //                  configMINIMAL_STACK_SIZE,            /* Stack size in bytes. */
  //                  NULL,             /* Parameter passed as input of the task */
  //                  5,                /* Priority of the task. */
  //                  NULL);

  // xTaskCreateUniversal (
  //                  vMatrixTask,          /* Task function. */
  //                  "MatrixTask",        /* String with name of task. */
  //                  10000,            /* Stack size in bytes. */
  //                  NULL,             /* Parameter passed as input of the task */
  //                  0 | portPRIVILEGE_BIT ,                /* Priority of the task. */
  //                  &xHandleMatrixTask,
  //                  0);
}


void setup()
{
  Serial.begin(115200);
  // vTaskSuspendAll();
  initSPIFFS();
  initIO();
  initMatrix();
  // vTaskDelay(1000);
  // textScroll();
  initWifi(ssid, password, !digitalRead(SWLEFT)); 
  initWebServer();
  
  createTasks();
  // vTaskResume(xHandleMatrixTask);
}

void loop()
{
  // Serial.print("Battery Voltage: "); Serial.println(batVoltage());
  // delay(500);
  // String inString;
  // xQueueReceive(xStringQueue, &inString, portMAX_DELAY);
  // Serial.print(inString);
  vMatrixTask();
}
