#ifndef MAIN_H
#define MAIN_H
/*Arduino INCLUDES*/
#include <Arduino.h>



/*WIFI INCLUDES*/
extern int initWifi(char *ssid, char *password, uint16_t mode);

/*SPIFFS INCLUDES*/
extern int initSPIFFS();

/*BOARD AND IO INCLUDES*/
#include "boardpins.h"
extern int initIO();
extern float batVoltage();

#endif