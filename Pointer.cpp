#include <iostream>

using namespace std;

/**
 * 引用很容易与指针混淆，它们之间有三个主要的不同：
 * 1. 不存在空引用。引用必须连接到一块合法的内存。
 * 2. 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
 * 3. 引用必须在创建时被初始化。指针可以在任何时间被初始化。
 */
int main(int argc, char const *argv[]) {
    string name = "Vance";
    int age = 10;

    cout << "&name = " << &name << ", &age = " << &age << "\n";

    int *NULLptr = NULL;
    cout << "&NULL = " << NULLptr << "\n";

    int arr[] = {10, 20, 30, 40, 50};
    int *arrPtr = arr;
    cout << "*arrPtr = " << *arrPtr << "\n";

    arrPtr++;
    cout << "*(arrPtr++) = " << *arrPtr << "\n";

    int *arrPtr4 = &arr[4];
    cout << "&arr[4] = " << *arrPtr4 << "\n";

    arrPtr4--;
    cout << "&arr[4]-- = " << *arrPtr4 << "\n";
    return 0;
}
