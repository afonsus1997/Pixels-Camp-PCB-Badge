
#include "../include/wifip.h"

AsyncWebServer server(80);




int initWebHandles(){
    server.on("/heap", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", String(ESP.getFreeHeap()));
    });

    //server.on("/Score", handleSendScore);

    //server.on("/StringState", handleString);

    server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");

    return 1;
}


int initWebServer(){
    initWebHandles();
    server.begin();
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
  Serial.print("TIME: ");
  Serial.println("time");
  String sendString = "{\"Score\": " + String("time") + "}";
  request->send(200, "application/json", sendString);
}

int initWifi(char *ssid, char *password){
    Serial.print("Initializing Wifi...");
    WiFi.softAP("Pixels Camp Badger", "1234567890");
    IPAddress myIP = WiFi.softAPIP();
    Serial.println("Done!");
    Serial.print("Initializing Webserver...");
    initWebServer();
    Serial.println("Done!");
    Serial.println("==============");
    Serial.print("SSID: "); Serial.println(ssid);
    Serial.print("Password: "); Serial.println(password);
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    Serial.println("==============");

}


