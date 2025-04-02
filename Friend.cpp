#include <iostream>

using namespace std;

/**
 * https://learn.microsoft.com/zh-cn/cpp/cpp/friend-cpp?view=msvc-170
 *
 * 1. 友元机制旨在打破封装性。
 * 2. 友元函数虽然被声明在类的内部，但本质上并不是类的成员函数。
 * 3. 友元函数是 C++
 * 中一种特权机制，通过类内声明赋予外部函数访问私有成员的权限，但其本质仍是独立于类的全局函数。
 * 4. 这种设计在需要跨类协作或操作符重载时非常有用，但也需注意其对封装性的破坏，应避免滥用。
 */

class FriendClass {
   private:
    string name;

   public:
    FriendClass(string name) : name(name) {}
    void method1();
    friend void method2(FriendClass f);

    friend class OtherClass;
};

void FriendClass::method1() { cout << "name = " << name << endl; }
// 友元函数不被视为类成员
void method2(FriendClass f) { cout << "name = " << f.name << endl; }

class OtherClass {
   public:
    void myFriendClass(FriendClass f);
};

void OtherClass::myFriendClass(FriendClass f) {
    // 如果不声明友元，无法访问 FriendClass 中的私有成员变量 name
    cout << "FriendClass name: " << f.name;
}

int main(int argc, char const *argv[]) {
    FriendClass f("Vance");

    f.method1();
    method2(f);

    return 0;
}
