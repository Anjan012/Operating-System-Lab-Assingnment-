#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock;   // Mutex lock to ensure mutual exclusion
int shared = 0;         // Shared variable

// Function for thread1
void* thread1_func(void* arg) {
    pthread_mutex_lock(&lock);  // Acquire the lock
    shared++;                   // Increment the shared variable
    printf("Thread1 incremented shared to: %d\n", shared);
    pthread_mutex_unlock(&lock); // Release the lock
    return NULL;
}

// Function for thread2
void* thread2_func(void* arg) {
    pthread_mutex_lock(&lock);  // Acquire the lock
    shared--;                   // Decrement the shared variable
    printf("Thread2 decremented shared to: %d\n", shared);
    pthread_mutex_unlock(&lock); // Release the lock
    return NULL;
}

int main() {
    // Initialize the mutex lock
    pthread_mutex_init(&lock, NULL);
    
    pthread_t thread1, thread2;  // Declare thread variables

    // Create two threads
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    // Wait for both threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print final value of shared variable
    printf("Final value of shared: %d\n", shared);

    // Destroy the mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}
