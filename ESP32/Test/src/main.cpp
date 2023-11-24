//bibliotecas--------------------
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include <EEPROM.h>
#include <LittleFS.h>
//bibliotecas--------------------

//configuracoes variaveis--------
bool PontH;
bool SensorM;
bool status = false;
bool statusPH = false;
bool statusMS = false;
bool fimAlto = false;
bool fimBaixo = false;

int valorLimiteChuva = 500;           
bool chuva = false;

bool fatorMotor = 0;

int timerMotor = 0;
//configuracoes variiveis--------

//configuracoes WIFI-------------
const char* ApAdress = "ESP8266-Access-Point";
const char* ApPass = "170704gui";
//configuracoes WIFI-------------

//definir pinos------------------
#define A0 17
#define D1 5
#define D2 4
#define D3 0
#define D4 2
//definir pinos------------------

AsyncWebServer server(80);

String messagemMonitor(){
    String var = "OII";
    Serial.println(var);
    return var;
}

void Motor1At(){
	Serial.println("Motor 1 ativo");
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
}

void Motor2At(){
	Serial.println("Motor 2 ativo");
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
}

void ResetMotor(){
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
}

String msg1(){
    
    String var = "ligou1";
    return var;
}

String msg2(){
    
    String var = "ligou2";
    return var;
}

void HighMotor(bool x, bool y){
    if(x == 1 && y == false){
        if(fimAlto == true){
            ResetMotor();
        }else{
            Motor1At();
        }
    }
    if(x == 1 && y == true){
        if(fimBaixo == true){
            ResetMotor();
        }else{
            Motor2At();
        }
    }
}

String sensorModulo(){

    int valorSensorChuva = analogRead(A0);
    Serial.print("Sensor de chuva = ");
    Serial.print(valorSensorChuva);
    if (valorSensorChuva < valorLimiteChuva){
        Serial.println(" => Esta chovendo");
        chuva = true;
    }else{
        Serial.println(" => O tempo esta seco");
   	    chuva = false;
    }
    return String(valorSensorChuva);
}

void setup() {

    Serial.begin(115200);
    LittleFS.begin();

    //configuracoes pinos------------
    pinMode(A0, INPUT);
    pinMode(D1, OUTPUT); //positivo
    pinMode(D2, OUTPUT); //negativo
    pinMode(D3, INPUT);
    pinMode(D4, INPUT);
    //configuracoes pinos------------

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
        request->send(LittleFS, "/style.css", "text/css");
    });

    server.on("/5213449.png", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/5213449.png", "image/png");
    });

    server.on("/3105807.png", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/3105807.png", "image/png");
    });

    server.on("/chart.umd.js", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/chart.umd.js", "text/javascript");
    });

    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/script.js", "text/javascript");
    });

    server.on("/PHON", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", msg1().c_str());
        statusPH = true;
    });

    server.on("/PHOFF", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", msg2().c_str());
        statusPH = false;
        ResetMotor();
    });

    server.on("/SM", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", sensorModulo().c_str());
    });
    
    
    server.begin();
    Serial.println("HTTP server rodando");
    
}

void SensorFim(){
    fimAlto = !digitalRead(D3);
    fimBaixo = !digitalRead(D4);
}

void loop(){
    SensorFim();
    HighMotor(statusPH, chuva);
}