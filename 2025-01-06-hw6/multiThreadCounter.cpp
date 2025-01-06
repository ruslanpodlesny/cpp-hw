
#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

using namespace std;

std::atomic<unsigned int> counter = 0;

void countFunct() {
    for (int i = 0; i < 25000000; ++i) {
        ++counter;
    }
}

int main()
{
    vector<thread> threads;

    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(countFunct); 
        cout << "Thread created\n";
    }
    
    for (auto& thr : threads) {
        if (thr.joinable()) {
            thr.join();
            cout << "Thread joined\n";
        }
    }

    cout << counter << endl;

    return 0;
}