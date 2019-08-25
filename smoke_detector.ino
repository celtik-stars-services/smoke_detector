#include <MQ2.h>
#include <Wire.h> //?
#include <ESP8266WiFi.h>

int Analog_Input = A0;
int lpg, co, smoke;

MQ2 mq2(Analog_Input);

// Update these with values suitable for your network.
const char* ssid = "ssid";
const char* password = "pass";
const char* mqtt_server = "192.168.0.2";

void setup(){
  Serial.begin(9600);

  mq2.begin();
  WiFi.begin("ssid", "password");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  
}
void loop(){
  float* values= mq2.read(true); 
  lpg = mq2.readLPG();

  co = mq2.readCO();

  smoke = mq2.readSmoke();

  Serial.print("LPG:");
  Serial.print(lpg);
  Serial.print(" CO:");
  Serial.print(co);

  Serial.print("SMOKE:");
  Serial.print(smoke);
  Serial.print(" PPM");
  delay(1000);
}

