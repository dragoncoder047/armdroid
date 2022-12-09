#include "armdroid.cpp"

#define PA FILL_ME_IN
#define PB FILL_ME_IN
#define PC FILL_ME_IN
#define PD FILL_ME_IN
#define P1 FILL_ME_IN
#define P2 FILL_ME_IN
#define P3 FILL_ME_IN
#define PK FILL_ME_IN

Armdroid arm(PA, PB, PC, PD, P1, P2, P3, PK);

uint8_t watching = 0;
uint8_t i;
const char s[8] = 'BSELRGAJ';

void setup() {
    Serial.begin(9600);
}
void loop() {
    arm.tick();
    delay(10); // don't move the motors too fast
    long pos = 0;
    uint8_t motor = 255;
    if (Serial.available()) {
        char c = Serial.peek();
        while ('0' <= c && c <= 9) {
            pos *= 10;
            pos += c - '0';
            c = Serial.peek();
        }
        for (i = 0; i < 8; i++) {
            if (s[i] == (c | 0x20)) { // allow uppercase or lowercase
                motor = i;
                break;
            }
        }
        if (motor == 255) {
            Serial.println('Invalid Motor');
            Serial.flush();
            return;
        }
        watching |= 1 << motor;
        Serial.print("Moving Motor ");
        Serial.write(s[i]);
        Serial.print(" from position ");
        Serial.print(arm.getPos(i));
        Serial.print(" to position ");
        Serial.println(pos);
        arm.motorGoto(motor, pos);
    }
    for (i = 0; i < 8; i++) {
        if (watching & (1 << i) && arm.isStopped(i)) {
            watching &= ~(1 << i);
            Serial.print("Motor ");
            Serial.write(s[i]);
            Serial.print(" is now at position ");
            Serial.println(arm.getPos(i));
        }
    }
}
