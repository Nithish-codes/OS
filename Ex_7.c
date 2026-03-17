#include <stdio.h>

int main() {
    int n, m, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], request[n][m], available[m];
    int finish[n], work[m];

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter Request Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int found;

    do {
        found = 0;

        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int possible = 1;

                for (j = 0; j < m; j++) {
                    if (request[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if (possible) {
                    for (j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

    } while (found);

    int deadlock = 0;

    for (i = 0; i < n; i++) {
        if (!finish[i]) {
            deadlock = 1;
            printf("Process P%d is in deadlock\n", i);
        }
    }

    if (!deadlock) {
        printf("No Deadlock Detected\n");
    }

    return 0;
}
