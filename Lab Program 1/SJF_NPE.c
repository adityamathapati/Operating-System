#include <stdio.h>
struct Process {
    int id, AT, BT, CT, TAT, WT, RT;
};
int main() {
    int n;
    printf("Enter no.of Processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Arrival Time of P%d: ", p[i].id);
        scanf("%d", &p[i].AT);
        printf("Burst Time of P%d: ", p[i].id);
        scanf("%d", &p[i].BT);
    }
    int completed = 0, time = 0, SumTAT = 0, SumWT = 0;
    int isComplete[n];
    for (int i = 0; i < n; i++) isComplete[i] = 0;
    while (completed != n) {
        int idx = -1, minBT = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= time && !isComplete[i] && p[i].BT < minBT) {
                minBT = p[i].BT;
                idx = i;
            }
        }
        if (idx != -1) {
            p[idx].CT = time + p[idx].BT;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            SumTAT += p[idx].TAT;
            SumWT += p[idx].WT;
            time += p[idx].BT;
            isComplete[idx] = 1;
            completed++;
        } else {
            time++;
        }
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAverage TAT : %.2f\n", (float)SumTAT / n);
    printf("Average WT  : %.2f\n", (float)SumWT / n);
    return 0;
}
