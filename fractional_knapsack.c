#include <stdio.h>
#include <conio.h>

struct item {
    float profit;
    float weight;
    float ratio;
} Item[10];

void fractionalKnapsack(struct item Item[], int capacity, int n) {
    float maxProfit = 0.0, X[10];
    struct item temp;
    int i, j;
    
    for(i = 0; i < n; i++) {
        X[i] = 0.0;
        Item[i].ratio = Item[i].profit / Item[i].weight;
    }

    printf("\nThe P/W Ratios are:\n");
    for(i = 0; i < n; i++) {
        printf("Item %d => Profit: %.2f, Weight: %.2f, Ratio: %.2f\n", i + 1, Item[i].profit, Item[i].weight, Item[i].ratio);
    }

    // Sorting by ratio in descending order
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(Item[j].ratio < Item[j + 1].ratio) {
                temp = Item[j];
                Item[j] = Item[j + 1];
                Item[j + 1] = temp;
            }
        }
    }

    printf("\nItems sorted by P/W ratio in descending order:\n");
    for(i = 0; i < n; i++) {
        printf("Item %d => Profit: %.2f, Weight: %.2f, Ratio: %.2f\n", i + 1, Item[i].profit, Item[i].weight, Item[i].ratio);
    }

    i = 0;
    while(i < n && capacity > 0) {
        if(Item[i].weight <= capacity) {
            X[i] = 1.0;
            capacity -= Item[i].weight;
            maxProfit += X[i] * Item[i].profit;
        } else {
            X[i] = (float)capacity / Item[i].weight;
            maxProfit += X[i] * Item[i].profit;
            capacity = 0;
        }
        i++;
    }

    printf("\nSolution Array (Fraction of items taken):\n");
    for(i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, X[i]);
    }

    printf("\nThe Maximum Profit is: %.2f", maxProfit);
}

void main() {
    int capacity, n, i;
    clrscr();

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("\nEnter profit for each item:\n");
    for(i = 0; i < n; i++) {
        printf("Profit of item %d: ", i + 1);
        scanf("%f", &Item[i].profit);
    }

    printf("\nEnter weight for each item:\n");
    for(i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%f", &Item[i].weight);
    }

    printf("\nEnter maximum capacity of knapsack: ");
    scanf("%d", &capacity);

    fractionalKnapsack(Item, capacity, n);

    getch();
}
