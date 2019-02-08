#include "wifi.h"

int initWifi(char *ssid, char *password){
    WiFi.softAP(ssid, password);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
}


int initWebServer(){
    initWebHandles();
    server.begin();
    return 1;
    
}

int initWebHandles(){
    server.on("/heap", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", String(ESP.getFreeHeap()));
    });

    server.on("/Score", handleSendScore);

    server.on("/StringState", handleString);

    server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");

    return 1;
}

void handleString(AsyncWebServerRequest *request)
{
  String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
  Serial.println("Got Name " + t_state);
  request->send(200);
}

void handleSendScore(AsyncWebServerRequest *request)
{
  int time = reactStart();
  Serial.print("TIME: ");
  Serial.println(time);
  String sendString = "{\"Score\": " + String(time) + "}";
  request->send(200, "application/json", sendString);
}