#include "armdroid.cpp"

#define PA 8
#define PB 9
#define PC 6
#define PD 7
#define P0 2
#define P1 5
#define P2 4
#define PK 3

Armdroid arm(PA, PB, PC, PD, P0, P1, P2, PK);

void setup() {
    // nothing
    Serial.begin(9600);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);
}
#define mmm(N) r = analogRead(A##N); if (abs(r - 512) > 50) arm.motorMoveby(N, r > 512 ? 2 : -2); Serial.print(r); Serial.write('\t'); 
void loop() {
    arm.tick();
    arm.tick();
    delay(2); // don't move the motors too fast
    int r;
    Serial.println("m0\tm1\tm2\tm3\tm4\tm5");
    mmm(0);
    mmm(1);
    mmm(2);
    mmm(3);
    mmm(4);
    mmm(5);
    Serial.write('\n');
}
