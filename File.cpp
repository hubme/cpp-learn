#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // 可以写成一行：ofstream outFile("test.txt");
    ofstream outFile;
    outFile.open("test.txt");
    outFile << "Hello, World!" << "\n" << "Hello, C++!" << "\n";
    outFile.close();

    ifstream inFile("test.txt");
    string line;
    while (std::getline(inFile, line)) {
        cout << line << "\n";
    }
    inFile.close();
    return 0;
}
