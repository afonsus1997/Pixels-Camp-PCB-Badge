#include "../include/io.h"

int initIO(){
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(BATPIN, INPUT);
}

float batVoltage(){
    float read = analogRead(BATPIN);
    return read*2;
}