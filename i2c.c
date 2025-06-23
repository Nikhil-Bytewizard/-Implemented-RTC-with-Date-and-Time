```c
#include <LPC21xx.h>
#include "i2c.h"

void I2C_Init(void) {
    I2C0CONSET = 0x40; // Enable I2C
    I2C0SCLH = 75; I2C0SCLL = 75; // 100kHz for 12MHz clock
}

void I2C_Start(void) {
    I2C0CONSET = 0x20; // Send START
    while (!(I2C0CONSET & 0x08)); // Wait for completion
}

void I2C_Write(char data) {
    I2C0DAT = data;
    I2C0CONSET = 0x04; // Enable ACK
    while (!(I2C0CONSET & 0x08));
}

void I2C_Stop(void) {
    I2C0CONSET = 0x10; // Send STOP
    while (I2C0CONSET & 0x10);
}

void I2C_WriteReg(char addr, char reg, char data) {
    I2C_Start();
    I2C_Write(addr); // Device address (write)
    I2C_Write(reg);  // Register address
    I2C_Write(data); // Data
    I2C_Stop();
}

char I2C_ReadReg(char addr, char reg) {
    char data;
    I2C_Start();
    I2C_Write(addr); // Device address (write)
    I2C_Write(reg);  // Register address
    I2C_Start();
    I2C_Write(addr | 0x01); // Device address (read)
    I2C0CONCLR = 0x04; // No ACK for last byte
    while (!(I2C0CONSET & 0x08));
    data = I2C0DAT;
    I2C_Stop();
    return data;
}
```