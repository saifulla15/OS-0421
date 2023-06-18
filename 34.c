#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

// Structure to hold file records
struct Record {
    int id;
    char data[50];
};

// Function to add a record to the file
void addRecord(struct Record file[], int *num_records) {
    if (*num_records == MAX_RECORDS) {
        printf("File is full. Cannot add more records.\n");
        return;
    }

    struct Record record;
    printf("Enter record ID: ");
    scanf("%d", &record.id);
    printf("Enter record data: ");
    scanf(" %[^\n]", record.data);

    file[*num_records] = record;
    (*num_records)++;
    printf("Record added successfully.\n");
}

// Function to display all records in the file
void displayFile(struct Record file[], int num_records) {
    printf("File Records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("ID: %d\n", file[i].id);
        printf("Data: %s\n", file[i].data);
        printf("------------------------\n");
    }
}

// Function to search and display a record by ID
void searchRecord(struct Record file[], int num_records) {
    int searchID;
    printf("Enter record ID to search: ");
    scanf("%d", &searchID);

    int found = 0;
    for (int i = 0; i < num_records; i++) {
        if (file[i].id == searchID) {
            printf("Record Found!\n");
            printf("ID: %d\n", file[i].id);
            printf("Data: %s\n", file[i].data);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record with ID %d not found.\n", searchID);
    }
}

int main() {
    struct Record file[MAX_RECORDS];
    int num_records = 0;

    int choice;
    do {
        printf("\nFile Allocation Strategy\n");
        printf("1. Add Record\n");
        printf("2. Display File\n");
        printf("3. Search Record by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(file, &num_records);
                break;
            case 2:
                displayFile(file, num_records);
                break;
            case 3:
                searchRecord(file, num_records);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
