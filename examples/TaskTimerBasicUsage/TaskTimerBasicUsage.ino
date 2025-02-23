#include <TaskTimer.h>

void onReset() { Serial.println("Reset"); }

TaskTimer timer(
  1000,
  [](){ Serial.println("Exec"); },
  [](){ Serial.println("Start"); },
  onReset,
  5
);

void setup() {
  Serial.begin(9600);
  delay(500);
  timer.start();
}

void loop() { timer.tick(); }
