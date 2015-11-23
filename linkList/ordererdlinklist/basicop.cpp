/*
	SINWAR PREM
	premsinwar4@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>
//node 
struct node
{
	int data;
	struct node *next;
};
//create head node and set it equal to null
struct node* head=NULL;
void insert();
void del();
void print();
int main()
{
	int a,b,c;
	printf("This is the ordered linklist\n");
	lable:
		printf("Press \n1 for insertion \n2 for deletion \n3 for display\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				insert();//calling function insert
				break;
			case 2:
				del();//calling function for deletion
				break;
			case 3:
				print();//calling function for display
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
		goto lable;
}
//functon for taking information from user
struct node *inform(struct node *naya)
{
	naya=(struct node *)malloc(sizeof(struct node));
	naya->next=NULL;
	printf("Enter data for new node\n");
	scanf("%d",&naya->data);
	return naya;
}
//function for insertion
void insert()
{
	struct node* h;
	h=inform(h);
	if(head == NULL)
	{
		head=h;
	}
	else
	{
		struct node* temp=head;
		struct node* prev;
		if(h->data<=head->data)
		{
			h->next=head;
			head=h;
		}
		else
		{
			while(h->data>temp->data && temp->next!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}
			//this can be removed(bug here)
			if(temp->next==NULL && h->data<temp->data)
			{
				h->next=prev->next;
				prev->next=h;
			}
			else
			{
				h->next=temp->next;
				temp->next=h;
			}
		}
	}
}
//function for display all the elements of linklist
void print()
{
	if(head==NULL)
	{
		printf("There is no element for display\n");
	}
	else
	{
		struct node* temp=head;
		printf("\n%d ",temp->data);
		while(temp->next!=NULL)
		{
			temp=temp->next;
			printf("%d ",temp->data);
		}
		printf("\n");
	}
}
int dat;
//function for deletion
void del()
{
	printf("Enter the data of element to be deleted\n");
	scanf("%d",&dat);
	struct node* temp;
	struct node* prev;
	if(head==NULL)
	{
		printf("There is no element for deletion\n");
	}
	else if(head->data==dat)
	{
		temp->next=head;
		head=temp;
		free(temp);
	}
	else
	{
		temp=head;
		temp=temp->next;
		while(temp->data!=dat && temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=temp->next;
		temp->next=NULL;
		free(temp);
	}
}
