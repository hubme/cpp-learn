#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    const int* number;
    // 输出指针的地址：0x7fff0937a258
    cout << "number: " << number << endl;

    // 定义变量 value
    int value = 6;
    // 取变量 value 的地址并赋值给指针 number
    number = &value;
    cout << "number: " << *number << endl;

    int* number2 = &value;
    // 通过指针修改所指向的值
    *number2 = 10;
    cout << "number2: " << *number2 << endl;

    return 0;
}
