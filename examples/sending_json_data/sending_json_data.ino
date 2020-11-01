#include <SoftwareSerial.h>
#include "SIM7080X.h"

SoftwareSerial Serial_SIM7080X(6, 7);

SIM7080X sim7080x;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial_SIM7080X.begin(9600);
  sim7080x.init(&Serial_SIM7080X);
  
  sim7080x.PowerOn(5);
  sim7080x.connectCellular();
  sim7080x.connectServer("iot.aphese.kr",1883,"g96egwTCXuB3FLtXm7TO");
  
  
  
  sim7080x.sendDataJson("{\"sensor_data\":209.997}");
}

void loop() {
  // put your main code here, to run repeatedly:

}
