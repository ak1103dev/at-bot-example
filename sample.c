#include <atx.h>
int ledPin = 48;
void setup()
{
  lcd("Hello Robot!");
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
