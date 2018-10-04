// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{


    int pid = fork();

    if (pid == 0) {
        printf("child print\n");
        printf(" pid is %d\n", (int) getpid());
    } else {
        int test = waitpid(pid, NULL, 0);
        
        printf("parent print\n");
        printf("pid is %d\n", (int) getpid());
    }


    return 0;
}
