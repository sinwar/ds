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
	while(b==0)
	{
		printf("Press \n1 for insertion \n2 for deletion \n3 for deletion\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				print();
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
		printf("Press 0 for continue 1 for exit\n");
		scanf("%d",&b);
	}
}
struct node *inform(struct node *naya)
{
	naya->next=NULL;
	printf("Enter data for new node\n");
	scanf("%d",&naya->data);
	return naya;
}
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
		while(h->data>temp->data)
		temp=temp->next;
		h->next=temp->next;
		temp->next=h;
	}
}
void print()
{
	struct node* temp=head;
	printf("%d ",temp->data);
	while(temp->next!=NULL)
	{
		temp=temp->next;
		printf("%d ",temp->data);
	}
}
