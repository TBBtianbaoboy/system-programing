# 1: /proc 文件系统
- /proc 文件系统是一个**虚拟的文件系统**
- 该文件系统驻留在/proc 目录下，包含了各种用于展示内核信息的文件
- 允许进程使用文件I/O系统调用来读取和修改这些信息
- 之所以称之为虚拟文件系统，那是因为/proc 目录下的文件和子目录并**未存储在磁盘上**，而是在进程访问这些信息时由内核动态创建而成

## 1.1 /proc/PID 获取与进程有关的信息
> 文件与子目录

| 文件名或目录名 | 描述 |
|:----:|:----:|
| cmdline  | 以\0分隔的命令行参数 |
| status  | 进程的各种状态信息 |
| cwd     | 符号链接-指向进程的当前的工作目录 |
| exe     | 符号链接-指向进程正在执行的程序 |
| fd/  | 包含由当前进程打开的文件描述符 |
| environ | 当前进程的环境列表，由\0分隔 |
| maps | 进程的虚拟内存 |
| smaps | 进程的虚拟内存的详细信息 |
| mounts | 进程的挂载信息 |
| root  | 符号链接-指向根目录 |
| task/  | 包含线程子目录(线程就是进程) |

### 1.1.1 status 文件详情
```sh
######Example###### -- kernel version: Linux 5.13.16-200.fc34.x86_64
Name:	clash          # 进程启动所使用的命令
Umask:	0022           # 创建文件或文件夹的默认权限
State:	S (sleeping)   # 进程的状态
Tgid:	746            # 线程组ID(也就是当前线程(线程也就是进程)归属进程的ID)
Ngid:	0              # UNKNOW
Pid:	4433           # 进程ID(也可以说是线程ID)
PPid:	1              # 父进程ID
TracerPid:	0          # 跟踪进程的PID(0 表示没有跟踪进程)
Uid:	0	0	0	0  # UNKNOW
Gid:	0	0	0	0  # UNKNOW
FDSize:	128            # 文件描述符的最大个数
Groups:	               # 启动该进程的用户所属的组ID,可以有多个
NStgid:	746            # UNKNOW
NSpid:	4433           # UNKNOW
NSpgid:	7463           # UNKNOW
NSsid:	7463           # UNKNOW
VmPeak:	 2710932 kB    # 进程虚拟内存的最大值
VmSize:	 2645396 kB    # 进程当前虚拟内存的大小
VmLck:	       0 kB    # 进程锁住的虚拟内存的大小
VmPin:	       0 kB    # UNKNOW
VmHWM:	   30440 kB    # 文件内存映射和匿名内存映射的大小
VmRSS:	   17360 kB    # 当前正在使用的物理内存的大小
RssAnon:	   12536 kB         # UNKNOW
RssFile:	    4824 kB         # UNKNOW
RssShmem:	       0 kB         # UNKNOW
VmData:	  327000 kB    # 进程数据段的大小(存放初始化数据)
VmStk:	     132 kB    # 进程用户栈使用大小
VmExe:	    4744 kB    # 进程代码段中可执行的虚拟内存的大小
VmLib:	    2428 kB    # 被映射到虚拟内存的共享库的大小
VmPTE:	     396 kB    # 进程的所有页表的大小
VmSwap:	       0 kB    # UNKNOW
HugetlbPages:	       0 kB     # UNKNOW
CoreDumping:	0      # UNKNOW
THP_enabled:	1      # UNKNOW
Threads:	27         # 线程组中的线程总数
SigQ:	5/30583                 # 待处理的信号的个数/目前最大可以处理的信号的个数
SigPnd:	0000000000000000        # 屏蔽位，存储当前线程的待处理信号
ShdPnd:	0000000000000000        # 屏蔽位，存储当前线程组的待处理信号
SigBlk:	0000000000000000        # 存放被阻塞的信号
SigIgn:	0000000000000000        # 存放被忽略的信号
SigCgt:	fffffffdffc1feff        # 存放被俘获到的信号
CapInh:	0000000000000000        # 能被当前进程执行的程序的继承能力
CapPrm:	000001ffffffffff        # 当前进程能够使用的能力
CapEff:	000001ffffffffff        # UNKNOW
CapBnd:	000001ffffffffff        # UNKNOW
CapAmb:	0000000000000000        # UNKNOW
NoNewPrivs:	0          # UNKNOW
Seccomp:	0          # UNKNOW
Seccomp_filters:	0           # UNKNOW
Speculation_Store_Bypass:	thread vulnerable         #UNKNOW
SpeculationIndirectBranch:	conditional enabled       #UNKNOW
Cpus_allowed:	ff              # 可以执行当前进程的CPU掩码集
Cpus_allowed_list:	0-7         # 对应上述掩码集
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001    # UNKNOW
Mems_allowed_list:	0           # UNKNOW
voluntary_ctxt_switches:	246488                    # 进程主动切换的次数
nonvoluntary_ctxt_switches:	6957                      # 进程被动切换的次数
```

### 1.1.2 task/ 目录详情

```sh
# 就是线程目录(其实就是进程目录，只是这些目录不会显示在/proc 目录下，而是在这里)
 11525   3980   4433     527082   527085   647002   746   816   887
 3978    3981   4434     527083   643388   647003   814   817   891
 3979    4410   526999   527084   643389   647004   815   818   893
```

### 1.1.3 fd/ 目录详情
```sh
 0 -> /dev/null
 1 -> 'socket:[23354]'
 10 -> 'socket:[3229806]'
 11 -> 'socket:[3229809]'
 12 -> 'socket:[3220284]'
 13 -> 'socket:[3005671]'
 14 -> 'socket:[3220289]'
 15 -> 'socket:[3271293]'
 16 -> 'socket:[3276082]'
 17 -> 'socket:[3273568]'
 18 -> 'socket:[3277319]'
 19 -> 'socket:[3277841]'
 2 -> 'socket:[23354]'
 20 -> 'socket:[3277846]'
 3 -> 'anon_inode:[eventpoll]'
 4 -> 'pipe:[28740]'
 48 -> 'socket:[3002755]'
 5 -> 'pipe:[28740]'
 51 -> 'socket:[2998777]'
 6 -> 'socket:[24865]'
 65 -> 'socket:[3005675]'
 67 -> 'socket:[3004566]'
 7 -> 'socket:[24867]'
 73 -> 'socket:[3002757]'
 75 -> 'socket:[2998778]'
 77 -> 'socket:[3001869]'
 8 -> 'socket:[24868]'
 9 -> 'socket:[17268]'
```

