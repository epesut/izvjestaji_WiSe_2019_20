#include "Sensors.h"
#include <LowPower.h>
SENSORS sensor;

void setup()
{
  Serial.begin(9600);
  sensor.DHT_init();
  sensor.BH1750_init();
}

void loop()
{
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  sensor.readTempHum();
  sensor.readLight();
}
