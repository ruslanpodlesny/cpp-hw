#include <iostream>
#include <ctime>

int Rnd_Gen(int lower_bound, int upper_bound) {
    return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}

void Swap(int* x, int* y) {
    // сделать через указатели
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void qsort(int array[], int left, int right) {
    if (left > right) {
        return;
    }

    int pivot = array[(right + left) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (array[i] < pivot) {
            ++i;
        }

        while (array[j] > pivot) {
            --j;
        }
        if (i <= j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            ++i;
            --j;
            //Swap(&array[i], &array[j]);

        }
    }
    //std::cout << "recurse" << std::endl;
    qsort(array, left, j);
    qsort(array, i, right);

}

int main() {

    srand(time(0));

    const int array_size = 20;

    int array[array_size];
    int even = 0, not_even = 0;
    int lower_bound = 0;
    int upper_bound = 100;

    for (int i = 0; i < array_size; ++i) {
        array[i] = Rnd_Gen(lower_bound, upper_bound);
    }

    for (int i = 0, j = 1; i < array_size; ++i, ++j) {
        printf("%3d%c", array[i], (j % 20 == 0 ? '\n' : ' '));

    }

    int left = 0;
    int right = array_size - 1;

    qsort(array, left, right);

    for (int i = 0, j = 1; i < array_size; ++i, ++j) {
        printf("%3d%c", array[i], (j % 20 == 0 ? '\n' : ' '));

    }
    return 0;
}