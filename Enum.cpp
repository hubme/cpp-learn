#include <iostream>

using namespace std;

enum Color {
    RED,
    GREEN = 5,
    // 比前一个大1
    BLUE

};

enum class Week { MON, TUE, WED };

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
            os << "Unknown day";
    }
    return os;
}

int main(int argc, char const *argv[]) {
    cout << "RED=" << RED << " GREEN=" << GREEN << " BLUE=" << BLUE << endl;

    Color myColor = BLUE;
    cout << myColor << endl;

    // C++ 标准库没有为 enum class 定义默认的输出流操作符（operator<<）
    cout << Week::MON << endl;

    return 0;
}
