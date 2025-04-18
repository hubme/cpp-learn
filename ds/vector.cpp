#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    // vector<int> vector1;  // 定义一个空的 vector
    vector<int> vector1 = {1, 2, 3, 4, 5};
    vector1.reserve(10);    // 预留空间，避免频繁扩容
    vector1.push_back(11);  // 在末尾添加元素

    string text;
    text.append("capacity(): ");
    text.append(to_string(vector1.capacity()));  // 总容量，可能包含预留空间
    text.append("\nsize(): ");
    text.append(to_string(vector1.size()));  // 当前元素个数
    text.append("\nmax_size(): ");
    text.append(to_string(vector1.max_size()));
    text.append("\nempty(): ");
    text.append(vector1.empty() ? "true" : "false");

    vector1.shrink_to_fit();  // 收缩到当前大小，释放多余的内存
    text.append("\n\nafter shrink_to_fit() \ncapacity(): ");
    text.append(to_string(vector1.capacity()));  // 收缩后容量
    text.append("\nsize(): ");
    text.append(to_string(vector1.size()));  // 收缩后大小

    cout << text << endl;

    // 遍历 vector 的元素，const_iterator 是只读的，不能修改元素
    for (vector<int>::const_iterator it = vector1.cbegin(); it != vector1.cend(); it++) {
        cout << *it << " ";  // 只读访问元素
    }

    cout << endl;

    cout << "可修改的迭代器：" << endl;
    for (vector<int>::iterator it = vector1.begin(); it != vector1.end(); it++) {
        *it = *it + 1;  // 可以修改元素
        cout << *it << " ";
    }

    return 0;
}
