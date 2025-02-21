#include "src/MsTime/TaskTimer.h"

TaskTimer timer(
  1000,
  [](){ Serial.println("Exec"); },
  nullptr,
  [](){ Serial.println("Reset"); },
  3
);

void setup() {
  Serial.begin(9600);
  delay(500);
  timer.attachOnStart([](){ Serial.println("Start"); });
  timer.detachOnReset();
  timer.start();
}

void loop() { timer.tick(); }
