#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ds1307.h"

#define I2C_PORT i2c0
#define SDA_PIN 0
#define SCL_PIN 1

int main() {
    stdio_init_all();

    i2c_init(I2C_PORT, 100000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    DS1307 rtc(I2C_PORT);
    if (!rtc.begin()) {
        printf("Failed to find DS1307\n");
        return 1;
    }

    rtc.setTime(13, 18, 0);  // Set initial time to 13:18:00

    while (true) {
        uint8_t hr, min, sec;
        rtc.getTime(hr, min, sec);
        printf("Time: %02d:%02d:%02d\n", hr, min, sec);
        sleep_ms(1000);
    }
}
