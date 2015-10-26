/*
	SINWAR PREM
	premsinwar4@gmail.com
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//node
struct node{
	int data;
	struct node *next;
};
struct node* head=NULL;
struct node *inform(struct node *naya)
{
	naya=(struct node*)malloc(sizeof(struct node));
	naya->next=NULL;
	printf("Enter data for new node\n");
	scanf("%d",&naya->data);
	return naya;
}
void insert()
{
	int a;
	struct node *naya;
	struct node *temp=head;
	printf("Press \n1 for front \n2 for in-between \n3 for end\n");
	scanf("%d",&a);
	naya=inform(naya);
	naya->next=head;
	switch(a){
		case 1:
			naya->next=head;
			if(head!=NULL)
			{
				while(temp->next!=head)//last node point to head node
				{
					temp=temp->next;
				}
				temp->next=naya;
				head=naya;
			}
			else
			{
				naya->next=naya;
				head=naya;
			}
			break;
		case 2:
			int dat;
			printf("Insert the data of the node after which the new node to be inserted\n");
			scanf("%d",&dat);
			
			while(temp->data!=dat)
			temp=temp->next;
			naya->next=temp->next;
			temp->next=naya;
			break;
		case 3:
			while(temp->next!=head)
			temp=temp->next;
			temp->next=naya;
			naya->next=head;	
			break;
	}	
}
void print()
{
	if(head==NULL)
	printf("There is no element for print\n");
	else
	{
		struct node* temp=head;
		printf("\n%d ",temp->data);
		while(temp->next!=head)
		{
			temp=temp->next;
			printf("%d ",temp->data);
		}
	}
	printf("\n\n");
}
//function for deletion
void del()
{
	int b;
	printf("Press \n1 for front \n2 for in-between \n3 for end\n");
	scanf("%d",&b);
	struct node* temp;
	switch(b){
		case 1:
			if(head==NULL)
			printf("Head node is not there\n");
			else
			{
				struct node* prev=head;
				while(prev->next!=head)
				prev=prev->next;
				temp=head;
				head=temp->next;
				prev->next=head;
				free(temp);
			}
			break;
		case 2:
			printf("Enter the data of node to be deleted\n");
			int t;
			scanf("%d",&t);
			temp=head;
			struct node* prev;
			while(temp->data!=t)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=temp->next;
			temp->next=NULL;
			free(temp);
			break;
		case 3:
			temp=head;
			while(temp->next!=head)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=head;
			temp->next=NULL;
			free(temp);
			break;
		default:
			printf("Invalid choice\n");
			break;
	}
}
int main()
{
	int ch;
	printf("Circular Link List\n");
	lable:
		printf("Press \n1 for insertion \n2 for deletion \n3 for display\n");
		scanf("%d",&ch);
		switch(ch){
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
	goto lable;
}
