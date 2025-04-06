#include <iostream>

using namespace std;

class ClassGod {
   public:
    ClassGod();
    ~ClassGod();

    virtual void toString() = 0;
};

ClassGod::ClassGod() { cout << "ClassGod::ClassGod" << endl; }

ClassGod::~ClassGod() { cout << "ClassGod::~ClassGod" << endl; }

class ClassA : public ClassGod {
   public:
    ClassA();
    ~ClassA();
    // 虚函数
    virtual void toString();
    // 纯虚函数。如果子类 A 没有全部实现父类的纯虚函数，那么子类 A 也是抽象类。
    // virtual void print() = 0
    // virtual void print2() = 0;
};

ClassA::ClassA() { cout << "ClassA::ClassA()" << endl; }

ClassA::~ClassA() { cout << "ClassA::~ClassA()" << endl; }

void ClassA::toString() { cout << "ClassA#toString()" << endl; }

class ClassB : public ClassA {
   public:
    virtual void toString();
};

void ClassB::toString() { cout << "ClassB#toString()" << endl; }

int main(int argc, char const* argv[]) {
    // 抽象类不能实例化
    // ClassGod classGod;

    ClassA* classA;

    /*
    ClassB classB;
    classB.toString();

    classA = &classB;
    classA->toString();

    cout << endl;
    */

    classA = new ClassA();
    classA->toString();
    delete classA;
    classA == nullptr;

    return 0;
}
