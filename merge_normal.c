#include <stdio.h>
#include <conio.h>

void mergeSort(int arr[], int n);
void merge(int arr[], int temp[], int left, int mid, int right);
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

    mergeSort(arr, n);

    printf("\nSorted array (Normal Iterative Merge Sort):\n");
    printArray(arr, n);

    getch();
}

void mergeSort(int arr[], int n) {
    int curr_size, left_start, mid, right_end;
    int temp[100], i;

    for(curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for(left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            mid = left_start + curr_size - 1;
            right_end = left_start + 2 * curr_size - 1;

            if(right_end >= n)
                right_end = n - 1;

            if(mid < right_end)
                merge(arr, temp, left_start, mid, right_end);
        }
    }
}

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left; i <= right; i++)
        arr[i] = temp[i];
}

void printArray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
