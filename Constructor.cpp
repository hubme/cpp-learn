#include <iostream>
using namespace std;

class Person
{
private:
    // 空字符串
    string name;
    // 一个不确定的值，可能是任何整数
    int age;

public:
    Person();
    Person(string name, int age);
    ~Person();

    void print();
};

Person::Person()
{
    cout << "构造函数-空参数" << endl;
    name = "";
    age = 0;
}

// 初始化列表，不能和 “Person::Person()” 同时定义。
/* Person::Person() : name(""), age(0)
{
    cout << "构造函数-初始化列表" << endl;
    // name = "hahaha";
    // age = 0;
} */

Person::Person(string name, int age)
{
    cout << "构造函数-带参数" << endl;
    this->name = name;
    this->age = age;
}

Person::~Person()
{
    cout << "析构函数" << endl;
}

void Person::print()
{
    cout << "name = " << name << ", age = " << age << endl;
}

int main(int argc, char const *argv[])
{
    Person p1;
    p1.print();

    Person p2 = Person("Hahaha", 18);
    p2.print();

    Person *p2_1 = &p2;
    p2_1->print();

    // 通过 new 关键字创建的对象，需要使用指针接收
    Person *p3 = new Person("hehehe", 20);
    // 通过指针访问
    p3->print();
    delete p3;

    return 0;
}
