#include "src/MsTime/Timer.h"

Timer timer(1000, 5);

void setup() {
  Serial.begin(9600);
  delay(500);
  timer.start();
}

void loop() {
  static uint8_t count = 0;
  if(timer.tick())
    Serial.println(++count);
}
