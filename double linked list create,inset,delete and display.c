#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;

struct node *create(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory allocation is failed\n");
        exit(1);
    }
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
};

struct node *insert_end(int data)
{
    struct node *newnode=create(data);
    if(head==NULL)
    {
        return newnode;
    }
    struct node *current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;
    newnode->prev=current;
    return head;
};

void insert_left(int new_data,int key_value)
{
    struct node *newnode=create(new_data);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    struct node *current=head;
    while(current!=NULL && current->data!=key_value)
    {
        current=current->next;
    }
    if(current==NULL)
    {
        printf("Target node with value %d not found node not inserted.\n",key_value);
        free(newnode);
        return;
    }
    newnode->next=current;
    newnode->prev=current->prev;

    if(current->prev!=NULL)
    {
        current->prev->next=newnode;
    }
    else
    {
        head=newnode;
    }
    current->prev=newnode;
}

void delete_by_vlaue(int key)
{
    struct node *current=head;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    while(current!=NULL&&current->data!=key)
    {
        current=current->next;
    }
    if(current==NULL)
    {
        printf("Node with value %d not found key");
        return;
    }
    if(current==head)
    {
        head=current->next;
    }
    if(head!=NULL)
    {
        head->prev=NULL;
    }

else
{
    current->prev->next=current->next;
    if(current->next!=NULL)
    {
        current->next->prev=current->prev;
    }
}
free(current);
printf("Node with value %d deleted\n",key);
}

void search(int key)
{
    struct node *current=head;
    int pos=0;
    while(current!=NULL&&current->data!=key)
    {
        pos++;
        current=current->next;
    }
    if(current==NULL||current->data!=key)
    {
        printf("Element not found\n");
    }
    else
        printf("Element found at position %d",pos+1);
}

void display()
{
    if(head==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *current=head;
    printf("Doubly linked list is:");
    while(current!=NULL)
    {
        printf("%d<->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

void main()
{
    int ch,value,key;
    do
    {
        printf("\n 1.Insert end \n 2.Insert left \n 3.Delete specific value \n 4.Search an element \n 5.display \n 6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the value to inserted:");
                   scanf("%d",&value);
                   insert_end(value);
                   break;
            case 2:printf("Enter the new value and key value:");
                   scanf("%d%d",&value,&key);
                   insert_left(value,key);
                   break;
            case 3:printf("Enter the value of a node to be deleted:");
                   scanf("%d",&key);
                   delete_by_vlaue(key);
                   break;
            case 4:printf("Enter the value to searched:");
                   scanf("%d",&key);
                   search(key);
                   break;
            case 5:display();
                   break;
            case 6:break;
            default:printf("\n Your choice is wrong!");
        }
    }while(ch!=6);
}
