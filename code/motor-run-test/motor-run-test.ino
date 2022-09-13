// Pins
#define PA 3
#define PB 4
#define PC 5
#define PD 6

#define CTL A0

#define MAPF(x, il, ih, ol, oh) (((x)-(il))*((oh)-(ol))/((ih)-(il))+(ol))

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

void setup() {
    pinMode(PA, OUTPUT); pinMode(PB, OUTPUT); pinMode(PC, OUTPUT); pinMode(PD, OUTPUT);
    pinMode(CTL, INPUT);
}
void loop() {
    // update index
    if (analogRead(CTL) < (1023 / 2)) index = (index + 1) & 7; // &7 same as %8 but faster
    else                                    index = (index + 7) & 7; // +7 is equivalent to -1 in mod-8

    // update pins
    uint8_t s = steps[index];
    digitalWrite(PA, s & 0b0001);
    digitalWrite(PB, s & 0b0010);
    digitalWrite(PC, s & 0b0100);
    digitalWrite(PD, s & 0b1000);

    // delay the required amount
    // Math here: 1000000 us   / 400 half-steps   X turns \    X us
    //            ---------- / | -------------- x ------- | == ----
    //               sec       \      turn          sec   /    step
    int32_t delay_amount = (1000000L / 400) / (int32_t)MAPF((float)analogRead(CTL), 0, 1023.0, -10.0, 10.0);
    delayMicroseconds(abs(delay_amount));
}