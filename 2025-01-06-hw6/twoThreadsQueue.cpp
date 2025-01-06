
#include <iostream>
#include <queue>
#include <ctime>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
bool push_thread_done = false;
bool pop_thread_done = false;

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

string CarNameRND (){
    string car_brands[] = {"Mazda", "Toyota", "GMC", "Citroen", "Volkswagen", "Honda", "Mercedes", "Nissan", "Renault", "BMW"};
    int x = rand() % 10;
    
    return car_brands[x];
   
}

void PushQueue(queue<Car>& CarQueue, mutex& m_push) {
    
    bool fill_queue = false;
    int i = 1;
    while (i<=10) {
        
        m_push.lock();

        if (CarQueue.empty()) {
            fill_queue = true;
        }

        if ((CarQueue.size() < 5) && (fill_queue == true)) {
            CarQueue.push(Car(CarNameRND()));
            cout << "Pushed" << endl; 
            
            ++i;            
        }
        
        if (CarQueue.size() >= 5) {
            fill_queue = false;
        }

        m_push.unlock();

        this_thread::sleep_for(chrono::seconds(1)); // wait 5 seconds

    }

    push_thread_done = true;

}

void PopQueue(queue<Car>& CarQueue, mutex& m_pop) {
      

    while (true) {

        m_pop.lock();
        
        if (!CarQueue.empty()) {
            cout << "<< " << CarQueue.front().car_brand << " - Popped >>" << endl;
            CarQueue.pop();                        
        }

        m_pop.unlock();

        if (push_thread_done && CarQueue.empty()) {
            break;
        }

        this_thread::sleep_for(chrono::seconds(3)); // wait 10 seconds

    }
    pop_thread_done = true;
}

int Car::object_count = 0;

int main()
{
    srand(time(0));
    mutex m_push, m_pop;
    queue<Car> CarQueue;
    
    thread push_thread(PushQueue, ref(CarQueue), ref(m_push)); 
    thread pop_thread(PopQueue, ref(CarQueue), ref(m_pop));

    while (!push_thread_done) {
        push_thread.join();
        break;
    }

    cout << "Push thread joined\n";

    while (!pop_thread_done) {
        pop_thread.join();
        break;
    }

    cout << "Pop thread joined\n";

}


