# Laboratory monitoring system
![Build Status](https://travis-ci.org/Razzaz/labmonitoring.svg?branch=master)
[![Documentation Status](https://readthedocs.org/projects/labmonitoring/badge/?version=latest)](https://labmonitoring.readthedocs.io/en/latest/?badge=latest)

```
This project  is under heavy development, experimental, unversioned and not stable yet.
```
Project preview : [Go to dashboard](https://console.thinger.io/#/dashboard/labmonitoringDashboard?authorization=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiJEYXNoYm9hcmRfbGFibW9uaXRvcmluZ0Rhc2hib2FyZCIsInVzciI6InJhenpheiJ9.PXVjeoinGa1Vy7QXDAfhlfTAjLj-42ZbjM2urWpYKE8)

![Dashboard Preview](https://github.com/Razzaz/labmonitoring/blob/master/src/dashboard_1.png)

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
- Based on IoT (integrating with notification alert for unwanted/dangerous condition)

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

## Initialization
```
Arduino IDE v1.8.9

Click 'tools' and do configuration below
Board         : NodeMCU 1.0  (ESP-12E Module)
Upload Speed  : 115200
CPU Frequency : 80 Mhz
Flash Size    : 4M (1M SPIFFS)
Debug port    : Disabled
Debug Level   : None
IwIP Variant  : v2 Lower Memory
Erase Flash   : Only Skecth
Port          : Check on 'Device Manager'
Programmer    : AVRISP mkll
```


## Documentation
- [Thinger](http://docs.thinger.io/arduino/)
- [IFTTT](https://platform.ifttt.com/docs)
- [BH1750](https://github.com/Erriez/ErriezBH1750/blob/master/README.md)
- [DHT11](https://github.com/adafruit/DHT-sensor-library)
- [MQ135](https://github.com/GeorgK/MQ135)

## Library Dependencies
- Built-in ```Wire.h```
