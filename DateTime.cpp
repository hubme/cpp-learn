#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    time_t now = time(NULL);
    cout << "时间戳: " << now << "\t当前日期和时间: " << ctime(&now) << "\n";

    tm *gmt = gmtime(&now);
    cout << "格林威治时间: " << asctime(gmt) << "\n";
    tm *local = localtime(&now);
    cout << "本地时间: " << asctime(local) << "\n";

    cout << 1900 + local->tm_year << "年" << 1 + local->tm_mon << "月" << local->tm_mday << "日"
         << local->tm_hour << "时" << local->tm_min << "分" << local->tm_sec << "秒\n";

    char buffer[50];
    strftime(buffer, 50, "%Y-%m-%d %H:%M:%S %Z", local);
    std::cout << "Formatted time: " << buffer << "\n";

    return 0;
}
