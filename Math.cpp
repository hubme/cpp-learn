#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "sin(30)=" << sin(30) << "\n";
    cout << "cos(60)=" << cos(60) << "\n";
    cout << "tan(45)=" << tan(45) << "\n";
    cout << "sqrt(9)=" << sqrt(9) << "\n";
    cout << "pow(2, 3)=" << pow(2, 3) << "\n";
    cout << "abs(-10)=" << abs(-10) << "\n";
    cout << "floor(3.14)=" << floor(3.14) << "\n";
    cout << "ceil(3.14)=" << ceil(3.14) << "\n";
    cout << "round(3.14)=" << round(3.14) << "\n";

    cout << fixed << setprecision(2);
    cout << "round(3.15)=" << std::round(3.15) << "\n";

    return 0;
}
