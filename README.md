# Motor Vibration Monitor

An Arduino-based vibration monitoring system that measures motor vibration pulses using a digital vibration sensor and displays real-time vibration intensity and operational status on an SSD1306 128x64 OLED display.

## Hardware Components
- Arduino Board (Uno / Nano / Mega)
- Digital Vibration Sensor Module (e.g., SW-420) connected to **Digital Pin 2**
- SSD1306 0.96" I2C OLED Display (128x64, address `0x3C`)
- Connecting Wires & Breadboard

## Wiring / Pin Configuration
| Component | Arduino Pin | Notes |
|---|---|---|
| Vibration Sensor DO | Pin 2 | Input |
| Vibration Sensor VCC | 5V / 3.3V | Power |
| Vibration Sensor GND | GND | Ground |
| OLED SDA | A4 (Uno/Nano) / SDA | I2C Data |
| OLED SCL | A5 (Uno/Nano) / SCL | I2C Clock |
| OLED VCC | 5V / 3.3V | Power |
| OLED GND | GND | Ground |

## Status Thresholds
The vibration level is calculated every 1 second based on recorded pulses:
- **NORMAL**: Vibration Level < 30%
- **WARNING**: Vibration Level 30% - 69%
- **FAULT**: Vibration Level >= 70%

## Required Arduino Libraries
- `Adafruit GFX Library`
- `Adafruit SSD1306`
- `Wire` (built-in)
