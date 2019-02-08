//#include "SPIFFS.h"
//#include <SPIFFS.h>
#include <SPIFFS.h>
#include <Arduino.h>


int initSPIFFS(){
    if (!SPIFFS.begin())
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
}