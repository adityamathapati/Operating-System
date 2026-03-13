#include <stdio.h>
struct Process {
    int pid, bt, at, priority, rt, wt, tat, ct;
};
int main() {
    int n;
    printf("Enter number of processes :");
    scanf("%d", &n);
    struct Process p[n];
    int isCompleted[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter Burst Time, Arrival Time and Priority for P%d:", p[i].pid);
        scanf("%d %d %d", &p[i].bt, &p[i].at, &p[i].priority);
        p[i].rt = p[i].bt;
        isCompleted[i] = 0;
    }
    int completed = 0, time = 0;
    while (completed != n) {
        int idx = -1;
        int highestPriority = 999999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && isCompleted[i] == 0) {
                if (p[i].priority < highestPriority) {
                    highestPriority = p[i].priority;
                    idx = i;
                } else if (p[i].priority == highestPriority) {
                    if (p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1) {
            p[idx].rt--;
            time++;
            if (p[idx].rt == 0) {
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                isCompleted[idx] = 1;
                completed++;
            }
        } else {
            time++;
        }
    }
    float avgWT = 0, avgTAT = 0;
    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].priority,
               p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage TAT = %.2f", avgTAT / n);
    printf("\nAverage WT = %.2f", avgWT / n);
    return 0;
}
