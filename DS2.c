// Implementation of binary search trees
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
struct tree
{
 int data;
 struct tree *lchild;
 struct tree *rchild;
} *t, *temp;
int element;
void inorder(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);
struct tree *create(struct tree *, int);
struct tree *find(struct tree *, int);
struct tree *insert(struct tree *, int);
struct tree *del(struct tree *, int);
struct tree *findmin(struct tree *);
struct tree *findmax(struct tree *);
int main(void)
{
 int ch;
 printf("BINARY SEARCH TREE\n\n");
 do
 {
 printf("**************************\n");
 printf("*** MAIN MENU ***\n");
 printf("**************************\n");
 printf("1. Create\n");
 printf("2. Insert\n");
 printf("3. Delete\n");
 printf("4. Find\n");
 printf("5. FindMin\n");
 printf("6. FindMax\n");
 printf("7. Inorder\n");
 printf("8. Preorder\n");
 printf("9. Postorder\n");
 printf("10. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &ch);

 printf("\n");
 switch (ch)
 {
 case 1:
 printf("Enter the data: ");
 scanf("%d", &element);
 printf("\n");
 t = create(t, element);
 inorder(t);
 printf("\n\n");
 break;
 case 2:
 printf("Enter the data: ");
 scanf("%d", &element);
 printf("\n");
 t = insert(t, element);
 inorder(t);
 printf("\n\n");
 break;
 case 3:
 printf("Enter the data: ");
 scanf("%d", &element);
 printf("\n");
 t = del(t, element);
 inorder(t);
 printf("\n\n");
 break;
 case 4:
 printf("Enter the data: ");
 scanf("%d", &element);
 temp = find(t, element);
 if (temp->data == element)
 printf("\nElement %d is at %d", element, temp);
 else
 printf("\nElement is not found");
 printf("\n\n");
 break;
 case 5:
 temp = findmin(t);
 printf("Min element = %d", temp->data);
 printf("\n\n");
 break;
 case 6:
 temp = findmax(t);
 printf("Max element = %d", temp->data);
 printf("\n\n");
 break;

 case 7:
 inorder(t);
 printf("\n\n");
 break;
 case 8:
 preorder(t);
 printf("\n\n");
 break;
 case 9:
 postorder(t);
 printf("\n\n");
 break;
 case 10:
 printf("Thank you for using the binary search tree program!\n");
 exit(0);
 }
 } while (ch <= 10);
}
struct tree *create(struct tree *t, int element)
{
 t = (struct tree *)malloc(sizeof(struct tree));
 t->data = element;
 t->lchild = NULL;
 t->rchild = NULL;
 return t;
}
struct tree *find(struct tree *t, int element)
{
 if (t == NULL)
 return NULL;
 if (element < t->data)
 return (find(t->lchild, element));
 else if (element > t->data)
 return (find(t->rchild, element));
 else
 return t;
}
struct tree *findmin(struct tree *t)
{
 if (t == NULL)
 return NULL;
 else if (t->lchild == NULL)
 return t;
 else
 return (findmin(t->lchild));
}
struct tree *findmax(struct tree *t)
{
 if (t != NULL)
 {
 while (t->rchild != NULL)
 t = t->rchild;
 }
 return t;
}
struct tree *insert(struct tree *t, int element)
{
 if (t == NULL)
 {
 t = (struct tree *)malloc(sizeof(struct tree));
 t->data = element;
 t->lchild = NULL;
 t->rchild = NULL;
 return t;
 }
 else if (element < t->data)
 {
 t->lchild = insert(t->lchild, element);
 }
 else if (element > t->data)
 {
 t->rchild = insert(t->rchild, element);
 }
 else if (element == t->data)
 {
 printf("Element already present\n");
 }
 return t;
}
struct tree *del(struct tree *t, int element)
{
 if (t == NULL)
 printf("Element not found\n");
 else if (element < t->data)
 t->lchild = del(t->lchild, element);
 else if (element > t->data)
 t->rchild = del(t->rchild, element);
else if (t->lchild && t->rchild)
 {
 temp = findmin(t->rchild);
 t->data = temp->data;
 t->rchild = del(t->rchild, t->data);
 temp = t;
 if (t->lchild == NULL)
 t = t->rchild;
 return t;
 }
 else if (t->rchild == NULL)
 t = t->lchild;
 free(temp);
 return t;
}
void inorder(struct tree *t)
{
 if (t == NULL)
 return;
 else
 {
 inorder(t->lchild);
 printf("\t%d", t->data);
 inorder(t->rchild);
 }
}
void preorder(struct tree *t)
{
 if (t == NULL)
 return;
 else
 {
 printf("\t%d", t->data);
 preorder(t->lchild);
 preorder(t->rchild);
 }
}
void postorder(struct tree *t)
{
 if (t == NULL)
 return;
 else
 {
 postorder(t->lchild);
 postorder(t->rchild);
 printf("\t%d", t->data);
 }
}
