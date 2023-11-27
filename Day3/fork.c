#include <stdio.h>
#include <unistd.h>
void forkExample(){
    int x=1, p_id, pp_id;
    if(fork()==0){
        p_id=getpid();
        printf("Child has pid:%d \tx=%d\n",p_id,++x);
    }else{
        pp_id=getpid();
        printf("Parent has pid:%d \tx=%d\n",pp_id,--x);
    }
}
int main(){
    forkExample();
    return 0;
}