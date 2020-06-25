#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10
const int trigPin = 3;
const int echoPin = 2;

const byte address[6] = {"1node"};

RF24 radio(CE_PIN, CSN_PIN);

struct SensorData
{
    bool info;
};

SensorData dataToSend;

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 50;
int ldistance = 65;
int counter = 0;

void send();
long read();

void setup()
{
    Serial.begin(115200);

    Serial.println(F("SimpleTx Starting"));
    radio.begin();
    radio.setDataRate(RF24_2MBPS);
    radio.setChannel(112);
    radio.setPALevel(RF24_PA_MAX);
    radio.setRetries(3, 5); // delay, count
    radio.openWritingPipe(address);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop()
{
    currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis)
    {
        send();
        prevMillis = millis();
    }
}

void send()
{

    long distance = read();
    if (ldistance - distance > 50)
    {
        dataToSend.info = true;
        // Always use sizeof() as it gives the size as the number of bytes.
        // For example if dataToSend was an int sizeof() would correctly return 2
        delay(50);
        while (!(radio.write(&dataToSend, sizeof(dataToSend))))
        {
            counter++;
            Serial.println("TXfailed");
        }
        Serial.print("\n BROJAC :");
        Serial.print(counter);
        Serial.print("\n");
        counter = 0;
    }
    //Serial.println(ldistance);
    //Serial.println(distance);
    ldistance = distance;
    //Serial.print("Data Sent ");
    //Serial.print(dataToSend.info);
    Serial.print(" ");
    dataToSend.info = false;
}

long read()
{
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1;
    delay(50);
    return distance;
}
