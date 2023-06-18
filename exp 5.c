#include <stdio.h>

#define MAX_PROCESSES 5

struct Process {
    int pid;
    int priority;
    int burstTime;
};

void schedule(struct Process processes[], int n) {
    int i, j;
    struct Process temp;

    // Sort the processes based on priority in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].priority < processes[j + 1].priority) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    printf("Process ID\tPriority\tBurst Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].priority, processes[i].burstTime);
    }
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int i, n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
    }

    printf("\nScheduling based on priority:\n");
    schedule(processes, n);

    return 0;
}
