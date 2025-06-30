#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void testWriteFile() {
    char data[50];

    cout << "请输入内容：";
    cin.getline(data, 50);
    cout << "你输入的内容是：" << data << endl;

    // ofstream outfile("./build/test.txt", ios::out | ios::app);

    ofstream outfile;
    outfile.open("./build/test.txt", ios::out | ios::trunc);
    if (!outfile) {
        cerr << "文件打开失败" << endl;
    }

    outfile << data;

    outfile.close();
    cout << "数据已写入文件" << endl;
}

void testReadFile() {
    ifstream infile;
    infile.open("./build/test.txt", ios::in);
    if (!infile) {
        cerr << "文件打开失败" << endl;
    }
    char data[50];
    infile.getline(data, 50);
    cout << "文件内容是：" << data << endl;

    infile.seekg(-10, ios::end);
    if (infile.fail()) {
        cerr << "文件读取失败" << endl;
    }

    infile.getline(data, 50);
    if (infile.gcount() == 0) {
        cerr << "没有读取到任何数据" << endl;
    } else {
        cout << "文件内容是：" << data << endl;
    }

    infile.close();
    cout << "数据已读取" << endl;
}

void testFail() {
    if (cin.fail()) {
        cin.clear();  // 清除错误状态
        // 需要导入 limits 头文件
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 忽略输入缓冲区中的错误数据
    }
}

int main(int argc, char const *argv[]) {
    // testWriteFile();
    cout << "------------------------" << endl;
    testReadFile();

    return 0;
}
