#include <iostream>

using namespace std;

class Person
{

public:
    void toString();
};

void Person::toString()
{
    cout << "我是 Person 类" << endl;
}

// 使用 typedef 为一个已有的类型取一个别名
typedef Person Human;

int main(int argc, char const *argv[])
{
    Person Person;
    Person.toString();

    Human human;
    human.toString();

    return 0;
}
