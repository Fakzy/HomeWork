#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    const int size = 1000;
    int arr[size];
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000;
    }

    auto start = high_resolution_clock::now();
    bubbleSort(arr, size);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Время выполнения сортировки: " << duration.count() << endl;

    return 0;
}
