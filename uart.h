```c
#ifndef UART_H
#define UART_H

void UART_Init(void);          // Start UART0 (9600 baud)
void UART_SendChar(char c);    // Send one character
void UART_SendText(char *text); // Send a string
void UART_SendNum(char num);   // Send a two-digit number

#endif
```