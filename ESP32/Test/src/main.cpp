#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include <TextHtmlRoot.h>
#include <pontH.h>
#include <sensorModule.h>

#include <EEPROM.h>
#include <LittleFS.h>

bool PontH;
bool SensorM;
bool status = false;
bool statusPH = false;
bool statusMS = false;

const char* ApAdress = "ESP8266-Access-Point";
const char* ApPass = "170704gui";

AsyncWebServer server(80);


void setup() {

    Serial.begin(115200);
    LittleFS.begin();

//estacao local-----------
    WiFi.softAP(ApAdress, ApPass);
    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);
//-------------------------

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/index.html", String(), false);
    });

    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/style.css","text/css");
    });

    server.on("/chart.umd.js", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/chart.umd.js","text/javascript");
    });

    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/script.js","text/javascript");
    });
    
    server.begin();
    Serial.println("HTTP server rodando");
    
}

void loop() {

    if(statusPH){}
    if(statusMS){}
}