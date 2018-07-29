#include <stdio.h>

int main() {
    int tests;
    int i, j, k;
    scanf("%d", &tests);

    int cases[tests];
    for (i = 0; i < tests; i++) {
        scanf("%d", &cases[i]);
    }

    for (i = 1; i <= tests; i++) {
        int weight = cases[i - 1];
        printf("Case #%d:", i);

        for (j = 0; j <= weight; j++) {
            int spaces = weight - j;
            int stars = weight - spaces;

            for (k = 0; k < spaces; k++) {
                printf(" ");
            }

            for (k = 0; k < stars; k++) {
                printf("*");
            }

            printf("\n");
        }
    }

    return 0;
}
