#include <Car.h>

void Car::Forward()
{
    for (int i = 0; i < 4; i++)
    {
        allMotors[i]->Forward();
    }
}

void Car::Backward()
{
    for (int i = 0; i < 4; i++)
    {
        allMotors[i]->Backward();
    }
}

void Car::Stop()
{

    for (int i = 0; i < 4; i++)
    {
        allMotors[i]->Stop();
    }
}

void Car::FrwLeft()
{
    Stop();
    upRightMotor->Forward();
    downRightMotor->Forward();
}

void Car::FrwRight()
{
    Stop();
    upLeftMotor->Forward();
    downLeftMotor->Forward();
}

void Car::BackLeft()
{
    Stop();
    upRightMotor->Backward();
    downRightMotor->Backward();
}

void Car::BackRight()
{
    Stop();
    upLeftMotor->Backward();
    downLeftMotor->Backward();
}
