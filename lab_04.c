#include <stdio.h>

int main() {
    int n, i;
    float avg_wait_time = 0, avg_turnaround_time = 0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], wait_time[n], turnaround_time[n];

    // Input burst times for all processes
    printf("Enter the burst times of processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Calculate waiting time for each process
    wait_time[0] = 0; // Waiting time for the first process is 0
    for (i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
    }

    // Calculate turnaround time for each process
    for (i = 0; i < n; i++) {
        turnaround_time[i] = wait_time[i] + burst_time[i];
    }

    // Calculate average waiting time and turnaround time
    for (i = 0; i < n; i++) {
        avg_wait_time += wait_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_wait_time /= n;
    avg_turnaround_time /= n;

    // Display process details
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], wait_time[i], turnaround_time[i]);
    }

    // Display averages
    printf("\nAverage Waiting Time: %.2f", avg_wait_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
