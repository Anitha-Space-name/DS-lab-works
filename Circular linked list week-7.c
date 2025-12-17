#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


struct node *create(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}


void insert_beg(struct node **head, int data) {
    struct node *newnode = create(data);

    if (*head == NULL) {
        *head = newnode;
        newnode->next = *head;
    }
    else {
        struct node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = *head;
        *head = newnode;
    }
}


void insert_end(struct node **head, int data) {
    struct node *newnode = create(data);

    if (*head == NULL) {
        *head = newnode;
        newnode->next = *head;
    }
    else {
        struct node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = *head;
    }
}


void insert_pos(struct node **head, int data, int position) {
    if (position == 0) {
        insert_beg(head, data);
        return;
    }

    struct node *newnode = create(data);
    struct node *temp = *head;
    int i = 0;

    while (i < position - 1 && temp->next != *head) {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


void delete_beg(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    }
    else {
        struct node *temp = *head;

        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = (*head)->next;

        struct node *del = *head;
        *head = (*head)->next;
        free(del);
    }
}


void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}


int main() {
    struct node *head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_beg(&head, data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_end(&head, data);
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert_pos(&head, data, pos);
            break;

        case 4:
            delete_beg(&head);
            break;

        case 5:
            display(head);
            break;

        case 6:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
