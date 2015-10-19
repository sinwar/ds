/* 
	SINWAR PREM
	premsinwar4@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>
struct node *insbeg(struct node*);
int insin(struct node*);
int insend(struct node*);
struct node *delbeg(struct node*);
int delin(struct node*);
int delend(struct node*);
int display(struct node*);
int empty(struct node*);
struct node *getinfo(struct node*);
struct node{
	int rno;
	char name[20];
	float cgpa;
	struct node *next;
};
int main()
{
	struct node *h;
	h=NULL;
	int ch,d,pos;
	lable:
	printf("\nenter ur choice...\n1.insert\n2.delete\n3.display\n4.exit");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nposition to insert...\n1.begin\n2.inbetween\n3.end\n");
			scanf("%d",&pos);
			switch(pos)
			{
				case 1:
					h=insbeg(h);
					break;
				case 2:
					insin(h);
					break;
				case 3:
					insend(h);
					break;
			}
			break;
		case 2:
			printf("\nposition to insert...\n1.begin\n2.inbetween\n3.end\n");
			scanf("%d",&pos);
			switch(pos)
			{
				case 1:
					h=delbeg(h);
					break;
				case 2:
					delin(h);
					break;
				case 3:
					delend(h);
					break;
			}
			break;
		case 3:
			display(h);
			break;
		case 4:
			return 0;
	}
	goto lable;
}
int empty(struct node *n)
{
	if(n==NULL)
	return 1;
	return 0;
}
struct node *getinfo(struct node *n)
{
	n->next=NULL;
	printf("\nenter ur data...\n1.Rollno\n2.Name\n3.CGPA\n");
	scanf("%d",&n->rno);
	scanf("%s",n->name);
	scanf("%f",&n->cgpa);
	return n;
}
struct node *insbeg(struct node *h)
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n=getinfo(n);
	if(h==NULL)
	{
		h=n;
		return h;
	}
	n->next=h;
	h=n;
	return h;
}
int insin(struct node *h)
{
	struct node *n,*t;
	t=h;
	n=(struct node*)malloc(sizeof(struct node));
	n=getinfo(n);
	int pos;
	printf("\nenter ur position...\n");
	scanf("%d",&pos);
	while(pos!=2)
	{
		t=t->next;
		pos--;
	}
	n->next=t->next;
	t->next=n;
	return 0;
}
int insend(struct node *h)
{
	struct node *n,*t;
	t=h;
	n=(struct node*)malloc(sizeof(struct node));
	while(t->next!=NULL)
	{
		t=t->next;	
	}
	n=getinfo(n);
	t->next=n;
	n->next=NULL;
	return 0;
}
struct node *delbeg(struct node *h)
{
	if(empty(h))
	return h;
	struct node *t;
	t=h;
	t=t->next;
	h->next=NULL;
	h=t;
	return h;
}
int delin(struct node *h)
{
	struct node *t,*t1;
	t=h;
	int pos;
	printf("\nenter pos...");
	scanf("%d",&pos);
	while(pos!=2)
	t=t->next;
	t1=t->next;
	t->next=t1->next;
	t1->next=NULL;
	return 0;
}
int delend(struct node *h)
{
	int cnt=0;
	struct node *t,*t1;
	t=h;
	if(empty(h))
	return 0;
	while(t->next!=NULL)
	{
		t=t->next;
		cnt++;
	}
	cnt--;
	t=h;
	while(cnt!=0)
	{
		t=t->next;
		cnt--;
	}
	t->next=NULL;
	return 0;
}
int display(struct node *h)
{
	struct node *t;
	t=h;
	if(empty(h))
	return 0;
	while(t!=NULL)
	{
		printf("\nYour details..\n1.Rollno:%d\n2.Name:%s\n3.CGPA:%f",t->rno,t->name,t->cgpa);
		t=t->next;
	}
	return 0;
}
