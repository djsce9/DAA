#include <stdio.h>
#include <conio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void printArray(int arr[], int n);

void main() {
    int arr[100], n, i;
    clrscr();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nSorted array (Normal/Iterative approach):\n");
    printArray(arr, n);

    getch();
}

void quickSort(int arr[], int low, int high) {
    int stack[100], top = -1, i, j, pivot;

    stack[++top] = low;
    stack[++top] = high;

    while(top >= 0) {
        high = stack[top--];
        low = stack[top--];

        pivot = partition(arr, low, high);

        if(pivot - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivot - 1;
        }

        if(pivot + 1 < high) {
            stack[++top] = pivot + 1;
            stack[++top] = high;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1, j;

    for(j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
