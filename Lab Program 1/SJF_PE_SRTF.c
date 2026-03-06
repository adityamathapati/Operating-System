#include<stdio.h>
struct process {
    int id, at, bt, ct, tat, wt, rt, rem;
};
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time for P%d: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time for P%d: ", p[i].id);
        scanf("%d", &p[i].bt);
        p[i].rem = p[i].bt;
        p[i].rt = -1;
    }
    int completed = 0, time = 0, sumtat = 0, sumwt = 0, sumrt = 0;
while (completed != n) {
    int idx = -1, minrem = 1e9;
    for (int i = 0; i < n; i++) {
      if (p[i].at <= time && p[i].rem > 0) {
            if (p[i].rem < minrem ||(p[i].rem==minrem&&p[i].at<p[idx].at)) {
                minrem = p[i].rem;
                idx = i;
            }
        }
    }
    if (idx == -1) {
        time++;
        continue;
    }
    if (p[idx].rt == -1) {
        p[idx].rt = time - p[idx].at;
        sumrt += p[idx].rt;
    }
    p[idx].rem--;
    time++;
    if (p[idx].rem == 0) {
        completed++;
        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        sumtat += p[idx].tat;
        sumwt += p[idx].wt;
    }
 }
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].ct,
               p[i].tat, p[i].wt);
    }
    printf("\nAverage TAT: %.2f\n", (float)sumtat / n);
    printf("Average WT: %.2f\n", (float)sumwt / n);
    return 0;
}
