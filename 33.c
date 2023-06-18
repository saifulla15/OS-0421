#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

// Function to find the page with the longest future reference distance
int findOptimalPage(int pages[], int frames[], int current, int num_pages, int num_frames) {
    int farthest = -1;
    int page_index = -1;

    for (int i = 0; i < num_frames; i++) {
        int j;
        for (j = current; j < num_pages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    page_index = i;
                }
                break;
            }
        }

        if (j == num_pages)
            return i;
    }

    if (page_index == -1)
        page_index = 0;

    return page_index;
}

// Function to simulate optimal paging technique
void simulateOptimalPaging(int pages[], int num_pages) {
    int frames[MAX_FRAMES];
    int page_faults = 0;

    for (int i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1;

    for (int i = 0; i < num_pages; i++) {
        int j;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i])
                break;
        }

        if (j == MAX_FRAMES) {
            int page_index = findOptimalPage(pages, frames, i + 1, num_pages, MAX_FRAMES);
            frames[page_index] = pages[i];
            page_faults++;
        }
    }

    printf("Page Faults: %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES];
    int num_pages;

    printf("Enter the number of pages (maximum %d): ", MAX_PAGES);
    scanf("%d", &num_pages);

    printf("Enter the page reference string:\n");
    for (int i = 0; i < num_pages; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    simulateOptimalPaging(pages, num_pages);

    return 0;
}
