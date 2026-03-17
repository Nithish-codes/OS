#include <stdio.h>

int main() {
    int p, r, i, j, count = 0;

    printf("Enter number of processes and resources: ");
    scanf("%d %d", &p, &r);

    int allocation[10][10], max[10][10], need[10][10];
    int available[10], safe[10], done[10];

    printf("Enter allocation matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter max matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available resources:\n");
    for (i = 0; i < r; i++) {
        scanf("%d", &available[i]);
    }

    printf("\nNeed Matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < p; i++) {
        done[i] = 0;
    }

    while (count < p) {
        int found = 0;

        for (i = 0; i < p; i++) {
            if (done[i] == 0) {
                int flag = 1;

                for (j = 0; j < r; j++) {
                    if (need[i][j] > available[j]) {
                        flag = 0;
                        break;
                    }
                }

                if (flag) {
                    safe[count] = i;
                    done[i] = 1;

                    for (j = 0; j < r; j++) {
                        available[j] += allocation[i][j];
                    }

                    count++;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("\nSystem is in Unsafe State\n");
            return 0;
        }
    }

    printf("\nSafe Sequence: ");
    for (i = 0; i < p; i++) {
        printf("P%d ", safe[i]);
    }

    printf("\nSystem is in Safe State\n");

    return 0;
}
