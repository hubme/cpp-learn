#include <iostream>

using namespace std;

extern const int number;
extern int number2;

int main() {
    cout << "number: " << number << " number2: " << number2 << endl;
    return 0;
}