```c
#include <LPC21xx.h>
#include "rtc.h"
#include "i2c.h"

char BCD_to_Dec(char bcd); // Forward declaration
char Dec_to_BCD(char dec);

void RTC_SetTime(char sec, char min, char hour, char day, char date, char month, char year) {
    I2C_Start();
    I2C_Write(RTC_ADDR); // RTC address (write)
    I2C_Write(0x00); // Start at seconds register
    I2C_Write(Dec_to_BCD(sec));
    I2C_Write(Dec_to_BCD(min));
    I2C_Write(Dec_to_BCD(hour));
    I2C_Write(Dec_to_BCD(day));
    I2C_Write(Dec_to_BCD(date));
    I2C_Write(Dec_to_BCD(month));
    I2C_Write(Dec_to_BCD(year));
    I2C_Stop();
}

void RTC_GetTime(char *sec, char *min, char *hour, char *day, char *date, char *month, char *year) {
    *sec = BCD_to_Dec(I2C_ReadReg(RTC_ADDR, 0x00));
    *min = BCD_to_Dec(I2C_ReadReg(RTC_ADDR, 0x01));
    *hour = BCD_to_Dec(I2C_ReadReg(RTC_ADDR, 0x02));
    *day = BCD_to_Dec(I2C_ReadReg(RTC_ADDR, 0x03));
    *date = BCD_to_Dec(I2C_ReadReg(RTC_ADDR, 0x04));
    *month = BCD_to_Dec(I2C_ReadReg(RTC_ADDR, 0x05));
    *year = BCD_to_Dec(I2C_ReadReg(RTC_ADDR, 0x06));
}

char BCD_to_Dec(char bcd) {
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

char Dec_to_BCD(char dec) {
    return ((dec / 10) << 4) | (dec % 10);
}
```