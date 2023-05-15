#include <stdio.h>

#define MAX_MEM_SIZE 1000  // maximum size of memory
#define MAX_PROC_SIZE 100  // maximum size of a process

int main() {
    int mem_size, n;
    int mem_blocks[MAX_MEM_SIZE], proc_size[MAX_PROC_SIZE], proc_alloc[MAX_PROC_SIZE];
    int i, j;

    // Get user input for memory size and number of processes
    printf("Enter the size of the memory: ");
    scanf("%d", &mem_size);
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Initialize memory blocks to 0 (i.e. unallocated)
    for (i = 0; i < mem_size; i++) {
        mem_blocks[i] = 0;
    }

    // Get user input for process sizes
    printf("Enter the size of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &proc_size[i]);
    }

    // Allocate memory to each process using First Fit algorithm
    for (i = 0; i < n; i++) {
        for (j = 0; j < mem_size; j++) {
            if (mem_blocks[j] == 0 && j + proc_size[i] <= mem_size) {
                // This memory block is free and large enough to allocate the process
                int k;
                for (k = j; k < j + proc_size[i]; k++) {
                    mem_blocks[k] = i + 1;  // mark the memory block as allocated to process i+1
                }
                proc_alloc[i] = j;  // record the starting position of the allocated memory block
                break;
            }
        }
        if (j == mem_size) {
            // No free memory block is large enough to allocate the process
            printf("Error: Not enough memory to allocate Process %d\n", i + 1);
            return 1;
        }
    }

    // Print the allocation table
    printf("Allocation Table:\n");
    printf("Process\tSize\tStart Address\tEnd Address\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\n", i + 1, proc_size[i], proc_alloc[i], proc_alloc[i] + proc_size[i] - 1);
    }

    return 0;
}
