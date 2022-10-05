#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int chartoint(char* c){
    int ans = 0;
    int i = 0;
    while(c[i] != '\0'){
        ans = ans*10 + c[i] - '0';
        i++;
    }
    return ans;
}

int main(int argc,char * argv[]){
    if(argc != 3){
        printf("This user program needs two integer arguments\n");
        exit(0);
    }

    int m = chartoint(argv[1]);
    int n = chartoint(argv[2]);
    printf("m = %d , n = %d\n",m,n);

    if(n!=0 && n!=1){
        printf("Error: n must be 0 or 1. Aborting...\n");
        exit(0);
    }
    if(m<=0){
        printf("Error: m must be non-negative. Aborting...\n");
        exit(0);
    }

    int pid;
    if((pid=fork())==0){
        if(n==0){
            sleep(m);
            printf("%d: Child\n",getpid());
        }
        else{
            printf("%d: Child\n",getpid());
        }
    }
    else{
        if(n==0){
            printf("%d: Parent\n",getpid());
            // $ is printed when parent exits hence should wait here
            wait(&pid);
        }
        else{
            sleep(m);
            printf("%d: Parent\n",getpid());
        }
    }
    exit(0);
}