# -Implemented-RTC-with-Date-and-Time
Designed Digital Clock system that can display the present Date and Time on 16x2 LCD with  capability of setting the desired date and time in it. 

# Modular Digital Clock with LPC2129, RTC, LCD, and UART

## Overview
A digital clock using the LPC2129 microcontroller. It displays time (HH:MM:SS) and date (DD/MM/YY) on a 16x2 LCD and sends them to a PC via UART0 (9600 baud). Uses DS1307 RTC via I2C. Two buttons (SET, INC) adjust the time (minutes only).

## Features
- Shows time/date on 16x2 LCD.
- Outputs time/date to serial terminal.
- Set minutes using buttons.
- Modular drivers for UART, I2C, LCD, and RTC.

## Hardware
- **Microcontroller**: LPC2129 (12MHz crystal).
- **RTC**: DS1307 (I2C, 3V battery).
- **Display**: 16x2 LCD (HD44780).
- **Buttons**: 2 (SET, INC).
- **Serial**: USB-to-serial adapter (e.g., CP2102).
- **Other**: 4.7kΩ resistors (I2C), 10kΩ potentiometer (LCD), breadboard, wires.

## Pin Connections
| Component   | LPC2129 Pin | Purpose                 |
|-------------|-------------|-------------------------|
| LCD D4-D7   | P0.4-P0.7   | LCD data pins          |
| LCD RS      | P0.10       | Register select        |
| LCD EN      | P0.11       | Enable                 |
| DS1307 SCL  | P0.2        | I2C clock              |
| DS1307 SDA  | P0.3        | I2C data               |
| SET Button  | P0.8        | Start setting mode     |
| INC Button  | P0.9        | Increment minutes      |
| UART TXD    | P0.0        | Serial output to PC    |

## Software
- **IDE**: Keil uVision or LPCXpresso.
- **Compiler**: ARM7 toolchain.
- **Terminal**: Tera Term/PuTTY (9600 baud, 8-N-1).
- **Files**:
  - `main.c`: Main program.
  - `uart.h`, `uart.c`: UART driver.
  - `i2c.h`, `i2c.c`: I2C driver.
  - `lcd.h`, `lcd.c`: LCD driver.
  - `rtc.h`, `rtc.c`: RTC driver.
  - `utils.h`, `utils.c`: Delay function.

## Setup
1. **Circuit**:
   - DS1307: SCL to P0.2, SDA to P0.3, 4.7kΩ pull-ups to 3.3V.
   - LCD: D4-D7 to P0.4-P0.7, RS to P0.10, EN to P0.11, V0 to pot wiper, VDD to 5V, VSS/RW to GND.
   - Buttons: P0.8 (SET), P0.9 (INC) to GND, pull-ups to 3.3V.
   - UART: P0.0 (TXD) to adapter RX, GND to GND.
   - Power: 3.3V (LPC2129), 5V (LCD/DS1307).

2. **Program**:
   - Create project in Keil uVision/LPCXpresso.
   - Add all `.c` and `.h` files.
   - Compile and flash using JTAG/ISP.
   - Open terminal (9600 baud).

3. **Run**:
   - Power on. LCD shows "Time: 12:00:00", "Date: 23/06/25".
   - Terminal shows:
     ```
     Time: 12:00:00
     Date: 23/06/25
     ```
   - Press SET, then INC to increment minutes.
   - Updates every second.

## Project Structure
- `src/`: `main.c`, `uart.c`, `i2c.c`, `lcd.c`, `rtc.c`, `utils.c`.
- `include/`: `uart.h`, `i2c.h`, `lcd.h`, `rtc.h`, `utils.h`.
- `docs/`: This README.
- `images/`: Circuit diagram, setup photo, LCD/terminal output.

## Images
1. **Circuit Diagram**: Show LPC2129, DS1307, LCD, buttons, serial adapter (Fritzing/KiCad).
2. **Setup Photo**: Breadboard/PCB with all components.
3. **LCD Output**: Photo of LCD showing time/date.
4. **Terminal Output**: Screenshot of serial terminal.

## Troubleshooting
- **LCD Blank**: Check wiring, 5V, contrast pot.
- **No Serial Output**: Verify P0.0 to RX, baud rate.
- **RTC Failure**: Check I2C pull-ups, 3V battery.
- **No Updates**: Ensure DS1307 is initialized.

## Future Improvements
- Set hours, date, month, year via buttons.
- Add UART input for time setting.
- Include alarm feature.

## License
MIT License.
