//Write a C program to implement the LOOK Disk Scheduling algorithm to calculate the total seek count. The program should prompt the user to enter the size of the disk queue, the disk queue itself, and the initial head position.

#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int i, n, head, direction, seek_count = 0, distance;
    int queue[20];
    
    printf("Enter the size of disk queue: ");
    scanf("%d", &n);

    printf("Enter the disk queue: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Sort the disk queue
    sort(queue, n);

    printf("Enter the direction (0 for left and 1 for right): ");
    scanf("%d", &direction);

    // If direction is right, first serve all requests to the right of the head
    if (direction == 1) {
        // Serve all requests to the right
        for (i = 0; i < n; i++) {
            if (queue[i] >= head) {
                distance = abs(head - queue[i]);
                seek_count += distance;
                head = queue[i];
                printf("%d -> ", head);
            }
        }
        // Then serve all requests to the left
        for (i = n - 1; i >= 0; i--) {
            if (queue[i] < head) {
                distance = abs(head - queue[i]);
                seek_count += distance;
                head = queue[i];
                printf("%d -> ", head);
            }
        }
    }
    // If direction is left, first serve all requests to the left of the head
    else {
        // Serve all requests to the left
        for (i = n - 1; i >= 0; i--) {
            if (queue[i] <= head) {
                distance = abs(head - queue[i]);
                seek_count += distance;
                head = queue[i];
                printf("%d -> ", head);
            }
        }
        // Then serve all requests to the right
        for (i = 0; i < n; i++) {
            if (queue[i] > head) {
                distance = abs(head - queue[i]);
                seek_count += distance;
                head = queue[i];
                printf("%d -> ", head);
            }
        }
    }

    printf("\nTotal seek count = %d\n", seek_count);

    return 0;
}
