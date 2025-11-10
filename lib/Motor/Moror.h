#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor
{
private:
    int IA, IB;

public:
    Motor(int ia, int ib);
    ~Motor() = default;

    void Forward();
    void Backward();
    void Stop();
};



#endif // MOTOR_H
