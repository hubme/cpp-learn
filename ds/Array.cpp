#include <array>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // 指定的大小超过了实际的元素个数，填充 0。
    array<int, 8> arr = {7, 8, 9, 4, 5, 6};
    auto front = arr.front();
    auto back = arr.back();
    auto size = arr.size();
    auto max_size = arr.max_size();
    auto empty = arr.empty();
    auto index9 = arr[9]; // 注意：std::array 的大小是固定的，访问越界会导致未定义行为。
    // auto index9_1 = arr[9];

    cout << "front: " << front << ", back: " << back << ", size: " << size
         << ", max_size: " << max_size << ", empty: " << empty << ", index9: " << index9 << endl;
    // cout << "index9_1: " << index9_1 << endl;
    return 0;
}
