//#include "SPIFFS.h"
//#include <SPIFFS.h>
#include <Arduino.h>
#include <SPIFFS.h>


int initSPIFFS(){
    Serial.print("Initializing SPIFFS...");
    if (!SPIFFS.begin())
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return 1;
  }
  Serial.println("Done!");
}