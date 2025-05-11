#include <stdio.h>
#include <conio.h>

int x[50], count = 0;

struct activity {
    int index;
    int start;
    int finish;
} arr[50];

void sort(int no) {
    int i, j;
    struct activity temp;
    for(i = 0; i < no - 1; i++) {
        for(j = 0; j < no - i - 1; j++) {
            if(arr[j].finish > arr[j + 1].finish) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void activitySelection(int no) {
    int i, j = 0, k = 1;
    x[0] = arr[0].index;
    count = 1;

    for(i = 1; i < no; i++) {
        if(arr[i].start >= arr[j].finish) {
            x[k] = arr[i].index;
            j = i;
            count++;
            k++;
        }
    }
}

void main() {
    int no, i;
    clrscr();

    printf("--- Activity Selection Problem using Greedy Approach ---\n");
    printf("Enter the number of activities: ");
    scanf("%d", &no);

    printf("\nEnter the details of activities (index, start time, finish time):\n");
    for(i = 0; i < no; i++) {
        printf("\nActivity %d:\n", i + 1);
        printf("Index: ");
        scanf("%d", &arr[i].index);
        printf("Start Time: ");
        scanf("%d", &arr[i].start);
        printf("Finish Time: ");
        scanf("%d", &arr[i].finish);
    }

    sort(no);

    printf("\nActivities sorted by finish time:\n");
    printf("Index\tStart\tFinish\n");
    for(i = 0; i < no; i++) {
        printf("%d\t%d\t%d\n", arr[i].index, arr[i].start, arr[i].finish);
    }

    activitySelection(no);

    printf("\nSelected Activities:\n");
    for(i = 0; i < count; i++) {
        printf("Activity %d\n", x[i]);
    }

    getch();
}
