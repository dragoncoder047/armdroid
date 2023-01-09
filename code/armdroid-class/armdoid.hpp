#include <Arduino.h>
#include "armbase.hpp"

class ParallelArmdroid : public AbstractArmdroid {
    private:
        uint8_t port[8];
    public:
    ParallelArmdroid(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t x, uint8_t y, uint8_t z, uint8_t k) {
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
};
