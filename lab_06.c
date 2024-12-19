#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], i, j, pos, temp;
    float total_wt = 0, total_tat = 0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times
    printf("Enter the burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Burst time of Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sorting burst times using Selection Sort (for SJF)
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos]) {
                pos = j; // Find the process with the shortest burst time
            }
        }
        // Swap burst times to arrange them in ascending order
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }

    // Calculate waiting times and turnaround times
    wt[0] = 0; // First process has zero waiting time

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time = sum of previous burst times
        total_wt += wt[i];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i]; // Turnaround time = waiting time + burst time
        total_tat += tat[i];
    }

    // Print results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Calculate and print averages
    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
