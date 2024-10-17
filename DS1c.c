#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
};
struct Node *front = NULL, *rear = NULL;
void insert(int);
void delet();
void display();
void main()
{
 int choice, value;
 printf("LINKED LIST IMPLEMENTATION OF QUEUES\n\n");
 while (1) {
printf("*************************\n");
printf("*** MAIN MENU ***\n");
printf("*************************\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
printf("\n");
switch (choice) {
 case 1:
printf("Enter the value to be inserted: ");
scanf("%d", &value);
insert(value);
break;
 case 2:
delet();
break;
 case 3:
display();
break;
 case 4:
printf("\nThank you for using the program. Exiting...\n");
exit(0);
 default:
printf("\nInvalid option. Try again.\n");
}
 }
}
void insert(int value)
{
 struct Node *newNode;
 newNode = (struct Node *)malloc(sizeof(struct Node));
 newNode -> data = value;
 newNode -> next = NULL;
 if (front == NULL)
front = rear = newNode;
 else {
rear -> next = newNode;
rear = newNode;
 }
 printf("\nINSERTION SUCCESSFULL\n\n");
}
void delet()
{
 if (front == NULL)
 printf("EMPTY QUEUE\n\n");
 else {
 struct Node *temp = front;
 front = front->next;
 printf("Deleted element: %d\n\n", temp -> data);
 free(temp);
 }
}
void display()
{
 if (front == NULL)
 printf("EMPTY QUEUE\n\n");
 else {
 struct Node *temp = front;

while (temp -> next != NULL) {
 printf("%d -> ", temp -> data);
 temp = temp->next;
 }
 printf("%d -> NULL\n\n", temp -> data);
 }
}