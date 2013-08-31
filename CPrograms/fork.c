#include <sys/types.h>
#include <stdio.h>

int main()
{
    int pid;
    pid = fork();
    if (pid >= 0)
    {
        if (pid == 0)
        {
            printf("\nI am child process");        
        }
        else if (pid >= 0)
        {
            printf("\nI am parent process");
        }
    }
    else
    {
        printf("\nFork Failed");
    }
}
