#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* nomeRede = "BERTOLA_2.4G_EXT";
const char* senhaRede = "170704gui";
const int Port = 3000;

bool status = 0;

WiFiClient client;
HTTPClient http;

void Connection(){
    WiFi.begin(nomeRede, senhaRede);
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }
    Serial.println(" ");
    Serial.println("Conectado a rede!!!");
}

void getFunction(String url){
    if(http.begin(client, url)){
        Serial.println("Http iniciado");
    }else{
        Serial.println("Http error de conexao");
    }

    int httpCode = http.GET();
    Serial.println(httpCode);

    http.end();
}

void setup(){
    Serial.begin(9600);
    Connection();
    getFunction("http://localhost:3000/");
}

void loop(){

}