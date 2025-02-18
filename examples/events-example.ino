#include "src/MsTime/ScheduledEvent.h"

#define N 3

#define EVENT_1_INDEX 0
#define EVENT_2_INDEX 1
#define EVENT_3_INDEX 2

ScheduledEvent event1;
ScheduledEvent event2(1000, [](){ Serial.println("Exec: Event #2"); });
ScheduledEvent event3(
  2000, 
  [](){ Serial.println("Exec: Event #3"); },
  nullptr,
  [](){ Serial.println("Stop: Event #3"); },
  5
);

ScheduledEvent* events[N] = { &event1, &event2, &event3 };

void eventThreeOnInit() { Serial.println("Init: Event #3"); }

void setup() {
  Serial.begin(9600);
  delay(500);

  events[EVENT_1_INDEX]->setTimeout(3000);
  events[EVENT_1_INDEX]->setNumRepeats(10);
  events[EVENT_1_INDEX]->attach(
    [](){ Serial.println("Exec: Event #1"); },
    [](){ Serial.println("Init: Event #1"); },
    [](){ Serial.println("Stop: Event #1"); }
  );

  events[EVENT_3_INDEX]->attach("init", eventThreeOnInit);

  for(uint8_t i = 0; i < N; i++)
    events[i]->init();

  for(uint8_t i = 0; i < N; i++)
    events[i]->start();
}

void loop() {
  for(uint8_t i = 0; i < N; i++)
    events[i]->tick();
}
