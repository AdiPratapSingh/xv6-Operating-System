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
    if (pid == 0) {
        printf("child say parent pid: %d\n", getppid());
    }
    else {
        wait(&pid);
        printf("Parent say parent pid: %d\n", getpid());
    }
    exit(0);
}