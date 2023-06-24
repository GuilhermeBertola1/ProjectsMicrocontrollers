#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <DNSServer.h>
#include <ESP8266mDNS.h>

#include <TextHtmlRoot.h>
#include <pontH.h>
#include <sensorModule.h>

#include <EEPROM.h>
#include <FS.h>

const char* AdressRede = "BERTOLA_2.4G_EXT";
const char* Password = "170704gui";

WiFiClient client;
ESP8266WebServer server(80);

void handleRoot(){

    server.send(200, "text/html", message());
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


void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(AdressRede, Password);
    while (WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }
    Serial.println(" ");
    Serial.print("Conextado em: ");
    Serial.println(AdressRede);
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());

    if(MDNS.begin("esp8266")){
        Serial.println("MDNS respondendo");
    }

    server.on("/", handleRoot);

    server.on("/inline", []() {
        server.send(200,  "text/plain", "this works as well");
    });

    server.onNotFound(handNotFound);

    server.begin();
    Serial.println("HTTP serve rodando");

}

void loop() {
    server.handleClient();
}