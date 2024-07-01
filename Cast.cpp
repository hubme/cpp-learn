#include <iostream>

using namespace std;

class CastTest {
   public:
    /**
     * 静态转换是将一种数据类型的值强制转换为另一种数据类型的值。
     */
    void staticCast();

    /**
     * 动态转换通常用于将一个基类指针或引用转换为派生类指针或引用。动态转换在运行时进行类型检查，如果不能进行转换则返回空指针或引发异常。
     */
    void dynamicCast();

    /**
     * 常量转换用于将 const 类型的对象转换为非 const
     * 类型的对象。常量转换只能用于转换掉 const 属性，不能改变对象的类型。
     */
    void constCast();

    /**
     * 重新解释转换将一个数据类型的值重新解释为另一个数据类型的值，通常用于在不同的数据类型之间进行转换。重新解释转换不进行任何类型检查，因此可能会导致未定义的行为。
     */
    void reinterpretCast();
};

class Children {
   public:
    virtual ~Children() { cout << "virtual ~Children()" << endl; }
};

class Parent : public Children {};

/**
 * C++ 中有四种类型转换：静态转换、动态转换、常量转换和重新解释转换。
 */
int main(int argc, char const* argv[]) {
    CastTest cast;
    cout << "=====staticCast=====" << endl;
    cast.staticCast();

    cout << endl << "=====dynamicCast=====" << endl;
    cast.dynamicCast();

    cout << endl << "=====constCast=====" << endl;
    cast.constCast();

    cout << endl << "=====reinterpretCast=====" << endl;
    cast.reinterpretCast();
    return 0;
}

void CastTest::staticCast() {
    int num1 = 11;
    float num2 = 3.99f;
    int num3 = static_cast<int>(num2);

    cout << "num1 = " << num1 << ",num2 = " << num2 << ",num3 = " << num3
         << endl;
}

void CastTest::dynamicCast() {
    Children* ptr_base = new Parent;
    // 将基类指针转换为派生类指针
    Parent* ptr_derived = dynamic_cast<Parent*>(ptr_base);
}

void CastTest::constCast() {
    const int num = 10;
    // 常量转换，将const int转换为int
    int& num2 = const_cast<int&>(num);

    cout << "const num: " << num << " num2: " << num2 << endl;
}

void CastTest::reinterpretCast() {
    int num = 10;
    // 重新解释将int类型转换为float类型
    float num2 = reinterpret_cast<float&>(num);

    cout << "num: " << num << " num2: " << num2 << endl;
}
