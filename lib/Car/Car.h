#ifndef CAR_H
#define CAR_H

#include <Moror.h>

class Car
{

private:
    Motor *upLeftMotor;
    Motor *upRightMotor;
    Motor *downLeftMotor;
    Motor *downRightMotor;

    Motor *allMotors[4]; // Array of pointers to the motors

public:
    Car(Motor *motors[4]) : upLeftMotor(motors[0]),
                            upRightMotor(motors[1]),
                            downLeftMotor(motors[2]),
                            downRightMotor(motors[3])
    {
        for (int i = 0; i < 4; i++)
        {
            allMotors[i] = motors[i];
        }
    };

    void Forward();
    void Backward();
    void Stop();
    void FrwLeft();
    void FrwRight();
    void BackLeft();
    void BackRight();
};

#endif // CAR_H
