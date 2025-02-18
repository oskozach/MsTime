# MsTime

MsTime is an Arduino library for managing time-based events using `millis()`. It includes:

- `Timer` – A basic timer for interval tracking with repeat support.
- `ScheduledEvent` – Extends `Timer` to execute functions at set intervals with `init`, `exec`, and `stop` handlers.
- `StopWatch` – A simple stopwatch for measuring elapsed time with `start`, `stop`, and `lap` functions.
