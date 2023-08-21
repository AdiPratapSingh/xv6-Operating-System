#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

int main(int argc, char *argv[])
{   
    int pid = fork();
    int i = 0;
    if (pid == 0) {
        while(i<1000000000) i++;
        printf("pid after yield() : %d\n", getpid());
    }
    else {
        yield();
        while(1)yield();
        printf("pid before yield() : %d\n", getpid());
        // while(i<1000000000) i++;
    }

    exit(0);
}