#include <stdio.h>
#include<math.h>
#define MAX 10
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
int main() {
    int n;
    int burst[MAX], period[MAX];
    int hyperperiod;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the CPU burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
    }
    printf("Enter the time periods:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &period[i]);
    }
    hyperperiod = period[0];
    for (int i = 1; i < n; i++) {
        hyperperiod = lcm(hyperperiod, period[i]);
    }
    printf("LCM=%d\n\n", hyperperiod);
    printf("Rate Monotone Scheduling:\n");
    printf("PID   Burst   Period\n");
    for (int i = 0; i < n; i++) {
        printf("%d     %d      %d\n", i + 1, burst[i], period[i]);
    }
    double utilization = 0.0;
    for (int i = 0; i < n; i++) {
        utilization += (double)burst[i] / period[i];
    }
    double bound = n * (pow(2.0, 1.0 / n) - 1);
    printf("\n%f <= %f => %s\n", utilization, bound,
           (utilization <= bound) ? "true" : "false");
    printf("Scheduling occurs for %d ms\n\n", hyperperiod);
    int remaining[MAX] = {0};
    for (int time = 0; time < hyperperiod; time++) {
        for (int i = 0; i < n; i++) {
            if (time % period[i] == 0) {
                remaining[i] = burst[i];
            }
        }
        int selected = -1;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                selected = i;
                break;
            }
        }
        if (selected != -1) {
            if (remaining[selected] == burst[selected]) {
                printf("%dms onwards: Process %d running\n", time, selected + 1);
            }
            remaining[selected]--;
        } else {
            printf("%dms onwards: CPU is idle\n", time);
        }
    }
    return 0;
}
