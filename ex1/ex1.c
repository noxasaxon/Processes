// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 0;
    int pid = fork();

    if(pid){
        printf("\n pid is %d, x is %d\n", (int) getpid(), x);
        x = 13;
        printf("\n pid is %d, x is %d\n", (int) getpid()), x;
    }

    if (pid == 0){
        printf("\n pid is %d, x is %d\n", (int) getpid());
    }


    return 0;
}
