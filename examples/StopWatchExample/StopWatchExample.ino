#include "src/MsTime/StopWatch.h"

StopWatch stopwatch;

void setup() {
    Serial.begin(9600);
    delay(500);

    Serial.println("Starting the stopwatch...");

    stopwatch.start();
    delay(1000);

    uint32_t lap1 = stopwatch.lap();
    delay(1000);

    uint32_t lap2 = stopwatch.lap();
    delay(1000);

    uint32_t final = stopwatch.stop();

    Serial.print("lap #1: "); Serial.println(lap1);
    Serial.print("lap #2: "); Serial.println(lap2);
    Serial.print("final:  "); Serial.println(final);
}

void loop() {}
