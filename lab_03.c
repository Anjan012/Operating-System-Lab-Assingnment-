// "Write a C program that demonstrates process creation using the fork() system call. The program should create a child process using fork() and print the process IDs for both the parent and child processes."

#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid; // to store process ID
    pid = fork(); // create a new process

    if (pid < 0) 
    { 
        // Error handling
        printf("Error: Child process creation failed.\n");
    } 
    else if (pid == 0) 
    { 
        // Child process
        printf("Child process. PID: %d, Parent PID: %d\n", getpid(), getppid());
    } 
    else 
    { 
        // Parent process
        printf("Parent process. PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}
