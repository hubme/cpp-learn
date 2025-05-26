#include <iostream>

using namespace std;

/**
 * 语法：[capture](parameters)->return-type{body}
 *
 * [capture] ：捕获列表
 * []      // 沒有定义任何变量。使用未定义变量会引发错误。
 * [x, &y] // x以传值方式传入（默认），y以引用方式传入。
 * [&]     // 任何被使用到的外部变量都隐式地以引用方式加以引用。
 * [=]     // 任何被使用到的外部变量都隐式地以传值方式加以引用。
 * [&, x]  // x显式地以传值方式加以引用。其余变量以引用方式加以引用。
 * [=, &z] // z显式地以引用方式加以引用。其余变量以传值方式加以引用。
 *
 */

void test() {
    auto add = [](int a, int b) { return a + b; };
    cout << "add(1, 2)=" << add(1, 2) << "\n";

    int n = 2;
    // 值捕获：n不会被改变
    auto multiply = [n](int x) { return x * n; };
    cout << "multiply=" << multiply(5) << "\n";

    n = 0;
    // 引用捕获：n会被改变
    auto multiply2 = [&n](int x) { return x * n; };
    cout << "multiply2=" << multiply2(5) << "\n";

    auto lambda1 = [](int a, int &b) {
        a = 10;
        b = 20;
        cout << a << "\t" << b << endl;
    };
    int i = 1, j = 2;
    lambda1(i, j);                   // 输出：10  20
    cout << i << "\t" << j << endl;  // 输出：1 20

    // 以 auto 为形参类型时，该 lambda 为泛型 lambda(C++14 起)
    auto lambda2 = [](auto a, int b = 10) { cout << a << "\t" << b << endl; };
    lambda2(1.5, 2);  // 输出：1.5 2
    lambda2(true);    // 输出：1 10。

    // 无法推断是否返回 int 还是 double，因此需显示指定类型
    auto lambda3 = []() -> double {
        if (1 > 2)
            return 1;
        else
            return 2.0;
    };
    cout << lambda3() << endl;

    int a = 10, b = 10;
    // 加上mutable才可以在lambda函数中改变捕获的变量值
    auto lambda4 = [a, &b]() mutable { a = 100, b = 100; };
    lambda4();
    // 输出:10 100
    cout << a << "\t" << b << endl;
}

void test1() {
    int id = 0;
    // 先看前面的id 如果没有mutable error: expression must be a modifiable lvalue
    auto f = [id]() mutable {
        cout << "id=" << id << endl;
        ++id;
    };

    /*
    class Functor {
       private:
           int id;
       public:
           void operator() {
               cout << "id=" << id << endl;
               ++id;
           }
    };
    Functor f;
    */

    id = 42;
    f();                 // 0
    f();                 // 1
    f();                 // 2
    cout << id << endl;  // 42
}

void test2() {
    int id = 0;
    // 加不加mutable没影响,且传引用只要后面id1被修改了,就会使用修改后的值进行操作
    auto f1 = [&id]() {
        cout << "id1=" << id << endl;
        ++id;
    };
    id = 42;
    f1();  // 42
    f1();  // 43
    f1();  // 44
    cout << id << endl;//45
}

int main(int argc, char const *argv[]) {
    test2();
    return 0;
}
