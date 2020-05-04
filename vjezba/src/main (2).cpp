/*#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <BH1750.h>

#define DHTPIN 2 // what digital pin we're connected to

#define DHTTYPE DHT22 // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

BH1750 lightMeter(0x23);

class SENSORS
{
public:
  SENSORS(){};
  ~SENSORS(){};
  void DHT_init()
  {
    Serial.println(F("DHTxx test!"));
    dht.begin();
  };

  void BH1750_init()
  {
    lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
    Serial.println(F("BH1750 Test"));
  };

  void readTempHum()
  {
    uint8_t h;
    uint8_t t;

    delay(2000);

    h = dht.readHumidity();
    t = dht.readTemperature();

    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print(F("Temperature: "));
    Serial.print(t);
    Serial.print(" *C ");
  };

  void readLight()
  {
    uint16_t lux;
    lux = lightMeter.readLightLevel();
    Serial.print(F("Light: "));
    Serial.print(lux);
    Serial.println(F(" lx"));
  };
};
*/
#include "Sensors.h"
SENSORS sensor;
void setup()
{
  Serial.begin(9600);
  sensor.DHT_init();
  sensor.BH1750_init();
}

void loop()
{
  sensor.readTempHum();
  sensor.readLight();
}