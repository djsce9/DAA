#include <stdio.h>
#include<conio.h>

int linear_comparisons = 0;
int divide_comparisons = 0;
int arr[100];
int i;

void linearMinMax(int arr[], int n, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];
    for (i = 1; i < n; i++)
    {
        linear_comparisons++;
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
        linear_comparisons++;
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }
}

void divideAndConquerMinMax(int arr[], int low, int high, int *min, int *max) {
    int mid, min1, max1, min2, max2;

    if (low == high)
    {
    *min = *max = arr[low];
    }
    else if (high == low + 1)
    {
    divide_comparisons++;
    if (arr[low] < arr[high])
    {
        *min = arr[low];
        *max = arr[high];
    }
    else
    {
        *min = arr[high];
        *max = arr[low];
    }
    }
    else
    {
    mid = (low + high) / 2;

    divideAndConquerMinMax(arr, low, mid, &min1, &max1);

    divideAndConquerMinMax(arr, mid + 1, high, &min2, &max2);

    divide_comparisons++;
    *min = (min1 < min2) ? min1 : min2;

    divide_comparisons++;
    *max = (max1 > max2) ? max1 : max2;
    }
}

int main()
{
    int n, i;
    int min_linear, max_linear, min_divide, max_divide;
    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    linearMinMax(arr, n, &min_linear, &max_linear);

    divideAndConquerMinMax(arr, 0, n - 1, &min_divide, &max_divide);

    printf("\n--- Linear Approach ---\n");
    printf("Minimum element: %d\n", min_linear);
    printf("Maximum element: %d\n", max_linear);
    printf("Total Comparisons: %d\n", linear_comparisons);

    printf("\n--- Divide and Conquer Approach ---\n");
    printf("Minimum element: %d\n", min_divide);
    printf("Maximum element: %d\n", max_divide);
    printf("Total Comparisons: %d\n", divide_comparisons);

    getch();
}

