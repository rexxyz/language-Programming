#include <AS5600.h>

AS5600 encoder;
float output;
int sudut;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // get the angle in degrees of the encoder
  output = encoder.getAngle();
  sudut = output * 0.087890625;
  Serial.println(sudut);
  //FXXRPI pull
}
