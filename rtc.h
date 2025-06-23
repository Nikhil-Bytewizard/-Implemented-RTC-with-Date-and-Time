```c
#ifndef RTC_H
#define RTC_H

#define RTC_ADDR 0xD0 // DS1307 I2C address

void RTC_SetTime(char sec, char min, char hour, char day, char date, char month, char year);
void RTC_GetTime(char *sec, char *min, char *hour, char *day, char *date, char *month, char *year);

#endif
```