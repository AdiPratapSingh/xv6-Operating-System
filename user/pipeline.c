#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char*argv[]){

    int n,x;
    n = atoi(argv[1]);
    x = atoi(argv[2]);

    if(n<=0){
        printf("Error: n must be positive. Aborting...\n");
        exit(0);
    }
    
    int fd[2];
    int pid; 

    pipe(fd);
    write(fd[1],&x,1);
    
    while(n--){
        read(fd[0],&x,sizeof(int));
        x += getpid();
        printf("%d: %d\n",getpid(),x);

        close(fd[0]);
        close(fd[1]);

        pipe(fd);

        write(fd[1],&x,sizeof(int));

        if(n>0 && (pid = fork()) != 0){
            wait(&pid);
            break;
        }
    }

    exit(0);
}