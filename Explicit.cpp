#include <iostream>

using namespace std;

/*
explicit 是 C++中的一个关键修饰符，主要用于禁止编译器执行隐式类型转换，
强制要求代码中必须显式进行构造函数调用或类型转换操作。
它是避免意外类型转换导致错误的重要工具。
*/

class String {
   public:
    // 情景一：非 explicit 构造函数（允许隐式转换）
    String(int size) { cout << "Constructing String with size: " << size << endl; }

    // 情景二：explicit 构造函数（禁止隐式转换）
    explicit String(const char* str) { cout << "Constructing String with value: " << str << endl; }
};

void printString(const String& s) { /* 打印字符串内容 */ }

int main() {
    // 使用非 explicit 构造函数（允许隐式转换）
    printString(10);  // 合法：隐式调用 String(int)

    // 使用 explicit 构造函数
    // printString("hello");  // 错误：禁止隐式转换
    printString(String("hello"));  // 合法：显式构造

    return 0;
}