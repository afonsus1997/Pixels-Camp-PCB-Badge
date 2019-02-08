#ifndef MAIN_H
#define MAIN_H
/*Arduino INCLUDES*/
#include <Arduino.h>

/*WIFI INCLUDES*/
extern int initWifi(char *ssid, char *password);

/*SPIFFS INCLUDES*/
int initSPIFFS();

/*BOARD INCLUDES*/
#include "boardpins.h"


#endif