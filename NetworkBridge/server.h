#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define PORT 80
#define HTTP_OK 200
#define SYSTEM_SSID "CONTROL-NODE"
#define SYSTEM_PASS "1234567890"
#define DEFAULT_MIME "text/html"

ESP8266WebServer server(PORT);
char command[4] = {0, 0, 0, 0};
char relayStates[8] = {'0', ',', '0', ',' , '0', ',', '0'};

void controlRelays(){
  int relay_id = server.arg(0).toInt();
  if(relay_id >= 0 && relay_id <= 3){
    command[0] = 0x30 + ((char) relay_id);
    command[1] = 0x30 + ((char) !server.arg(1).toInt());
    relayStates[relay_id*2] = 0x30 + ((char) server.arg(1).toInt());
  
     
    i2c_send_data(TARGET_ADDR, command);  
  }
  server.send(HTTP_OK, DEFAULT_MIME, relayStates);
}

void getRelayStatus(){
    server.send(HTTP_OK, DEFAULT_MIME, relayStates);
}

void nothing(){
    server.send(HTTP_OK, DEFAULT_MIME, "");
}

void init_net(){
  WiFi.mode(WIFI_AP);
  WiFi.softAP(SYSTEM_SSID, SYSTEM_PASS);
}

void init_server(){
  server.on("/control", controlRelays);
  server.on("/status", getRelayStatus);
  server.on("/reset", reset_relays);
  server.onNotFound(nothing);
  server.begin();
}


void server_loop(){
  server.handleClient();
}
