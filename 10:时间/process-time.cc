#include <cstdlib>
#include <ctime>
#include <sys/times.h>
#include <iostream>
#include <unistd.h>
using std::cout;
using std::endl;

int main(int argc,char* argv[]){
    for(int i=0;i<1000000;++i)
        cout << i << endl;
    //@func sysconf #include<unistd.h> 在应用程序运行时获得系统限制
    //@paras_1 系统时钟单位，即每秒有多少个时钟单位
    //@return success return long int value,error return -1 and errno is EINVAL
    long int clock_time = sysconf(_SC_CLK_TCK);
    struct tms tms;
    //@func times #include<sys/times>
    //@paras_1 struct tms #include<sys/times>
    //@return (clock_t)-1 on error
    if (times(&tms) == -1){
        cout << "times error" << endl;
        exit(1);
    }
    cout <<"user cpu time: " << (double)tms.tms_utime/clock_time << endl;
    cout <<"system cpu time: " << (double)tms.tms_stime/clock_time << endl;

    //----------------------------------------------------
    //clock与times的计量单位不同
    //@func clock #include<ctime>
    //@return clock_t
    cout << "总CPU : " << (double)clock()/CLOCKS_PER_SEC << endl;
    return 0;

}
