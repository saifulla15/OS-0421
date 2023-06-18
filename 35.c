#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100
#define MAX_FILES 10

typedef struct {
    int indexBlock[MAX_BLOCKS];
    int fileSize;
} File;

void initializeFile(File *file) {
    file->fileSize = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        file->indexBlock[i] = -1;
    }
}

int allocateBlock(File *file, int blockNumber) {
    if (file->fileSize >= MAX_BLOCKS) {
        printf("File is too large. Allocation failed.\n");
        return 0;
    }
    file->indexBlock[file->fileSize] = blockNumber;
    file->fileSize++;
    return 1;
}

void displayFile(File file) {
    printf("File Size: %d blocks\n", file.fileSize);
    printf("Block Pointers: ");
    for (int i = 0; i < file.fileSize; i++) {
        printf("%d ", file.indexBlock[i]);
    }
    printf("\n");
}

int main() {
    File files[MAX_FILES];
    int fileCount = 0;

    while (1) {
        printf("\nFile Allocation Strategy Simulation\n");
        printf("1. Create new file\n");
        printf("2. Allocate block to file\n");
        printf("3. Display file information\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (fileCount >= MAX_FILES) {
                    printf("Maximum file limit reached.\n");
                } else {
                    initializeFile(&files[fileCount]);
                    printf("New file created with index: %d\n", fileCount);
                    fileCount++;
                }
                break;
            }
            case 2: {
                int fileIndex, blockNumber;
                printf("Enter file index: ");
                scanf("%d", &fileIndex);
                printf("Enter block number: ");
                scanf("%d", &blockNumber);
                if (fileIndex >= 0 && fileIndex < fileCount) {
                    if (allocateBlock(&files[fileIndex], blockNumber)) {
                        printf("Block allocated successfully.\n");
                    }
                } else {
                    printf("Invalid file index.\n");
                }
                break;
            }
            case 3: {
                int fileIndex;
                printf("Enter file index: ");
                scanf("%d", &fileIndex);
                if (fileIndex >= 0 && fileIndex < fileCount) {
                    displayFile(files[fileIndex]);
                } else {
                    printf("Invalid file index.\n");
                }
                break;
            }
            case 4: {
                printf("Exiting program.\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
