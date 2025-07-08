#include <iostream>

using namespace std;

class ClassA {
   public:
    ClassA() { cout << "ClassA constructor called" << endl; }
    ~ClassA() /* noexcept */ {
        cout << "ClassA destructor called" << endl;
        throw runtime_error("ClassA destructor exception");
    }
};

class ClassB {
   public:
    ClassB() { cout << "ClassB constructor called" << endl; }
    ~ClassB() { cout << "ClassB destructor called" << endl; }
};

void exection_handler() {
    std::cerr << "Unhandled Exception!\n";
    std::abort();  // terminate program
}

int main() {
    // 异常处理器
    set_terminate(exection_handler);

    ClassB b;
    // a 对象的析构函数会抛出异常，程序终止，导致 b 对象的析构函数不会执行，出现内存泄漏。
    ClassA a;
    /* try {
        ClassA a;
    } catch (const std::runtime_error& e) {
        std::cerr << "出错了：" << e.what() << '\n';
    } */

    return 0;
}