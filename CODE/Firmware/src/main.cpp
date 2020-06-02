


#include "../include/main.h"


//#include <ESPmDNS.h>

char *ssid = "Pixels Camp Badger";
char *password = "1234567890";

extern void initMatrix();
extern void textScroll();
// extern void I2CUnloadTask ( void * parameter );


void idleLedTask( void * parameter )
{
  // textScroll();
}

void BtnReadTask( void * parameter )
{
  for(;;){
    uint8_t state = 000;
    state = (digitalRead(SWLEFT) << 2) | (digitalRead(SWCENTER) << 1 ) | (digitalRead(SWRIGHT));
    Serial.print("Button state: "); Serial.println(state);
    delay(100);
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
  

  // xTaskCreate(
  //                  BtnReadTask,          /* Task function. */
  //                  "BtnReadTask",        /* String with name of task. */
  //                  1000,            /* Stack size in bytes. */
  //                  NULL,             /* Parameter passed as input of the task */
  //                  2,                /* Priority of the task. */
  //                  NULL);
}


void setup()
{
  Serial.begin(115200);
  // vTaskSuspendAll();
  initSPIFFS();
  initIO();
  initMatrix();
  vTaskDelay(1000);
  // textScroll();
  initWifi(ssid, password); 
  // createTasks();
}

void loop()
{
  // Serial.print("Battery Voltage: "); Serial.println(batVoltage());
  // delay(500);
}
