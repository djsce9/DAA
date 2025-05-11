#include <stdio.h>
#include <conio.h>
#include <limits.h>

int m[100][100], s[100][100];

void matrixChainOrder(int n, int p[]) {
    int i, j, l, k, q;
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParens(int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j] + 1, j);
        printf(")");
    }
}

void main() {
    int dimNo, p[20], i, j, n;

    clrscr();

    printf("Enter the number of dimensions (number of matrices + 1): ");
    scanf("%d", &dimNo);

    printf("Enter the dimensions:\n");
    for (i = 0; i < dimNo; i++) {
        printf("p[%d]: ", i);
        scanf("%d", &p[i]);
    }

    n = dimNo - 1;

    matrixChainOrder(n, p);

    printf("\nCost Matrix (m[i][j]):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i > j)
                printf("-\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nSplit Matrix (s[i][j]):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i > j)
                printf("-\t");
            else
                printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum number of scalar multiplications: %d\n", m[1][n]);

    printf("Optimal Parenthesization: ");
    printOptimalParens(1, n);
    printf("\n");

    getch();
}
