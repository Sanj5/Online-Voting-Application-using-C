#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of reminders
#define MAX_REMINDERS 50
#define MAX_LENGTH 100

// Structure to hold reminder information
struct Reminder {
    int day;
    int month;
    int year;
    char text[MAX_LENGTH];
};

int main() {
    struct Reminder reminders[MAX_REMINDERS];
    int numReminders = 0,i;

    printf("Calendar/Reminder Application\n");

    while (1) {
        printf("\nMENU\n");
        printf("1. Add Reminder\n");
        printf("2. View Reminders\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                if (numReminders < MAX_REMINDERS) {
                    printf("Enter date (DD MM YYYY): ");
                    int day, month, year;
                    scanf("%d %d %d", &day, &month, &year);
                    getchar(); // Clear newline from input buffer

                    if (day < 1 || day > 31 || month < 1 || month > 12) {
                        printf("Invalid date. Please enter a valid date.\n");
                        break;
                    }

                    if (numReminders >= MAX_REMINDERS) {
                        printf("Maximum reminders reached. Cannot add more.\n");
                        break;
                    }

                    printf("Enter reminder text: ");
                    fgets(reminders[numReminders].text, MAX_LENGTH, stdin);
                    reminders[numReminders].text[strcspn(reminders[numReminders].text, "\n")] = '\0'; // Remove newline

                    reminders[numReminders].day = day;
                    reminders[numReminders].month = month;
                    reminders[numReminders].year = year;

                    numReminders++;
                    printf("Reminder added successfully.\n");
                } else {
                    printf("Maximum reminders reached. Cannot add more.\n");
                }
                break;

            case 2:
                if (numReminders == 0) {
                    printf("No reminders added yet.\n");
                } else {
                    printf("REMINDERS:\n");
                    for (i = 0; i < numReminders; i++) {
                        printf("Date: %d/%d/%d - %s\n", reminders[i].day, reminders[i].month, reminders[i].year, reminders[i].text);
                    }
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }

    return 0;
}
