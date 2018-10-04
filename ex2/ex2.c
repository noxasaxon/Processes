// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define FNAME "text.txt"

int main(void)
{
    FILE* filePointer = fopen(FNAME, "w");

    int pid = fork();

    if(pid == 0){
        printf("\n pid is %d\n", (int) getpid());
        
        fwrite("test string", sizeof(char), strlen("test string"), filePointer);
    }

    else {
        printf("parent's pid: %d \n", (int) getpid());

        fwrite("parent string", sizeof(char), strlen("parent string"), filePointer);
    }

    //close file
    fclose(filePointer);

    return 0;
}
