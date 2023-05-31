#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* nomeRede = "BERTOLA_2.4G_EXT";
const char* senhaRede = "170704gui";
const int Port = 3000;

void Connection(){
    WiFi.begin(nomeRede, senhaRede);
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }
    Serial.println(" ");
    Serial.println("Conectado a rede!!!");
}

void setup(){
    Serial.begin(9600);
    Connection();
}

void loop(){

}