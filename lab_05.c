#include <stdio.h>

int main() {
    int n, i, quantum, count = 0, sq = 0;
    int bt[10], wt[10], tat[10], rem_bt[10];
    float avg_wt = 0, avg_tat = 0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times
    printf("Enter the burst times of processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Copy burst times to remaining burst time array
    }

    // Input quantum time
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    // Simulate Round Robin Scheduling
    while (1) {
        int all_done = 1; // Check if all processes are done

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                all_done = 0; // There is at least one process still running

                if (rem_bt[i] > quantum) {
                    sq += quantum;       // Increase the time spent so far
                    rem_bt[i] -= quantum; // Reduce remaining burst time
                } else {
                    sq += rem_bt[i];      // Add remaining time to total time
                    tat[i] = sq;          // Calculate turnaround time
                    rem_bt[i] = 0;        // Mark process as completed
                }
            }
        }

        if (all_done) break; // Exit the loop if all processes are completed
    }

    // Calculate waiting time and average times
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i]; // Waiting time = Turnaround time - Burst time
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Display averages
    avg_wt /= n;
    avg_tat /= n;
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
