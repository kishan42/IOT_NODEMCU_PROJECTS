#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "node-mcu-623e8-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "YsfTEsq4OPEASDpmHLUrAwLXTU2mi5cyVecfCHMg"
#define WIFI_SSID "Kishan"
#define WIFI_PASSWORD "93283Kish@n"


void setup() {
  
 Serial.begin(9600);
 
 
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 
 pinMode(D0, OUTPUT);  
 pinMode(D1, OUTPUT);  
 pinMode(D2, OUTPUT);  
}

String l1;
void loop() {

 l1=Firebase.getString("LED");

 
    if(String(l1).equals("RED"))
    {
      digitalWrite(D0,HIGH);    
    }
    if(String(l1).equals("YELLOW"))
    {
      digitalWrite(D1,HIGH);    
    }
    if(String(l1).equals("GREEN"))
    {
      digitalWrite(D2,HIGH);    
    }
    if(String(l1).equals("RED OFF"))
    {
      digitalWrite(D0,LOW);          
    }
    if(String(l1).equals("YELLOW OFF"))
    {
      digitalWrite(D1,LOW);          
    }
    if(String(l1).equals("GREEN OFF"))
    {
      digitalWrite(D2,LOW);          
    }
delay(100);
}
