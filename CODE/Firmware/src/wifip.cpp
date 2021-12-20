
#include "../include/wifip.h"
#include <string>
AsyncWebServer server(80);

extern void matrixPrintString(int in);
extern SemaphoreHandle_t xStringSemaphore;
extern String textRX;
extern int spacing;
extern String text;
extern int speed;
extern void setBrightness(int brightness);
extern int brightness;

String ip_addr;

void handleStringTxt(AsyncWebServerRequest *request)
{
    //String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
    String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
    Serial.println("Got Name " + t_state);
    request->send(200);
    textRX = t_state;
    xSemaphoreGive(xStringSemaphore);
}

void handleStringSpacing(AsyncWebServerRequest *request)
{
    //String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
    String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
    Serial.println("Got Spacing " + t_state);
    request->send(200);
    spacing = t_state.toInt(); //stoi(t_state);
    // for (int i = 0; i < spacing; i++)
    //     textRX += " ";
    Serial.println(textRX);
    xSemaphoreGive(xStringSemaphore);
}

void handleStringSpeed(AsyncWebServerRequest *request)
{
    //String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
    String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
    Serial.println("Got Speed " + t_state);
    request->send(200);
    speed = map(t_state.toInt(), 0, 100, 150, 0)-1;
    Serial.println(map(t_state.toInt(), 0, 100, 100, 0));
    //xSemaphoreGive(xStringSemaphore);
}

void handleStringBrightness(AsyncWebServerRequest *request)
{
    //String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
    String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
    Serial.println("Got Brightness " + t_state);
    request->send(200);
    brightness = t_state.toInt();
    // setBrightness(brightness);
    // xSemaphoreGive(xStringSemaphore);
}



int initWebHandles()
{
    // server.on("/heap", HTTP_GET, [](AsyncWebServerRequest *request) {
    // request->send(200, "text/plain", String(ESP.getFreeHeap()));
    // });

    // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    // request->send(SPIFFS, "/index.html", "text/html");
    // // Serial.println("Hello World!\n");
    // });

    // //server.on("/StringState", handleString);
    server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");
    server.on("/SendString", handleStringTxt);
    server.on("/SpacingString", handleStringSpacing);
    server.on("/SpeedString", handleStringSpeed);
    server.on("/BrightnessString", handleStringBrightness);


    return 1;
}

int initWebServer()
{
    Serial.println("Starting web server...");
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

// void handleString(AsyncWebServerRequest *request)
// {
//   String t_state = String(request->arg("StringTxt")); //Refer  xhttp.open("GET", "StringState?StringTxt="+value, true);
//   Serial.println("Got Name " + t_state);
//   request->send(200);
// }

int initWifi(char *ssid, char *password, uint16_t mode)
{
    Serial.print("Initializing Wifi...");
    if (mode)
    {
        WiFi.softAP("Pixels Camp Badger", "1234567890");
        IPAddress myIP = WiFi.softAPIP();
        Serial.println("Done!");
        //initDNS("pixelsbadger");
        Serial.print("Initializing Webserver...");
        // initWebServer();
        Serial.println("Done!");
        Serial.println("==============");
        Serial.print("SSID: ");
        Serial.println(ssid);
        Serial.print("Password: ");
        Serial.println(password);
        Serial.print("AP IP address: ");
        Serial.println(myIP);
        Serial.println("==============\n");
    }
    else
    {
        WiFi.mode(WIFI_STA); //Optional
        WiFi.begin(SSID, PASSWORD);
        Serial.println("\nConnecting");

        while (WiFi.status() != WL_CONNECTED)
        {
            Serial.print(".");
            delay(100);
        }

        Serial.println("\nConnected to the WiFi network");
        Serial.print("Local ESP32 IP: ");
        Serial.println(WiFi.localIP().toString());
    }
    ip_addr = WiFi.localIP().toString();
    
}
