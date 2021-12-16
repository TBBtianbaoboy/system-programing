#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc,char* argv[]){
    struct timeval tv;
    int is_ok;
    is_ok = gettimeofday(&tv,nullptr);
    if(is_ok==-1){
        cout << "gettimeofday error" << endl;
        exit(1);
    }
    cout <<"gettimeofday->ctime: " << ctime(&tv.tv_sec);

    time_t now;
    now = time(nullptr);
    cout << "time->ctime" << ctime(&now);

    cout << "UTC time: " << asctime(gmtime(&(now=time(nullptr))));
    cout << "local time: " << asctime(localtime(&(now=time(nullptr))));

    return 0;
}
