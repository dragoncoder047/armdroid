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
#define WRIST_RIGHT 0
#define GRIPPER 1
#define ACCESSORY 7
#define JACKS 3

class AbstractArmdroid {
    private:
        int64_t current_positions[8];
        int64_t target_positions[8];
        uint8_t phases[8];
        uint8_t dividers[8];
        uint8_t counters[8];
    public:
    AbstractArmdroid() {
        // noop
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
    void torqueOff() {
        for (uint8_t i = 0; i < 8; i++) {
            this->writeToPort(i, 0);
        }
    }
    virtual void writeToPort(uint8_t address, uint8_t data) {};
};
