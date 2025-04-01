#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>

int main()
{
    int x = 100; // Initial value of x

    printf("Before fork: x = %d\n", x);

    pid_t pid = fork(); // Create a child process

    if (pid < 0)
    {
        // Fork failed
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child: Initially, x = %d\n", x);
        x = 200; // Change x in the child process
        printf("Child: After change, x = %d\n", x);
    }
    else
    {
        // Parent process
        printf("Parent: Initially, x = %d\n", x);
        x = 300; // Change x in the parent process
        printf("Parent: After change, x = %d\n", x);
    }

    // Both parent and child execute this
    printf("Process (PID = %d): Final x = %d\n", getpid(), x);

    return 0;
}
