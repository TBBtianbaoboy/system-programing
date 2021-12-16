#include <asm-generic/errno-base.h>
#include <cerrno>
#include <cstddef>
#include <cstdio>
#include <unistd.h>
#include <pwd.h>
#include <shadow.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

int main(int argc,char *argv[]){
    char *username,*password,*encrypted,*p;
    struct passwd *pwd;
    struct spwd *spwd;
    bool auth_ok;
    size_t len;
    long lnmax = sysconf(_SC_LOGIN_NAME_MAX);
    if(lnmax == -1 )
        lnmax = 256;
    username = (char*)malloc(lnmax);
    if(username==nullptr){
        cout << "malloc error" << endl;
        exit(1);
    }

    //输入用户名
    cout << "Username: ";
    fflush(stdout);
    if(fgets(username,lnmax,stdin)==nullptr){
        exit(2);
    }
    len = strlen(username);
    if(username[len-1]=='\n')
        username[len-1] = '\0';
    pwd = getpwnam(username);
    if(pwd==nullptr){
        cout << "user not exist"<<endl;
        exit(3);
    }

    //密码
    spwd = getspnam(username);
    if(spwd==nullptr && errno==EACCES){
        cout << "permission deny" << endl;
        exit(4);
    }
    if(spwd!=nullptr)
        pwd->pw_passwd = spwd->sp_pwdp;
    password = getpass("Password: ");

    //验证加密后的密码
    encrypted = crypt(password,pwd->pw_passwd);
    //火速清除原明文密码
    for(p = password;*p != '\0';)
        *p++ = '\0';
    if(encrypted==nullptr){
        cout << "cry error" << endl;
        exit(5);
    }
    auth_ok = strcmp(encrypted,pwd->pw_passwd) == 0;
    if(!auth_ok){
        cout << "password error" << endl;
        exit(6);
    }
    cout <<"login successful" << " UID: " << pwd->pw_uid << endl;
    free(username);
    return 0;
}
