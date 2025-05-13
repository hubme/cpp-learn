#include <iostream>

using namespace std;
/**
 * https://learn.microsoft.com/zh-cn/cpp/cpp/macro-cpp?view=msvc-170
 *
 * 1. 宏定义是 C/C++ 中的一种预处理指令，用于在编译时进行文本替换。
 * 2. 宏定义的语法为 #define 宏名 替换文本。
 * 3. 宏定义可以用于常量、函数、条件编译等场景。
 * 4. 宏定义没有类型检查，可能导致难以调试的错误。
 * 5. 使用 const 或 inline 函数替代宏定义可以提高代码的可读性和安全性。
 */
#define PI 3.14159
#define SQUARE(x) (x * x)
#define MAX(a, b) (a > b ? a : b)
#define PRINT(x) cout << #x << " = " << x << endl
#define CONCAT(a, b) #a " " #b

#define f1() cout << "f1()" << endl;
#define f2() cout << "f2()" << endl;

#define fun() \
    {         \
        f1(); \
        f2(); \
    }

int main(int argc, char const *argv[]) {
    // 使用宏定义
    cout << "PI = " << PI << endl;
    cout << "SQUARE(5) = " << SQUARE(5) << endl;
    cout << "MAX(3, 4) = " << MAX(3, 4) << endl;
    PRINT("Hello, World!");

    cout << "CONCAT(Hello, World!) = " << CONCAT(Hello, World) << endl;

    fun();

    return 0;
}
