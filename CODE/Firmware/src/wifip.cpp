
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
/*
int initDNS(char *hostname){
   // Set up mDNS responder:
    // - first argument is the domain name, in this example
    //   the fully-qualified domain name is "esp8266.local"
    // - second argument is the IP address to advertise
    //   we send our IP address on the WiFi network
    Serial.print("Initializing DNS Server...");
    if (!MDNS.begin(hostname)) {
        Serial.println("Error setting up MDNS responder!");
        return 0;
    }
    Serial.println(" Done!");
    return 1;
}*/

void handleString(AsyncWebServerRequest *request)
{
  String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
  Serial.println("Got Name " + t_state);
  request->send(200);
}



int initWifi(char *ssid, char *password){
    Serial.print("Initializing Wifi...");
    WiFi.softAP("Pixels Camp Badger", "1234567890");
    IPAddress myIP = WiFi.softAPIP();
    Serial.println("Done!");
    //initDNS("pixelsbadger");
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



