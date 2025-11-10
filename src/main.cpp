#include <Arduino.h>

#include <BleController.h>

// TOP RIGHT
const int B1A_TOP = D6;
const int B2A_TOP = D5;
// TOP LEFT
const int A1A_TOP = D7;
const int A1B_TOP = D8;
// DOWN LEFT
const int B1A_DOWN = D9;
const int B2A_DOWN = D10;
// DOWN RIGHT
const int A1A_DOWN = D0;
const int A1B_DOWN = D2;

BleController *controller = nullptr; // Глобально

void setup()
{
  Serial.begin(115200);
  // Pinmode inside each motor
  Motor *allMotors[4] = {
      // up left
      new Motor{A1A_TOP, A1B_TOP},
      // up right
      new Motor{B1A_TOP, B2A_TOP},
      // down left
      new Motor{A1A_DOWN, A1B_DOWN},
      // down right
      new Motor{B1A_DOWN, B2A_DOWN},
  };

  Car *car = new Car{allMotors};

  // listen ble commands inside
  controller = new BleController{car};
  Serial.println("Программа запущена!");
}

void loop()
{
  delay(15000);
  Serial.println("Программа работает!");
}
