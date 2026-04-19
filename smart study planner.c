#include <stdio.h>
#include <string.h>

#define MAX 50

// Structure for Study Task
struct Task {
    char subject[50];
    int duration; // in minutes
    int completed; // 0 = not done, 1 = done
};

struct Task tasks[MAX];
int count = 0;

// Function to add task
void addTask() {
    if (count >= MAX) {
        printf("Task list is full!\n");
        return;
    }

    printf("Enter subject name: ");
    scanf(" %[^\n]", tasks[count].subject);

    printf("Enter study duration (in minutes): ");
    scanf("%d", &tasks[count].duration);

    tasks[count].completed = 0;
    count++;

    printf("Task added successfully!\n");
}

// Function to view tasks
void viewTasks() {
    if (count == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\n--- Study Plan ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | %d mins | %s\n",
               i + 1,
               tasks[i].subject,
               tasks[i].duration,
               tasks[i].completed ? "Completed" : "Pending");
    }
}

// Function to mark task as completed
void completeTask() {
    int choice;
    viewTasks();

    printf("Enter task number to mark as completed: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("Invalid choice!\n");
        return;
    }

    tasks[choice - 1].completed = 1;
    printf("Task marked as completed!\n");
}

// Main function
int main() {
    int option;

    while (1) {
        printf("\n--- Smart Study Planner ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}