// Linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void pop();
void push(int value);
void display();
struct node
{
 int data;
 struct node *link;
};
struct node *top = NULL, *temp;
void main()
{
 int choice, data;
 printf("LINKED LIST IMPLEMENTATION OF STACK\n\n");

 while (1) // infinite loop is used to insert/delete infinite number of elements in stack
 {
 printf("*************************\n");
 printf("* MAIN MENU *\n");
 printf("*************************\n");
 printf("1. Push\n");
 printf("2. Pop\n");
 printf("3. Display\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 printf("\n");
 switch (choice)
 {
 case 1: // To push a new element into stack
 {
 printf("Enter a new element: ");
 scanf("%d", &data);
 push(data);
 break;
 }
 case 2: // pop the element from stack
 {
 pop();
 break;
 }
 case 3: // Display the stack elements
 {
 display();
 break;
 }
 case 4: // To exit
 {
 printf("Thank you for using the program. Exiting...\n");
 exit(0);
 }
 }
 }
 getch();
 // return 0;
}
void display()
{
 temp = top;
 if (temp == NULL)
 {
 printf("\nStack is empty\n");
 }
 printf("\nThe Contents of the Stack are...\n");
 while (temp != NULL)
 {
 printf(" %d->", temp->data);
 temp = temp->link;
 }
 printf("\n\n");
}
void push(int data)
{
 temp = (struct node *)malloc(sizeof(struct node)); // creating a space for the new element.
 temp->data = data;
 temp->link = top;
 top = temp;
 display();
}
void pop()
{
 if (top != NULL)
 {
 printf("The popped element is %d", top->data);
 printf("\n");
 top = top->link;
 }
 else
 {
 printf("\nStack Underflow");
 }
 display();
}