//---------------------------------
//File Name    : all-file.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2021-11-25 15:32:24
//Description  : 
//----------------------------------
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char*argv[]){
    if(argc!=3)
        return 0;
    int a = open(argv[1],O_RDONLY);
    if(a<0)
        perror("open 1 error");
    int b = open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,S_IWUSR|S_IRUSR|S_IRGRP|S_IXOTH);
    if(b<0)
        perror("open 2 error");
    int length;
    char buf[1024]{};
    int wlength;
    while((length = read(a,buf,1024))>0)
        if((wlength=write(b,buf,length))!=length)
            perror("write not complete");
    if(close(a)<0)
        perror("close 1 error");
    if(close(b)<0)
        perror("close 2 error");
    return 0;
}
