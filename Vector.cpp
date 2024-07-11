#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<string> list;
    // 添加元素
    list.push_back("Hello");
    list.push_back(", ");
    list.push_back("World");
    list.push_back("!");

    cout << "list.size()= " << list.size() << " list.capacity()= " << list.capacity()
         << " list.max_size()= " << list.max_size() << " list.empty()= " << list.empty() << "\n";

    // 读取元素
    for (int i = 0; i < list.size(); i++) {
        // cout << list[i];
        cout << list.at(i);
    }
    // 删除指定索引元素
    // list.erase(list.begin() + 1);
    // 删除指定区间元素
    list.erase(list.begin() + 1, list.end() - 1);
    cout << "\n";
    for (string item : list) {
        cout << item;
    }

    cout << "\n";
    // 清空
    list.clear();
    cout << list.size();
    return 0;
}
