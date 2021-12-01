//---------------------------------
//File Name    : glibc.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2021-11-25 13:16:39
//Description  : 
//----------------------------------
#include <iostream>
#include <gnu/libc-version.h>
int main(){
    std::cout << gnu_get_libc_version() << std::endl;
    return 0;
}
