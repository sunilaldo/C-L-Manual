#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct list
{ int no;
struct list*next;
}
LIST;
LIST *p,*t,*h,*y,*ptr,*pt;
void create(void);
void insert(void);
void delet(void);
void display(void);
int j,pos,k=1,count;
void main()
{int n,i=1,opt;
p=NULL;
printf("linked list implementation of list ADTs \n\n");
printf("eter the number of nodes:");
scanf("%d",&n);
printf("\n");
count=n;
while(i<=n)
{
create();
i++;
}
printf("\n");
do
{
printf("*******************\n");
printf("*MAIN MENU*\n");
printf("1.Insert\n");
printf("2.Delete\n");
printf("3,Display\n");
printf("4.Exit\n");
printf("Enter your option:");
scanf("%d",&opt);
printf("\n");
switch(opt)
{
case 1:
insert();
count++;
break;
case 2:
delet();
count--;
if(count==0)
{
printf("\nList is Empty\n");
}
break;
case 3:
printf("list elements are :\n");
display();
break;
case 4:
printf("thank you for using the program!\n");
exit(0);
break;
}
}
while(opt!=4);
getch();
}
void create()
{
if(p==NULL)
{
p=(LIST*)malloc(sizeof(LIST));

printf("enter the element:");
scanf("%d",&p->no);
p->next=NULL;
h=p;
}
else
{
t=(LIST*)malloc(sizeof (LIST));
printf("enter the element:");
scanf("%d",&t->no);
t->next=NULL;
p->next=t;
p=t;
}
}
void insert()
{
t=h;
p=(LIST*)malloc(sizeof(LIST));
printf("enter the elements to be inserted:");
scanf("%d",&p->no);
printf("enter the postion to insert:");
scanf("%d",&pos);
if(pos==1)
{
h=p;
h->next=t;
}
else
{
for(j=1;j<(pos-1);j++)
t=t->next;
p->next=t->next;
t->next=p;
t=p;
}
printf("\n");
}
void delet()
{
printf("enter the position to delete:");
scanf("%d",&pos);
if(pos==1)
{
h=h->next;
}
else
{
t=h;
for(j=1;j<(pos-1);j++)
t=t->next;
pt=t->next->next;
free(t->next);
t->next=pt;
}
printf("\n");
}
void display()
{
t=h;
while(t-> next!=NULL)
{
printf("%d\t",t->no);
t=t->next;
}
printf("%d",t->no);
printf("\n\n");
}


