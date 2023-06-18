#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

// Process structure
struct Process {
    int pid;       // Process ID
    int burst_time; // Burst time
    int priority;  // Priority
    int remaining_time; // Remaining time
};

int main() {
    int n, i, time_quantum, total_time = 0, completed = 0, current_time = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    bool is_completed[MAX_PROCESSES] = {false};

    struct Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        processes[i].pid = i + 1;
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Enter the priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
        total_time += processes[i].burst_time;
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &time_quantum);

    // Execute processes
    while (completed < n) {
        int highest_priority = -1, process_index = -1;

        // Find process with highest priority
        for (i = 0; i < n; i++) {
            if (!is_completed[i] && processes[i].priority > highest_priority && processes[i].remaining_time > 0 && processes[i].remaining_time <= time_quantum) {
                highest_priority = processes[i].priority;
                process_index = i;
            }
        }

        // If no process found, increment time
        if (process_index == -1) {
            current_time++;
        } 
        // Otherwise, execute process
        else {
            processes[process_index].remaining_time -= time_quantum;
            current_time += time_quantum;

            if (processes[process_index].remaining_time == 0) {
                is_completed[process_index] = true;
                completed++;
                int waiting_time = current_time - processes[process_index].burst_time;
                int turnaround_time = current_time;
                avg_waiting_time += waiting_time;
                avg_turnaround_time += turnaround_time;

                printf("\nProcess %d completed\n", processes[process_index].pid);
                printf("Waiting time: %d\n", waiting_time);
                printf("Turnaround time: %d\n", turnaround_time);
            }
        }
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\nAverage waiting time: %f\n", avg_waiting_time);
    printf("Average turnaround time: %f\n", avg_turnaround_time);

    return 0;
}
