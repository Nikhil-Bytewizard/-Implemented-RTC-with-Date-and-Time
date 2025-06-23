```c
#include <LPC21xx.h>
#include "lcd.h"
#include "i2c.h"
#include "uart.h"
#include "rtc.h"
#include "utils.h"

#define SET_BUTTON (1 << 8) // P0.8: Set time
#define INC_BUTTON (1 << 9) // P0.9: Increment

int main(void) {
    char sec, min, hour, day, date, month, year;
    
    // Set button pins as input
    IO0DIR &= ~(SET_BUTTON | INC_BUTTON);
    
    // Initialize modules
    UART_Init();
    I2C_Init();
    LCD_Init();
    
    // Set initial time: 12:00:00, Mon, 23/06/25
    RTC_SetTime(0, 0, 12, 1, 23, 6, 25);
    
    while (1) {
        // Read time from RTC
        RTC_GetTime(&sec, &min, &hour, &day, &date, &month, &year);
        
        // Display on LCD
        LCD_Clear();
        LCD_Text("Time: ");
        LCD_Data((hour / 10) + '0'); LCD_Data((hour % 10) + '0');
        LCD_Data(':');
        LCD_Data((min / 10) + '0'); LCD_Data((min % 10) + '0');
        LCD_Data(':');
        LCD_Data((sec /10) + '0'); LCD_Data((sec % 10) + '0');
        
        LCD_Cmd(0xC0); // Second line
        LCD_Text("Date: ");
        LCD_Data((date / 10) + '0'); LCD_Data((date % 10) + '0');
        LCD_Data('/');
        LCD_Data((month / 10) + '0'); LCD_Data((month % 10) + '0');
        LCD_Data('/');
        LCD_Data((year / 10) + '0'); LCD_Data((year % 10) + '0');
        
        // Send to UART
        UART_SendText("Time: ");
        UART_SendNum(hour); UART_SendChar(':');
        UART_SendNum(min); UART_SendChar(':');
        UART_SendNum(sec); UART_SendText("\r\n");
        
        UART_SendText("Date: ");
        UART_SendNum(date); UART_SendChar('/');
        UART_SendNum(month); UART_SendChar('/');
        UART_SendNum(year); UART_SendText("\r\n\r\n");
        
        // Check buttons
        if (!(IO0PIN & SET_BUTTON)) { // SET pressed
            Delay_ms(200); // Avoid bounce
            if (!(IO0PIN & INC_BUTTON)) { // INC pressed
                min = (min + 1) % 60; // Increase minutes
                RTC_SetTime(sec, min, hour, day, date, month, year);
            }
        }
        
        Delay_ms(1000); // Update every second
    }
}
```