#include "armdroid.hpp"

uint8_t pack(uint8_t address, uint8_t data) {
    uint8_t revAddress = ((address & 4) >> 2) | (address & 2) | ((address & 1) << 2);
    return revAddress << 4 | data;
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
if (abs(r - 512) > 50) { \
    arm.motorMoveby(P, map(r, 1023, 0, -20, 20)); \
    t += abs(r - 512); \
}

void loop() {
    for (int i = 0; i < 20; i++) {
        arm.tick();
        delayMicroseconds(300);
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
