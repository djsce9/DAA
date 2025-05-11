#include <stdio.h>
#include <conio.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Structure to store item details
struct Item {
    int index;
    int weight;
    int profit;
};

// Function to sort items by weight in ascending order
void sortItems(int n, struct Item items[]) {
    int i, j;
    struct Item temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (items[j].weight > items[j + 1].weight) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void main() {
    int n, capacity, i, j;
    struct Item items[20]; // Max 20 items
    int K[20][20];         // DP table (fixed size)
    int selected[20] = {0}; // Selected items (0 = Not Selected, 1 = Selected)

    clrscr();
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Taking input for weights and profits
    printf("\nEnter weights and profits of items:\n");
    for (i = 0; i < n; i++) {
        items[i].index = i + 1;
        printf("Weight of Item %d: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Profit of Item %d: ", i + 1);
        scanf("%d", &items[i].profit);
    }

    printf("\nEnter capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort items by weight for correct DP table
    sortItems(n, items);

    // Initialize DP table
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (items[i - 1].weight <= j)
                K[i][j] = max(items[i - 1].profit + K[i - 1][j - items[i - 1].weight], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    // Display the DP Table
    printf("\nFinal Knapsack DP Table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            printf("%d\t", K[i][j]);
        }
        printf("\n");
    }

    // Backtrack to find selected items
    i = n;
    j = capacity;
    while (i > 0 && j > 0) {
        if (K[i][j] != K[i - 1][j]) {
            selected[i - 1] = 1; // Mark item as selected
            j -= items[i - 1].weight;
        }
        i--;
    }

    // Display the solution in original order
    printf("\nSolution Array (1 = Selected, 0 = Not Selected):\n");
    printf("Item\tWeight\tProfit\tSelected\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", items[i].index, items[i].weight, items[i].profit, selected[i]);
    }

    // Calculate and display the maximum profit
    int maxProfit = K[n][capacity];
    printf("\nMaximum Profit: %d\n", maxProfit);

    // Display the selected items in the original order
    printf("\nItems included in Knapsack (Original Order): ");
    for (i = 0; i < n; i++) {
        if (selected[i] == 1) {
            printf("Item%d ", items[i].index);
        }
    }

    getch();
}
