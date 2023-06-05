#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "BERTOLA_2.4G_EXT";
const char* password = "170704gui";


WiFiClient client;
HTTPClient http;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println(WiFi.localIP());

}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    http.begin(client, "http://127.0.0.1:3000/");
    int httpCode = http.GET();
    Serial.println("Connected");
    Serial.println(httpCode);
    //Check the returning code
    if (httpCode == 200) {
      Serial.println("Connected");
      String payload = http.getString();
      Serial.println("http string");
      Serial.println(payload);
      Serial.println("http string end");

    } else {
      Serial.println("Gateway Problem");
    }
    http.end();   //Close connection
  } else {
    Serial.println("NOT Connected! Check WiFi");
  }
  // Delay
  delay(1000);

}