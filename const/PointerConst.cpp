#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    int value = 10;
    int* const ptr = &value;  // 指针常量，指向 value 的地址

    // 指向常量的常量指针，即不能修改指针指向的内容，也不能修改指针指向的地址
    const int* const ptr2 = &value;
    // *ptr2 = 20; // error
    // ptr2 = nullptr;  // error

    cout << "*ptr = " << *ptr << endl;

    // ptr = nullptr;  // error, ptr 已声明为常量，不能修改指向的地址
    *ptr = 20;  // 可以修改指针指向的值

    cout << "*ptr = " << *ptr << endl;

    return 0;
}
