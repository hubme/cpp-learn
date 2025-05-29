#include <iostream>
#include <vector>

using namespace std;

/**
 * 1. initializer_list 提供了一种方便的方式来初始化容器或对象。
 * 2. initializer_list 对象中的元素永远是常量值，无法修改。
 * 3. 拷贝或赋值一个 initializer_list 对象不会拷贝列表中的元素，原始列表和副本共享元素。
 */

int main(int argc, char const* argv[]) {
    initializer_list<int> il = {1, 2, 3, 4, 5};
    for (int i = 0; i < il.size(); i++) {
        cout << il.begin()[i] << " ";
    }
    cout << endl;

    // vector<int> vec = {1, 2, 3, 4};
    vector<int> vec{2, 3, 5};
    for (const auto v : vec) {
        cout << v << " ";
    }
    cout << endl;

    int valueArray[]{6, 7, 9};
    for (const auto v : valueArray) {
        cout << v << " ";
    }

    return 0;
}
