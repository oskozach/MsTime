#include <StopWatch.h>

StopWatch stopwatch;

void setup() {
    Serial.begin(9600);
    delay(500);

    Serial.println("Starting stopwatch...");

    stopwatch.start();
    delay(1000);

    uint32_t lapTime = stopwatch.lap();
    delay(1000);

    uint32_t totalElapsedTime = stopwatch.stop();

    Serial.print("Lap: "); Serial.println(lapTime);
    Serial.print("Total:  "); Serial.println(totalElapsedTime);
}

void loop() {}
