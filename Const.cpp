#include <iostream>

using namespace std;

class MyClass {
   private:
    int value;
    const int number;

   public:
    int age;
    MyClass();
    MyClass(int age);
    // 不会修改对象状态的成员函数
    void hello() const;
    void hello();
    void hello2() { cout << "hello2" << endl; }
    void setAge(int age);
    void getAge() const;
};

MyClass::MyClass() : number(100) {}

MyClass::MyClass(int value) : number(10) { this->value = value; }

void MyClass::hello() { cout << "hello" << endl; }

void MyClass::hello() const {
    // 无法修改成员变量的值，但是可以访问。
    // number = 10;
    cout << "number = " << number << endl;
}

void MyClass::setAge(int age) { this->age = age; }

void MyClass::getAge() const { cout << "getAge() age = " << age << endl; }

int main(int argc, char const* argv[]) {
    /*
    const int* ptr;  // 指向常量的指针
    int* const ptr;  // 常量指针
    const int* const ptr;  // 指向常量的常量指针
    */

    MyClass clazz(11);
    // 调用非 const 成员函数
    clazz.hello();
    clazz.hello2();
    clazz.age = 10;

    // 通过指向 const 对象的指针调用 const 成员函数
    const MyClass* MyClassPtr = &clazz;
    MyClassPtr->hello();

    const MyClass constClazz(11);
    // 编译报错，不能调用非const成员函数。对象是常量，无法修改对象状态
    // constClazz.setAge(111);
    constClazz.getAge();
    // 调用 const 成员函数
    constClazz.hello();
    // const 对象只能调用 const 成员函数
    // constClazz.hello2();// error

    /*
    如果const位于*的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；
    如果const位于*的右侧，const就是修饰指针本身，即指针本身是常量。
    */
    const char* a;        // 指向const对象的指针或者说指向常量的指针。
    char const* b;        // 同上
    char* const c = "c";  // 指向类型对象的const指针。或者说常指针、const指针。
    const char* const d = "d";  // 指向const对象的const指针。

    const int* ptr;  // 同 int const* ptr;
    int val = 3;
    ptr = &val;  // ok
    // *ptr = 4; //error
    cout << "ptr = " << ptr << ", *ptr = " << *ptr << "\n";

    int number1 = 123, number2 = 456;
    // 常指针必须初始化
    int* const constPtr = &number1;
    // constPtr = &number2;  // error, const 指针不能修改指向
    *constPtr = 111;  // 指针是 const，内容不是 const，可以修改
    cout << "constPtr = " << constPtr << ", *constPtr = " << *constPtr << "\n";

    const int number3 = 222;
    // int* const constPtr2 = &number3;  // error

    return 0;
}
