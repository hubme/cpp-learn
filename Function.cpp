#include <functional>
#include <iostream>

using namespace std;

typedef function<int(int)> Functional;

// using Functional = function<int(int)>;

int TestFunc(int a) { return a; }

void test1() {
    Functional obj = TestFunc;
    int res = obj(11);
    cout << res << endl;
}

void test2() {
    Functional obj = bind(TestFunc, 10);
    int res = obj(10);
    cout << res << endl;
}

int main() {
    test2();
    return 0;
}