
/* REQUIRES the following Arduino libraries:
  Adafruit library dht11 available in ide */

#include "DHT.h"

#define DHTPIN 2     // Digital pin 2 connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));
  dht.begin();
}

void loop()
{ 
  delay(2000); // Wait a few seconds between measurements.

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  
  float h = dht.readHumidity(); // Read relative humidity
  float t = dht.readTemperature(); // Read temperature as Celsius (the default)
 
  if (isnan(h) || isnan(t))  // Check if any reads failed and exit early (to try again).
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C ")); 
}
