#include <iostream>

using namespace std;

enum Color {
    RED,
    GREEN = 5,
    // 比前一个大1
    BLUE

};

// BLUE 已经在 Color 中定义，重复定义会报错
// enum Feeling { EXCITED, BLUE };

// 使用 namespace 解决作用域不受限的问题，更“有效”的办法是用一个类或结构体来限定其作用域
namespace Feeling {
enum Type { EXCITED, BLUE };
}

// C++11 的枚举类
enum class Week { MON, TUE, WED, THU, FRI, SAT, SUN, BLUE };

// 自定义输出流操作符
std::ostream &operator<<(std::ostream &os, const Week &day) {
    switch (day) {
        case Week::MON:
            os << "Monday";
            break;
        case Week::TUE:
            os << "Tuesday";
            break;
        case Week::WED:
            os << "Wednesday";
            break;
        default:
            os << "Other day";
    }
    return os;
}

int main(int argc, char const *argv[]) {
    cout << "RED=" << RED << " GREEN=" << GREEN << " BLUE=" << BLUE << endl;

    Color myColor = BLUE;
    cout << myColor << endl;

    // C++ 标准库没有为 enum class 定义默认的输出流操作符（operator<<）
    cout << "MON: " << Week::MON << " SUN: " << Week::SUN << endl;

    Feeling::Type feeling = Feeling::BLUE;
    cout << "Feeling::BLUE=" << feeling << endl;

    return 0;
}
