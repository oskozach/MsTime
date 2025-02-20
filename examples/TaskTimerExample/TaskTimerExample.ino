#include "src/MsTime/TaskTimer.h"

void onStop() { Serial.println("Task: Stop"); }

// TaskTimer taskTimer(1000,
//                     [](){ Serial.println("Task: Exec"); },
//                     [](){ Serial.println("Task: Start"); },
//                     onStop,
//                     5);
TaskTimer taskTimer;

void setup() {
  Serial.begin(9600);
  delay(500);

  taskTimer.setTimeout(1000);
  taskTimer.setNumRepeats(5);
  taskTimer.attachExec([](){ Serial.println("Task: Exec"); });
  taskTimer.attachOnStart([](){ Serial.println("Task: Start"); });
  taskTimer.attachOnStop(onStop);
  
  taskTimer.start();
}

void loop() { taskTimer.tick(); }
