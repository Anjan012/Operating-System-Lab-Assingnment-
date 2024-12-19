#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int shared = 1; // Shared variable

// Function for Thread 1
void *fun1() {
    int x;
    x = shared; // Thread 1 reads the value of shared variable
    printf("Thread1 reads the value of shared variable as %d\n", x);
    x++; // Thread 1 increments the value
    printf("Local updation by Thread1: %d\n", x);
    sleep(1); // Thread 1 gets preempted
    shared = x; // Thread 1 updates the shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);
    return NULL;
}

// Function for Thread 2
void *fun2() {
    int y;
    y = shared; // Thread 2 reads the value of shared variable
    printf("Thread2 reads the value as %d\n", y);
    y--; // Thread 2 decrements the value
    printf("Local updation by Thread2: %d\n", y);
    sleep(1); // Thread 2 gets preempted
    shared = y; // Thread 2 updates the shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    // Wait for both threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Final value of the shared variable
    printf("Final value of shared is %d\n", shared);
    return 0;
}
