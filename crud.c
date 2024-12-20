#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} User;

void addUser(FILE *file) {
    User user;
    printf("Enter user ID: ");
    scanf("%d", &user.id);
    printf("Enter user name: ");
    getchar();
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0';
    printf("Enter user age: ");
    scanf("%d", &user.age);

    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    printf("User added successfully.\n");
}

void displayUsers(FILE *file) {
    rewind(file);
    User user;
    int hasUsers = 0;

    printf("ID\tName\tAge\n");
    printf("-----------------------\n");

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        hasUsers = 1;
        printf("%d\t%s\t%d\n", user.id, user.name, user.age);
    }

    if (!hasUsers) {
        printf("No users to display.\n");
    }
}

void updateUser(FILE *file, int id) {
    rewind(file);
    FILE *tempFile = tmpfile();
    if (!tempFile) {
        printf("Error creating temporary file.\n");
        return;
    }

    User user;
    int found = 0;

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

    if (!found) {
        printf("User not found.\n");
    } else {
        rewind(file);
        rewind(tempFile);
        freopen(NULL, "w", file);
        while (fscanf(tempFile, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
            fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
        }
        printf("User updated successfully.\n");
    }
}

void deleteUser(FILE *file, int id) {
    rewind(file);
    FILE *tempFile = tmpfile();
    if (!tempFile) {
        printf("Error creating temporary file.\n");
        return;
    }

    User user;
    int found = 0;

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    if (!found) {
        printf("User not found.\n");
    } else {
        rewind(file);
        rewind(tempFile);
        freopen(NULL, "w", file);
        while (fscanf(tempFile, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
            fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
        }
        printf("User deleted successfully.\n");
    }
}

int main() {
    FILE *file = fopen("users.txt", "w+");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    while (1) {
        int choice, id;
        printf("\n1. Add User\n2. Display Users\n3. Update User\n4. Delete User\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(file);
                break;
            case 2:
                displayUsers(file);
                break;
            case 3:
                printf("Enter user ID to update: ");
                scanf("%d", &id);
                updateUser(file, id);
                break;
            case 4:
                printf("Enter user ID to delete: ");
                scanf("%d", &id);
                deleteUser(file, id);
                break;
            case 5:
                printf("Exiting the program!!\n");
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
