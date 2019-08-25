#include <MQ2.h>
#include <Wire.h> 

int Analog_Input = A0;
int lpg, co, smoke;

MQ2 mq2(Analog_Input);

void setup(){
  Serial.begin(9600);

  mq2.begin();
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


