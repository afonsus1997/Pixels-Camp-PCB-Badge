


#include "../include/main.h"


//#include <ESPmDNS.h>

char *ssid = "Pixels Camp Badger";
char *password = "1234567890";

extern void initI2C();

void idleLedTask( void * parameter )
{
  for(;;){
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  delay(250);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  delay(250);
  }
}

void idleLedTask2( void * parameter )
{
  for(;;){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  delay(250);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(250);
  }
}

void createTasks(){
  xTaskCreate(
                    idleLedTask,          /* Task function. */
                    "idleLedTask",        /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    2,                /* Priority of the task. */
                    NULL);  
  

  xTaskCreate(
                    idleLedTask2,          /* Task function. */
                    "idleLedTask2",        /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    2,                /* Priority of the task. */
                    NULL);  
}

void setup()
{
  Serial.begin(115200);

  initSPIFFS();
  initIO();
  //initI2C();
  initWifi(ssid, password); 
  
  
  
  
}

void loop()
{
  //Serial.print("Battery Voltage: "); Serial.println(batVoltage());
  //delay(500);
}
