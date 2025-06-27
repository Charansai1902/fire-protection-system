#include <DHT.h>
#define DHTPIN D4          
#define DHTTYPE DHT11
#define LEDPIN D2          

DHT dht(DHTPIN, DHTTYPE);

float temperatureThreshold = 45.0;  
float humidityThreshold = 15.0;

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C, Hum: ");
  Serial.print(hum);
  Serial.println(" %");

  if (temp >= temperatureThreshold && hum <= humidityThreshold) {
    digitalWrite(LEDPIN, HIGH);  
    Serial.println("🔥 Fire detected!");
  } else {
    digitalWrite(LEDPIN, LOW);   
  }

  delay(2000);
}
