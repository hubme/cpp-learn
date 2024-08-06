#include <unistd.h>

#include <csignal>
#include <iostream>

using namespace std;

void signalHandler(int signum) {
    cout << "Caught signal: " << signum << endl;

    // 清理并终止程序
    exit(signum);
}

int main(int argc, char const *argv[]) {
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);

    cout << "Going to sleep...." << endl;
    sleep(3);  // unistd.h
    cout << "Sleep ends...." << endl;

    raise(SIGINT);

    return 0;
}
