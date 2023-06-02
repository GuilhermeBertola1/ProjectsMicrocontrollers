#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* nomeRede = "BERTOLA_2.4G_EXT";
const char* senhaRede = "170704gui";

bool status = 0;

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
    HTTPClient http;
    WiFiClient client;
    
    if(http.begin(client, url)){
        Serial.println("Http iniciado");
    }else{
        Serial.println("Http error de conexao");
    }

    int httpCode = http.GET();
    Serial.println(httpCode);
    String res = http.getString();
    Serial.println(res);

}

void setup(){
    Serial.begin(9600);
    Connection();
    getFunction("http://localhost:3000");
}

void loop(){

}