#include <Arduino.h>

const uint8_t PHASETAB[8] = {
    0b0001,
    0b0011,
    0b0010,
    0b0110,
    0b0100,
    0b1100,
    0b1000,
    0b1001
};

// use an enum here ??
#define BASE 6
#define SHOULDER 5
#define ELBOW 4
#define WRIST_LEFT 2
#define WRIST_RIGHT 3
#define GRIPPER 1
#define ACCESSORY 7
#define JACKS 8

class Armdroid {
    private:
        uint8_t port[8];
        int64_t current_positions[8];
        int64_t target_positions[8];
        uint8_t phases[8];
        uint8_t dividers[8];
        uint8_t counters[8];
    public:
    Armdroid(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t x, uint8_t y, uint8_t z, uint8_t k) {
        this->port[0] = x;
        this->port[1] = y;
        this->port[2] = z;
        this->port[3] = a;
        this->port[4] = b;
        this->port[5] = c;
        this->port[6] = d;
        this->port[7] = k;
        for (uint8_t i = 0; i < 8; i++) pinMode(this->port[i], OUTPUT);
        digitalWrite(this->port[7], HIGH);
    }
    void motorGoto(uint8_t m, long pos) {
        this->target_positions[m] = pos;
    }
    void motorMoveby(uint8_t m, long pos) {
        this->target_positions[m] += pos;
    }
    bool isStopped(uint8_t m) {
        return this->current_positions[m] == this->target_positions[m];
    }
    long getPos(uint8_t m) {
        return this->current_positions[m];
    }
    void setDivider(uint8_t m, uint8_t div) {
        this->dividers[m] = div;
    }
    void tick() {
        // update phases
        uint8_t changed_flags = 0, motor = 0;
        for (motor = 0; motor < 8; motor++) {
            if (this->isStopped(motor)) {
                this->counters[motor] = 0;
            } else {
                this->counters[motor]++;
                if (this->counters[motor] >= this->dividers[motor]) {
                    this->counters[motor] = 0;
                    if (this->current_positions[motor] < this->target_positions[motor]) {
                        this->current_positions[motor]++;
                        this->phases[motor] = (this->phases[motor] + 1) & 7;
                    } else {
                        this->current_positions[motor]--;
                        this->phases[motor] = (this->phases[motor] + 7) & 7;
                    }
                    changed_flags |= 1 << motor;
                }
            }
        }
        // write to port
        for (motor = 0; motor < 8; motor++) {
            if ((changed_flags & (1 << motor)) == 0) continue;
            this->writeToPort(motor, PHASETAB[this->phases[motor]]);
        }
    }
    void writeToPort(uint8_t address, uint8_t data) {
        uint8_t bits = data << 3 | address;
        for (uint8_t i = 0; i < 7; i++) {
            digitalWrite(this->port[i], bits & (1 << i) ? HIGH : LOW);
        }
        delayMicroseconds(20);
        digitalWrite(this->port[7], LOW);
        delayMicroseconds(20);
        digitalWrite(this->port[7], HIGH);
        delayMicroseconds(20);
    }
    void torqueOff() {
        for (uint8_t i = 0; i < 8; i++) {
            this->writeToPort(i, 0);
        }
    }
};
