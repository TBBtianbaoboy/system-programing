#include <asm-generic/errno-base.h>
#include <cerrno>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc,char* argv[]){
    //@func pathconf #include<unistd.h> 获取文件相关的限制值
    //@param_1 文件名(绝对路径或相对路径)
    //@param_2 系统限制名 #include<unistd.h>
    //@return success return long int,error return -1 and errno is EINVAL
    long int conf = pathconf("../10:时间/timeval.cc",_PC_NAME_MAX);
    if(conf == -1){
        if (errno == EINVAL){
            cout << "invalid typename" << endl;
            exit(1);
        }
        cout << "invalid filename" << endl;
        exit(2);
    }
    cout << conf << endl;

    //--------------------------------------------------------------------
    //@func fpathconf #include<unistd.h> 获取文件描述符相关的限制值
    //@param_1 文件描述符,(可以是不存在的文件描述符，你也可以错误地认为这是一个bug)
    //@param_2 系统限制名 #include<unistd.h>
    //@return success return long int,error return -1 and errno is EINVAL
    conf = fpathconf(STDIN_FILENO,_PC_FILESIZEBITS);
    if(conf == -1){
        if (errno == EINVAL){
            cout << "invalid typename" << endl;
            exit(3);
        }
        cout << "invalid filedescname" << endl;
        exit(4);
    }
    cout << conf << endl;
    return 0;

}
