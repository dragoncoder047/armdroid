// Pins
#define PA 3
#define PB 4
#define PC 5
#define PD 6

#define CTL A0

#define MAPF(x, il, ih, ol, oh) (((x)-(il))*((oh)-(ol))/((ih)-(il))+(ol))

#define ENABLE_FULL_STEPPING

const unt8_t steps[8] = {
    0b0001,
    0b0011,
    0b0010,
    0b0110,
    0b0100,
    0b1100,
    0b1000,
    0b1001
};

// State
uint8_t index = 0;
uint64_t lastStep = 0;

void setup() {
    pinMode(PA, OUTPUT); pinMode(PB, OUTPUT); pinMode(PC, OUTPUT); pinMode(PD, OUTPUT);
    pinMode(CTL, INPUT);
}

void loop() {
    uint32_t val = analogRead(CTL);
    // delay the required amount
    // Math here: 1000000 us   / 400 half-steps   X turns \    X us
    //            ---------- / | -------------- x ------- | == ----
    //               sec       \      turn          sec   /    step
    int64_t speed = (1000000L / 400) / (int32_t)MAPF((float)val, 0, 1023.0, -10.0, 10.0);
    uint64_t delay_amount = abs(speed); // abs is a macro; let's save some calculations
    uint64_t mi = micros();
    if (lastStep + delay_amount >= mi) {
        lastStep = mi;
        step(speed > 0);
#if defined(ENABLE_FULL_STEPPING)
        if (delay_amount < 1000) { // Do full steps for speed > 1 kHz
            lastStep += delay_amount; // account for increased speed speed
            step(speed > 0);
        }
#endif
        updatePins();
    }
}

void step(bool forward) {
    if (forward) index = (index + 1) & 7; // &7 same as %8 but faster
    else         index = (index + 7) & 7; // +7 is equivalent to -1 in mod-8
}

void updatePins(void) {
    uint8_t s = steps[index];
    digitalWrite(PA, s & 0b0001);
    digitalWrite(PB, s & 0b0010);
    digitalWrite(PC, s & 0b0100);
    digitalWrite(PD, s & 0b1000);
}