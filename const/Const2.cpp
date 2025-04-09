#include <iostream>

using namespace std;

/*

常量指针:
定义: 指针指向的值是常量，不能通过该指针修改值，但指针本身可以指向其他地址。
语法: const T* ptr 或 T const* ptr
特点:
1. 指针指向的值是只读的，不能通过指针修改。
2. 指针本身可以重新赋值，指向其他变量。

*/

int main(int argc, char const* argv[]) {
    const int* number;
    // 输出指针的地址：0x7fff0937a258
    cout << "number: " << number << endl;

    // 定义变量 value
    int value = 6;
    int value2 = 7;
    // 取变量 value 的地址并赋值给指针 number
    number = &value;
    cout << "number: " << *number << endl;
    // *number = 7;  // error, 不能赋值

    // 取变量 value2 的地址并赋值给指针 number
    number = &value2;
    cout << "number: " << *number << endl;

    int* number2 = &value;
    // 通过指针修改所指向的值
    *number2 = 10;
    cout << "number2: " << *number2 << endl;

    return 0;
}
