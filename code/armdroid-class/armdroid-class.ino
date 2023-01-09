#include "armdroid.hpp"

#define PA 6
#define PB 7
#define PC 8
#define PD 9
#define P0 2
#define P1 5
#define P2 4
#define PK 3

Armdroid arm(PA, PB, PC, PD, P0, P1, P2, PK);

void setup() {
    Serial.begin(115200);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);
}
#define mmm(N, P) r = analogRead(A##N); if (abs(r - 512) > 200) arm.motorMoveby(P, r > 512 ? 2 : -2); Serial.print(arm.getPos(P)); Serial.write('\t'); t += abs(r); 

void loop() {
    arm.tick();
    arm.tick();
    int r;
    unsigned long t;
    Serial.println("m0\tm1\tm2\tm3\tm6\tm7");
    mmm(0, BASE);
    mmm(1, SHOULDER);
    mmm(2, WRIST_RIGHT);
    mmm(3, WRIST_LEFT);
    mmm(4, ELBOW);
    mmm(5, GRIPPER);
    if (t == 0) arm.torqueOff();
    Serial.write('\n');
    Serial.flush();
    //The time for the serial buffer to clear functions as a delay()
}
