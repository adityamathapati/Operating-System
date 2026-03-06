#include <stdio.h>
struct Process {
    int ID, AT, BT, CT, TAT, WT, RT;
};
int main() {
    int n;
    printf("Enter no of processes : ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].ID = i + 1;
        printf("Arrival time of P%d : ", p[i].ID);
        scanf("%d", &p[i].AT);
        printf("Burst time of P%d : ", p[i].ID);
        scanf("%d", &p[i].BT);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].AT > p[j + 1].AT) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    int timePassed = 0, SumTAT = 0, SumWT = 0, SumRT = 0;

    for (int i = 0; i < n; i++) {
        if (timePassed < p[i].AT) {
            timePassed = p[i].AT;
        }
        p[i].RT = timePassed - p[i].AT;
        p[i].CT = timePassed + p[i].BT;
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        timePassed += p[i].BT;
        SumTAT += p[i].TAT;
        SumWT += p[i].WT;
        SumRT += p[i].RT;
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].ID, p[i].AT, p[i].BT, p[i].CT,
               p[i].TAT, p[i].WT, p[i].RT);
    }
    printf("\nAverage TAT : %.2f\n", (float)SumTAT / n);
    printf("Average WT  : %.2f\n", (float)SumWT / n);
    printf("Average RT  : %.2f\n", (float)SumRT / n);
    return 0;
}
