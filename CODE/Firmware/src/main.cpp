


#include "main.h"

//#include <ESPmDNS.h>

const char *ssid = "Pixels Camp Badger";
const char *password = "1234567890";


void setup()
{
  Serial.begin(115200);

  initSPIFFS();
  initWifi(&ssid, &password); 

  
}

void loop()
{
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
