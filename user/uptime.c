#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc,int *argv[]){
    printf("%d\n",uptime());
    exit(0);
}