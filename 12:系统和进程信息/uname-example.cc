#include <asm-generic/errno-base.h>
#include <sys/utsname.h>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc,char* argv[]){
    struct utsname utsname;
    //@func uname #include<sys/utsname.h> 保存系统信息
    //@param_1 &struct utsname #include<sys/utsname.h>
    //@return success return 0,error return -1 and errno EFAULT
    int flag = uname(&utsname);
    if ( flag == -1){
        if (errno == EFAULT){
            cout << "uname buf is not valid" << endl;
            exit(1);
        }
        cout << "uname uknow error" << endl;
        exit(2);
    }
    cout << utsname.sysname << endl;
    cout << utsname.machine << endl;
    cout << utsname.nodename << endl;
    cout << utsname.release << endl;
    cout << utsname.version << endl;
    cout << utsname.domainname << endl;

    return 0;
}

