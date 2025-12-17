#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node*next;
}*head=NULL;
int count()
{
struct node *temp;
int i=1;
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
i++;
}
return(i);
}

struct node *create(int value)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Memory allocation failed\n");
exit(0);
}
temp->data=value;
temp->next=NULL;
return temp;
}

void insert_begin(int value)
{
struct node *newnode;
newnode=create(value);
if(head==NULL)
{
head=newnode;
}
else
{
newnode->next=head;
head=newnode;
}
}

void insert_end(int value)
{
struct node *newnode, *temp;
newnode=create(value);
if(head==NULL)
{
head=newnode;
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
}
void insert_pos(int value, int pos)
{
struct node *newnode, *temp1,*temp2;
int i, c=1;
newnode=create(value);

i=count();
if(pos==1)
insert_begin(value);
else if(pos > i+1)
{
printf("insertion is not posible");
return;
}
else
{
temp1=head;
while(c <= pos-1 && temp1 != NULL)
{
temp2=temp1;
temp1=temp1->next;
c++;
}
newnode->next=temp2->next;
temp2->next=newnode;
}
}
void display()
{
struct node *temp;
if(head==NULL)
{
printf("list is empty");
}
else
{
temp=head;
while(temp->next!=NULL)
{
printf("%d-> ", temp->data);
temp=temp->next;
}
printf("%d", temp->data);
}
}

void main()
{
int ch, pos, value;
do
{
printf("\n 1.insert begin\n 2.insert end\n 3.insert position\n 4. display\n 5.exit\n");
printf("enter your choice:");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("enter the value:");
scanf("%d",&value);
insert_begin(value);
break;
case 2: printf("enter value:");
scanf("%d", &value);
insert_end(value);
break;
case 3: printf("enter value:");
scanf("%d", &value);
printf("enter position you want to insert: ");
scanf("%d", &pos);
insert_pos(value, pos);
break;
case 4: display();
break;
case 5:break;
default: printf("\nyour choice is wrong!.. ");
}
} while(ch!=5);
}
