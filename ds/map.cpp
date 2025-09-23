#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 1. https://hackingcpp.com/cpp/std/associative_containers.html
 * 2. https://www.apiref.com/cpp-zh/cpp/container/unordered_map.html
 */

void test1() {
    map<string, int> numberMap = {{"one", 1}, {"two", 2}, {"three", 3}};
    numberMap["four"] = 4;
    numberMap["five"] = 5;
    numberMap["five"] = 55;  // 可以更新值

    numberMap.insert(pair<string, int>("six", 6));
    numberMap.insert(make_pair("seven", 7));
    numberMap.insert({"eight", 8});
    numberMap.insert({"eight", 88});  // 重复插入不会报错，但不会更新已有的值
    //.insert_or_assign(key,value) → pair<@pos,insert_success> C++17
    numberMap.insert_or_assign("eight", 88);  // 可以更新值。

    cout << "five=" << numberMap["five"] << " eight=" << numberMap["eight"] << endl;  // 输出 55

    set<string> keys{"one", "three", "five", "ten"};
    auto aa = keys.extract("ten");

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
    cout << endl;
}

void test2() {
    map<int, string> numberMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    numberMap[0] = "zero";
    numberMap[1] = "ONE";  // 可以更新值

    try {
        numberMap.at(4) = "four";  // 如果 key 不存在，会抛出 out_of_range 异常
    } catch (const out_of_range &e) {
        cerr << "Exception: " << e.what() << endl;
    }

    for (auto const &pair : numberMap) {
        cout << pair.first << " = " << pair.second << "\n";
    }
}

void test3() {
    unordered_map<int, string> m{{6, "x"}, {4, "a"}, {7, "n"}, {2, "z"}};
    cout << "m.size() = " << m.size() << " m.bucket_count() = " << m.bucket_count()
         << " m.bucket_size(1) = " << m.bucket_size(1) << " m.bucket_size(2) = " << m.bucket_size(2)
         << " m.bucket_size(3) = " << m.bucket_size(3) << " m.load_factor = " << m.load_factor()
         << " m.max_load_factor = " << m.max_load_factor() << endl;
}

void test4() {
    unordered_set<int> s{1, 3, 5, 8, 9};
    // get bucket with key 3
    const auto b = s.bucket(1);
    // iterate over keys in bucket
    for (auto i = s.cbegin(b); i != s.cend(b); ++i) {
        cout << *i << ' ';
    }
}

int main(int argc, char const *argv[]) {
    test4();
    return 0;
}
