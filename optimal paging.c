#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

int main() {
    int pages[MAX_FRAMES], frames[MAX_FRAMES], n, i, j, k, optimal_index, page_faults = 0;
    bool is_duplicate, is_full;

    // Initialize frames with -1 to indicate they are empty
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page sequence: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("\nPage   Frames\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", pages[i]);

        // Check if page is already in frames
        is_duplicate = false;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                is_duplicate = true;
                break;
            }
        }

        if (!is_duplicate) {
            // Check if frames are full
            is_full = true;
            for (j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1) {
                    is_full = false;
                    break;
                }
            }

            // If frames are full, find the optimal page to replace
            if (is_full) {
                int dist[MAX_FRAMES] = {0};
                for (j = 0; j < MAX_FRAMES; j++) {
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            dist[j] = k - i;
                            break;
                        }
                    }
                    if (k == n) {
                        dist[j] = n;
                    }
                }
                optimal_index = 0;
                for (j = 1; j < MAX_FRAMES; j++) {
                    if (dist[j] > dist[optimal_index]) {
                        optimal_index = j;
                    }
                }
                frames[optimal_index] = pages[i];
            }
            // Otherwise, add the page to an empty frame
            else {
                for (j = 0; j < MAX_FRAMES; j++) {
                    if (frames[j] == -1) {
                        frames[j] = pages[i];
                        break;
                    }
                }
            }

            page_faults++;
        }

        // Print current frames
        for (k = 0; k < MAX_FRAMES; k++) {
            printf("%d ", frames[k]);
        }
        printf("\n");
    }

    printf("\nTotal page faults = %d\n", page_faults);
    return 0;
}
