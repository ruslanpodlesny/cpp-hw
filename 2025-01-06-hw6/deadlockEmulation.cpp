
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

void Sum(int& num1, int& num2, int& num3, mutex& m_sum, mutex& m_sub) {
    
    m_sum.lock();
    
    cout << num1 + num2 << endl;
    this_thread::sleep_for(chrono::seconds(5));
    
    m_sub.lock();   // Deadlock
    while (true) {

    }
    m_sub.unlock();


    m_sum.unlock();

    cout << "Thread \"Sum\" has been closed" << endl;
}

void Sub(int& num1, int& num2, int& num3, mutex& m_sum, mutex& m_sub) {
    
    m_sub.lock();
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << num3 - num2 << endl;    

    m_sum.lock();   // Deadlock
    while (true) {

    }
    m_sum.unlock();

    m_sub.unlock();
}

int main()
{
    
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;

    mutex m_sum;
    mutex m_sub;

    thread sum(Sum, ref(num1), ref(num2), ref(num3), ref(m_sum), ref(m_sub));
    thread sub(Sub, ref(num1), ref(num2), ref(num3), ref(m_sub), ref(m_sum));

    if (sum.joinable()) {
        sum.join();
    }
    
    if (sub.joinable()) {
        sub.join();
    }


    return 0;
}


