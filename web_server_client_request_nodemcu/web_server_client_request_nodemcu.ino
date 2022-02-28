#include<ESP8266WiFi.h>

WiFiClient client1;
WiFiServer server(80);

#define WIFI_SSID "Kishan"
#define WIFI_PASSWORD "93283Kish@n"

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
 Serial.print("connecting");
 while(WiFi.status() != WL_CONNECTED)
 { 
  Serial.print(".");
  delay(500);
  }
  Serial.println();
  Serial.println("connected");
  Serial.println(WiFi.localIP());
  server.begin();
 }

void loop() {
  // put your main code here, to run repeatedly:
 client1 = server.available();
 if (client1 == 1){
  String request = client1.readStringUntil('\n');
  request.trim();
  Serial.println(request); 
  }
}
