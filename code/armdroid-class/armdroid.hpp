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
            digitalWrite(this->port[i], bits & (1 << i));
        }
        delayMicroseconds(20);
        digitalWrite(this->port[7], LOW);
        delayMicroseconds(20);
        digitalWrite(this->port[7], HIGH);
        delayMicroseconds(20);
    }
};

class PartialSerialArmdroid : public Armdroid {
    private:
        uint8_t dataPin;
        uint8_t clockPin;
        uint8_t latchPin;
        uint32_t dataIndexes;
        uint32_t addressIndexes;
    public:
    PartialSerialArmdroid(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint32_t dataIndexes, uint32_t addressIndexes) {
        this->dataPin = dataPin;
        this->clockPin = clockPin;
        this->latchPin = latchPin;
        pinMode(this->dataPin, OUTPUT);
        pinMode(this->clockPin, OUTPUT);
        pinMode(this->latchPin, OUTPUT);
        digitalWrite(this->dataPin, LOW);
        digitalWrite(this->clockPin, LOW);
        digitalWrite(this->latchPin, HIGH);
        this->dataIndexes = dataIndexes;
        this->addressIndexes = addressIndexes;
    }
    void writeToPort(uint8_t address, uint8_t data) {
        uint8_t b = (
            (((address >> ((this->addressIndexes >> 16) & 15)) & 1)     ) |
            (((address >> ((this->addressIndexes >>  8) & 15)) & 1) << 1) |
            (((address >> ((this->addressIndexes      ) & 15)) & 1) << 2) |
            (((data    >> ((this->dataIndexes    >> 24) & 15)) & 1) << 3) |
            (((data    >> ((this->dataIndexes    >> 16) & 15)) & 1) << 4) |
            (((data    >> ((this->dataIndexes    >>  8) & 15)) & 1) << 5) |
            (((data    >> ((this->dataIndexes         ) & 15)) & 1) << 6)
        );
        shiftOut(this->dataPin, this->clockPin, LSBFIRST, b);
        digitalWrite(this->latchPin, LOW);
        digitalWrite(this->latchPin, HIGH);
    }
};
