#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//rede wifi - conexao
const char* rede = "BERTOLA_2.4G";
const char* senha = "170704gui";

//mqtt broker - conexao
const char* mqtt_broker = "192.168.0.15";
const char* topico = "topico/auto";
const char* mqtt_user = "Bertola123";
const char* mqtt_pas = "170704gui";
const int mqtt_port = 1883;

bool mqttStatus;

WiFiClient espClient;
PubSubClient client(espClient);

bool connectMQTT();
void callback(char* topic, byte* payload, unsigned int length);

void setup(){
    Serial.begin(115200);

    WiFi.begin(rede, senha);
    Serial.println();
    Serial.print("conectando na REDE");
    while(WiFi.status() != WL_CONNECTED){
        delay(100);
        Serial.print(".");
    }
    Serial.println(WiFi.localIP());

    mqttStatus = connectMQTT();
    
}

void loop(){
    if(mqttStatus){
        client.loop();
    }
}

bool connectMQTT(){
    byte tentativa = 0;
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);

    do{
        String client_id = "BERTOLA-";
        client_id += String(WiFi.macAddress());

        if(client.connect(client_id.c_str(), mqtt_user, mqtt_pas)){
            Serial.println("Exito na conexao:");
            Serial.printf("Cliente %s conextado ao broker\n", client_id.c_str());
        }else{
            Serial.print("Falha ao conectar no broker");
            Serial.print(client.state());
            Serial.println();
            Serial.print("tentativa: ");
            Serial.print(tentativa);
            delay(2000);
        }
        tentativa++;
    }while(!client.connected() && tentativa < 5);

    if(tentativa < 5){
        client.publish(topico, "tentativasMultiplas");
        client.subscribe(topico);
        return 1;
    }else{
        Serial.println("Nao conectado");
        return 0;
    }
}

void callback(char* topic, byte* payload, unsigned int length){
    Serial.print("Messagem do topico:");
    Serial.println(topic);
    Serial.print("Mensagem:");
    for(int i=0; i < length; i++){
        Serial.print((char) payload[i]);
    }
    Serial.println();
    Serial.println("---------------");
}