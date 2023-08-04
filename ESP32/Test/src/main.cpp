#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <WiFiManager.h>
#include <DNSServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>

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

ESP8266WebServer server(80);

void handleRoot(){

    Serial.println(PontH);
    Serial.println(SensorM);

    server.send(200, "text/html", messageHTML(status, status));
}

void handNotFound(){

    String message = "pagina nao encontrada";
    message += "URI: ";
    message += server.uri();
    message += "\nArguments: ";
    message += server.args();
    message += "\n";

    for(uint8_t i=0; i<server.args(); i++){
        message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }

    server.send(404, "text/plain", message);
}

void handlePHON(){
    PontH = true;
    statusPH = true;

    Serial.println("entradas PH:");
    Serial.println(PontH);
    Serial.println();

    server.send(200, "text/html", messageHTML(statusPH, statusMS));
}

void handlePHOFF(){
    PontH = false;
    statusPH = false;

    Serial.println("entradas PH:");
    Serial.println(PontH);
    Serial.println();

    server.send(200, "text/html", messageHTML(statusPH, statusMS));
}

void handleSMon(){
    SensorM = true;
    statusMS = true;

    Serial.println("entradas SM:");
    Serial.println(SensorM);
    Serial.println();

    server.send(200, "text/html", messageHTML(statusPH, statusMS));
}

void handleSMoff(){
    SensorM = false;
    statusMS = false;

    Serial.println("entradas SM:");
    Serial.println(SensorM);
    Serial.println();

    server.send(200, "text/html", messageHTML(statusPH, statusMS));
}


void setup() {

    Serial.begin(115200);

//estacao local-----------
    WiFi.softAP(ApAdress, ApPass);
    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);
//-------------------------

    server.on("/", handleRoot);
    server.on("/PhON", handlePHON);
    server.on("/PhOFF", handlePHOFF);
    server.on("/SensorON", handleSMon);
    server.on("/SensorOFF", handleSMoff);
    server.onNotFound(handNotFound);

    server.on("/inline", []() {
        server.send(200,  "text/plain", "this works as well");
    });

    server.begin();
    Serial.println("HTTP serve rodando");
    
}

void loop() {
    server.handleClient();

    if(statusPH){}
    if(statusMS){}
}