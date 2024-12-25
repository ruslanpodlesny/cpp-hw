
#include <iostream>
#include <vector>

using namespace std;

class Car {

public:
    string car_manufacturer;
    string car_brand;
    int engine_power;
    int car_max_speed;

    Car(string car_manufacturer = "None", string car_brand = "None", int engine_power = 0, int car_max_speed = 0) {
        this->car_manufacturer = car_manufacturer;
        this->engine_power = engine_power;
        this->car_brand = car_brand;
        this->car_max_speed = car_max_speed;
        cout << "Constructor called" << endl;
    }

    void PrintCar() const {
        cout << car_manufacturer << " " << car_brand << " " << engine_power << " " << car_max_speed << endl;
    }

};

void add_to_vector(const Car& car, vector<Car>& car_vector) {
    car_vector.push_back(car);
}

int main()
{
    const int array_size = 3;

    vector<Car> car_vector;
    
    Car car1("Honda", "Civic", 170, 270);
    Car car2("Toyota", "RAV4", 155, 230);
    Car car3("Nissan", "Qashqai", 140, 250);

    add_to_vector(car1, car_vector);
    add_to_vector(car2, car_vector);
    add_to_vector(car3, car_vector);
        
    Car array[array_size];
    vector<Car>::iterator vect_iter = car_vector.begin();
    
    int i = 0;
    while (vect_iter != car_vector.end() && i < array_size) {
        array[i] = *vect_iter;

        ++i;
        ++vect_iter;
    }

    for (const Car& car : car_vector) {
        cout << "vector: ";
        car.PrintCar();
    }
  
    for (int i = 0; i < array_size; ++i) {
        cout << "array: ";
        array[i].PrintCar();
    }
 
}


