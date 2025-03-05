#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    char* userProfile = getenv("USERPROFILE");
    if (userProfile) {
        cout << "USERPROFILE: " << userProfile << endl;
    } else {
        char* home = getenv("HOME");
        if (home) {
            cout << "HOME: " << home << endl;
        } else {
            cout << "Переменная окружения не найдена." << endl;
        }
    }
    return 0;
}
