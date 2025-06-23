```c
#include <LPC21xx.h>
#include "uart.h"

void UART_Init(void) {
    PINSEL0 |= 0x00000005; // Enable TXD0 (P0.0), RXD0 (P0.1)
    U0LCR = 0x83; // 8 bits, 1 stop bit, enable divisor
    U0DLL = 78; U0DLM = 0; // 9600 baud for 12MHz clock
    U0LCR = 0x03; // Disable divisor
}

void UART_SendChar(char c) {
    while (!(U0LSR & 0x20)); // Wait until ready
    U0THR = c; // Send character
}

void UART_SendText(char *text) {
    while (*text) UART_SendChar(*text++); // Send each character
}

void UART_SendNum(char num) {
    UART_SendChar((num / 10) + '0'); // Tens digit
    UART_SendChar((num % 10) + '0'); // Units digit
}
```