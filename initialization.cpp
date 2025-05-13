#include <iostream>

using namespace std;

// 未初始化的变量会被默认初始化为 0
int a;
// 列表初始化，推荐
int b{9};
// 直接初始化
int c = 10;

char d;
float e;
double f;
int* g;

void test1() {
    // 局部变量默认初始化
    int a;
    // 列表初始化，推荐
    int b{9};
    // 直接初始化
    int c = 10;

    char d;
    float e;
    double f;
    int* g;

    cout << "int a=" << a << "\nint b=" << b << "\nint c=" << c << "\nchar d=" << d
         << "\nfloat e=" << e << "\ndouble f=" << f << "\npointer g=" << g << endl;
}

int main(int argc, char const* argv[]) {
    cout << "int a=" << a << "\nint b=" << b << "\nint c=" << c << "\nchar d=" << d
         << "\nfloat e=" << e << "\ndouble f=" << f << "\npointer g=" << g << endl;

    cout << "局部变量默认初始化：\n";
    test1();

    // 等价于 unsigned int x
    unsigned x;
    unsigned int y;

    // GCC 中 "unsigned int" 类型是 "j"; MSVC 中则是 "unsigned int"
    cout << "unsigned x=" << typeid(x).name() << "\nunsigned int y=" << typeid(y).name() << endl;

    return 0;
}
