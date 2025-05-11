#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define MAX 100

// Function to return minimum value
int min(int table1, int table2) {
    return (table1 < table2) ? table1 : table2;
}

void main() {
    int amount, coins[MAX], no, i, j, total_coin, solution[MAX], table[MAX][MAX], k = 0;
    clrscr();

    // Input amount and number of denominations
    printf("\nCoin Change Problem Using Dynamic Programming :-");
    printf("\nEnter the total amount : ");
    scanf("%d", &amount);
    printf("\nEnter the total number of coin denominations : ");
    scanf("%d", &no);

    // Input coin denominations
    printf("\nEnter the denominations : ");
    for(i = 0; i < no; i++) {
        scanf("%d", &coins[i]);
    }

    // Initialize DP table
    for(i = 0; i <= no; i++) {
        for(j = 0; j <= amount; j++) {
            table[i][j] = INT_MAX;  // Use INT_MAX as infinity
        }
    }

    // Base condition
    for(i = 0; i <= no; i++) {
        table[i][0] = 0;  // No coins needed to make amount 0
    }

    // Fill the DP table
    for(i = 1; i <= no; i++) {
        for(j = 1; j <= amount; j++) {
            if(coins[i - 1] > j) {
                table[i][j] = table[i - 1][j];  // Coin cannot be used
            } else {
                table[i][j] = min(table[i - 1][j], 1 + table[i][j - coins[i - 1]]);  // Include or exclude coin
            }
        }
    }

    // Output the DP table
    printf("\n The table is :- \n");
    for(i = 0; i <= no; i++) {
        for(j = 0; j <= amount; j++) {
            if(table[i][j] == INT_MAX) {
                printf("INF\t");  // Represent infinity as INF
            } else {
                printf("%d\t", table[i][j]);
            }
        }
        printf("\n");
    }

    // Print the minimum number of coins
    printf("\n The minimum number of coins used are:-  %d ", table[no][amount]);

    // Retrieve the solution (the actual coins used)
    i = no;
    j = amount;
    while(j > 0) {
        if(table[i][j] == table[i - 1][j]) {
            i = i - 1;  // Coin not used
        } else {
            solution[k] = coins[i - 1];  // Coin used
            j = j - coins[i - 1];  // Reduce amount
            k++;
        }
    }

    // Print the solution array (coins used)
    printf("\nThe Solution Array is :- ");
    for(i = 0; i < k; i++) {
        printf("\n%d", solution[i]);
    }

    getch();
}
