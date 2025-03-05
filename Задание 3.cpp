#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int main() {
    ofstream outFile("numbers.txt");
    if (!outFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    srand(time(nullptr));
    for (int i = 0; i < 10; ++i) {
        outFile << rand() % 100 << endl;
    }
    outFile.close();

    ifstream inFile("numbers.txt");
    if (!inFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int numbers[10];
    for (int i = 0; i < 10; ++i) {
        inFile >> numbers[i];
    }
    inFile.close();

    auto start = high_resolution_clock::now();
    sort(numbers, numbers + 10);
    auto end = high_resolution_clock::now();

    cout << "Отсортированные числа: ";
    for (int i = 0; i < 10; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Время выполнения сортировки: " << duration.count() << " мс" << endl;

    return 0;
}
