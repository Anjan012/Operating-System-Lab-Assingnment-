#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, head, seek_count = 0; // Variables for disk queue size, head position, and seek count
    int queue[20]; // Array to store disk requests

    // Step 1: Input disk queue size
    printf("Enter the size of disk queue: ");
    scanf("%d", &n); // User enters the size of the queue (e.g., 5)

    // Step 2: Input disk requests
    printf("Enter the disk queue: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]); // User enters disk requests (e.g., 82, 170, 43, 140, 24)
    }

    // Step 3: Input initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head); // User enters the initial head position (e.g., 50)

    // Step 4: Process the disk queue (FCFS)
    printf("\nSeek Sequence is:\n");
    for (i = 0; i < n; i++) {
        printf("%d -> ", queue[i]); // Print seek sequence
        seek_count += abs(queue[i] - head); // Calculate seek distance
        head = queue[i]; // Move head to the current request position
    }

    // Step 5: Print total seek count
    printf("\nTotal seek count = %d\n", seek_count);

    return 0;
}
