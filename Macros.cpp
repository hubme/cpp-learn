#include <iostream>

using namespace std;

/*
1. 所有的预处理器指令都是以井号（#）开头，只有空格字符可以出现在预处理指令之前。预处理指令不是 C++
语句，所以它们不会以分号（;）结尾。
2. 预处理指令有 #include、#define、#if、#else、#line 等
3. 一般形式是：#define macro-name replacement-text
*/

#define PI 3.1415926

#define MIN(a, b) (a < b ? a : b)

#define DEBUG

int main(int argc, char const *argv[]) {
    cout << "PI=" << PI << "\n";
    cout << "MIN(1, 2)=" << MIN(1, 2) << "\n";

#ifdef DEBUG
    cout << "DEBUG is defined" << "\n";
#endif

    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    return 0;
}
