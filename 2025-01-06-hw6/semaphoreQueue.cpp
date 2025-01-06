
#include <iostream>
#include <queue>
#include <ctime>
#include <thread>
#include <semaphore>
#include <chrono>

using namespace std;

binary_semaphore
smphSignalMainToPush{ 0 },
smphSignalPushToPop{ 0 },
smphSignalPopToMain{ 0 };

class Car {
    static int object_count;
public:
    string car_brand;

    Car(string car_brand) {
        this->car_brand = car_brand;
        this->object_count += 1;
        cout << "Object: " << object_count << " " << car_brand << endl;
    }

    string GetCarBrand() {
        return car_brand;
    }

    int GetObjNumber() {
        return object_count;
    }
};

string CarNameRND() {
    srand(time(0));
    string car_brands[] = { "Mazda", "Toyota", "GMC", "Citroen", "Volkswagen", "Honda", "Mercedes", "Nissan", "Renault", "BMW" };
    int x = rand() % 10;

    return car_brands[x];

}

void PushQueue(queue<Car>& CarQueue) {

    smphSignalMainToPush.acquire();

    int i = 1;
    while (i <= 10) {
           
        CarQueue.push(Car(CarNameRND()));
        //cout << "Pushed" << endl;
        ++i;
        
        this_thread::sleep_for(chrono::seconds(1)); // wait for 1 second
    }
    cout << '\n';

    smphSignalMainToPush.release();
    
    smphSignalPushToPop.release();
    cout << "Signal from Push to Pop\n" << endl;
}

void PopQueue(queue<Car>& CarQueue) {

    smphSignalPushToPop.acquire();

    while (!CarQueue.empty()) {

        cout << "Pop: " << CarQueue.front().car_brand << endl;
        CarQueue.pop();

        this_thread::sleep_for(chrono::seconds(1)); // wait for 1 second

    }
    cout << '\n';

    smphSignalPushToPop.release();
    
    smphSignalPopToMain.release();
    cout << "Signal from Pop to Main" << endl;
}

int Car::object_count = 0;

int main()
{
    queue<Car> CarQueue;
    
    thread push_thread(PushQueue, ref(CarQueue));
    thread pop_thread(PopQueue, ref(CarQueue));

    smphSignalMainToPush.release();
    cout << "Signal from Main to Push\n" << endl;

    smphSignalPopToMain.acquire();

    if (push_thread.joinable()) {
        push_thread.join();
        cout << "Push thread has been joined." << endl;
    }
    
    if (pop_thread.joinable()) {
        pop_thread.join();
        cout << "Pop thread has been joined." << endl;
    }
    
    return 0;

}


