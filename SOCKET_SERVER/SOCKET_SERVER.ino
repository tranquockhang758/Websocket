#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
WebSocketsServer webSocket = WebSocketsServer(81);

const IPAddress apIP(192, 168, 4, 1);
const char* apSSID = "ESP8266";

int indexthang;
int indexbang;
int indexva;
String inputString = ""; 
String username = "";
String password = "";
String Token = "";
bool stringComplete = false;

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);               // chuyen sang che dong Access point
  WiFi.softAP(apSSID,"12345678");              //thiet lap 1 open netword WiFi.softAP(ssid, password)
  Serial.print("Starting Access Point at \"");
  Serial.print(apSSID);
  Serial.println("\"");
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}
void loop() {
  webSocket.loop();
}

void webSocketEvent(uint8_t num, WStype_t type,
                    uint8_t * payload,
                    size_t length)
{
  String payloadString = (const char *)payload;
  Serial.print(payloadString);
  webSocket.broadcastTXT("@C201=C201nlttao&xyzGHYKLM123x");
  
}
