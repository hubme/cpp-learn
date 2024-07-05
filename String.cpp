#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    string name("Vance");
    cout << name << "\n";

    string str = "Hello World!";
    cout << str << "\n";

    bool isEmpty = str.empty();
    // 返回当前分配给该字符串的内存空间大小,即可以容纳的最大字符数
    int capacity = str.capacity();
    // 返回字符串中实际包含的字符数量
    int size = str.size();
    // 等价于 str.size()
    int length = str.length();
    int max_size = str.max_size();

    cout << "isEmpty = " << isEmpty << " capacity = " << capacity << " size = " << size
         << " max_size = " << max_size << " length = " << length << "\n";

    char at4 = str.at(4);
    string subStr = str.substr(1, 6);
    // “l”或“o” 首次出现的位置
    int find_first_of = str.find_first_of("lo");
    // 字符串 “lo” 首次出现的位置
    int find = str.find("lo");

    cout << "at3 = " << at4 << " subStr = " << subStr << " find_first_of = " << find_first_of
         << " find = " << find << "\n";
    return 0;
}
