#include <iostream>

using namespace std;

void incement(int* number) {
    (*number)++;  // 或 ++*number
}

void incement2(int& number) { number++; }

int main() {
    int number = 5;
    int* ptr = &number;
    // number 的引用。相当于创建了一个 number 变量的别名
    int& numberRef = number;
    cout << "number: " << number << " ptr: " << ptr << " numberRef: " << numberRef << endl;

    numberRef = 8;
    cout << "number: " << numberRef << endl;

    incement(ptr);
    cout << "8+1: " << number << endl;

    incement2(number);
    cout << "9+1: " << number << endl;

    cout << endl;

    int a = 10;
    int b = 20;

    int* ref = &a;
    cout << "ref=" << *ref;
    *ref = 11;
    cout << " ref=" << *ref;
    ref = &b;
    cout << " ref=" << *ref;
    *ref = 21;
    cout << " ref=" << *ref << endl;

    return 0;
}