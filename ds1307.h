#ifndef DS1307_H
#define DS1307_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define DS1307_ADDR 0x68

class DS1307 {
public:
    DS1307(i2c_inst_t* i2c_port);
    bool begin();
    void setTime(uint8_t hr, uint8_t min, uint8_t sec);
    void getTime(uint8_t &hr, uint8_t &min, uint8_t &sec);

private:
    i2c_inst_t* i2c;
    uint8_t decToBcd(uint8_t val);
    uint8_t bcdToDec(uint8_t val);
};

#endif
