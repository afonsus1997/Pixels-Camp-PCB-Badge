



#include <SPIFFS.h>

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <WiFiAP.h>
//#include <ESPmDNS.h>
#include "react.h"

const char* ssid = "Pixels Camp Badger";
const char* password =  "1234567890";
 int led=0;
AsyncWebServer server(80);
 
int reactStart(){
    //tell user to get ready
    long timedif;
    long randNumber;
    int btnState;
    randomSeed(analogRead(0));
    randNumber = random(1,8)*1000;
    delay(randNumber);
    long startTime = millis();
    //Serial.print(startTime);
    digitalWrite(LEDPIN, 1);

    while(1){
      btnState = (digitalRead(SWPIN));
     if(!btnState){
       break;
     }
     else
     delay(10);
    }
    digitalWrite(LEDPIN, 0);
    Serial.println("Btn Pressed");
    return millis() - startTime;

}


void handleString(AsyncWebServerRequest *request){

  
  String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
  Serial.println("Got Name " + t_state);
  request->send(200);
}

void handleSendScore(AsyncWebServerRequest *request) {
  int time = reactStart();
  Serial.print("TIME: "); Serial.println(time);    
  String sendString = "{\"Score\": " + String(time) + "}";
  request->send(200, "application/json", sendString); 
}


void setup(){
  Serial.begin(115200);
 
  if(!SPIFFS.begin()){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
  }
 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  
  
  pinMode(SWPIN, INPUT_PULLUP);
   
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
  

  //server.on("/html", HTTP_GET, [](AsyncWebServerRequest *request){
  //  request->send(SPIFFS, "/index.html");
  //});
 
  server.on("/heap", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(ESP.getFreeHeap()));
  });
  
  server.on("/Score", handleSendScore);

  
  server.on("/StringState", handleString);
  


  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");

  server.begin();
}
 
void loop(){
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


