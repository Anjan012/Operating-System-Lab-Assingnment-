#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Thread function
void *thread_function(void *arg) {
    printf("Inside Thread\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", i);
        sleep(1); // Simulate work
    }
    printf("Thread Finished\n");
    return NULL;
}

int main() {
    pthread_t a_thread;  // Declare thread variable

    // Create the thread
    pthread_create(&a_thread, NULL, thread_function, NULL);

    // Main program logic runs concurrently with the thread
    printf("Thread Created\n");
    printf("Inside Main Program\n");
    for (int j = 20; j < 25; j++) {
        printf("%d\n", j);
        sleep(1); // Simulate work
    }

    // Thread exits automatically; no need to join if we don't need synchronization
    printf("Main Program Finished\n");
    return 0;
}
