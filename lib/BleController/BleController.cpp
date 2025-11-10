#include <Arduino.h>
#include <BleController.h>

#include <unordered_map>

enum class Direction
{
    UNKNOWN,
    FORWARD,
    BACKWARD,
    UP_LEFT,
    UP_RIGHT,
    DOWN_LEFT,
    DOWN_RIGHT,
    STOP,

};

// String to enum
Direction stringToDirection(const std::string &str)
{
    static const std::unordered_map<std::string, Direction> directionMap = {
        {"F", Direction::FORWARD},
        {"B", Direction::BACKWARD},
        {"UL", Direction::UP_LEFT},
        {"UR", Direction::UP_RIGHT},
        {"DL", Direction::DOWN_LEFT},
        {"DR", Direction::DOWN_RIGHT},
        {"S", Direction::STOP},
    };

    auto it = directionMap.find(str);
    if (it != directionMap.end())
    {
        return it->second;
    }
    throw Direction::UNKNOWN;
}

class MyCharacteristicCallbacks : public BLECharacteristicCallbacks
{
private:
    Car *car; // Ссылка на контроллер мотора

public:
    // Конструктор с параметрами
    MyCharacteristicCallbacks(Car *car) : car(car) {}

    void onWrite(BLECharacteristic *pCharacteristic) override
    {
        auto value = pCharacteristic->getValue();

        if (value.length() > 0)
        {
            auto direction = stringToDirection(value);

            switch (direction)
            {
            case Direction::FORWARD:
                car->Forward();
                break;
            case Direction::BACKWARD:
                car->Backward();
                break;
            case Direction::UP_LEFT:
                car->FrwLeft();
                break;
            case Direction::UP_RIGHT:
                car->FrwRight();
                break;
            case Direction::DOWN_LEFT:
                car->BackLeft();
                break;
            case Direction::DOWN_RIGHT:
                car->BackRight();
                break;
            case Direction::STOP:
                car->Stop();
                break;

            default:
                break;
            }
        }
    }
};

BleController::BleController(Car *car) : car(car)
{
    Serial.println("Starting BLE work!");
    Serial.flush(); // Ожидаем отправки всех данных

    BLEDevice::init("Car");
    pServer = BLEDevice::createServer();
    pService = pServer->createService(SERVICE_UUID);
    pCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE |
            BLECharacteristic::PROPERTY_NOTIFY);

    // Устанавливаем callback для обработки записи
    pCharacteristic->setCallbacks(new MyCharacteristicCallbacks(car));

    pCharacteristic->setValue("Controller");
    pService->start();
    Serial.println("pService->start()!");

    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06); // functions that help with iPhone connections issue
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();
    Serial.println("Characteristic defined! Now you can read and write it from your phone!");
}

BleController::~BleController()
{
    // pService->stop();
    // BLEDevice::deinit();
}
