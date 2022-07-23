#include <ESP8266WiFi.h>
#include <WebSocketsClient.h> //https://github.com/Links2004/arduinoWebSockets
WebSocketsClient webSocket;

const char* ip_host = "192.168.4.1"; //Đổi luôn IP host của PC nha
const uint16_t port = 81; //Port thích đổi thì phải đổi ở server nữa
const char* ssid = "ESP8266";
const char* pass = "12345678";
void setup() {
  Serial.begin(9600);
    WiFi.begin(ssid,pass); 
    Serial.printf("Connecting to %s \n", ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");

    }
    Serial.println();
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
  webSocket.begin(ip_host, port);

}
void loop() {
  webSocket.loop();
  webSocket.sendTXT("/HEHEHE=0776537277&43hjkFKDSOK9u787234klj@12");
  delay(200);
}
