#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

struct node *create(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void insert_end(int data) {
    struct node *newnode = create(data);

    if (head == NULL) {
        head = newnode;   // FIXED ✔
        return;
    }

    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newnode;
    newnode->prev = current;
}

void insert_left(int new_data, int key_value) {
    struct node *newnode = create(new_data);

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *current = head;
    while (current != NULL && current->data != key_value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Key %d not found, insertion failed.\n", key_value);
        free(newnode);
        return;
    }

    newnode->next = current;
    newnode->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = newnode;
    else
        head = newnode;   // inserting before first node

    current->prev = newnode;
}

void delete_by_value(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found\n", key);
        return;
    }

    if (current == head) {     // deleting first node
        head = current->next;
        if (head != NULL)
            head->prev = NULL;
    } else {
        current->prev->next = current->next;
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);
    printf("Node with value %d deleted\n", key);
}

void search(int key) {
    struct node *current = head;
    int pos = 1;

    while (current != NULL && current->data != key) {
        current = current->next;
        pos++;
    }

    if (current == NULL)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", pos);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;
    printf("Doubly Linked List: ");

    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, value, key;

    do {
        printf("\n1. Insert end\n2. Insert left\n3. Delete specific value\n4. Search element\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 2:
                printf("Enter new value and key value: ");
                scanf("%d%d", &value, &key);
                insert_left(value, key);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                delete_by_value(key);
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 5:
                display();
                break;

            case 6:
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 6);

    return 0;
}

