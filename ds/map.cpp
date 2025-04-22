#include <iostream>
#include <map>

using namespace std;

void test1() {
    map<string, int> numberMap = {{"one", 1}, {"two", 2}, {"three", 3}};
    numberMap["four"] = 4;
    numberMap["five"] = 5;

    // 遍历 map
    for (auto const &pair : numberMap) {
        /* if (pair.first == "two") {
            pair.second = 22;  // 错误：pair.second 是 const 引用，不能修改
        } */
        cout << pair.first << ": " << pair.second << "  ";
    }
    cout << endl;

    // 通过迭代器遍历 map

    map<string, int>::iterator it = numberMap.begin();
    while (it != numberMap.end()) {
        cout << it->first << ": " << it->second << "  ";
        it++;
    }
    cout << endl;

    for (auto it = numberMap.begin(); it != numberMap.end(); ++it) {
        cout << it->first << ": " << it->second << "  ";
    }
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
