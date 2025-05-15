#include "ds1307.h"

DS1307::DS1307(i2c_inst_t* i2c_port) {
    i2c = i2c_port;
}

bool DS1307::begin() {
    uint8_t reg = 0x00;
    uint8_t sec;
    int ret = i2c_write_blocking(i2c, DS1307_ADDR, &reg, 1, true);
    if (ret < 0) return false;
    ret = i2c_read_blocking(i2c, DS1307_ADDR, &sec, 1, false);
    return ret >= 0;
}

uint8_t DS1307::decToBcd(uint8_t val) {
    return ((val / 10) << 4) | (val % 10);
}

uint8_t DS1307::bcdToDec(uint8_t val) {
    return ((val >> 4) * 10) + (val & 0x0F);
}

void DS1307::setTime(uint8_t hr, uint8_t min, uint8_t sec) {
    uint8_t data[4];
    data[0] = 0x00;
    data[1] = decToBcd(sec);
    data[2] = decToBcd(min);
    data[3] = decToBcd(hr);
    i2c_write_blocking(i2c, DS1307_ADDR, data, 4, false);
}

void DS1307::getTime(uint8_t &hr, uint8_t &min, uint8_t &sec) {
    uint8_t reg = 0x00;
    uint8_t data[3];
    i2c_write_blocking(i2c, DS1307_ADDR, &reg, 1, true);
    i2c_read_blocking(i2c, DS1307_ADDR, data, 3, false);
    sec = bcdToDec(data[0] & 0x7F);
    min = bcdToDec(data[1]);
    hr = bcdToDec(data[2] & 0x3F);
}
