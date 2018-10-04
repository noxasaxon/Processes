// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{

    printf("parent's pid: %d \n", (int) getpid());
    int pid = fork();


    if (pid == 0){
      printf("child's pid %d\n", (int) getpid());

      char *args[] = {"ls", "-l", NULL};
      
      execl("ls", args);
    }
    else{
      int wait = waitpid(pid, NULL, 0);
    }


    return 0;
}
