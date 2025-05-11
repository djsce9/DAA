#include <stdio.h>
#include <conio.h>

// Function to sort coin denominations in descending order (Selection Sort)
void sortDescending(int coins[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (coins[i] < coins[j]) {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
}

// Function to find the minimum number of coins using Greedy Approach
void coinChange(int coins[], int n, int amount) {
    int i, count = 0;
    int selectedCoins[20] = {0}; // To store selected coins

    for (i = 0; i < n; i++) {
        // Use as many coins of the current denomination as possible
        while (amount >= coins[i]) {
            amount -= coins[i];
            selectedCoins[count++] = coins[i];
        }
    }

    // Display the result
    printf("\nMinimum number of coins needed: %d\n", count);
    printf("Coins used: ");
    for (i = 0; i < count; i++) {
        printf("%d ", selectedCoins[i]);
    }
}

void main() {
    int n, i, amount;
    int coins[20]; // Max 20 coins

    clrscr();
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    // Input coin denominations
    printf("\nEnter the coin denominations:\n");
    for (i = 0; i < n; i++) {
        printf("Coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }

    printf("\nEnter the amount to be changed: ");
    scanf("%d", &amount);

    // Sort coins in descending order
    sortDescending(coins, n);

    // Find minimum coins using greedy approach
    coinChange(coins, n, amount);

    getch();
}
