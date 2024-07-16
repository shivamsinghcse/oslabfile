#include <stdio.h>

struct Process {
    int pid;
    int burstTime;
    int priority;
    int waitingTime;
};

void swap(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void findWaitingTime(struct Process processes[], int n, int quantum) {
    int remainingBurstTime[n];
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = processes[i].burstTime;
    }
    int time = 0;
    while (1) {
        int completed = 1;
        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                completed = 0;
                if (remainingBurstTime[i] > quantum) {
                    time += quantum;
                    remainingBurstTime[i] -= quantum;
                } else {
                    time += remainingBurstTime[i];
                    processes[i].waitingTime = time - processes[i].burstTime;
                    remainingBurstTime[i] = 0;
                }
            }
        }
        if (completed == 1) {
            break;
        }
    }
}

void printDetails(struct Process processes[], int n) {
    printf("Process ID\tBurst Time\tPriority\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burstTime, processes[i].priority, processes[i].waitingTime);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter process ID, burst time, and priority for process %d: ", i + 1);
        scanf("%d%d%d", &processes[i].pid, &processes[i].burstTime, &processes[i].priority);
    }

    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    sort(processes, n);
    findWaitingTime(processes, n, quantum);
    printDetails(processes, n);

    return 0;
}
