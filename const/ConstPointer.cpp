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
void test1() {
    int value = 6;
    int value2 = 7;
    const int number = 10;  // 常量
    const int* numberPtr;   // 指向常量的指针

    // 取变量 number 的地址并赋值给指针 numberPtr
    numberPtr = &number;
    // 因为 numberPtr 不是 const，所以可以重新赋值。
    numberPtr = &value;

    /*
    原因是 const int* numberPtr 声明了一个指向 const int 的指针。
    这意味着通过该指针不能修改它所指向的值，即指针指向的内容是只读的。
    */
    // *numberPtr = 10;  // error, 试图通过指针修改所指向的值，这违反了 const 的约束

    // 输出 numberPtr: 0x61fddc *numberPtr: 10
    cout << "numberPtr: " << numberPtr << " *numberPtr: " << *numberPtr << endl;

}

int main(int argc, char const* argv[]) {
    test1();
    return 0;
}
