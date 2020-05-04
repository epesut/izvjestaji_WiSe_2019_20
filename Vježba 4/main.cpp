int ledPin = 13;
int buttonPin = 2;

byte pinState = LOW;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(buttonPin), glow, RISING);
}
void loop()
{
}
void glow()
{
    digitalWrite(ledPin, pinState);
    pinState = !pinState;
}