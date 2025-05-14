#include <iostream>

using namespace std;

void incement(int* number) {
    (*number)++;  // 或 ++*number
}

void incement2(int& number) { number++; }

class Test {
   public:
    void test1();
    void test2();
};

void Test::test1() {
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
}

void Test::test2() {
    int a = 1;
    int b = 2;

    int* p = &a;  // 初始化指针p指向变量a
    int& r = a;   // 初始化引用r指向变量a
    cout << "a = " << a << ", b = " << b << ", *p = " << *p << ", r = " << r << endl;

    p = &b;  // 指针p指向了变量b
    r = b;   // 引用r依然指向a，但a的值变成了b，即将 b 的值赋值给了 a

    cout << "a = " << a << ", b = " << b << ", *p = " << *p << ", r = " << r << endl;
}

int main() {
    Test test;
    // test.test1();
    test.test2();

    return 0;
}