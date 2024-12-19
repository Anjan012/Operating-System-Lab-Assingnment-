#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX

int main()
{
    int i, j, n, head, seek_count = 0;
    int queue[20];

    // Step 1: Input disk queue size
    printf("Enter the size of disk queue: ");
    scanf("%d", &n);

    // Step 2: Input disk requests
    printf("Enter the disk queue: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Step 3: Input initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int current = head; // Head starts at the initial position

    // Process each request using SSTF logic
    for (i = 0; i < n; i++) {
        int min_distance = INT_MAX;
        int closest_index = -1;

        // Step 4: Find the request with the shortest seek time
        for (j = 0; j < n; j++) {
            if (abs(queue[j] - current) < min_distance && queue[j] != -1) {
                min_distance = abs(queue[j] - current);
                closest_index = j;
            }
        }

        // Print the current disk location and update variables
        printf("%d -> ", queue[closest_index]);
        seek_count += min_distance; // Add distance to seek count
        current = queue[closest_index]; // Move the head
        queue[closest_index] = -1; // Mark the request as processed
    }

    printf("\nTotal seek count = %d\n", seek_count);
    return 0;
}
