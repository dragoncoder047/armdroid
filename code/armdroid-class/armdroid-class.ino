#define ARMDROID_DEBUG
#include "armdroid.hpp"

uint8_t bitReverse(uint8_t data, const uint8_t numBits) {
    uint8_t out = 0;
    for (uint8_t i = 0; i < numBits; i++) {
        out = (out << 1) | (data & 1);
        data >>= 1;
    }
    return out;
}

uint8_t pack(uint8_t address, uint8_t data) {
    uint8_t aa = address >> 1 | (address & 1) << 2;
    uint8_t dd = data >> 2 | (data & 3) << 2;
    return aa << 4 | dd;
}

PartialSerialArmdroid arm(8, 7, 3, pack);

void setup() {
    Serial.begin(115200);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);
    pinMode(13, OUTPUT);
}

#define mmm(N, P) \
r = analogRead(A##N); \
if (abs(r - 512) > 20) { \
    arm.motorMoveby(P, map(r, 0, 1023, -20, 20)); \
    t += abs(r - 512); \
}

void loop() {
    for (int i = 0; i < 20; i++) {
        arm.tick();
        delayMicroseconds(700);
    }
    int r;
    unsigned long t = 0;
    mmm(0, BASE);
    mmm(1, SHOULDER);
    mmm(2, WRIST_RIGHT);
    mmm(3, WRIST_LEFT);
    mmm(4, GRIPPER);
    mmm(5, ELBOW);
    digitalWrite(13, t > 0);
}