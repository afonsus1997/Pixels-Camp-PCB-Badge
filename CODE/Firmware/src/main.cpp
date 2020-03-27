


#include "../include/main.h"


//#include <ESPmDNS.h>

char *ssid = "Pixels Camp Badger";
char *password = "1234567890";

extern void initI2C();
extern void textScroll();

void idleLedTask( void * parameter )
{
  textScroll();
}

void idleLedTask2( void * parameter )
{
  for(;;){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  delay(250);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  delay(250);
  }
}

void createTasks(){
  xTaskCreate(
                    idleLedTask2,          /* Task function. */
                    "idleLedTask2",        /* String with name of task. */
                    1000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    2,                /* Priority of the task. */
                    NULL);  
  

  //xTaskCreate(
  //                  idleLedTask2,          /* Task function. */
  //                  "idleLedTask2",        /* String with name of task. */
  //                  10000,            /* Stack size in bytes. */
  //                  NULL,             /* Parameter passed as input of the task */
  //                  2,                /* Priority of the task. */
  //                  NULL);
}

void setup()
{
  Serial.begin(115200);

  initSPIFFS();
  initIO();
  initI2C();
  textScroll();
  createTasks();
  initWifi(ssid, password); 
  
  
  
  
}

void loop()
{
  //Serial.print("Battery Voltage: "); Serial.println(batVoltage());
  //delay(500);
}
