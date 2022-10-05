#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, int * argv[]){
    if(argc != 2){
        printf("Error: There must be only one argument. Aborting...\n");
        exit(0);
    }
    int x = argv[1];
    if( x > 100 || x < 2 ){
        printf("Error: Input must be in range [2,100]. Aborting...\n");
        exit(0);
    }

    int fd[2];
    pipe(fd);

    while(x!=0){
        
    }
}