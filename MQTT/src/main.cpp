#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//rede wifi - conexao
const char* rede = "BERTOLA_2.4G";
const char* senha = "170704gui";

//mqtt broker - conexao
const char* mqtt_broker = "192.168.0.15";
const char* topic = "topico/auto";
const char* mqtt_user = "Bertola123";
const char* mqtt_pas = "170704gui";
const char* mqtt_port = "1883";