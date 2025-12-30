#include <stdio.h>
#define MAX 5
int cq[MAX];
int front = -1, rear = -1;

void insert() {
int value;
if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
printf("Queue Overflow! Cannot insert element.\n");
} else {
printf("Enter the value to insert: ");
scanf("%d", &value);
if (front == -1) {
front = rear = 0;
} else if (rear == MAX - 1 && front != 0) {
rear = 0;
} else {
rear++;
}
cq[rear] = value;
printf("%d inserted into queue.\n", value);
}
}


void delete() {
if (front == -1) {
printf("Queue is Empty! Cannot delete element.\n");
} else {
printf("%d deleted from queue.\n", cq[front]);
if (front == rear) {
front = rear = -1;
} else if (front == MAX - 1) {
front = 0;
} else {
front++;
}
}
}

void display() {
int i;
if (front == -1) {
printf("Queue is Empty.\n");
} else {
printf("Queue elements are:\n");
if (front <= rear) {
for (i = front; i <= rear; i++) {
printf("%d ", cq[i]);
}
} else {
for (i = front; i < MAX; i++) {
printf("%d ", cq[i]);
}
for (i = 0; i <= rear; i++) {
printf("%d ", cq[i]);
}
}
printf("\n");
}
}

int main() {
int choice;
while (1) {
printf("\n--- Circular Queue Operations ---\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
printf("Exiting program.\n");
return 0;
default:
printf("Invalid choice! Try again.\n");
}
}
}

