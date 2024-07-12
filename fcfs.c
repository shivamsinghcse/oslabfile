#include <stdio.h>

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
};

void findWaitingTime(struct Process processes[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            currentTime = processes[i].arrivalTime;
        } else {
            currentTime += processes[i - 1].burstTime;
        }
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
    }
}

void printDetails(struct Process processes[], int n) {
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter process ID, arrival time, and burst time for process %d: ", i + 1);
        scanf("%d%d%d", &processes[i].pid, &processes[i].arrivalTime, &processes[i].burstTime);
    }

    findWaitingTime(processes, n);
    printDetails(processes, n);

    return 0;
}
