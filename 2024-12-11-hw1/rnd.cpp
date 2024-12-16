#include <iostream>
#include <ctime>

int rnd_gen(int lower_bound, int upper_bound) {
    return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}


int main() {
    
    srand(time(0));

    const int array_size = 1000;
  
    int array[array_size];
    int even = 0, not_even = 0;
    int lower_bound = 20;
    int upper_bound = 100;

    for (int i = 0; i < array_size; ++i) {
        array[i] = rnd_gen(lower_bound, upper_bound);
    }

    for (int i = 0, j=1; i < array_size; ++i, ++j) {
        printf("%3d%c", array[i], (j % 25 == 0 ? '\n' : ' '));

    }

    for (int i : array) {
        if (i % 2 == 0) {
            ++even;
        } 
        else {
            ++not_even;
        }
    }

    std::cout << "Even: " << even << std::endl;
    std::cout << "Not Even: " << not_even << std::endl;

    int max_value, min_value;

    max_value = min_value = array[0];

    for (int i = 1; i < array_size; ++i) {
        if (max_value < array[i]) {
            max_value = array[i];
        }
        else if (min_value > array[i]) {
            min_value = array[i];;
        }
    }

    std::cout << "Max value: " << max_value << std::endl;
    std::cout << "Min value: " << min_value << std::endl;


}