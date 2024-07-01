#include <iostream>

using namespace std;

class MyClass {
   private:
    int aa;

   public:
    MyClass();
    const int number;
    // 不会修改对象状态的成员函数
    void hello() const;
};

MyClass::MyClass() : number(100) {}

void MyClass::hello() const {
    // 无法修改成员变量的值，但是可以访问。
    // number = 10;
    cout << "number = " << number << endl;
}

int main(int argc, char const *argv[]) {
    /*
    const int* ptr;  // 指向常量的指针
    int* const ptr;  // 常量指针
    const int* const ptr;  // 指向常量的常量指针
    */

    MyClass clazz;
    clazz.hello();

    return 0;
}
