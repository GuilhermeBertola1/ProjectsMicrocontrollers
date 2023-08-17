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

int valorLimiteChuva = 500;           
bool chuva = false;

bool fatorMotor = 0;

int timerMotor = 0;
//configuracoes variaveis--------

//configuracoes WIFI-------------
const char* ApAdress = "ESP8266-Access-Point";
const char* ApPass = "170704gui";
//configuracoes WIFI-------------

//definir pinos------------------
#define D0 16
#define D1 5
#define D2 4
//definir pinos------------------

AsyncWebServer server(80);

String messagemMonitor(){
    String var = "OII";
    Serial.println(var);
    return var;
}

String msg(){
    String var = "ligou";
    return var;
}

void Motor1At(){
	Serial.println("Motor 1 ativo");
   	do{	
		Serial.println(timerMotor + 1);
      
    	digitalWrite(D2, LOW);
    	digitalWrite(D1, HIGH);
        timerMotor++;
        delay(1000);
    }while(timerMotor < 5);
      
    timerMotor = 0;
    digitalWrite(D1, LOW);
    fatorMotor = 1;
}

void Motor2At(){
	Serial.println("Motor 2 ativo");
  	
    do{
  		Serial.println(timerMotor + 1);
      
    	digitalWrite(D1, LOW);
    	digitalWrite(D2, HIGH);
        timerMotor++;
        delay(1000);
    }while(timerMotor < 5);
      
    timerMotor = 0;
    digitalWrite(D2, LOW);
    fatorMotor = 0;
}

void HighMotor(){

    if(fatorMotor == 0 && chuva == true){
		Motor1At();
    }
  
    if(fatorMotor == 1 && chuva == false){
      	Motor2At();
    }

}

String sensorModulo(){

    int valorSensorChuva = analogRead(D0);
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
    pinMode(D0, INPUT);
    pinMode(D1, OUTPUT); //positivo
    pinMode(D2, OUTPUT); //negativo
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
        request->send(LittleFS, "/style.css","text/css");
    });

    server.on("/chart.umd.js", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/chart.umd.js","text/javascript");
    });

    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/script.js","text/javascript");
    });

    server.on("/PHON", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", msg().c_str());
        statusPH = true;
    });

    server.on("/PHOFF", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", msg().c_str());
        statusPH = false;
    });

    server.on("/SM", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", sensorModulo().c_str());
    });
    
    
    server.begin();
    Serial.println("HTTP server rodando");
    
}

void loop() {
}