class Flasher
{
    int ledPin;                   // the number of the LED pin
    long OnTime;                  // milliseconds of on-time
    long OffTime;                 // milliseconds of off-time
    int ledState;                 // ledState used to set the LED
    unsigned long previousMillis; // will store last time LED was updated

public:
    Flasher(int pin, long ontime, long offtime)
    {
        ledPin = pin;
        OnTime = ontime;
        OffTime = offtime;
        pinMode(ledPin, OUTPUT);

        ledState = LOW;
        previousMillis = 0;
    }
    void Update(long currentMillis)
    {
        if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
        {
            ledState = LOW;                 // Turn it off
            previousMillis = currentMillis; // Remember the time
            digitalWrite(ledPin, ledState); // Update the actual LED
        }
        else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
        {
            ledState = HIGH;                // turn it on
            previousMillis = currentMillis; // Remember the time
            digitalWrite(ledPin, ledState); // Update the actual LED
        }
    }
};

Flasher ledB(13, 100, 200);
Flasher ledR(12, 340, 126);
Flasher ledO(11, 480, 600);

void setup()
{
}

void loop()
{
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();
    ledB.Update(currentMillis);
    ledR.Update(currentMillis);
    ledO.Update(currentMillis);
}