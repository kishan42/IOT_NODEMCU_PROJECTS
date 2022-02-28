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
  client1.println("HTTP/1.1 200 OK");
  client1.println("content-Type: text/html");
  client1.println("");
  client1.println("<!DOCTYPE html>");
client1.println("<html>");
client1.println("<body>");
client1.println("<h2>WELCOME TO WEB-PAGE !</h2>");
client1.println("<h4>SEND A MESSAGE TO NODEMCU</h4>");
client1.println("<br>");
client1.println("<a href=\"/hello\"\"><button>HELLO</button></a>");
client1.println("<a href=\"/hello_kishan\"\"><button>HELLO KISHAN</button></a><br/>");
client1.println("<a href=\"/hii\"\"><button>HII</button></a>");
client1.println("<a href=\"/hii_kishan\"\"><button>HII KISHAN</button></a><br/>");
client1.println("</body>");
client1.println("</html>");

}
