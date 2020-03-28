#include "../include/io.h"

int initIO(){
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(MATRIX_EN, OUTPUT);
    
    pinMode(BATPIN, INPUT);
    pinMode(SWLEFT, INPUT);
    pinMode(SWCENTER, INPUT);
    pinMode(SWRIGHT, INPUT);

    digitalWrite(MATRIX_EN, HIGH);
}

float batVoltage(){
    float read = analogRead(BATPIN);
    return read*2;
}