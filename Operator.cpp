#include <iostream>

using namespace std;

class Distance {
   private:
    int feet;    // 0 到无穷
    int inches;  // 0 到 12
   public:
    Distance();
    Distance(int f, int i);
    Distance operator-();
    friend ostream &operator<<(ostream &os, const Distance &d);
    void display();
};

Distance::Distance() {
    feet = 0;
    inches = 0;
}

Distance::Distance(int f, int i) {
    feet = f;
    inches = i;
}

Distance Distance::operator-() {
    feet = -feet;
    inches = -inches;
    return Distance(feet, inches);
}

void Distance::display() { cout << feet << " feet, " << inches << " inches" << "\n"; }

ostream &operator<<(ostream &os, const Distance &d) {
    os << "feet=" << d.feet << " inches=" << d.inches << "\n";
    return os;
}

int main(int argc, char const *argv[]) {
    Distance d1(5, 10);
    d1.display();
    cout << d1;

    -d1;

    d1.display();
    cout << d1;
    return 0;
}
