#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "personal-58698-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "anyNV3EeBpLPrkseh9pjKg0wiBYfjcZMPlK37JUM"
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
     
}

void loop() 
{
             Firebase.set("name","KISHAN");
             Firebase.set("COLLAGE",1234);
             
            
  }
