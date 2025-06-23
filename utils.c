```c
#include <LPC21xx.h>
#include "utils.h"

void Delay_ms(int ms) {
    int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1141; j++); // Calibrated for 12MHz
}
```