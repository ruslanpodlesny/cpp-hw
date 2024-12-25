#include <iostream>
#include <string>

class Engine {
public:
    std::string engine_manufacturer;
    unsigned int engine_power;

    Engine(std::string engine_manufacturer, unsigned int engine_power) {
        this->engine_manufacturer = engine_manufacturer;
        this->engine_power = engine_power;
        std::cout << "Engine " << engine_manufacturer << " has been created." << std::endl;
    }
    const void toString() {
        std::cout << "Engine " << engine_manufacturer << " has power : " << engine_power << std::endl;
    }
};

class Driver {
public:
    std::string driver_name;
    std::string driver_gender;
    unsigned int driver_experience;

    Driver(std::string driver_name, std::string driver_gender, unsigned int driver_experience) {
        this->driver_name = driver_name;
        this->driver_experience = driver_experience;
        std::cout << "Driver " << driver_name << " has been created." << std::endl;
    }

    void toString() {
        std::cout << "Driver " << driver_name << " has " << driver_experience << " years of experience." << std::endl;
    }
};

class Car {

public:
    std::string car_brand;
    std::string car_class; 
    unsigned int car_weight;
    unsigned int car_max_speed;
    unsigned int car_current_speed=0;
    bool engine_on = false;
    Engine engine;
    Driver driver;

    Car(Engine& engine,
        Driver& driver,
        std::string car_brand,
        std::string car_class,
        unsigned int car_weight,
        unsigned int car_max_speed) : engine(engine), driver(driver) {

        this->car_brand = car_brand;
        this->car_class = car_class;
        this->car_weight = car_weight;
        this->car_max_speed = car_max_speed;
        
    }

    void StartEngine() {
        if (!engine_on) {
            engine_on = true;
            std::cout << "The engine is running" << std::endl;
        }
        else {
            std::cout << "The engine is already running!" << std::endl;
        }

    }

    void MoveCar(unsigned int car_set_speed) {
        if (engine_on && car_set_speed > car_max_speed) {
            car_set_speed = car_max_speed;
            std::cout << "Set speed is higher than max speed! Set speed is  " << car_max_speed << std::endl;
        }
        
        if (engine_on && car_set_speed <= car_max_speed) {
            
            std::cout << "Car speed is set to " << car_set_speed << std::endl;

            for (int i = car_current_speed; i <= car_set_speed; ++i) {
                if (i % 10 == 0) {
                    std::cout << "Accelerating: " << i << std::endl;
                }
            }

            this->car_current_speed = car_set_speed;
            std::cout << "The car's speed is " << car_current_speed << std::endl;
        }
        else   {
            std::cout << "Start the engine!" << std::endl;
        }
    }

    void StopCar() {
        if (car_current_speed > 0 && engine_on) {
            for (int i = car_current_speed; i > 0; --i) {
                if (i % 10 == 0) {
                    std::cout << "Stopping: " << i << std::endl;
                }
            }
            car_current_speed = 0;
            std::cout << "Stopping: " << car_current_speed << std::endl;
            std::cout << "The car has been stopped." << std::endl;
        }
        else {
            std::cout << "The car is already stopped." << std::endl;
        }
    }
    
    void StopEngine() {
        if (car_current_speed > 0) {
            std::cout << "Stop the car prior stopping the engine!" << std::endl;
        }
        else if (car_current_speed == 0 && engine_on) {
            engine_on = false;
            std::cout << "The engine has been stopped." << std::endl;
            
        }
    }

    void ToString() {
        std::cout << car_brand << " " << car_class << " " << car_weight << " " << car_max_speed << std::endl;
        engine.toString();
        driver.toString();
    }
    
};

class F1_car : Car
{
public:
    unsigned int add_max_speed;

    F1_car(Engine& engine,
        Driver& driver,
        std::string car_brand,
        std::string car_class,
        unsigned int car_weight,
        unsigned int car_max_speed,
        unsigned int add_max_speed) : Car(engine, driver, car_brand, car_class, car_weight, car_max_speed + add_max_speed) {
        
        this->add_max_speed = add_max_speed;
    }

    void ToString() {
        std::cout << car_brand << " " << car_class << " " << car_weight << " " << car_max_speed << std::endl;
        engine.toString();
        driver.toString();
    }
};

class Truck : Car
{
public:
    unsigned int load_capacity;

    Truck(Engine& engine,
        Driver& driver,
        std::string car_brand,
        std::string car_class,
        unsigned int car_weight,
        unsigned int car_max_speed,
        unsigned int load_capacity) : Car(engine, driver, car_brand, car_class, car_weight, car_max_speed) {

        this->load_capacity = load_capacity;
    }

    void ToString() {
        std::cout << car_brand << " " << car_class << " " << car_weight << " " << car_max_speed << " " << load_capacity << std::endl;
        engine.toString();
        driver.toString();
    }
};


int main()
{
    Engine WarthogEngine("TurboWarthog", 220);
    Driver Spartan("John117", "Male", 20);

    Car Warthog(WarthogEngine, Spartan, "Warthog", "Halo", 2500, 220);
    Warthog.ToString();
    Warthog.MoveCar(100);
    Warthog.StartEngine();
    Warthog.StartEngine();
    Warthog.MoveCar(110);
    Warthog.MoveCar(250);
    Warthog.StopEngine();
    Warthog.StopCar();
    Warthog.StopEngine();

    std::cout << std::endl;

    Engine F1_engine("SuperTurbo", 500);
    Driver F1_pilot("T1000", "Unknown", 20);

    F1_car F1(F1_engine, F1_pilot, "McLaren", "UltraSpeed", 1200, 220, 110);
    F1.ToString();

    std::cout << std::endl;

    Engine truck_engine("HeavyPartner", 1500);
    Driver truck_driver("AI_Bot", "OpenAI", 100);

    Truck ai_truck (truck_engine, truck_driver, "Kamaz", "UltraHeavy", 5000, 170, 10000);
    ai_truck.ToString();
}

