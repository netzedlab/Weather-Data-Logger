# Weather Data Logger
### NETZED Laboratory, DAP, IIT Roorkee

## Abstract
We made five Weather Data Loggers and installed them at Rajiv Gandhi International Airport, Hyderabad to measure the building’s surface temperature, air temperature, humidity for the purpose of the research that is being carried out at NETZED Laboratory, Department of Architecture and Planning, IIT Roorkee.

![Final-Product](https://github.com/SanjeevKrishnan/Weather-Data-Logger/blob/master/Images/Final%20Product.JPG)

## Function
It measures the building’s surface temperature, air temperature, and humidity and logs it in an SD card at an interval of 1 minute.

![Module](https://github.com/SanjeevKrishnan/Weather-Data-Logger/blob/master/Images/Module.JPG)

## Components
1. Arduino Uno - Microcontroller
2. Arduino Data Logger Shield Module - For SD card module and RTC Module
3. DS18B20 Temperature Sensor Probe - Measures Surface Temperature
4. DHT22 - Measures Air Temperature and Humidity
5. DC 5V 1A Adapter - Powers the system 

## Libraries 
1. Wire.h - For SD card communication
2. OneWire.h - For One Wire communication(DS18B20)
3. RTCLib.h - For RTC module
4. TimeLib.h - To set time in RTC Module
5. SPI.h - For SPI communication between microcontroller and SD card
6. SD.h - For SD card communication
7. DallasTemperature.h - For DS18B20
8. DHT.h - For DHT22

## References

<https://create.arduino.cc/projecthub/iotboys/how-to-use-ds18b20-water-proof-temperature-sensor-2adecc>

<https://create.arduino.cc/projecthub/mafzal/temperature-monitoring-with-dht22-arduino-15b013>

<https://learn.adafruit.com/adafruit-data-logger-shield>
