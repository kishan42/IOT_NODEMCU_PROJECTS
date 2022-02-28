#include<ESP8266WiFi.h>

WiFiClient client2;
WiFiServer  server(80);
 
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 WiFi.softAP("X_MAN","bhai bhai");    // it command is used to create on server by nodemcu 
 Serial.println();
 Serial.println("network is started");
 Serial.print(WiFi.softAPIP());   // it command is used to print ip address of nodemcu
 server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  client2 = server.available();
  if(client2 == 1)
  {
    String request = client2.readStringUntil('\n');
    Serial.println(request);
  }
}
