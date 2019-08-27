# Laboratory monitoring system
```
This project  is under heavy development, experimental, unversioned and not stable yet.
```
Project preview : 

## System Specification
- Hardware
  - NodeMCU 1.0 ESP8266
  - BH1750
  - DHT11
  - MQ135
  
- IoT Platform
  - [thinger.io](https://thinger.io/)
  - [IFTTT](https://ifttt.com/)

## System Features
- Light intensity measurement
- Temperature and humidity measurement
- Air quality measurement
- Realtime data collecting
- Based on IoT (integrating with notification alert for dangerous condition)

## Hardware Interfacing
**Schematic will be uploaded here**

| Pins board - BH1750            | Pins board - NodeMCU 1.0 ESP8266      |
| :----------------------------: | :-----------------------------------: |
| VIN                            | 3V3                                   |
| GND                            | GND                                   |
| SCL                            | D2                                    |
| SDA                            | D1                                    |

| Pins board - MQ135             | Pins board - NodeMCU 1.0 ESP8266      |
| :----------------------------: | :-----------------------------------: |
| VCC                            | 3V3                                   |
| GND                            | GND                                   |
| A0                             | A0                                    |
| D0                             | D0 (Not used)                         |

| Pins board - DHT11             | Pins board - NodeMCU 1.0 ESP8266      |
| :----------------------------: | :-----------------------------------: |
| VCC                            | 3V3                                   |
| GND                            | GND                                   |
| DATA                           | D8                                    |
| NC                             | (Not used)                            |
