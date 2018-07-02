#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "0914542f136f4f6b898c735b987b444b";
const char* ssid = "brus5-network-2.4GHz-ex";
const char* password = "krawiitoszeff";

IPAddress ip(192, 168, 1, 99);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

#define ONE_WIRE_BUS D5

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, password);
  sensors.begin();
}

void sendTemps(){
  sensors.requestTemperatures();

  float temp = sensors.getTempCByIndex(0);
  Serial.println(temp);
  Blynk.virtualWrite(V1,temp);
}

void loop() {
  Blynk.run();
  sendTemps();
}
