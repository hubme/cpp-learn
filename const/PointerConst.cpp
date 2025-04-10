#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    int value = 10;
    const int constValue = 20;
    int* const ptr = &value;  // 指针常量，指向 value 的地址

    // 假如可以赋值，那么就可以通过 ptr 来修改内容，和 const 约束冲突了。
    // int* const ptr = &constValue;  // error, constValue 是常量，不能修改指向的地址
    // 解决方法：同时为指针添加 const 关键字，不能通过指针修改内容。
    // const int* const ptr = &constValue;

    // 指向常量的常量指针，即不能修改指针指向的内容，也不能修改指针地址
    const int* const ptr2 = &value;
    // *ptr2 = 20; // error
    // ptr2 = nullptr;  // error

    cout << "*ptr = " << *ptr << endl;

    // ptr = nullptr;  // error, ptr 已声明为常量，不能修改指向的地址
    *ptr = 20;  // 可以修改指针指向的值

    cout << "*ptr = " << *ptr << endl;

    return 0;
}
