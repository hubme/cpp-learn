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
    void setAge(int age);
    void getAge() const;
};

MyClass::MyClass() : number(100) {}

MyClass::MyClass(int value) : number(10) { this->value = value; }

void MyClass::hello() const {
    // 无法修改成员变量的值，但是可以访问。
    // number = 10;
    cout << "number = " << number << endl;
}

void MyClass::setAge(int age) { this->age = age; }

void MyClass::getAge() const { cout << "getAge() age = " << age << endl; }

int main(int argc, char const *argv[]) {
    /*
    const int* ptr;  // 指向常量的指针
    int* const ptr;  // 常量指针
    const int* const ptr;  // 指向常量的常量指针
    */

    MyClass clazz(11);
    clazz.hello();
    clazz.age = 10;

    const MyClass constClazz(11);
    // 编译报错，不能调用非const成员函数。对象是常量，无法修改对象状态
    // constClazz.setAge(111);
    constClazz.getAge();

    return 0;
}
