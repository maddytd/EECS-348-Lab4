#include <stdio.h>

void find_combinations(int score) {
    int td2, td1, td, fg, saf;
    int count = 0;

    printf("Possible combinations of scoring plays if a team's score is %d:\n\n", score);

    for (td2 = 0; td2 * 8 <= score; td2++) {
        for (td1 = 0; td2 * 8 + td1 * 7 <= score; td1++) {
            for (td = 0; td2 * 8 + td1 * 7 + td * 6 <= score; td++) {
                for (fg = 0; td2 * 8 + td1 * 7 + td * 6 + fg * 3 <= score; fg++) {
                    int remaining = score - (td2 * 8 + td1 * 7 + td * 6 + fg * 3);
                    /* remaining must be divisible by 2 for safeties */
                    if (remaining % 2 == 0) {
                        saf = remaining / 2;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               td2, td1, td, fg, saf);
                        count++;
                    }
                }
            }
        }
    }

    if (count == 0) {
        printf("No possible combinations found.\n");
    }
    printf("\nTotal combinations: %d\n\n", count);
}

int main() {
    int score;

    printf("Enter 0 or 1 to STOP\n");

    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }

        find_combinations(score);
    }

    return 0;
}