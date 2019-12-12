#include <ThingerSmartConfig.h>
#include <Wire.h>
#include <ErriezBH1750.h>
#include <MQ135.h>
#include <DHT.h>

/* Put everything about lightSensor (BH1750) down here */
/* 
   Pin configuration : 
   VIN -> VCC 
   GND -> GND 
   SCL -> D2 
   SDA -> D1
*/
uint16_t lux;
void lightSensor();
BH1750 sensor(LOW);

/* Put everything about gasSensor (MQ135) down here */
/* 
   Pin configuration : 
   VCC -> VCC 
   GND -> GND 
   A0  -> A0 
   DO  -> D0 (Not Used)
*/
#define RLOAD 22.0
#define RZERO 879.13
float ppmCO2; 
void co2Sensor();
MQ135 gasSensor = MQ135(A0);

/* Put everything about humiditySensor (DHT11) down here */
/* 
   Pin configuration : 
   VCC -> VCC 
   GND -> GND 
   DATA-> D8
   NC  -> (Not Used)
*/
#define DHTTYPE DHT11
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE);
float humidity;
float temperature;
void humiditySensor();

/* Put everything about WiFi down here */
#define SSID      "ssid"
#define PASSWORD  "pass"

/* Put everything about Thinger down here */
#define USERNAME  "username"
#define DEVICE_ID "deviceid"
#define DEVICE_CREDENTIAL "authtoken"
ThingerSmartConfig thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  Serial.begin(9600);

  /* lightSensor */
  Wire.begin();
  sensor.begin(ModeContinuous, ResolutionHigh);
  sensor.startConversion();

  /* gasSensor */
  // no need setup

  /* humiditySensor */
  dht.begin();

  
  WiFi.begin(SSID, PASSWORD);
  pinMode(D0, OUTPUT);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << digitalPin(D0);

  // resource output example (i.e. reading a sensor value)
  thing["Lux"] >> outputValue(lux);
  thing["CO2"] >> outputValue(ppmCO2);
  thing["Temperature"] >> outputValue(temperature);
  thing["Humidity"] >> outputValue(humidity);

}

void loop() {
  thing.handle();
  lightSensor();
  co2Sensor();
  humiditySensor();
}

void lightSensor() {
  if (sensor.isConversionCompleted()) {
    // Read light
    lux = sensor.read();

    // Print for test
    Serial.print(F("Light: "));
    Serial.print(lux / 2);
    Serial.print(F("."));
    Serial.print(lux % 10);
    Serial.println(F(" LUX"));
  }
  delay(1000); 
}

void co2Sensor() {
  ppmCO2 = gasSensor.getPPM();
  
  // Print for test
  Serial.print("CO2 : ");
  Serial.println(ppmCO2);
  delay(1000);
}

void humiditySensor(){
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  
  // Print for test
  Serial.print("Humidity : ");
  Serial.println(humidity);
  Serial.print("Temperature : ");
  Serial.println(temperature);
  delay(1000);
}
