#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char* ssid = "WiFixD";
const char* password = "0123456789";
bool isSet = false;

void setup() {
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);

  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.println(IP);
  
  server.on("/on", HTTP_GET, [] (AsyncWebServerRequest *request) {
    fuck = true;
    request->send(200, "text/plain", "Hello");
  });
  
  server.on("/off", HTTP_GET, [] (AsyncWebServerRequest *request) {
    fuck = false;
    request->send(200, "text/plain", "Hello");
  });

  server.begin();
}

void loop() {
  if(isSet){
    digitalWrite(2,LOW);
  } else {
    digitalWrite(2,HIGH);
  }
}
