/*
* Create a WiFi access point and provide a web server on it.
* Connect Desktop, Laptop, Mobile HasWifi Enable to Wifi Named "ESPap"
* Then go to browser type http://192.168.4.1 to visit web page and Output Message
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define APSSID "ESPap" // WIFI SSID  NAME
#define APPSK  "thereisnospoon" //WIFI PASSWORD

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected to NodeMCU</h1>");
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(APSSID, APPSK);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  
}

void loop() {
  server.handleClient();
}
