#include <Arduino.h>
#include <LittleFS.h>
#include <String.h>

void jschart(){

  LittleFS.begin();

  File file = LittleFS.open("chart.umd.js", "r");

  if (!file) {
    Serial.println("could not open file for reading");
  } else {

    while (file.available()) {
      char buf[32];

      size_t bytesRead = file.readBytes(buf, sizeof(buf) - 1);
      buf[bytesRead] = '\0';

      Serial.print(buf);

      yield();
    }

    file.close();
  }

  LittleFS.end();
}
