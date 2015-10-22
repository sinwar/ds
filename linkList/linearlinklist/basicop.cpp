#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert_first();
//create a node having three data and one pointer
struct node
{
	int data;
	float cgpa;
	char name[20];
	struct node *next;
};
//set initially head node as null
struct node *head=NULL;
void print();
void insert_in();
void insert_end();
void del_first();
void del_end();
void del_in();
int rar;
int main()
{
	int ch,a=0,a1,b=0,c=0,c1;
	printf("Choose a operation on linear linked list.\n");
	lable:
		printf("1 for insertion\n 2 for deletion\n 3 for display\n 4 for exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				
					printf("Press\n 1 for at front\n 2 for at in-between\n 3 for at end.\n");
					scanf("%d",&a1);
					switch(a1)
					{
						case 1:
							insert_first();
							break;
						case 2:
							insert_in();
							break;
						case 3:
							insert_end();
							break;
					}
				break;
			case 2:
					printf("Press for deletion\n 1 from front\n 2 from in-between\n 3 from end\n");
					scanf("%d",&c1);
					switch(c1)
					{
						case 1:
							del_first();
							break;
						case 2:
							del_in();
							break;
						case 3:
							del_end();
							break;
					}
				break;
			case 3:
				print();
				break;
				//here is one error to remove
			case 4:
				break;
			default: printf("Invalid choice\n");
				break;
			
		}
	goto lable;
	getch();
}
//function for new node at front 
void insert_first()
{
	struct node *fnew;
	fnew=(struct node *)malloc(sizeof(struct node));
	printf("insert roll no, cgpa and name respectivly\n");
	scanf("%d%f%s",&fnew->data,&fnew->cgpa,&fnew->name);
	if(head==NULL)
	{
		fnew->next=NULL;
		head=fnew;
	}
	else
	{
		fnew->next=head;
		head=fnew;
	}
}
//function for print complete link list
void print()
{
	if(head==NULL)
	printf("Nothing for print\n");
	else
	{
		printf("RollNo  CGPA  Name\n");
		struct node* temp=head;
		printf("%d  %.2f  %s\n",temp->data,temp->cgpa,temp->name);
		while(temp->next!=NULL)
		{
			temp=temp->next;
			printf("%d  %.2f  %s\n",temp->data,temp->cgpa,temp->name);
		}
	}
}
//function for insert in-between
void insert_in()
{
	struct node* fnew;
	fnew=(struct node*)malloc(sizeof(struct node));
	printf("Enter the roll no after which insertion takes place.\n");
	scanf("%d",&rar);
	printf("insert roll no, cgpa and name respectivly\n");
	scanf("%d%f%s",&fnew->data,&fnew->cgpa,&fnew->name);
	struct node* temp=head;
	while(temp->data!=rar)
	{
		temp=temp->next;
	}
	fnew->next=temp->next;
	temp->next=fnew;
}
//function for insert end of the link list
void insert_end()
{
	struct node* fnw;
	fnw=(struct node*)malloc(sizeof(struct node));
	printf("insert roll no, cgpa and name respectivly\n");
	scanf("%d%f%s",&fnw->data,&fnw->cgpa,&fnw->name);
	struct node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=fnw;
	fnw->next=NULL;
}
//function for delete first node
void del_first()
{
	if(head==NULL)
	printf("There is no element for deletion\n");
	else
	{
		struct node* temp=head;
		head=temp->next;
		temp->next=NULL;
		free(temp);
	}
}
//function for delete last element
void del_end()
{
	struct node* temp=head;
	struct node* prev;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	temp->next=NULL;
	free(temp);
}
//function for delete a element forom in-between
void del_in()
{
	printf("Enter the roll no for deletion\n");
	scanf("%d",&rar);
	struct node* temp=head;
	struct node* prev;
	while(temp->data!=rar)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	temp->next=NULL;
	free(temp);
}
