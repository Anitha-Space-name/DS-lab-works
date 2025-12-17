#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;


int count() {
    struct node *temp = head;
    int i = 0;

    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    return i;
}


struct node *create(int value) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}


void insert_begin(int value) {
    struct node *newnode = create(value);

    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}


void delete_begin() {
    struct node *temp;

    if (head == NULL) {
        printf("Deletion is not possible\n");
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}


void delete_end() {
    struct node *temp1, *temp2;

    if (head == NULL) {
        printf("Deletion is not possible\n");
    }
    else if (head->next == NULL) {  // only one node
        free(head);
        head = NULL;
    }
    else {
        temp1 = head;
        while (temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        free(temp1);
    }
}


void delete_pos(int pos) {
    struct node *temp1, *temp2;
    int i, c = 1;

    i = count();
    if (pos == 1) {
        delete_begin();
        return;
    }
    else if (pos > i || pos < 1) {
        printf("Deletion is not possible\n");
        return;
    }

    temp1 = head;
    while (c < pos) {
        temp2 = temp1;
        temp1 = temp1->next;
        c++;
    }
    temp2->next = temp1->next;
    free(temp1);
}


void delete_spec_value(int key) {
    struct node *temp1 = head, *temp2 = NULL;

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (head->data == key) {
        head = head->next;
        free(temp1);
        printf("Element %d deleted.\n", key);
        return;
    }

    while (temp1 != NULL && temp1->data != key) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (temp1 == NULL) {
        printf("Element %d not found.\n", key);
        return;
    }

    temp2->next = temp1->next;
    free(temp1);
    printf("Element %d deleted.\n", key);
}

// Display linked list
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, pos, value, key;

    do {
        printf("\n 1. Insert at Beginning\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Position\n");
        printf("5. Delete by Key\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_begin(value);
                break;

            case 2:
                delete_begin();
                break;

            case 3:
                delete_end();
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;

            case 5:
                printf("Enter key value to delete: ");
                scanf("%d", &key);
                delete_spec_value(key);
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (ch != 7);

    return 0;
}
