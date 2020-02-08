//Thinger
#include <ThingerESP32.h>
#define USERNAME ""
#define DEVICE_ID ""
#define DEVICE_CREDENTIAL ""
#define SSID "Rizal"
#define SSID_PASSWORD ""
ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

//DHT
#include "DHT.h"
#define DHTPIN 4    
#define DHTTYPE DHT11
float h, t;
DHT dht(DHTPIN, DHTTYPE);

//sensor water level
int water;
int pin_data = 34;

//sensor soil moisture
int sensor_pin = 35;
int valueMoisture ;
 
void setup()
{
  //Thinger
  pinMode(LED_BUILTIN, OUTPUT);
  thing.add_wifi(SSID, SSID_PASSWORD);
  thing["led"] << digitalPin(LED_BUILTIN);
  thing["millis"] >> outputValue(millis());
  thing["moisture"] >> outputValue(valueMoisture);
  thing["water"] >> outputValue(water);
  thing["humidity"] >> outputValue(h);
  thing["temperature"] >> outputValue(t);

  //Water level
  pinMode(pin_data,INPUT);

  //Serial
  Serial.begin(9600);
  Serial.println("Reading");
  delay(2000);

  //dht
  dht.begin();
}
 
void loop()
{
  //Thinger
  thing.handle();
  
  //Soil Moisture Sensor 
  valueMoisture= analogRead(sensor_pin);
  //value = map(value,550,0,0,100);
  
  //Water Level Sensor
  water = analogRead(34);

  //DHT
  h = dht.readHumidity();
  t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  
  Serial.println(" ");
  Serial.print("Moisture : ");
  Serial.print(valueMoisture);
  Serial.println("%");
  Serial.print("Water level woy: ");
  Serial.println(water);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(F("%"));  
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.println(F("°F"));  
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  delay(1000);
}
