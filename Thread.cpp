#include <iostream>
#include <mutex>
#include <thread>

std::mutex myMutex;

void printMessage(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "printMessage " + std::to_string(i) << std::endl;
    }
}

class PrintTask {
   public:
    void operator()(int count) const {
        for (int i = 0; i < count; ++i) {
            std::cout << "PrintTask " + std::to_string(i) << std::endl;
        }
    }
};

void testNewThread() {
    // 1. 使用函数指针
    std::thread myThread1(printMessage, 2);
    myThread1.join();

    // 2. 使用函数对象
    std::thread myThread2(PrintTask(), 2);
    myThread2.join();

    // 3. 使用 lambda 表达式
    std::thread myThread3(
        [](int count) {
            for (int i = 0; i < count; ++i) {
                std::cout << "lambda " + std::to_string(i) << std::endl;
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
    std::cout << "哈哈哈" << std::endl;
    // 释放互斥量
    myMutex.unlock();
}

void testSyncThread() {
    for (size_t i = 0; i < 100; i++) {
        std::thread myThread(safeFunction);
        myThread.join();
    }
}

int main(int argc, char const *argv[]) {
    testSyncThread();
    return 0;
}