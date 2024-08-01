#include <iostream>

using namespace std;

/*
1. 使用 class 时，类中的成员默认都是 private 属性的；而使用 struct 时，结构体中的成员默认都是 public
属性的。
2. class 继承默认是 private 继承，而 struct 继承默认是 public 继承
3. class 可以使用模板，而 struct 不能
*/
struct Human {
    string name;
    int age;

    Human() {
        name = "";
        age = 0;
    }

    Human(string name, int age) : name(name), age(age) {}
};

void printHuman(Human book) { cout << "姓名: " << book.name << " 年龄: " << book.age << endl; }

int main(int argc, char const *argv[]) {
    Human h0;
    printHuman(h0);

    Human h1 = {"Vance", 18};
    printHuman(h1);

    Human h2;
    h2.name = "Vance2";
    h2.age = 20;
    printHuman(h2);

    Human h3("Vance3", 22);
    printHuman(h3);

    return 0;
}
