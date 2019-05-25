#include <RTClib.h>
#include <Wire.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
#include "DHT.h"
#include <SPI.h>
#include <SD.h>
#include <TimeLib.h>

#define DHTTYPE DHT22   // DHT 22 
#define DHTPIN  8

const int chipSelect = 11;
#define ONE_WIRE_BUS 3 
RTC_DS1307 rtc;
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
DHT dht(DHTPIN, DHTTYPE);

void setup () {
  Serial.begin(9600);
  sensors.begin(); 
  dht.begin();
  while (!Serial); // for Leonardo/Micro/Zero
 Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(10, 11, 12, 13)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");


  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2019, 5, 26, 19, 11, 0));
    //rtc.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop () {
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(5, LOW);
  char buffer[10];
    float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
   sensors.requestTemperatures(); 
   

  float t = dht.readTemperature();
  File dataFile = SD.open("datalog.csv", FILE_WRITE);
    DateTime now = rtc.now();
    //DateTime now (now+ TimeSpan(0, 0, 17, 0));
    String dataString = "";
    dataString += dtostrf(now.year(), 4, 1, buffer);
    
     dataString += "-";
     dataString += dtostrf(now.month(), 4, 1, buffer);
    
     dataString += "-";
     dataString += dtostrf(now.day(), 4, 1, buffer);
    
     dataString += " ";
     dataString += dtostrf(now.hour(), 4, 1, buffer);
    
     dataString += ":";
     dataString += dtostrf(now.minute(), 4, 1, buffer);
    
     dataString += ":";
     dataString += dtostrf(now.second(), 4, 1, buffer);
    sensors.getTempCByIndex(0);
    
     dataString += " , ";
     dataString += dtostrf(h, 4, 1, buffer);

     dataString += " , ";
     dataString += dtostrf(t, 4, 1, buffer);
        
     dataString += " , ";
    sensors.requestTemperatures(); 
    dataString += dtostrf(sensors.getTempCByIndex(0), 4, 1, buffer);

     dataString += " ; ";
    if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
  delay(60000);
}
