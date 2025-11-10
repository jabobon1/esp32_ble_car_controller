#include <Arduino.h>
#include <Moror.h>

Motor::Motor(int ia, int ib) : IA(ia), IB(ib)
{
    pinMode(IA, OUTPUT);
    pinMode(IB, OUTPUT);
    Serial.println("Motor created");
}

void Motor::Forward()
{
    Serial.println("Motor frw");
    Serial.printf("%d - %d\n", IA, IB);
    digitalWrite(IA, HIGH);
    digitalWrite(IB, LOW);
}

void Motor::Backward()
{
    digitalWrite(IA, LOW);
    digitalWrite(IB, HIGH);
}

void Motor::Stop()
{
    digitalWrite(IA, LOW);
    digitalWrite(IB, LOW);
}
