#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 101

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    long long phoneNumber;
    struct Contact* next;
} Contact;

typedef struct PhoneBook {
    Contact* head;
    Contact* tail;
} PhoneBook;

void init(PhoneBook* pb) {
    pb->head = NULL;
    pb->tail = NULL;
}

Contact* findContact(PhoneBook* pb, const char* name) {
    Contact* current = pb->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void addContact(PhoneBook* pb, const char* name, long long number) {
    Contact* existing = findContact(pb, name);
    if (existing) {
        existing->phoneNumber = number;
        printf("Success\n");
        return;
    }

    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    newContact->phoneNumber = number;
    newContact->next = NULL;

    if (pb->head == NULL) {
        pb->head = pb->tail = newContact;
    } else {
        pb->tail->next = newContact;
        pb->tail = newContact;
    }
    printf("Success\n");
}

void deleteContact(PhoneBook* pb, const char* name) {
    if (pb->head == NULL) {
        printf("Not Found\n");
        return;
    }

    Contact* current = pb->head;
    Contact* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                pb->head = current->next;
                if (pb->head == NULL) pb->tail = NULL;
            } else {
                previous->next = current->next;
                if (current == pb->tail) pb->tail = previous;
            }
            free(current);
            printf("Success\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Not Found\n");
}

void searchContact(PhoneBook* pb, const char* name) {
    Contact* contact = findContact(pb, name);
    if (contact != NULL) {
        printf("%lld\n", contact->phoneNumber);
    } else {
        printf("Not Found\n");
    }
}

int main() {
    PhoneBook pb;
    init(&pb);

    int n;
    scanf("%d\n", &n);

    while (n--) {
        char name[MAX_NAME_LENGTH];
        long long number;
        char input[200];

        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "add(\"%[^\"]\", %lld)", name, &number) == 2) {
            addContact(&pb, name, number);
        } else if (sscanf(input, "delete(\"%[^\"]\")", name) == 1) {
            deleteContact(&pb, name);
        } else if (sscanf(input, "search(\"%[^\"]\")", name) == 1) {
            searchContact(&pb, name);
        }
    }

    return 0;
}
