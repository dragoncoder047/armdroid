#include "armdroid.hpp"

PartialSerialArmdroid arm(4, 7, 2, 0x012, 0x3456);

void setup() {
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);
}
#define mmm(N, P) r = analogRead(A##N); if (abs(r - 512) > 100) { arm.motorMoveby(P, map(r, 1023, 0, -20, 20)); t += abs(r); }

void loop() {
    for (int i = 0; i < 20; i++) {
        arm.tick();
        delay(1);
    }
    int r;
    unsigned long t;
    mmm(0, BASE);
    mmm(1, SHOULDER);
    mmm(2, WRIST_RIGHT);
    mmm(3, WRIST_LEFT);
    mmm(4, GRIPPER);
    mmm(5, ELBOW);
    if (t == 0) arm.torqueOff();
}
