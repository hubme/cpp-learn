#include <iostream>
#include <vector>

using namespace std;

/*
用 auto 声明万物的好处:
1. 代码简洁，减少了类型声明的冗余。
2. 代码可读性更高，尤其在复杂类型的情况下。
3. 自动推导类型，避免了手动声明类型的错误。
4. 适用于 lambda 表达式和范围 for 循环等场景。
5. 适用于 STL 容器和算法，简化了代码。
6. 适用于多态和模板编程，简化了类型声明。
7. 适用于函数返回值类型的推导，简化了函数声明。
*/

void test1() {
    // 未初始化的局部变量不会被赋予默认值，其值是未定义的，不可预测。
    int number1;
    // auto 强制赋值，否则编译出错。
    auto number2 = 10;
    cout << "number1: " << number1 << " number2: " << number2 << endl;

    auto f();  // 错误：看不到函数体，无法推导返回类型
}

void test2() {
    // auto 会推导为 int 类型
    // auto i = 11;
    // 显示类型转换
    // auto i = (size_t)11;
    auto i = size_t(11);
    // 超出 int 范围，编译会警告
    i = 0xffffffffff;

    cout << "i: " << i << endl;
}

auto multiply(int x) {
    if (x > 0) {
        return x * x;  // 表达式 `x * x` 的类型为 int，所以 auto 类型推导为 int
    } else {
        // return -1.0;  // 无法确定 auto 应该推导为 int 还是 double
        return 0;
    }
}

void test3() {
    auto resultInt = multiply(5);       // result 的类型为 int
    auto resultDouble = multiply(5.0);  // result2 的类型为 double
    cout << "multiply(5): " << resultInt << " multiply(5.0):" << resultDouble << endl;
    // 判断类型
    cout << "resultInt type: " << typeid(resultInt).name() << endl;
    cout << "resultDouble type: " << typeid(resultDouble).name() << endl;
    cout << "typeid(double) type: " << typeid(double).name() << endl;
}

void test4() {
    vector<int> arr = {1, 2, 3};
    for (auto const &i : arr) {
        cout << i << " ";
    }

    cout << endl;
    for (auto &i : arr) {  // auto &i 推导为 int &i，保存的是对 arr 中原元素的一份引用，不发生拷贝
        i += 1;  // 因为 i 现在是对 arr 中真正元素的引用，对其修改也会成功反映到原 arr 中去
        cout << i << " ";  // 输出 2 3 4
    }
}

int main(int argc, char const *argv[]) {
    test1();
    test2();
    test3();
    test4();
    return 0;
}
