#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure of user
typedef struct {
    int id;
    char name[50];
    int age;
} User;

// creates file to store user data
void createFile() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Error in creating the file.\n");
        return;
    }
    fclose(file);
}

// Function to add a user
void addUser() {
    User user;
    FILE *file = fopen("users.txt", "a");
    if (!file) {
        printf("Error in opening the file.\n");
        return;
    }

    printf("Enter user ID: ");
    scanf("%d", &user.id);
    printf("Enter user name: ");
    getchar();
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0';
    printf("Enter user age: ");
    scanf("%d", &user.age);

    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully.\n");
}

// Function to display all users
void displayUsers() {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        printf("Error opening the file.\n");
        return;
    }

    User user;
    printf("ID\tName\tAge\n");
    printf("-----------------------\n");

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        printf("%d\t%s\t%d\n", user.id, user.name, user.age);
    }
    fclose(file);
}

// Function to update a user
void updateUser(int id) {
    User user;
    int found = 0;
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            printf("Enter new user ID: ");
            scanf("%d", &user.id);
            printf("Enter new user name: ");
            getchar();
            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = '\0';
            printf("Enter new user age: ");
            scanf("%d", &user.age);
        }
        fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User updated successfully.\n");
    } else {
        printf("User not found.\n");
    }
}

// Function to delete a user
void deleteUser(int id) {
    User user;
    int found = 0;
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error creating in temporary file.\n");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User deleted successfully.\n");
    } else {
        printf("User not found.\n");
    }
}

int main() {
    createFile();

    while (1) {
        int choice, id;
        printf("\n1. Add User\n2. Display Users\n3. Update User\n4. Delete User\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                printf("Enter user ID to update: ");
                scanf("%d", &id);
                updateUser(id);
                break;
            case 4:
                printf("Enter user ID to delete: ");
                scanf("%d", &id);
                deleteUser(id);
                break;
            case 5:
                printf("Exiting the program!!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
