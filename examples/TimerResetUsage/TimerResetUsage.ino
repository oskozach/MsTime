#include "src/MsTime/Timer.h"

Timer timer;

void setup() {
  Serial.begin(9600);
  delay(500);
  timer.setTimeout(1000);
  timer.start();
}

void loop() {
  static uint8_t pos = 0;
  if(timer.tick()) {
    char ch = 'A' + pos++;
    Serial.println(ch);
    if(ch == 'F')
      timer.reset();
  }
}
