//Wifi
#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "put your firebase host here" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "put your auth here"
#define WIFI_SSID "put your ssid here"
#define WIFI_PASSWORD "password here"

FirebaseData firebaseData;
FirebaseJson json;

//Root Path
String path = "/ESP32_Device";

#include <DHT.h>
#define DHTPIN 4    
#define DHTTYPE    DHT11

DHT dht(DHTPIN, DHTTYPE);

float prev_temp;
float prev_humidity;

float h,t;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
  initWifi();
}

void loop() {
  t = dht.readTemperature();
  h = dht.readHumidity();
  
  delay(3000);
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));
  updateTemp(t);
    
  // Get humidity event and print its value.
  
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.println(F("%"));
    updateHumidity(h);
}

void updateTemp(float temp){
  if(prev_temp != temp){
    String tempString = "";
    tempString += (int)temp;
    tempString += "C";
    prev_temp = temp;
    i++;

    Firebase.setDouble(firebaseData, path +"/Temperature/Data", temp);
    Firebase.setDouble(firebaseData, path +"/Temperature/Data"+i, temp);    
  }
}

void updateHumidity(float humidity){
  if(prev_humidity != humidity){
    String humidityString = "";
    humidityString += (int)humidity;
    humidityString += "%";
    prev_humidity = humidity;

    Firebase.setDouble(firebaseData, path +"/Humidity/Data", humidity);
  }
}

void initWifi(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  
}
