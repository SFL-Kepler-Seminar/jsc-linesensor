// -*- c++ -*-

// See https://www.arduino.cc/en/Reference/PortManipulation
#define SDA_PORT PORTD
#define SDA_PIN 6
#define SCL_PORT PORTD
#define SCL_PIN 7

#define I2C_TIMEOUT 100
#define I2C_SLOWMODE 1

#include <SoftWire.h>
#include <Wire.h>  
#include <LineSensor.h>


LineSensor<SoftWire> line1;
LineSensor<TwoWire> line2;


     
void setup()
{
  
  Serial.begin(9600);
  while (!Serial);
  line1.setup();
  line2.setup();

}


void loop()
{
    Serial.print("Prox, prox2: ");
    Serial.print( line1.getProximity());
    Serial.print(", ");
    Serial.println( line2.getProximity());
}


