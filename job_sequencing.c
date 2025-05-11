#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 100

struct Job {
    char id[10];
    int profit;
    int deadline;
};

void sortJobs(struct Job jobs[], int n) {
    struct Job temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

void main() {
    int n, i, j, maxDeadline = 0, totalProfit = 0;
    struct Job jobs[MAX];
    int slot[MAX];
    char gantt[MAX][10];

    clrscr();

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter Job ID, Profit and Deadline for each job:\n");
    for (i = 0; i < n; i++) {
        printf("Job %d:\n", i + 1);
        printf("ID: ");
        scanf("%s", jobs[i].id);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);

        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Sort jobs by profit
    sortJobs(jobs, n);

    printf("\nJobs sorted in descending order of profit:\n");
    printf("JobID\tProfit\tDeadline\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\n", jobs[i].id, jobs[i].profit, jobs[i].deadline);
    }

    // Initialize slots
    for (i = 0; i < maxDeadline; i++) {
        slot[i] = 0;
        strcpy(gantt[i], "Idle");
    }

    // Job Scheduling
    for (i = 0; i < n; i++) {
        for (j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                strcpy(gantt[j], jobs[i].id);
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Gantt Chart
    printf("\nGantt Chart (Job Schedule):\n");
    for (i = 0; i < maxDeadline; i++) {
        printf("| %s ", gantt[i]);
    }
    printf("|\n");

    for (i = 0; i < maxDeadline; i++) {
        printf("  %d ", i + 1);
    }
    printf("\n");

    printf("\nTotal Profit Earned = %d\n", totalProfit);

    getch();
}
