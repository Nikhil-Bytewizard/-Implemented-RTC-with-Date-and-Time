```c
#ifndef LCD_H
#define LCD_H

void LCD_Init(void);      // Start LCD
void LCD_Cmd(char cmd);   // Send command
void LCD_Data(char data); // Send character
void LCD_Text(char *text); // Send string
void LCD_Clear(void);     // Clear display

#endif
```