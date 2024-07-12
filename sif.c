#include <stdio.h>

struct Process {
    int pid;
    int burstTime;
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
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void findWaitingTime(struct Process processes[], int n) {
    processes[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

void printDetails(struct Process processes[], int n) {
    printf("Process ID\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burstTime, processes[i].waitingTime);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter process ID and burst time for process %d: ", i + 1);
        scanf("%d%d", &processes[i].pid, &processes[i].burstTime);
    }

    sort(processes, n);
    findWaitingTime(processes, n);
    printDetails(processes, n);

    return 0;
}
