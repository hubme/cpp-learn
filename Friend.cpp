#include <iostream>

using namespace std;

/**
 * https://learn.microsoft.com/zh-cn/cpp/cpp/friend-cpp?view=msvc-170
 */

class FriendClass {
   private:
    string name;

   public:
    FriendClass(string name) : name(name) {}
    void method1();
    friend void method2(FriendClass f);
};

void FriendClass::method1() { cout << "name = " << name << endl; }
// 友元函数不被视为类成员
void method2(FriendClass f) { cout << "name = " << f.name << endl; }

int main(int argc, char const *argv[]) {
    FriendClass f("Vance");

    f.method1();
    method2(f);

    return 0;
}
