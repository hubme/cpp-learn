#include <iostream>

using namespace std;

void test1() {
    const int number = 10;  // 常量
    const int* number2;     // 指向常量的指针
    /*
    原因是 const int* number2 声明了一个指向 const int的指针。
    这意味着通过该指针不能修改它所指向的值，即指针指向的内容是只读的。
    *number2 = 10; 试图通过指针修改所指向的值，这违反了 const 的约束，因此会导致编译错误。
    */
    // *number2 = 10;  // error, 不能赋值
}

int main(int argc, char const* argv[]) { return 0; }
