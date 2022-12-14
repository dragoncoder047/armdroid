#include "armdroid.cpp"

#define PA FILL_ME_IN
#define PB FILL_ME_IN
#define PC FILL_ME_IN
#define PD FILL_ME_IN
#define P0 FILL_ME_IN
#define P1 FILL_ME_IN
#define P2 FILL_ME_IN
#define PK FILL_ME_IN

Armdroid arm(PA, PB, PC, PD, P0, P1, P2, PK);

void setup() {
    // nothing
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);
}
#define mmm(N) r = analogRead(A##N); if (abs(r - 512) > 50) arm.motorMoveby(N, r > 512 ? 2 : -2);
void loop() {
    arm.tick();
    delay(10); // don't move the motors too fast
    int r;
    mmm(0);
    mmm(1);
    mmm(2);
    mmm(3);
    mmm(4);
    mmm(5);
}
