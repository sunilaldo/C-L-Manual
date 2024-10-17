#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 3
struct node
{
 int data;
 struct node *next;
};
struct node *head[TABLE_SIZE] = {NULL}, *c, *p;
void insert(int i, int val)
{
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 newnode->data = val;
 newnode->next = NULL;
 if (head[i] == NULL)
 head[i] = newnode;
 else
 {
 c = head[i];
 while (c->next != NULL)
 c = c->next;
 c->next = newnode;
 }
}
void display(int i)
{
 if (head[i] == NULL)
 {
 if (i == 0)
 printf("No Hash Entry");
 return;
 }
 else
 {
 printf("%d ->", head[i]->data);
 for (c = head[i]->next; c != NULL; c = c->next)
 printf("%d ->", c->data);
 }
}
void main()
{
 int opt, val, i;
 printf("HASHING WITH SEPARATE CHAINING\n\n");
 while (1)
 {
 printf("*********************\n");
 printf("* MAIN MENU *\n");
 printf("*********************\n");
 printf("1. Insert\n");
 printf("2. Display\n");
 printf("3. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &opt);
 switch (opt)
 {
 case 1:
 printf("\nEnter a value to insert into the hash table:\n");
 scanf("%d", &val);
 i = val % TABLE_SIZE;
 insert(i, val);
 printf("\n");
 break;
 case 2:
 for (i = 0; i < TABLE_SIZE; i++)
 {
 printf("\nHash entries at index %d\n", i);
 display(i);
 }
 printf("\n\n");
 break;
 case 3:
 printf("\nThank you for using the program. Exiting...\n");
 exit(0);
 }
 }
}
