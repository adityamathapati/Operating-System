#include <stdio.h>
#define MAX_TASKS 10
typedef struct {
    int id;
    int execution_time;
    int period;
    int relative_deadline;
    int remaining_time;
    int deadline;
} Task;
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
    int n, hyperperiod;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    Task tasks[MAX_TASKS];
    printf("\nEnter Burst Time, Period, and Deadline for each task:\n");
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("\nTask %d Burst Time: ", i + 1);
        scanf("%d", &tasks[i].execution_time);
        printf("Task %d Period: ", i + 1);
        scanf("%d", &tasks[i].period);
        printf("Task %d Deadline: ", i + 1);
        scanf("%d", &tasks[i].relative_deadline);
        tasks[i].remaining_time = 0;
        tasks[i].deadline = tasks[i].relative_deadline;
    }
    hyperperiod = tasks[0].period;
    for (int i = 1; i < n; i++) {
        hyperperiod = lcm(hyperperiod, tasks[i].period);
    }
    printf("\nPID\tBurst\tDeadline\tPeriod\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\n",
               tasks[i].id,
               tasks[i].execution_time,
               tasks[i].relative_deadline,
               tasks[i].period);
    }
    printf("\nScheduling occurs for %d ms\n\n", hyperperiod);
    for (int time = 0; time < hyperperiod; time++) {
        for (int i = 0; i < n; i++) {
            if (time % tasks[i].period == 0) {
                tasks[i].remaining_time = tasks[i].execution_time;
                tasks[i].deadline = time + tasks[i].relative_deadline;
            }
        }
        int selected = -1;
        int earliest_deadline = 100000;
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_time > 0 &&
                tasks[i].deadline < earliest_deadline) {
                earliest_deadline = tasks[i].deadline;
                selected = i;
            }
        }
        if (selected != -1) {
            printf("%dms : Task %d is running.\n", time, tasks[selected].id);
            tasks[selected].remaining_time--;
        } else {
            printf("%dms : CPU is idle.\n", time);
        }
    }
    return 0;
}
