#include <iostream>

using namespace std;

/**
 * “位域”或“位段”(Bit field) 为一种数据结构，
 * 可以把数据以位的形式紧凑的储存，并允许程序员对此结构的位进行操作。
 *
 * - 位域在内存中的布局是与机器有关的
 * - 位域的类型必须是整型或枚举类型，带符号类型中的位域的行为将因具体实现而定
 * - 取地址运算符（&）不能作用于位域，任何指针都无法指向类的位域
 */

struct stuff {
    unsigned int field1 : 30;
    unsigned int : 2;  // 占 2 bit
    unsigned int field2 : 4;
    unsigned int : 0;  // 对齐到 32 bit
    unsigned int field3 : 3;
};

int main() {
    struct stuff s = {1, 3, 5};
    cout << s.field1 << endl;
    cout << s.field2 << endl;
    cout << s.field3 << endl;
    cout << sizeof(s) << endl;  // 输出 12
    return 0;
}
