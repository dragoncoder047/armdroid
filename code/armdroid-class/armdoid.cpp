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
#define BASE 0
#define SHOULDER 1
#define ELBOW 2
#define WRIST_LEFT 3
#define WRIST_RIGHT 4
#define GRIPPER 5
#define ACCESSORY 6
#define JACKS 7

class Armdroid {
    private:
        uint8_t port[8];
        long current_positions[8];
        long target_positions[8];
        long phases[8];
        uint8_t dividers[8];
        uint8_t counters[8];
    public:
    Armdroid(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t x, uint8_t y, uint8_t z, uint8_t k) {
        this->port[0] = a;
        this->port[1] = b;
        this->port[2] = c;
        this->port[3] = d;
        this->port[4] = x;
        this->port[5] = y;
        this->port[6] = z;
        this->port[7] = k;
        for (uint8_t i = 0; i < 8; i++) pinMode(this->port[i], OUTPUT);
    }
    void motorGoto(uint8_t m, long pos) {
        this->target_positions[m] = pos;
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
        uint8_t seven = data << 3 | address;
        for (uint8_t i = 0; i < 7; i++) {
            digitalWrite(this->port[i], seven & (128 >> i) ? HIGH : LOW);
        }
        delayMicroseconds(10);
        digitalWrite(this->port[7], HIGH);
        delayMicroseconds(10);
        digitalWrite(this->port[7], LOW);
        delayMicroseconds(10);
    }
};
