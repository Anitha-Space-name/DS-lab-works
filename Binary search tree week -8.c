#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node* create(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        exit(1);
    }
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


struct node* insert(struct node *root, int value) {
    if (root == NULL) {
        return create(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}


struct node* find_min(struct node *ptr) {
    while (ptr && ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr;
}


void inorder_tra(struct node *root) {
    if (root != NULL) {
        inorder_tra(root->left);
        printf("%d ", root->data);
        inorder_tra(root->right);
    }
}


void preorder_tra(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_tra(root->left);
        preorder_tra(root->right);
    }
}


void postorder_tra(struct node *root) {
    if (root != NULL) {
        postorder_tra(root->left);
        postorder_tra(root->right);
        printf("%d ", root->data);
    }
}


void display(struct node *root) {
    printf("Tree elements (In-order): ");
    inorder_tra(root);
    printf("\n");
}

int main() {
    struct node *root = NULL;
    int choice, value;

    do {
        printf("\n*** Binary Search Tree Menu ***\n");
        printf("1. Insert Element\n");
        printf("2. Traverse (In-order, Pre-order, Post-order)\n");
        printf("3. Display Elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("\nIn-order Traversal:\n");
                inorder_tra(root);
                printf("\n");

                printf("Pre-order Traversal:\n");
                preorder_tra(root);
                printf("\n");

                printf("Post-order Traversal:\n");
                postorder_tra(root);
                printf("\n");
                break;

            case 3:
                display(root);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
