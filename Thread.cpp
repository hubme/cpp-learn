#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex myMutex;

void printMessage(int count) {
    this_thread::sleep_for(chrono::seconds(3));
    cout << "threadId: " << this_thread::get_id() << endl;
    for (int i = 0; i < count; ++i) {
        cout << "printMessage " + to_string(i) << endl;
    }
}

class PrintTask {
   public:
    void operator()(int count) const {
        cout << "threadId: " << this_thread::get_id() << endl;
        for (int i = 0; i < count; ++i) {
            cout << "PrintTask " + to_string(i) << endl;
        }
    }
};

void testNewThread() {
    cout << "threadId main: " << this_thread::get_id() << endl;

    // 1. 使用函数指针
    thread myThread1(printMessage, 2);
    if (myThread1.joinable()) {
        myThread1.join();
    }

    // 2. 使用函数对象
    thread myThread2(PrintTask(), 2);
    myThread2.join();

    // 3. 使用 lambda 表达式
    thread myThread3(
        [](int count) {
            for (int i = 0; i < count; ++i) {
                cout << "lambda " + to_string(i) << endl;
            }
        },
        2);
    myThread3.join();
}

int number;

void safeFunction() {
    // 请求锁定互斥量
    myMutex.lock();
    // 访问或修改共享资源
    cout << "哈哈哈" << endl;
    // 释放互斥量
    myMutex.unlock();
}

void testSyncThread() {
    for (size_t i = 0; i < 100; i++) {
        thread myThread(safeFunction);
        myThread.join();
    }
}

int main(int argc, char const *argv[]) {
    testNewThread();
    return 0;
}